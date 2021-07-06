/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
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
  int iVar1;
  undefined4 uVar2;
  undefined2 in_register_00002032;
  byte bStack_21;
  int local_20;
  uchar *puStack_1c;
  undefined4 uStack_18;
  ulong auStack_14 [3];
  
  uStack_18 = 0;
  puStack_1c = (uchar *)0x0;
  iVar1 = spinel_datatype_unpack
                    (param_1,CONCAT22(in_register_00002032,param_2),&_LC58,&bStack_21,&local_20,
                     auStack_14,&puStack_1c,&uStack_18);
  if (iVar1 < 1) {
    iVar1 = 6;
  }
  else if ((bStack_21 & 0xf) == 0) {
    if (local_20 == 6) {
      HandleValueIs(this,auStack_14[0],puStack_1c,(ushort)uStack_18);
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 6;
  }
  if (iVar1 != 0) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing saved notification",uVar2);
  }
  return;
}

