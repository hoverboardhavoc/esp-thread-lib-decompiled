/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> lwip_hook_ip6_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lwip_hook_ip6_input(int param_1,int param_2)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  int iVar5;
  char cStack_11;
  
  uVar2 = (uint)*(ushort *)(param_1 + 8);
  if ((*(ushort *)(param_1 + 10) == uVar2) && (0x27 < uVar2)) {
    iVar5 = *(int *)(param_1 + 4);
    if ((*(uint *)(iVar5 + 0x18) & 0xff) == 0xff) {
      if (((*(uint *)(iVar5 + 0x18) & 0x8fff) != 0x1ff) && (1 < *(byte *)(iVar5 + 7))) {
        esp_openthread_multicast_forward_packet();
      }
      iVar3 = esp_openthread_get_lwip_backbone_netif();
      if ((((iVar3 == param_2) &&
           (pcVar4 = (char *)skip_ipv6_header_and_extensions(iVar5,uVar2,&cStack_11),
           pcVar4 != (char *)0x0)) && (cStack_11 == ':')) &&
         (uVar2 = uVar2 - ((int)pcVar4 - iVar5) & 0xffff, 7 < uVar2)) {
        cVar1 = *pcVar4;
        if ((byte)(cVar1 + 0x7dU) < 2) {
          if (0x17 < uVar2) {
            handle_mld_input_part_0(iVar5,param_2);
          }
        }
        else if (cVar1 == -0x71) {
          handle_mldv2_input(iVar5,param_2);
        }
        else if ((0x1b < uVar2) && (cVar1 == -0x7e)) {
          send_mldv2_report_netif(param_2,pcVar4);
        }
      }
    }
  }
  return 0;
}

