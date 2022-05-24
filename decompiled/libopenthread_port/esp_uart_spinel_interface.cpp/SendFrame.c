/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
    esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD");
  }
  return iVar1;
}

