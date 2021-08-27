/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
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
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC10,uVar2,"OPENTHREAD");
  }
  return iVar1;
}

