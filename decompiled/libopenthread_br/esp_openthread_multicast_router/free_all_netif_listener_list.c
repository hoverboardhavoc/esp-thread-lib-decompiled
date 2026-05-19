/*
 * Last changed at upstream commit 75a1adad77ac6a3a45ec0806c4f680520823fdba
 * https://github.com/espressif/esp-thread-lib/commit/75a1adad77ac6a3a45ec0806c4f680520823fdba
 * Upstream date: 2026-05-19 03:52:07 +0000
 * Upstream subject: feat(openthread): support s31 openthread br lib
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> free_all_netif_listener_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_all_netif_listener_list(void)

{
  undefined4 *__ptr;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 *puVar4;
  int iVar5;
  
  __ptr = s_netif_listener_lists;
  while (__ptr != (undefined4 *)0x0) {
    puVar4 = (undefined4 *)__ptr[2];
    iVar1 = __ptr[1];
    while (iVar1 != 0) {
      iVar5 = *(int *)(iVar1 + 0x18);
      iVar2 = leave_multicast_group_on_backbone_netif(*__ptr,iVar1);
      if (iVar2 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to leave multicast group\n",uVar3,"OPENTHREAD");
      }
      free_multicast_listener(iVar1);
      iVar1 = iVar5;
    }
    free(__ptr);
    __ptr = puVar4;
  }
  s_netif_listener_lists = (undefined4 *)0x0;
  return;
}

