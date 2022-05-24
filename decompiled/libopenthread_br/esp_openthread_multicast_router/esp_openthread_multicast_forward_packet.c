/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
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
    if ((*(ushort *)(param_1 + 8) != *(ushort *)(param_1 + 10)) || (*(ushort *)(param_1 + 8) < 0x28)
       ) {
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"OPENTHREAD",&_L0,uVar3,"OPENTHREAD");
      return;
    }
    if ((((1 < *(byte *)(iVar2 + 7)) &&
         (iVar4 = skip_ipv6_header_and_extensions(iVar2,(uint)uVar1,&cStack_71),
         piVar9 = s_netif_listener_lists, iVar4 != 0)) && (cStack_71 != '\x06')) &&
       (((*(uint3 *)(iVar2 + 0x18) & 0xff) == 0xff &&
        (((*(uint *)(iVar2 + 0x18) & 0x8fff) - 0x1ff & 0xfffffeff) != 0)))) {
      uStack_5c = 6;
      memcpy(auStack_70,(void *)(iVar2 + 0x18),0x14);
      uStack_44 = 6;
      uVar8 = (uint)uVar1 - (iVar4 - iVar2) & 0xffff;
      memcpy(auStack_58,(void *)(iVar2 + 8),0x14);
      for (; piVar9 != (int *)0x0; piVar9 = (int *)piVar9[2]) {
        if (*piVar9 != param_2) {
          for (__s1 = (void *)piVar9[1]; __s1 != (void *)0x0; __s1 = *(void **)((int)__s1 + 0x18)) {
            iVar5 = memcmp(__s1,auStack_70,0x10);
            if (iVar5 == 0) {
              iVar6 = pbuf_alloc(0x36,uVar8,0x280);
              iVar5 = s_icmp_send_pcb;
              if (cStack_71 == '\x11') {
                iVar5 = s_udp_send_pcb;
              }
              *(char *)(iVar5 + 0x3b) = *(char *)(iVar2 + 7) + -1;
              if (iVar6 == 0) {
                uVar3 = esp_log_timestamp();
                esp_log_write(2,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD");
              }
              else {
                pbuf_take(iVar6,iVar4,uVar8);
                raw_bind_netif(iVar5,0);
                *(undefined1 *)(iVar5 + 0x46) = 0;
                iVar7 = *piVar9;
                *(undefined2 *)(iVar5 + 0x44) = 0;
                iVar5 = raw_sendto_if_src(iVar5,iVar6,auStack_70,iVar7,auStack_58);
                if (iVar5 != 0) {
                  uVar3 = esp_log_timestamp();
                  esp_log_write(2,"OPENTHREAD",&_LC7,uVar3,"OPENTHREAD");
                }
                pbuf_free(iVar6);
              }
              break;
            }
          }
        }
      }
    }
  }
  return;
}

