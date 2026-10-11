/*
 * C:/mvp2004/source/common/animation/choosers/randomloadedchooser.cpp
 * (path string at 0x805DCE8C, passed by fn_8027985C to the RNG's file/line
 * arguments).
 *
 * .text 0x80279758-0x80279AE4, .rodata 0x805DCE7C-0x805DCEE8,
 * .data 0x8061E698-0x8061E69C.
 *
 * cRandomLoaded: vtable 0x80661F38 slot 3 (0x802ACB34) returns the pointer at
 * 0x8061E698 -> "cRandomLoaded". It embeds the weights-list helper from
 * randomchooser.cpp (ctor 0x8026FEB8, dtor 0x8026FF08); "a" and "weights"
 * (0x805DC538, 0x805DC53C) belong to that unit too.
 */
#include "game/chooser.h"
