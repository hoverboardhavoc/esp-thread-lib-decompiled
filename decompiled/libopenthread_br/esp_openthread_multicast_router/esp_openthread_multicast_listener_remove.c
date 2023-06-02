/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_listener_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_multicast_listener_remove(uint *param_1,void *param_2,int param_3)

{
  void *__s1;
  void *pvVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int *piVar5;
  void *pvVar6;
  int iVar7;
  void *pvVar8;
  
  if ((*param_1 & 0xff) != 0xff) {
    return 0x102;
  }
  if (((*param_1 & 0x8fff) - 0x1ff & 0xfffffeff) != 0) {
    uVar2 = esp_log_timestamp();
    uVar3 = ip6addr_ntoa(param_1);
    esp_log_write(3,"OPENTHREAD",&_L0,uVar2,"OPENTHREAD",uVar3);
    piVar5 = s_netif_listener_lists;
    while( true ) {
      if (piVar5 == (int *)0x0) {
        return 0x105;
      }
      if (param_3 == *piVar5) break;
      piVar5 = (int *)piVar5[2];
    }
    pvVar1 = (void *)piVar5[1];
    pvVar8 = (void *)0x0;
    while( true ) {
      __s1 = pvVar1;
      if (__s1 == (void *)0x0) {
        return 0x105;
      }
      iVar4 = memcmp(__s1,param_1,0x10);
      if (iVar4 == 0) break;
      pvVar1 = *(void **)((int)__s1 + 0x18);
      pvVar8 = __s1;
    }
    pvVar1 = *(void **)((int)__s1 + 0x14);
    iVar7 = *(int *)((int)pvVar1 + 0x14);
    iVar4 = memcmp(pvVar1,param_2,0x10);
    if (iVar7 == 0) {
      pvVar6 = (void *)0x0;
      if (iVar4 == 0) {
        iVar4 = esp_openthread_get_lwip_backbone_netif();
        if (param_3 != iVar4) {
          esp_openthread_get_lwip_backbone_netif();
          iVar4 = send_mldv2_joinleave_netif_constprop_0(param_1,0);
          if (iVar4 != 0) {
            return iVar4;
          }
        }
        if (pvVar8 == (void *)0x0) {
          piVar5[1] = *(int *)((int)__s1 + 0x18);
        }
        else {
          *(int *)((int)pvVar8 + 0x18) = *(int *)((int)__s1 + 0x18);
        }
        free_multicast_listener(__s1);
        return 0;
      }
    }
    else {
      pvVar6 = (void *)0x0;
    }
    do {
      pvVar8 = pvVar1;
      iVar4 = memcmp(pvVar8,param_2,0x10);
      pvVar1 = *(void **)((int)pvVar8 + 0x14);
      if (iVar4 == 0) {
        if (pvVar6 == (void *)0x0) {
          *(void **)((int)__s1 + 0x14) = pvVar1;
        }
        else {
          *(void **)((int)pvVar6 + 0x14) = pvVar1;
        }
        free(pvVar8);
        return 0;
      }
      pvVar6 = pvVar8;
    } while (pvVar1 != (void *)0x0);
    return 0x105;
  }
  return 0;
}

