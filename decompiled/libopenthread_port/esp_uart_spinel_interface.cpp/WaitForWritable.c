/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> WaitForWritable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::WaitForWritable() */

undefined4 __thiscall
esp::openthread::UartSpinelInterface::WaitForWritable(UartSpinelInterface *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  int extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  uint *puVar6;
  uint uVar7;
  uint local_38 [2];
  uint local_30 [2];
  timeval atStack_28 [2];
  
  atStack_28[0].tv_sec = 2;
  atStack_28[0].tv_usec = 0;
  uVar2 = otPlatTimeGet();
  uVar1 = uVar2 + 2000000;
  uVar2 = (uint)(uVar1 < uVar2) + extraout_a1;
  do {
    puVar6 = local_30;
    for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (uint *)((int)puVar6 + 1);
    }
    puVar6 = local_38;
    for (uVar7 = 0; uVar7 < 8; uVar7 = uVar7 + 1) {
      *(undefined1 *)puVar6 = 0;
      puVar6 = (uint *)((int)puVar6 + 1);
    }
    uVar7 = *(uint *)(this + 0x4c);
    if (uVar7 < 0x40) {
      local_30[uVar7 >> 5] = local_30[uVar7 >> 5] | 1 << (uVar7 & 0x1f);
      local_38[uVar7 >> 5] = local_38[uVar7 >> 5] | 1 << (uVar7 & 0x1f);
    }
    iVar3 = select(uVar7 + 1,(fd_set *)0x0,(fd_set *)local_30,(fd_set *)local_38,atStack_28);
    if (iVar3 < 1) {
      if ((-1 < iVar3) || (piVar5 = (int *)__errno(), *piVar5 == 4)) goto _L0;
      iVar3 = TryRecoverUart(this);
      if (iVar3 == 0) {
        return 1;
      }
      uVar4 = _esp_error_check_failed
                        ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                         ,0x9d,"otError esp::openthread::UartSpinelInterface::WaitForWritable()",
                         "TryRecoverUart()");
      uVar7 = extraout_a1_01;
_L0:
      if ((uVar2 != uVar7) || (uVar1 <= uVar4)) {
        return 1;
      }
    }
    else {
      uVar7 = *(uint *)(this + 0x4c);
      if ((uVar7 < 0x40) && ((local_30[uVar7 >> 5] & 1 << (uVar7 & 0x1f)) != 0)) {
        return 0;
      }
      if ((uVar7 < 0x40) && ((1 << (uVar7 & 0x1f) & local_38[uVar7 >> 5]) != 0)) {
        return 1;
      }
_L0:
      uVar4 = otPlatTimeGet();
      uVar7 = extraout_a1_00;
      if (uVar2 <= extraout_a1_00) goto _L0;
    }
    uVar4 = uVar1 - uVar4;
    iVar3 = (uVar2 - uVar7) - (uint)(uVar1 < uVar4);
    atStack_28[0].tv_sec = __udivdi3(uVar4,iVar3,1000000,0);
    atStack_28[0].tv_usec = __umoddi3(uVar4,iVar3,1000000,0);
  } while( true );
}

