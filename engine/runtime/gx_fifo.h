// The GX command stream (E0b item 10): the bytes the game writes to the
// write-gather pipe, split into commands as the command processor would. E0b
// draws nothing; it only needs the commands that report back to the CPU (the
// pixel engine's draw-done and token writes, which raise PE interrupts) and the
// vertex formats, to know where each primitive's vertex data ends.
//
// Command lengths follow the public GX documentation (YAGCD; the Dolphin SDK's
// GX macros): NOP 1 byte, CP register load 6, XF load 5 + 4n, indexed XF load
// 5, display list call 9, vertex cache invalidate 1, BP load 5, primitives 3 +
// count x vertex size from the current VCD and VAT registers. A display list
// call runs the list's commands from memory (they can change the vertex formats).
#pragma once

#include <array>
#include <cstdint>
#include <vector>

namespace mvp::rt {

class GxFifo {
 public:
  // What a BP register load reports to the pixel engine.
  struct Effects {
    bool draw_done = false;  // BP 0x45 with bit 1: the finish interrupt
    bool token_int = false;  // BP 0x48: token and the token interrupt
    bool token_set = false;  // BP 0x47 or 0x48: the token register
    std::uint16_t token = 0;
  };

  // Appends bytes and parses every complete command; returns the PE effects of
  // the commands completed by these bytes.
  Effects push(const std::uint8_t* bytes, std::size_t n);

  // Memory that display list addresses (physical) point into.
  void set_memory(const std::uint8_t* mem, std::uint32_t size) {
    mem_ = mem;
    mem_size_ = size;
  }

  // Vertex size in bytes for vertex format `fmt` (0-7) from the current state.
  std::uint32_t vertex_size(int fmt) const;

  std::uint64_t commands() const { return commands_; }
  std::uint64_t bp_loads() const { return bp_loads_; }
  std::uint64_t primitives() const { return primitives_; }
  std::uint64_t vertices() const { return vertices_; }
  std::uint64_t display_lists() const { return display_lists_; }
  // Display lists that ended inside a command, held one that starts no command,
  // or lay outside memory (their remaining bytes are skipped).
  std::uint64_t display_list_errors() const { return display_list_errors_; }
  // A byte that starts no known command stops the parse for good (the stream
  // position is lost); its value and offset are kept for the report.
  bool broken() const { return broken_; }
  std::uint8_t broken_opcode() const { return broken_opcode_; }
  std::uint64_t broken_offset() const { return broken_offset_; }

 private:
  // Length of the command at p (n bytes available), 0 if more bytes are needed
  // to know it, or ~0 if p[0] starts no command.
  std::size_t command_length(const std::uint8_t* p, std::size_t n) const;
  void execute(const std::uint8_t* cmd, Effects& fx, bool in_list);
  void call_list(std::uint32_t addr, std::uint32_t size, Effects& fx);

  std::vector<std::uint8_t> pending_;
  std::uint64_t consumed_ = 0;
  std::uint32_t vcd_lo_ = 0, vcd_hi_ = 0;
  std::array<std::uint32_t, 8> vat_a_{}, vat_b_{}, vat_c_{};
  std::uint64_t commands_ = 0, bp_loads_ = 0, primitives_ = 0, vertices_ = 0, display_lists_ = 0;
  std::uint64_t display_list_errors_ = 0;
  const std::uint8_t* mem_ = nullptr;
  std::uint32_t mem_size_ = 0;
  bool broken_ = false;
  std::uint8_t broken_opcode_ = 0;
  std::uint64_t broken_offset_ = 0;
};

}  // namespace mvp::rt
