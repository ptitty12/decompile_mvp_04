// A minimal WebAssembly binary encoder for the wasm emitter (E2): LEB128,
// sections, and a function-body writer that tracks the structured-control
// nesting so branches can name their target by the level it was opened at.
// Only what the emitter uses (MVP opcodes, sign extension, tail calls).
#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace mvp::xlat::wasm {

using u8 = std::uint8_t;
using u32 = std::uint32_t;
using u64 = std::uint64_t;
using s32 = std::int32_t;
using s64 = std::int64_t;

inline constexpr u8 kI32 = 0x7F, kI64 = 0x7E, kFuncRef = 0x70, kVoid = 0x40;

namespace op {
inline constexpr u8 unreachable = 0x00, block = 0x02, loop = 0x03, if_ = 0x04, else_ = 0x05, end = 0x0B, br = 0x0C,
                    br_if = 0x0D, br_table = 0x0E, return_ = 0x0F, call = 0x10, return_call = 0x12, drop = 0x1A,
                    select = 0x1B, local_get = 0x20, local_set = 0x21, local_tee = 0x22, global_get = 0x23,
                    i32_load = 0x28, i64_load = 0x29, i32_load8_u = 0x2D, i32_load16_u = 0x2F, i32_store = 0x36,
                    i64_store = 0x37, i32_store8 = 0x3A, i32_store16 = 0x3B, i32_const = 0x41, i64_const = 0x42,
                    i32_eqz = 0x45, i32_eq = 0x46, i32_ne = 0x47, i32_lt_s = 0x48, i32_lt_u = 0x49, i32_gt_s = 0x4A,
                    i32_gt_u = 0x4B, i32_le_u = 0x4D, i64_ge_u = 0x5A, i32_clz = 0x67, i32_add = 0x6A, i32_sub = 0x6B,
                    i32_mul = 0x6C, i32_div_s = 0x6D, i32_div_u = 0x6E, i32_and = 0x71, i32_or = 0x72, i32_xor = 0x73,
                    i32_shl = 0x74, i32_shr_s = 0x75, i32_shr_u = 0x76, i32_rotl = 0x77, i32_rotr = 0x78,
                    i64_eqz = 0x50, i64_add = 0x7C, i64_mul = 0x7E, i64_and = 0x83, i64_or = 0x84, i64_xor = 0x85,
                    i64_shl = 0x86, i64_shr_u = 0x88, i32_wrap_i64 = 0xA7, i64_extend_i32_s = 0xAC,
                    i64_extend_i32_u = 0xAD, i32_extend8_s = 0xC0, i32_extend16_s = 0xC1;
}  // namespace op

struct Buf {
  std::vector<u8> b;

  void byte(u8 x) { b.push_back(x); }
  void uleb(u64 v) {
    do {
      u8 c = static_cast<u8>(v & 0x7F);
      v >>= 7;
      if (v) c |= 0x80;
      b.push_back(c);
    } while (v);
  }
  void sleb(s64 v) {
    for (;;) {
      u8 c = static_cast<u8>(v & 0x7F);
      v >>= 7;  // arithmetic (C++20)
      bool done = (v == 0 && !(c & 0x40)) || (v == -1 && (c & 0x40));
      if (!done) c |= 0x80;
      b.push_back(c);
      if (done) return;
    }
  }
  void name(const std::string& n) {
    uleb(n.size());
    b.insert(b.end(), n.begin(), n.end());
  }
  void append(const std::vector<u8>& o) { b.insert(b.end(), o.begin(), o.end()); }
  // A section: id, byte length, contents.
  void section(u8 id, const Buf& body) {
    byte(id);
    uleb(body.b.size());
    append(body.b);
  }
};

// A function body under construction. `depth` counts the open blocks, loops and
// ifs; opening one returns its level, and br(level) computes the relative depth.
struct Fn : Buf {
  int depth = 0;

  void op(u8 x) { byte(x); }
  int block() {
    byte(op::block);
    byte(kVoid);
    return depth++;
  }
  int loop() {
    byte(op::loop);
    byte(kVoid);
    return depth++;
  }
  int if_() {
    byte(op::if_);
    byte(kVoid);
    return depth++;
  }
  int if_i32() {
    byte(op::if_);
    byte(kI32);
    return depth++;
  }
  int if_i64() {
    byte(op::if_);
    byte(kI64);
    return depth++;
  }
  void else_() { byte(op::else_); }
  void end() {
    byte(op::end);
    --depth;
  }
  void br(int level) {
    byte(op::br);
    uleb(static_cast<u32>(depth - 1 - level));
  }
  void br_if(int level) {
    byte(op::br_if);
    uleb(static_cast<u32>(depth - 1 - level));
  }
  void br_table(const std::vector<int>& levels, int default_level) {
    byte(op::br_table);
    uleb(levels.size());
    for (int l : levels) uleb(static_cast<u32>(depth - 1 - l));
    uleb(static_cast<u32>(depth - 1 - default_level));
  }
  void get(u32 l) {
    byte(op::local_get);
    uleb(l);
  }
  void set(u32 l) {
    byte(op::local_set);
    uleb(l);
  }
  void tee(u32 l) {
    byte(op::local_tee);
    uleb(l);
  }
  void global(u32 g) {
    byte(op::global_get);
    uleb(g);
  }
  void i32c(s32 v) {
    byte(op::i32_const);
    sleb(v);
  }
  void i32c(u32 v) { i32c(static_cast<s32>(v)); }
  void i64c(s64 v) {
    byte(op::i64_const);
    sleb(v);
  }
  void mem(u8 opcode, u32 align_log2, u32 offset) {
    byte(opcode);
    uleb(align_log2);
    uleb(offset);
  }
  void call(u32 f) {
    byte(op::call);
    uleb(f);
  }
  void return_call(u32 f) {
    byte(op::return_call);
    uleb(f);
  }
};

}  // namespace mvp::xlat::wasm
