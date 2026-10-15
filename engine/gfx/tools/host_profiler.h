// A sampling profiler of the host (E3c, development only): a thread suspends
// the emulation thread about every millisecond, reads its instruction pointer
// and resumes it; at the end the samples are grouped by host function through
// the PDB (DbgHelp) and the busiest are printed. It never touches guest state.
// Windows only; elsewhere it is a no-op.
#pragma once

#include <algorithm>
#include <cstdint>
#include <cstdio>
#include <map>
#include <string>
#include <utility>
#include <vector>

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>
#include <dbghelp.h>
#include <timeapi.h>

#include <atomic>
#include <thread>
#pragma comment(lib, "dbghelp.lib")
#pragma comment(lib, "winmm.lib")
#endif

namespace mvp::tools {

class HostProfiler {
 public:
#ifdef _WIN32
  // Samples the calling thread from now on (while *gate >= from).
  void start(const volatile std::uint64_t* gate = nullptr, std::uint64_t from = 0) {
    HANDLE self = GetCurrentThread();
    DuplicateHandle(GetCurrentProcess(), self, GetCurrentProcess(), &target_,
                    THREAD_SUSPEND_RESUME | THREAD_GET_CONTEXT | THREAD_QUERY_INFORMATION, FALSE, 0);
    timeBeginPeriod(1);
    thread_ = std::thread([this, gate, from] {
      while (!stop_.load(std::memory_order_relaxed)) {
        if (gate && *gate < from) {
          Sleep(1);
          continue;
        }
        if (SuspendThread(target_) != static_cast<DWORD>(-1)) {
          CONTEXT ctx{};
          ctx.ContextFlags = CONTEXT_CONTROL;
          if (GetThreadContext(target_, &ctx)) ++pcs_[ctx.Rip];
          ResumeThread(target_);
          ++samples_;
        }
        Sleep(1);
      }
    });
  }
  // Stops and prints the `top` host functions with the most samples.
  void finish(int top) {
    stop_ = true;
    if (thread_.joinable()) thread_.join();
    timeEndPeriod(1);
    HANDLE proc = GetCurrentProcess();
    SymSetOptions(SYMOPT_UNDNAME | SYMOPT_DEFERRED_LOADS);
    SymInitialize(proc, nullptr, TRUE);
    std::map<std::string, std::uint64_t> by_fn, by_module;
    alignas(SYMBOL_INFO) char buf[sizeof(SYMBOL_INFO) + 512];
    for (const auto& [pc, n] : pcs_) {
      auto* si = reinterpret_cast<SYMBOL_INFO*>(buf);
      si->SizeOfStruct = sizeof(SYMBOL_INFO);
      si->MaxNameLen = 511;
      DWORD64 disp = 0;
      std::string name;
      if (SymFromAddr(proc, pc, &disp, si)) name = si->Name;
      IMAGEHLP_MODULE64 mi{};
      mi.SizeOfStruct = sizeof mi;
      std::string mod = SymGetModuleInfo64(proc, pc, &mi) ? mi.ModuleName : "?";
      if (name.empty()) name = mod + "!?";
      // Translated guest functions (f_8XXXXXXX) count as one bucket.
      if (name.size() == 10 && name[0] == 'f' && name[1] == '_' && name[2] == '8') name = "[translated guest code]";
      by_fn[name] += n;
      by_module[mod] += n;
    }
    SymCleanup(proc);
    auto print = [&](const char* what, const std::map<std::string, std::uint64_t>& m, int k) {
      std::vector<std::pair<std::uint64_t, std::string>> v;
      for (const auto& [name, n] : m) v.push_back({n, name});
      std::sort(v.rbegin(), v.rend());
      std::printf("host profile (%s): %llu samples\n", what, static_cast<unsigned long long>(samples_));
      for (int i = 0; i < k && i < static_cast<int>(v.size()); ++i)
        std::printf("  %6.2f%%  %s\n", samples_ ? 100.0 * static_cast<double>(v[i].first) / static_cast<double>(samples_) : 0.0,
                    v[i].second.c_str());
    };
    print("modules", by_module, 12);
    print("functions", by_fn, top);
    CloseHandle(target_);
  }

 private:
  HANDLE target_ = nullptr;
  std::thread thread_;
  std::atomic<bool> stop_{false};
  std::map<std::uint64_t, std::uint64_t> pcs_;
  std::uint64_t samples_ = 0;
#else
  void start(const volatile std::uint64_t* = nullptr, std::uint64_t = 0) {}
  void finish(int) {}
#endif
};

}  // namespace mvp::tools
