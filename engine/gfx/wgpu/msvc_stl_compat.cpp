// Link shim for the prebuilt Dawn package (docs/engine/TOOLCHAIN.md, "Native:
// Dawn + SDL3"). Dawn's release was compiled with a newer MSVC STL, whose
// vectorized min_element/max_element entry points are split by signedness
// (`__std_min_element_4u`, ...). An older toolset's msvcprt.lib exports only the
// combined form (`__std_min_element_4(first, last, is_signed)`). These forward
// the split names to it. CMake compiles this file only when a configure-time
// probe finds that the toolset lacks the split names, so a newer toolset
// never sees duplicate definitions.
#include <cstddef>

extern "C" {
const void* __stdcall __std_min_element_4(const void* first, const void* last, bool is_signed) noexcept;
const void* __stdcall __std_min_element_8(const void* first, const void* last, bool is_signed) noexcept;
const void* __stdcall __std_max_element_4(const void* first, const void* last, bool is_signed) noexcept;
const void* __stdcall __std_max_element_8(const void* first, const void* last, bool is_signed) noexcept;

const void* __stdcall __std_min_element_4u(const void* first, const void* last) noexcept {
  return __std_min_element_4(first, last, false);
}
const void* __stdcall __std_min_element_4i(const void* first, const void* last) noexcept {
  return __std_min_element_4(first, last, true);
}
const void* __stdcall __std_min_element_8u(const void* first, const void* last) noexcept {
  return __std_min_element_8(first, last, false);
}
const void* __stdcall __std_min_element_8i(const void* first, const void* last) noexcept {
  return __std_min_element_8(first, last, true);
}
const void* __stdcall __std_max_element_4u(const void* first, const void* last) noexcept {
  return __std_max_element_4(first, last, false);
}
const void* __stdcall __std_max_element_4i(const void* first, const void* last) noexcept {
  return __std_max_element_4(first, last, true);
}
const void* __stdcall __std_max_element_8u(const void* first, const void* last) noexcept {
  return __std_max_element_8(first, last, false);
}
const void* __stdcall __std_max_element_8i(const void* first, const void* last) noexcept {
  return __std_max_element_8(first, last, true);
}
}
