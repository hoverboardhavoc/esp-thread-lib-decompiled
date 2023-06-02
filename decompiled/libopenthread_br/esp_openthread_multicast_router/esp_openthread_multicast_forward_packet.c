/*
 * Last changed at upstream commit e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * https://github.com/espressif/esp-thread-lib/commit/e6fe125f50ac1bec267fce4cd8f27c0e2e431636
 * Upstream date: 2023-06-02 12:00:23 +0800
 * Upstream subject: ot br lib: fix issues in certification esp-openthread: a158ca1 openthread:091f68e
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
  uint uVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  char cVar8;
  int *piVar9;
  int iVar10;
  void *__s1;
  char cStack_61;
  uint auStack_60 [5];
  undefined1 uStack_4c;
  undefined1 auStack_48 [20];
  undefined1 uStack_34;
  
  cVar8 = s_multicast_forwarding_enabled;
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = *(ushort *)(param_1 + 8);
  fence();
  fence();
  if (s_multicast_forwarding_enabled != '\0') {
    if ((*(ushort *)(param_1 + 8) != *(ushort *)(param_1 + 10)) || (*(ushort *)(param_1 + 8) < 0x28)
       ) {
      uVar4 = esp_log_timestamp();
      esp_log_write(2,"OPENTHREAD",&_LC5,uVar4,"OPENTHREAD");
      return;
    }
    if ((((1 < *(byte *)(iVar2 + 7)) &&
         (iVar5 = skip_ipv6_header_and_extensions(iVar2,(uint)uVar1,&cStack_61),
         piVar9 = s_netif_listener_lists, iVar5 != 0)) && (cStack_61 != '\x06')) &&
       (((*(uint3 *)(iVar2 + 0x18) & 0xff) == 0xff &&
        (((*(uint *)(iVar2 + 0x18) & 0x8fff) - 0x1ff & 0xfffffeff) != 0)))) {
      esp_openthread_get_backbone_netif();
      iVar6 = to_underlying_lwip_netif();
      uStack_4c = 6;
      memcpy(auStack_60,(void *)(iVar2 + 0x18),0x14);
      uStack_34 = 6;
      memcpy(auStack_48,(void *)(iVar2 + 8),0x14);
      for (; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
        iVar10 = *piVar9;
        if (iVar10 != param_2) {
          for (__s1 = (void *)piVar9[1]; __s1 != (void *)0x0; __s1 = *(void **)((int)__s1 + 0x18)) {
            iVar7 = memcmp(__s1,auStack_60,0x10);
            if (iVar7 == 0) goto _L0;
          }
        }
      }
      cVar8 = '\0';
      iVar10 = iVar6;
_L0:
      if ((((auStack_60[0] & 0x8eff) == 0x4ff) || ((auStack_60[0] & 0x8fff) == 0xeff)) ||
         (cVar8 != '\0')) {
        uVar3 = (uint)uVar1 - (iVar5 - iVar2) & 0xffff;
        iVar7 = pbuf_alloc(0x36,uVar3,0x280);
        iVar6 = s_icmp_send_pcb;
        if (cStack_61 == '\x11') {
          iVar6 = s_udp_send_pcb;
        }
        *(char *)(iVar6 + 0x3b) = *(char *)(iVar2 + 7) + -1;
        if (iVar7 == 0) {
          uVar4 = esp_log_timestamp();
          esp_log_write(2,"OPENTHREAD",&_LC6,uVar4,"OPENTHREAD");
        }
        else {
          pbuf_take(iVar7,iVar5,uVar3);
          raw_bind_netif(iVar6,0);
          *(undefined2 *)(iVar6 + 0x44) = 0;
          *(undefined1 *)(iVar6 + 0x46) = 0;
          iVar2 = raw_sendto_if_src(iVar6,iVar7,auStack_60,iVar10,auStack_48);
          if (iVar2 != 0) {
            uVar4 = esp_log_timestamp();
            esp_log_write(2,"OPENTHREAD",&_LC7,uVar4,"OPENTHREAD");
          }
          pbuf_free(iVar7);
        }
      }
    }
  }
  return;
}

