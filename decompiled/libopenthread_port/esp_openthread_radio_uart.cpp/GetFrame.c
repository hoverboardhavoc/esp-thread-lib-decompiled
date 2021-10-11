/*
 * Last changed at upstream commit 06ac9b875d9791f909572a74898757410582e76c
 * https://github.com/espressif/esp-thread-lib/commit/06ac9b875d9791f909572a74898757410582e76c
 * Upstream date: 2021-10-11 18:13:07 +0800
 * Upstream subject: openthread: update openthread(eb1de3d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>::GetFrame() const [clone .isra.24] */

MultiFrameBuffer<(unsigned_short)1024> * __thiscall
ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::GetFrame
          (MultiFrameBuffer<(unsigned_short)1024> *this)

{
  return this + *(ushort *)(this + 2) + 4;
}

