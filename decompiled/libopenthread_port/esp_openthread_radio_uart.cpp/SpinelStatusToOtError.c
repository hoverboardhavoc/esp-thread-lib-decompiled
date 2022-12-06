/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SpinelStatusToOtError
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::SpinelStatusToOtError(unsigned long) */

Spinel * __thiscall ot::Spinel::SpinelStatusToOtError(Spinel *this,ulong param_1)

{
  if (this == (Spinel *)0xc) {
    return (Spinel *)0x5;
  }
  if (this < (Spinel *)0xd) {
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
      if (this == (Spinel *)0x9) {
        return (Spinel *)0x6;
      }
      if (this == (Spinel *)0xb) {
        return (Spinel *)0x3;
      }
      if (this == (Spinel *)0x4) {
        return (Spinel *)0xd;
      }
    }
  }
  else {
    if (this == (Spinel *)0x12) {
      return (Spinel *)0xf;
    }
    if (this < (Spinel *)0x13) {
      if (this == (Spinel *)0xe) {
        return (Spinel *)0x2;
      }
      if (this == (Spinel *)0x11) {
        return (Spinel *)0xe;
      }
      if (this == (Spinel *)0xd) {
        return (Spinel *)0xc;
      }
    }
    else {
      if (this == (Spinel *)0x13) {
        return (Spinel *)0x18;
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

