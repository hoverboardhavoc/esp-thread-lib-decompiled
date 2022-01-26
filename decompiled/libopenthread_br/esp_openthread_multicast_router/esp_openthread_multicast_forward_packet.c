/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
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
  int iVar8;
  int *piVar9;
  void *__s1;
  char cStack_71;
  undefined1 auStack_70 [20];
  undefined1 uStack_5c;
  undefined1 auStack_58 [20];
  undefined1 uStack_44;
  
  iVar2 = *(int *)(param_1 + 4);
  uVar1 = *(ushort *)(param_1 + 8);
  fence();
  fence();
  if (s_multicast_forwarding_enabled != '\0') {
    if ((*(ushort *)(param_1 + 8) == *(ushort *)(param_1 + 10)) && (0x27 < *(ushort *)(param_1 + 8))
       ) {
      if ((((1 < *(byte *)(iVar2 + 7)) &&
           (iVar5 = skip_ipv6_header_and_extensions(iVar2,(uint)uVar1,&cStack_71),
           piVar9 = s_netif_listener_lists, iVar5 != 0)) && (cStack_71 != '\x06')) &&
         (((*(uint *)(iVar2 + 0x18) & 0xff) == 0xff &&
          (((*(uint *)(iVar2 + 0x18) & 0x8fff) - 0x1ff & 0xfffffeff) != 0)))) {
        uStack_5c = 6;
        memcpy(auStack_70,(void *)(iVar2 + 0x18),0x14);
        uStack_44 = 6;
        uVar3 = (uint)uVar1 - (iVar5 - iVar2) & 0xffff;
        memcpy(auStack_58,(void *)(iVar2 + 8),0x14);
        for (; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
          if (*piVar9 != param_2) {
            for (__s1 = (void *)piVar9[1]; __s1 != (void *)0x0; __s1 = *(void **)((int)__s1 + 0x18))
            {
              iVar6 = memcmp(__s1,auStack_70,0x10);
              if (iVar6 == 0) {
                iVar7 = pbuf_alloc(0x36,uVar3,0x280);
                iVar6 = s_icmp_send_pcb;
                if (cStack_71 == '\x11') {
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
                  *(undefined1 *)(iVar6 + 0x46) = 0;
                  iVar8 = *piVar9;
                  *(undefined2 *)(iVar6 + 0x44) = 0;
                  iVar6 = raw_sendto_if_src(iVar6,iVar7,auStack_70,iVar8,auStack_58);
                  if (iVar6 != 0) {
                    uVar4 = esp_log_timestamp();
                    esp_log_write(2,"OPENTHREAD",&_LC7,uVar4,"OPENTHREAD");
                  }
                  pbuf_free(iVar7);
                }
                break;
              }
            }
          }
        }
      }
    }
    else {
      uVar4 = esp_log_timestamp();
      esp_log_write(2,"OPENTHREAD",&_LC5,uVar4,"OPENTHREAD");
    }
  }
  return;
}

