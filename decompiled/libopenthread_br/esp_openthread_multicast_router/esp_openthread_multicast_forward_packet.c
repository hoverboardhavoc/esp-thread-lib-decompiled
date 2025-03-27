/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> esp_openthread_multicast_forward_packet
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_multicast_forward_packet(int param_1,int param_2)

{
  ushort uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  int iVar7;
  uint uVar8;
  int *piVar9;
  void *__s1;
  char cStack_51;
  uint auStack_50 [5];
  undefined1 uStack_3c;
  undefined1 auStack_38 [20];
  undefined1 uStack_24;
  
  fence();
  fence();
  if (s_multicast_forwarding_enabled == '\0') {
    return;
  }
  esp_openthread_get_backbone_netif();
  iVar2 = to_underlying_lwip_netif();
  if (param_2 != iVar2) {
    esp_netif_get_handle_from_ifkey("OT_DEF");
    iVar2 = to_underlying_lwip_netif();
    if (param_2 != iVar2) {
      return;
    }
  }
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = *(ushort *)(param_1 + 8);
  iVar3 = skip_ipv6_header_and_extensions(iVar2,(uint)uVar1,&cStack_51);
  piVar9 = s_netif_listener_lists;
  if ((((iVar3 != 0) && (cStack_51 != '\x06')) && ((*(uint3 *)(iVar2 + 0x18) & 0xff) == 0xff)) &&
     (((*(uint *)(iVar2 + 0x18) & 0x8fff) - 0x1ff & 0xfffffeff) != 0)) {
    uStack_3c = 6;
    memcpy(auStack_50,(void *)(iVar2 + 0x18),0x14);
    uStack_24 = 6;
    memcpy(auStack_38,(void *)(iVar2 + 8),0x14);
    for (; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
      iVar4 = *piVar9;
      if (iVar4 != param_2) {
        for (__s1 = (void *)piVar9[1]; __s1 != (void *)0x0; __s1 = *(void **)((int)__s1 + 0x18)) {
          iVar5 = memcmp(__s1,auStack_50,0x10);
          if (iVar5 == 0) {
            if (iVar4 != 0) goto _L0;
            goto _L0;
          }
        }
      }
    }
_L0:
    esp_netif_get_handle_from_ifkey("OT_DEF");
    iVar4 = to_underlying_lwip_netif();
    if ((param_2 == iVar4) &&
       (((auStack_50[0] & 0x8eff) == 0x4ff || ((auStack_50[0] & 0x8fff) == 0xeff)))) {
      esp_openthread_get_backbone_netif();
      iVar4 = to_underlying_lwip_netif();
      if ((iVar4 != 0) && (param_2 != iVar4)) {
_L0:
        uVar8 = (uint)uVar1 - (iVar3 - iVar2) & 0xffff;
        iVar5 = pbuf_alloc(0x36,uVar8,0x280);
        if (iVar5 == 0) {
          uVar6 = esp_log_timestamp();
          esp_log(1,"OPENTHREAD",
                  "E (%lu) %s: %s(%d): Cannot allocate pbuf for multicast forwarding\n",uVar6,
                  "OPENTHREAD","esp_openthread_multicast_forward_packet",0x85);
        }
        else {
          iVar7 = s_icmp_send_pcb;
          if (cStack_51 == '\x11') {
            iVar7 = s_udp_send_pcb;
          }
          *(char *)(iVar7 + 0x3b) = *(char *)(iVar2 + 7) + -1;
          pbuf_take(iVar5,iVar3,uVar8);
          raw_bind_netif(iVar7,0);
          *(undefined2 *)(iVar7 + 0x44) = 0;
          *(undefined1 *)(iVar7 + 0x46) = 0;
          iVar2 = raw_sendto_if_src(iVar7,iVar5,auStack_50,iVar4,auStack_38);
          if (iVar2 != 0) {
            uVar6 = esp_log_timestamp();
            esp_log(2,"OPENTHREAD","W (%lu) %s: Failed to forward multicast packet\n",uVar6,
                    "OPENTHREAD");
          }
          pbuf_free(iVar5);
        }
      }
    }
  }
  return;
}

