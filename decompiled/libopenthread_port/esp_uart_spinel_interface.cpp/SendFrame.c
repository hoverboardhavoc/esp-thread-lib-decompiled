/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> SendFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::SendFrame(unsigned char const*, unsigned short) */

int esp::openthread::UartSpinelInterface::SendFrame(uchar *param_1,ushort param_2)

{
  int iVar1;
  Encoder aEStack_430 [8];
  uchar *puStack_428;
  undefined2 uStack_424;
  uchar auStack_422 [1038];
  
  puStack_428 = auStack_422;
  uStack_424 = 0x400;
  ot::Hdlc::Encoder::Encoder(aEStack_430,(FrameWritePointer *)&puStack_428);
  iVar1 = ot::Hdlc::Encoder::BeginFrame();
  if (((iVar1 == 0) && (iVar1 = ot::Hdlc::Encoder::Encode((uchar *)aEStack_430,param_2), iVar1 == 0)
      ) && (iVar1 = ot::Hdlc::Encoder::EndFrame(), iVar1 == 0)) {
    iVar1 = Write((UartSpinelInterface *)param_1,auStack_422,(short)puStack_428 - (short)auStack_422
                 );
  }
  if (iVar1 != 0) {
    otLogCrit(0xc,"-PLAT----: ","send radio frame failed");
  }
  return iVar1;
}

