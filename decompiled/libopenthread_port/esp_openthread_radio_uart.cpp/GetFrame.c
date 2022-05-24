/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>::GetFrame() const [clone .isra.0] */

MultiFrameBuffer<(unsigned_short)1024> * __thiscall
ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
          (MultiFrameBuffer<(unsigned_short)1024> *this)

{
  return this + *(ushort *)(this + 2) + 4;
}

