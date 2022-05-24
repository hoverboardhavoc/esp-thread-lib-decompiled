/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetSkipLength
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>::SetSkipLength(unsigned short) [clone .isra.0]
    */

void __thiscall
ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::SetSkipLength
          (MultiFrameBuffer<(unsigned_short)1024> *this,ushort param_1)

{
  undefined4 uVar1;
  undefined2 in_register_0000202e;
  
  if ((MultiFrameBuffer<(unsigned_short)1024> *)
      (CONCAT22(in_register_0000202e,param_1) + 4 + *(int *)(this + 0x408)) <= this + 0x406) {
    *(ushort *)(*(int *)(this + 0x408) + 2) = param_1;
    uVar1 = GetFrame(*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x408));
    *(undefined4 *)this = uVar1;
    *(short *)(this + 4) = (short)(this + 0x406) - (short)uVar1;
  }
  return;
}

