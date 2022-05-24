/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SpinelStatusToOtError
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::SpinelStatusToOtError(unsigned long) */

Spinel * __thiscall ot::Spinel::SpinelStatusToOtError(Spinel *this,ulong param_1)

{
  if (this == (Spinel *)0xb) {
    return (Spinel *)0x3;
  }
  if (this < (Spinel *)0xc) {
    if (this == (Spinel *)0x3) {
      return (Spinel *)0x7;
    }
    if (this < (Spinel *)0x4) {
      if (this == (Spinel *)0x1) {
        return (Spinel *)0x1;
      }
      if (this == (Spinel *)0x2) {
        return (Spinel *)0xc;
      }
      if (this == (Spinel *)0x0) {
        return (Spinel *)0x0;
      }
    }
    else {
      if (this == (Spinel *)0x4) {
        return (Spinel *)0xd;
      }
      if (this == (Spinel *)0x9) {
        return (Spinel *)0x6;
      }
    }
  }
  else {
    if (this == (Spinel *)0x11) {
      return (Spinel *)0xe;
    }
    if (this < (Spinel *)0x12) {
      if (this == (Spinel *)0xd) {
        return (Spinel *)0x17;
      }
      if (this == (Spinel *)0xe) {
        return (Spinel *)0x2;
      }
      if (this == (Spinel *)0xc) {
        return (Spinel *)0x5;
      }
    }
    else {
      if (this == (Spinel *)0x13) {
        return (Spinel *)0x18;
      }
      if (this == (Spinel *)0x14) {
        return (Spinel *)0x17;
      }
      if (this == (Spinel *)0x12) {
        return (Spinel *)0xf;
      }
    }
  }
  if (SpinelStatusToOtError < this + -0x4000) {
    return (Spinel *)0x1;
  }
  return this + -0x4000;
}

