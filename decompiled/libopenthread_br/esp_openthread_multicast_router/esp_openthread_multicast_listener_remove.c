/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_listener_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_multicast_listener_remove(uint *param_1,void *param_2,int param_3)

{
  void *pvVar1;
  void *__s1;
  void *__s1_00;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  
  if ((*param_1 & 0xff) != 0xff) {
    return 0x102;
  }
  if (((*param_1 & 0x8fff) - 0x1ff & 0xfffffeff) != 0) {
    uVar2 = esp_log_timestamp();
    uVar3 = ip6addr_ntoa(param_1);
    esp_log(3,"OPENTHREAD","I (%lu) %s: Multicast listener remove: %s\n\n",uVar2,uVar3);
    piVar5 = s_netif_listener_lists;
    while( true ) {
      if (piVar5 == (int *)0x0) {
        return 0x105;
      }
      if (param_3 == *piVar5) break;
      piVar5 = (int *)piVar5[2];
    }
    pvVar1 = (void *)piVar5[1];
    pvVar6 = (void *)0x0;
    while( true ) {
      __s1_00 = pvVar1;
      if (__s1_00 == (void *)0x0) {
        return 0x105;
      }
      iVar4 = memcmp(__s1_00,param_1,0x10);
      if (iVar4 == 0) break;
      pvVar1 = *(void **)((int)__s1_00 + 0x18);
      pvVar6 = __s1_00;
    }
    pvVar1 = *(void **)((int)__s1_00 + 0x14);
    if (*(int *)((int)pvVar1 + 0x14) == 0) {
      iVar4 = memcmp(pvVar1,param_2,0x10);
      __s1 = (void *)0x0;
      if (iVar4 == 0) {
        iVar4 = esp_openthread_get_lwip_backbone_netif();
        if (param_3 != iVar4) {
          esp_openthread_get_lwip_backbone_netif();
          iVar4 = send_mldv2_joinleave_netif(param_1,0);
          if (iVar4 != 0) {
            return iVar4;
          }
        }
        if (pvVar6 == (void *)0x0) {
          piVar5[1] = *(int *)((int)__s1_00 + 0x18);
        }
        else {
          *(int *)((int)pvVar6 + 0x18) = *(int *)((int)__s1_00 + 0x18);
        }
        free_multicast_listener(__s1_00);
        return 0;
      }
    }
    else {
      __s1 = (void *)0x0;
    }
    do {
      pvVar6 = __s1;
      __s1 = pvVar1;
      if (__s1 == (void *)0x0) {
        return 0x105;
      }
      iVar4 = memcmp(__s1,param_2,0x10);
      pvVar1 = *(void **)((int)__s1 + 0x14);
    } while (iVar4 != 0);
    if (pvVar6 == (void *)0x0) {
      *(void **)((int)__s1_00 + 0x14) = pvVar1;
    }
    else {
      *(void **)((int)pvVar6 + 0x14) = pvVar1;
    }
    free(__s1);
    return 0;
  }
  return 0;
}

