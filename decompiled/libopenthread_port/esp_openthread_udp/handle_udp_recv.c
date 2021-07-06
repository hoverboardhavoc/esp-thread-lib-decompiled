/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_udp.o -> handle_udp_recv
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void handle_udp_recv(undefined4 param_1,undefined4 param_2,undefined4 *param_3,undefined2 param_4)

{
  undefined1 uVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  undefined4 *__ptr;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  
  __ptr = (undefined4 *)malloc(0x24);
  iVar4 = _esp_openthread_task_queue_post;
  iVar3 = _esp_netif_get_netif_impl_index;
  iVar6 = _ip_data;
  if (__ptr == (undefined4 *)0x0) {
    otLogCrit(0xc,"-PLAT----: ","Failed to allocate recv task when receiving OpenThread plat UDP");
  }
  *__ptr = param_1;
  __ptr[1] = param_2;
  uVar7 = param_3[1];
  uVar8 = param_3[2];
  uVar9 = param_3[3];
  uVar10 = param_3[4];
  uVar11 = param_3[5];
  __ptr[2] = *param_3;
  __ptr[3] = uVar7;
  __ptr[4] = uVar8;
  __ptr[5] = uVar9;
  __ptr[6] = uVar10;
  __ptr[7] = uVar11;
  *(undefined2 *)(__ptr + 8) = param_4;
  if (*(char *)(param_3 + 5) == '\x06') {
    uVar1 = *(undefined1 *)(iVar4 + 7);
  }
  else {
    uVar1 = *(undefined1 *)(iVar3 + 8);
  }
  *(undefined1 *)((int)__ptr + 0x22) = uVar1;
  bVar2 = *(byte *)(iVar6 + 0x196);
  esp_openthread_get_backbone_netif();
  uVar5 = esp_netif_get_netif_impl_index();
  *(bool *)((int)__ptr + 0x23) = (bVar2 + 1 & 0xff) == uVar5;
  iVar6 = esp_openthread_task_queue_post(udp_recv_task,__ptr);
  if (iVar6 != 0) {
    free(__ptr);
  }
  return;
}

