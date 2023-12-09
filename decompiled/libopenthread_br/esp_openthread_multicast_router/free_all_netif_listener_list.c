/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> free_all_netif_listener_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_all_netif_listener_list(void)

{
  int *__ptr;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  int *piVar4;
  int iVar5;
  int iVar6;
  
  __ptr = s_netif_listener_lists;
  while (__ptr != (int *)0x0) {
    piVar4 = (int *)__ptr[2];
    iVar1 = __ptr[1];
    while (iVar1 != 0) {
      iVar6 = *__ptr;
      iVar5 = *(int *)(iVar1 + 0x18);
      iVar2 = esp_openthread_get_lwip_backbone_netif();
      if (iVar6 != iVar2) {
        esp_openthread_get_lwip_backbone_netif();
        iVar2 = send_mldv2_joinleave_netif_isra_0(iVar1,0);
        if (iVar2 != 0) {
          uVar3 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC4,uVar3,"OPENTHREAD");
        }
      }
      free_multicast_listener(iVar1);
      iVar1 = iVar5;
    }
    free(__ptr);
    __ptr = piVar4;
  }
  s_netif_listener_lists = (int *)0x0;
  return;
}

