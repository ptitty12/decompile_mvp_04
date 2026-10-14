#include "runtime/hle.h"

#include <cstdio>
#include <cctype>
#include <cstring>

#include "ppc/mem_access.h"
#include "runtime/machine.h"

namespace mvp::rt {

namespace {

void default_report(const std::string& line) {
  std::fputs(line.c_str(), stdout);
}

// Guest variadic arguments (PowerPC EABI): integers in r3..r10, then the caller's
// parameter area at SP+8; doubles in f1..f8, then 8-byte aligned in the same area.
struct VaReader {
  Cpu& c;
  int gpr, fpr = 1;
  u32 overflow;
  VaReader(Cpu& cpu, int first) : c(cpu), gpr(first), overflow(cpu.gpr[1] + 8) {}
  u32 next_int() {
    if (gpr <= 10) return c.gpr[gpr++];
    u32 v = ppc::read32(c, overflow);
    overflow += 4;
    return v;
  }
  std::uint64_t next_int64() {  // long long: an aligned register pair, or 8 aligned bytes
    if (gpr <= 9) {
      if (!(gpr & 1)) ++gpr;  // pairs start at an odd register (r3, r5, r7, r9)
      if (gpr <= 9) {
        std::uint64_t v = (std::uint64_t(c.gpr[gpr]) << 32) | c.gpr[gpr + 1];
        gpr += 2;
        return v;
      }
    }
    gpr = 11;
    overflow = (overflow + 7) & ~7u;
    std::uint64_t v = ppc::read64(c, overflow);
    overflow += 8;
    return v;
  }
  double next_double() {
    std::uint64_t bits;
    if (fpr <= 8) {
      bits = c.fpr[fpr++].ps0;
    } else {
      overflow = (overflow + 7) & ~7u;
      bits = ppc::read64(c, overflow);
      overflow += 8;
    }
    double d;
    std::memcpy(&d, &bits, 8);
    return d;
  }
};

std::string read_cstring(Cpu& c, u32 a, std::size_t max = 4096) {
  std::string s;
  for (std::size_t k = 0; k < max; ++k) {
    u32 ch = ppc::read8(c, a + static_cast<u32>(k));
    if (!ch) break;
    s.push_back(static_cast<char>(ch));
  }
  return s;
}

// OSReport(const char* fmt, ...): the developer log.
void hle_os_report(Cpu& c, GuestFn) {
  ++g_report_count;
  g_report(format_guest(c, c.gpr[3], 4));
}

// ---- VM (DETERMINISM R10): the SDK's virtual memory pages an 8 MiB region at
// 0x7E000000 to ARAM through DSI exceptions. Here the region is plain RAM.

constexpr u32 kVmBase = 0x7E000000u;

// VMInit(u32 memSize, u32 aramBase, u32 aramSize): maps the region; no DSI handler,
// no ARAM paging (the original also patches its exception stubs into code).
void hle_vm_init(Cpu& c, GuestFn) {
  auto* m = static_cast<Machine*>(c.env);
  u32 size = c.gpr[5] ? c.gpr[5] : 0x00800000u;
  if (size > 0x02000000u) size = 0x02000000u;
  m->map_ram(kVmBase, (size + 0xFFFFu) & ~0xFFFFu);
}
// int VMAlloc(u32 vaddr, u32 size): the whole region is already backed.
void hle_vm_alloc(Cpu& c, GuestFn) { c.gpr[3] = 1; }
// void VMStoreAllPages(void), void VMSetLogStatsCallback(cb): nothing to do.
void hle_nothing(Cpu&, GuestFn) {}

}  // namespace

void (*g_report)(const std::string& line) = &default_report;
std::uint64_t g_report_count = 0;

std::string format_guest(Cpu& c, u32 fmt_addr, int first_gpr) {
  std::string fmt = read_cstring(c, fmt_addr);
  VaReader va(c, first_gpr);
  std::string out;
  for (std::size_t i = 0; i < fmt.size(); ++i) {
    if (fmt[i] != '%') {
      out.push_back(fmt[i]);
      continue;
    }
    std::size_t start = i++;
    while (i < fmt.size() && std::strchr("-+ #0", fmt[i])) ++i;
    while (i < fmt.size() && (std::isdigit(static_cast<unsigned char>(fmt[i])) || fmt[i] == '.')) ++i;
    int longs = 0;
    bool half = false;
    while (i < fmt.size() && std::strchr("hlLqjzt", fmt[i])) {
      if (fmt[i] == 'l') ++longs;
      if (fmt[i] == 'h') half = true;
      ++i;
    }
    if (i >= fmt.size()) break;
    char conv = fmt[i];
    std::string spec = fmt.substr(start, i - start);
    // Drop length modifiers; the host gets the value at full width.
    std::string flags;
    for (char ch : spec)
      if (!std::strchr("hlLqjzt", ch)) flags.push_back(ch);
    char buf[512];
    switch (conv) {
      case '%': out.push_back('%'); break;
      case 'd': case 'i': {
        long long v = longs >= 2 ? static_cast<long long>(va.next_int64())
                                 : static_cast<long long>(static_cast<std::int32_t>(va.next_int()));
        if (half) v = static_cast<std::int16_t>(v);
        std::snprintf(buf, sizeof buf, (flags + "lld").c_str(), v);
        out += buf;
        break;
      }
      case 'u': case 'x': case 'X': case 'o': {
        unsigned long long v = longs >= 2 ? va.next_int64() : va.next_int();
        if (half) v &= 0xFFFF;
        std::snprintf(buf, sizeof buf, (flags + "ll" + conv).c_str(), v);
        out += buf;
        break;
      }
      case 'c':
        std::snprintf(buf, sizeof buf, (flags + "c").c_str(), static_cast<int>(va.next_int() & 0xFF));
        out += buf;
        break;
      case 'p':
        std::snprintf(buf, sizeof buf, "0x%08x", va.next_int());
        out += buf;
        break;
      case 's': {
        std::string s = read_cstring(c, va.next_int());
        std::snprintf(buf, sizeof buf, (flags + "s").c_str(), s.c_str());
        out += buf;
        break;
      }
      case 'f': case 'F': case 'e': case 'E': case 'g': case 'G': case 'a': case 'A':
        std::snprintf(buf, sizeof buf, (flags + conv).c_str(), va.next_double());
        out += buf;
        break;
      case 'n': va.next_int(); break;
      default: out += spec + conv; break;
    }
  }
  return out;
}

const std::vector<HleEntry>& hle_table() {
  static const std::vector<HleEntry> t = {
      {"OSReport", &hle_os_report, "prints to the developer log instead of the debug console"},
      {"VMInit", &hle_vm_init, "maps 0x7E000000 as plain RAM (R10); no DSI paging"},
      {"VMAlloc", &hle_vm_alloc, "returns success: the region is plain RAM"},
      {"VMStoreAllPages", &hle_nothing, "no pages to write back"},
      {"VMSetLogStatsCallback", &hle_nothing, "no paging statistics"},
  };
  return t;
}

int hle_index(const std::string& name) {
  const auto& t = hle_table();
  for (std::size_t k = 0; k < t.size(); ++k)
    if (name == t[k].name) return static_cast<int>(k);
  return -1;
}

namespace {
std::vector<HleSite> g_sites;
}

void set_hle_sites(const HleSite* sites, std::size_t count) {
  g_sites.assign(sites, sites + count);
}

int hle_site(u32 address) {
  for (const auto& s : g_sites)
    if (s.address == address) return s.index;
  return -1;
}

bool hle_interpret(Cpu& c) {
  int k = hle_site(c.pc);
  if (k < 0) return false;
  hle_table()[static_cast<std::size_t>(k)].fn(c, nullptr);
  c.pc = c.lr & ~3u;
  return true;
}

void hle_call(Cpu& c, int index, GuestFn original) {
  hle_table()[static_cast<std::size_t>(index)].fn(c, original);
  c.pc = c.lr & ~3u;  // return as the guest blr would
}

}  // namespace mvp::rt
