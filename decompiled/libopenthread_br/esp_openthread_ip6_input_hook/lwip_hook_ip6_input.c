/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  int iVar4;
  char *pcVar5;
  char cStack_11;
  
  uVar2 = (uint)*(ushort *)(param_1 + 8);
  if ((*(ushort *)(param_1 + 10) == uVar2) && (0x27 < uVar2)) {
    iVar3 = *(int *)(param_1 + 4);
    if ((*(uint3 *)(iVar3 + 0x18) & 0xff) == 0xff) {
      if (((*(uint *)(iVar3 + 0x18) & 0x8fff) != 0x1ff) && (1 < *(byte *)(iVar3 + 7))) {
        esp_openthread_multicast_forward_packet();
      }
      iVar4 = esp_openthread_get_lwip_backbone_netif();
      if ((((iVar4 == param_2) &&
           (pcVar5 = (char *)skip_ipv6_header_and_extensions(iVar3,uVar2,&cStack_11),
           pcVar5 != (char *)0x0)) && (cStack_11 == ':')) &&
         (uVar2 = uVar2 - ((int)pcVar5 - iVar3) & 0xffff, 7 < uVar2)) {
        cVar1 = *pcVar5;
        if ((byte)(cVar1 + 0x7dU) < 2) {
          if (0x17 < uVar2) {
            handle_mld_input_part_0(iVar3,param_2);
          }
        }
        else if (cVar1 == -0x71) {
          handle_mldv2_input(iVar3,param_2);
        }
        else if ((0x1b < uVar2) && (cVar1 == -0x7e)) {
          send_mldv2_report_netif(param_2,pcVar5);
        }
      }
    }
  }
  return 0;
}

