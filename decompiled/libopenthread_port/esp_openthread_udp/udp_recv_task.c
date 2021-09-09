/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  undefined4 uVar3;
  int iVar4;
  undefined *puVar5;
  code *pcVar6;
  int iVar7;
  void *pvVar8;
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
  
  uStack_50 = 1;
  piVar2 = (int *)param_1[1];
  uStack_24 = *(undefined1 *)((int)param_1 + 0x22);
  auStack_54[0] = 0;
  pvVar8 = (void *)piVar2[1];
  uStack_2a = (undefined2)param_1[8];
  uStack_2c = 0;
  uStack_4c = 0;
  uStack_48 = 0;
  uStack_44 = 0;
  uStack_40 = 0;
  if ((char)param_1[7] == '\0') {
    iVar7 = param_1[2];
    param_1[3] = 0;
    param_1[2] = 0;
    param_1[5] = iVar7;
    param_1[4] = -0x10000;
    *(undefined1 *)(param_1 + 6) = 0;
  }
  memcpy(auStack_3c,param_1 + 2,0x10);
  if (*piVar2 == 0) {
    __ptr = (void *)0x0;
    if (pvVar8 != (void *)0x0) goto _L0;
  }
  else {
    uVar1 = *(ushort *)(piVar2 + 2);
    pvVar8 = malloc((uint)uVar1);
    if (pvVar8 != (void *)0x0) {
      pbuf_copy_partial(piVar2,pvVar8,(uint)uVar1,0);
      __ptr = pvVar8;
_L0:
      esp_openthread_get_instance();
      iVar7 = otUdpNewMessage(auStack_54);
      if (iVar7 == 0) {
        uVar3 = esp_log_timestamp();
        puVar5 = &_LC3;
      }
      else {
        iVar4 = otMessageAppend(pvVar8,(short)piVar2[2]);
        if (iVar4 == 0) {
          pcVar6 = *(code **)(*param_1 + 0x24);
          (*pcVar6)(*(undefined4 *)(*param_1 + 0x28),iVar7,&uStack_4c,pcVar6);
          otMessageFree(iVar7);
          goto _L0;
        }
        uVar3 = esp_log_timestamp();
        puVar5 = &_LC4;
      }
      esp_log_write(1,"OPENTHREAD",puVar5,uVar3,"OPENTHREAD");
      goto _L0;
    }
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC2,uVar3,"OPENTHREAD");
  __ptr = (void *)0x0;
_L0:
  free(param_1);
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  pbuf_free(piVar2);
  return;
}

