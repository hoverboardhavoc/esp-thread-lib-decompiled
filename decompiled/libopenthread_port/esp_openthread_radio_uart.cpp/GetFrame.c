/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>::GetFrame() const [clone .isra.23] */

MultiFrameBuffer<(unsigned_short)1024> * __thiscall
ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
          (MultiFrameBuffer<(unsigned_short)1024> *this)

{
  return this + *(ushort *)(this + 2) + 4;
}

