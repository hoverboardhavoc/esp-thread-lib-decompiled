/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_recv_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_recv_task(int *param_1)

{
  ushort uVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  code *pcVar6;
  void *pvVar7;
  void *__ptr;
  undefined1 auStack_54 [4];
  undefined4 uStack_50;
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [16];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_24;
  
  auStack_54[0] = 0;
  uStack_50 = 1;
  piVar2 = (int *)param_1[1];
  pvVar7 = (void *)piVar2[1];
  uStack_2c = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  uStack_24 = *(undefined1 *)((int)param_1 + 0x22);
  uStack_2a = (undefined2)param_1[8];
  if ((char)param_1[7] == '\0') {
    param_1[5] = param_1[2];
    param_1[4] = -0x10000;
    param_1[3] = 0;
    param_1[2] = 0;
    *(undefined1 *)(param_1 + 6) = 0;
  }
  memcpy(auStack_3c,param_1 + 2,0x10);
  __ptr = (void *)*piVar2;
  if ((void *)*piVar2 != (void *)0x0) {
    uVar1 = *(ushort *)(piVar2 + 2);
    pvVar7 = malloc((uint)uVar1);
    __ptr = pvVar7;
    if (pvVar7 != (void *)0x0) {
      pbuf_copy_partial(piVar2,pvVar7,(uint)uVar1,0);
    }
  }
  if (pvVar7 == (void *)0x0) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar5,"OPENTHREAD");
  }
  else {
    esp_openthread_get_instance();
    iVar3 = otUdpNewMessage(auStack_54);
    if (iVar3 == 0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar5,"OPENTHREAD");
    }
    else {
      iVar4 = otMessageAppend(pvVar7,(short)piVar2[2]);
      if (iVar4 == 0) {
        pcVar6 = *(code **)(*param_1 + 0x24);
        (*pcVar6)(*(undefined4 *)(*param_1 + 0x28),iVar3,&uStack_4c,pcVar6);
        otMessageFree(iVar3);
      }
      else {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC4,uVar5,"OPENTHREAD");
      }
    }
  }
  free(param_1);
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  pbuf_free(piVar2);
  return;
}

