/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> DiscardFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Hdlc::MultiFrameBuffer<(unsigned short)1024>::DiscardFrame() */

void __thiscall
ot::Hdlc::MultiFrameBuffer<(unsigned_short)1024>::DiscardFrame
          (MultiFrameBuffer<(unsigned_short)1024> *this)

{
  undefined4 uVar1;
  
  SetSkipLength(this,0);
  uVar1 = GetFrame(*(MultiFrameBuffer<(unsigned_short)1024> **)(this + 0x408));
  *(undefined4 *)this = uVar1;
  *(short *)(this + 4) = ((short)this + 0x406) - (short)uVar1;
  return;
}

