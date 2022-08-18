/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleNotification__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::HandleNotification(unsigned char const*, unsigned short) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
HandleNotification(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   *this,uchar *param_1,ushort param_2)

{
  undefined4 uVar1;
  int iVar2;
  undefined2 in_register_00002032;
  byte bStack_21;
  ulong uStack_20;
  undefined4 uStack_1c;
  uchar *puStack_18;
  int local_14 [2];
  
  uStack_1c = 0;
  puStack_18 = (uchar *)0x0;
  iVar2 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&::_L0,&bStack_21,local_14,
                     &uStack_20,&puStack_18,&uStack_1c);
  uVar1 = 6;
  if (((0 < iVar2) && ((bStack_21 & 0xf) == 0)) && (uVar1 = 0, local_14[0] == 6)) {
    HandleValueIs(this,uStack_20,puStack_18,(ushort)uStack_1c);
  }
  UpdateParseErrorCount(this,uVar1);
  LogIfFail("Error processing saved notification",uVar1);
  return;
}

