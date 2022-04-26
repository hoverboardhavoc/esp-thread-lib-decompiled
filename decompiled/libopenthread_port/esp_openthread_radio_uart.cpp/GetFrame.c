/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>::GetFrame() const [clone .isra.25] */

MultiFrameBuffer<(unsigned_short)1024> * __thiscall
ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
          (MultiFrameBuffer<(unsigned_short)1024> *this)

{
  return this + *(ushort *)(this + 2) + 4;
}

