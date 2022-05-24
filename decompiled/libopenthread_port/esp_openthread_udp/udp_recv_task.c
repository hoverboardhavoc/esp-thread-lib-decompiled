/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_recv_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_recv_task(int *param_1)

{
  ushort uVar1;
  void *__ptr;
  undefined4 uVar2;
  int iVar3;
  undefined *puVar4;
  code *pcVar5;
  int iVar6;
  int *piVar7;
  void *pvVar8;
  undefined2 auStack_50 [2];
  undefined4 uStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  undefined4 uStack_40;
  undefined1 auStack_3c [16];
  undefined2 uStack_2c;
  undefined2 uStack_2a;
  undefined1 uStack_24;
  
  piVar7 = (int *)param_1[1];
  auStack_50[0] = 0x100;
  uStack_24 = *(undefined1 *)((int)param_1 + 0x22);
  pvVar8 = (void *)piVar7[1];
  uStack_2c = 0;
  uStack_2a = (undefined2)param_1[8];
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  if ((char)param_1[7] == '\0') {
    iVar6 = param_1[2];
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[5] = iVar6;
    param_1[4] = -0x10000;
    *(undefined1 *)(param_1 + 6) = 0;
  }
  memcpy(auStack_3c,param_1 + 2,0x10);
  if (*piVar7 == 0) {
    __ptr = (void *)0x0;
    if (pvVar8 != (void *)0x0) goto _L0;
  }
  else {
    uVar1 = *(ushort *)(piVar7 + 2);
    __ptr = malloc((uint)uVar1);
    if (__ptr != (void *)0x0) {
      pbuf_copy_partial(piVar7,__ptr,(uint)uVar1,0);
      pvVar8 = __ptr;
_L0:
      esp_openthread_get_instance();
      iVar6 = otUdpNewMessage(auStack_50);
      if (iVar6 == 0) {
        uVar2 = esp_log_timestamp();
        puVar4 = &_LC3;
      }
      else {
        iVar3 = otMessageAppend(pvVar8,(short)piVar7[2]);
        if (iVar3 == 0) {
          pcVar5 = *(code **)(*param_1 + 0x24);
          (*pcVar5)(*(undefined4 *)(*param_1 + 0x28),iVar6,&uStack_4c,pcVar5);
          otMessageFree(iVar6);
          goto _L0;
        }
        uVar2 = esp_log_timestamp();
        puVar4 = &_LC4;
      }
      esp_log_write(1,"OPENTHREAD",puVar4,uVar2,"OPENTHREAD");
      goto _L0;
    }
  }
  uVar2 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD");
  __ptr = (void *)0x0;
_L0:
  free(param_1);
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  pbuf_free(piVar7);
  return;
}

