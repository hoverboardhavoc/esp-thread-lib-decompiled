/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_listener_add
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_multicast_listener_add(uint *param_1,void *param_2,int param_3)

{
  void *pvVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  void *pvVar5;
  int iVar6;
  
  if ((*param_1 & 0xff) != 0xff) {
    return 0x102;
  }
  if (((*param_1 & 0x8fff) - 0x1ff & 0xfffffeff) != 0) {
    esp_openthread_get_backbone_netif();
    iVar2 = to_underlying_lwip_netif();
    if (param_3 != iVar2) {
      esp_netif_get_handle_from_ifkey("OT_DEF");
      iVar2 = to_underlying_lwip_netif();
      if (param_3 != iVar2) {
        return 0;
      }
    }
    uVar3 = esp_log_timestamp();
    uVar4 = ip6addr_ntoa(param_1);
    esp_log_write(3,"OPENTHREAD",&_LC9,uVar3,"OPENTHREAD",uVar4);
    iVar2 = find_or_create_netif_listener_list(param_3);
    if (iVar2 != 0) {
      for (pvVar1 = *(void **)(iVar2 + 4); pvVar1 != (void *)0x0;
          pvVar1 = *(void **)((int)pvVar1 + 0x18)) {
        iVar6 = memcmp(pvVar1,param_1,0x10);
        if (iVar6 == 0) {
          pvVar5 = *(void **)((int)pvVar1 + 0x14);
          while( true ) {
            if (pvVar5 == (void *)0x0) {
              pvVar5 = malloc(0x18);
              if (pvVar5 == (void *)0x0) {
                return 0x101;
              }
              memcpy(pvVar5,param_2,0x14);
              *(undefined4 *)((int)pvVar5 + 0x14) = *(undefined4 *)((int)pvVar1 + 0x14);
              *(void **)((int)pvVar1 + 0x14) = pvVar5;
              return 0;
            }
            iVar2 = memcmp(pvVar5,param_2,0x10);
            if (iVar2 == 0) break;
            pvVar5 = *(void **)((int)pvVar5 + 0x14);
          }
          return 0;
        }
      }
      pvVar1 = malloc(0x1c);
      if (pvVar1 != (void *)0x0) {
        memcpy(pvVar1,param_1,0x14);
        *(undefined4 *)((int)pvVar1 + 0x18) = 0;
        pvVar5 = malloc(0x18);
        if (pvVar5 != (void *)0x0) {
          memcpy(pvVar5,param_2,0x14);
          *(undefined4 *)((int)pvVar5 + 0x14) = 0;
          *(void **)((int)pvVar1 + 0x14) = pvVar5;
          iVar6 = esp_openthread_get_lwip_backbone_netif();
          if (param_3 != iVar6) {
            esp_openthread_get_lwip_backbone_netif();
            iVar6 = send_mldv2_joinleave_netif_constprop_0(param_1,1);
            if (iVar6 != 0) {
              free_multicast_listener(pvVar1);
              return 0xffffffff;
            }
          }
          *(undefined4 *)((int)pvVar1 + 0x18) = *(undefined4 *)(iVar2 + 4);
          *(void **)(iVar2 + 4) = pvVar1;
          return 0;
        }
        free(pvVar1);
      }
    }
    return 0x101;
  }
  return 0;
}

