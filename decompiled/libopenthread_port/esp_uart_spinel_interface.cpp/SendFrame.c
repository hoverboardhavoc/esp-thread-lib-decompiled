/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  undefined4 uVar2;
  Encoder aEStack_430 [8];
  uchar *puStack_428;
  undefined2 uStack_424;
  uchar auStack_422 [1038];
  
  uStack_424 = 0x400;
  puStack_428 = auStack_422;
  ot::Hdlc::Encoder::Encoder(aEStack_430,(FrameWritePointer *)&puStack_428);
  iVar1 = ot::Hdlc::Encoder::BeginFrame();
  if ((((iVar1 != 0) ||
       (iVar1 = ot::Hdlc::Encoder::Encode((uchar *)aEStack_430,param_2), iVar1 != 0)) ||
      (iVar1 = ot::Hdlc::Encoder::EndFrame(), iVar1 != 0)) ||
     (iVar1 = Write((UartSpinelInterface *)param_1,auStack_422,
                    (short)puStack_428 - (short)auStack_422), iVar1 != 0)) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD");
  }
  return iVar1;
}

