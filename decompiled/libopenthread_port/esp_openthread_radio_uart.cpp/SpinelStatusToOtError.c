/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
    if (this == (Spinel *)0x2) {
      return (Spinel *)0xc;
    }
    if (this < (Spinel *)0x3) {
      if (this == (Spinel *)0x0) {
        return (Spinel *)0x0;
      }
      if (this == (Spinel *)0x1) {
        return (Spinel *)0x1;
      }
    }
    else {
      if (this == (Spinel *)0x4) {
        return (Spinel *)0xd;
      }
      if (this < (Spinel *)0x4) {
        return (Spinel *)&DAT_00000007;
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
      if (this < (Spinel *)0xd) {
        return (Spinel *)0x5;
      }
      if (this == (Spinel *)0xe) {
        return (Spinel *)0x2;
      }
    }
    else {
      if (this == (Spinel *)0x13) {
        return (Spinel *)0x18;
      }
      if (this < (Spinel *)0x13) {
        return (Spinel *)0xf;
      }
      if (this == (Spinel *)0x14) {
        return (Spinel *)0x17;
      }
    }
  }
  if (SpinelStatusToOtError < this + -0x4000) {
    return (Spinel *)0x1;
  }
  return this + -0x4000;
}

