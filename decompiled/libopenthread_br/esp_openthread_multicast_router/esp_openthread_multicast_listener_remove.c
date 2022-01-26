/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_listener_remove
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_multicast_listener_remove(uint *param_1,void *param_2,int param_3)

{
  void *__s1;
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  int *piVar5;
  void *pvVar6;
  void *pvVar7;
  
  if ((*param_1 & 0xff) != 0xff) {
    return 0x102;
  }
  if (((*param_1 & 0x8fff) - 0x1ff & 0xfffffeff) != 0) {
    uVar1 = esp_log_timestamp();
    uVar2 = ip6addr_ntoa(param_1);
    esp_log_write(3,"OPENTHREAD",&_LC9,uVar1,"OPENTHREAD",uVar2);
    piVar5 = s_netif_listener_lists;
    while( true ) {
      if (piVar5 == (int *)0x0) {
        return 0x105;
      }
      if (param_3 == *piVar5) break;
      piVar5 = (int *)piVar5[2];
    }
    pvVar4 = (void *)piVar5[1];
    pvVar7 = (void *)0x0;
    while( true ) {
      __s1 = pvVar4;
      if (__s1 == (void *)0x0) {
        return 0x105;
      }
      iVar3 = memcmp(__s1,param_1,0x10);
      if (iVar3 == 0) break;
      pvVar4 = *(void **)((int)__s1 + 0x18);
      pvVar7 = __s1;
    }
    pvVar4 = *(void **)((int)__s1 + 0x14);
    if (*(int *)((int)pvVar4 + 0x14) == 0) {
      iVar3 = memcmp(pvVar4,param_2,0x10);
      pvVar6 = (void *)0x0;
      if (iVar3 == 0) {
        iVar3 = esp_openthread_get_lwip_backbone_netif();
        if (param_3 != iVar3) {
          esp_openthread_get_lwip_backbone_netif();
          iVar3 = send_mldv2_joinleave_netif_isra_5(param_1,0);
          if (iVar3 != 0) {
            return iVar3;
          }
        }
        if (pvVar7 == (void *)0x0) {
          piVar5[1] = *(int *)((int)__s1 + 0x18);
        }
        else {
          *(int *)((int)pvVar7 + 0x18) = *(int *)((int)__s1 + 0x18);
        }
        free_multicast_listener(__s1);
        return 0;
      }
    }
    else {
      pvVar6 = (void *)0x0;
    }
    do {
      pvVar7 = pvVar4;
      iVar3 = memcmp(pvVar7,param_2,0x10);
      pvVar4 = *(void **)((int)pvVar7 + 0x14);
      if (iVar3 == 0) {
        if (pvVar6 == (void *)0x0) {
          *(void **)((int)__s1 + 0x14) = pvVar4;
        }
        else {
          *(void **)((int)pvVar6 + 0x14) = pvVar4;
        }
        free(pvVar7);
        return 0;
      }
      pvVar6 = pvVar7;
    } while (pvVar4 != (void *)0x0);
    return 0x105;
  }
  return 0;
}

