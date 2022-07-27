/*
 * Last changed at upstream commit 08bb0dcdce207ec830307c27ef1a1063631ff85c
 * https://github.com/espressif/esp-thread-lib/commit/08bb0dcdce207ec830307c27ef1a1063631ff85c
 * Upstream date: 2022-07-27 19:16:50 +0800
 * Upstream subject: br: fix UDP multicast forwarding
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> lwip_hook_ip6_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lwip_hook_ip6_input(int param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char acStack_21 [13];
  
  uVar1 = (uint)*(ushort *)(param_1 + 8);
  iVar2 = *(int *)(param_1 + 4);
  if (((*(ushort *)(param_1 + 10) == uVar1) && (0x27 < uVar1)) &&
     ((*(uint3 *)(iVar2 + 0x18) & 0xff) == 0xff)) {
    if (((*(uint *)(iVar2 + 0x18) & 0x8fff) != 0x1ff) && (1 < *(byte *)(iVar2 + 7))) {
      esp_openthread_multicast_forward_packet();
    }
    iVar3 = esp_openthread_get_lwip_backbone_netif();
    if (param_2 == iVar3) {
      pcVar4 = (char *)skip_ipv6_header_and_extensions(iVar2,uVar1,acStack_21);
      if (pcVar4 == (char *)0x0) {
        return 0;
      }
      if (acStack_21[0] != ':') {
        return 0;
      }
      uVar1 = uVar1 - ((int)pcVar4 - iVar2) & 0xffff;
      if (uVar1 < 8) {
        return 0;
      }
      if ((byte)(*pcVar4 + 0x7dU) < 2) {
        if (uVar1 < 0x18) {
          return 0;
        }
        handle_mld_input_part_0(iVar2,param_2);
        return 0;
      }
      if (*pcVar4 != -0x71) {
        return 0;
      }
      uVar5 = handle_mldv2_input(iVar2,pcVar4,param_2);
      return uVar5;
    }
  }
  return 0;
}

