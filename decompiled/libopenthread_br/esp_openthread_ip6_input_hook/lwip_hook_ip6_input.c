/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_br -> esp_openthread_ip6_input_hook.o -> lwip_hook_ip6_input
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lwip_hook_ip6_input(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  char *pcVar4;
  undefined4 uVar5;
  char acStack_21 [9];
  
  uVar2 = (uint)*(ushort *)(param_1 + 10);
  iVar1 = *(int *)(param_1 + 4);
  if (((uVar2 == *(ushort *)(param_1 + 8)) && (0x27 < uVar2)) && (*(char *)(iVar1 + 0x18) == -1)) {
    iVar3 = esp_openthread_get_lwip_backbone_netif();
    if (iVar3 == param_2) {
      pcVar4 = (char *)skip_ipv6_header_and_extensions(iVar1,uVar2,acStack_21);
      if (pcVar4 == (char *)0x0) {
        return 0;
      }
      if (acStack_21[0] != ':') {
        return 0;
      }
      uVar2 = uVar2 - ((int)pcVar4 - iVar1) & 0xffff;
      if (uVar2 < 8) {
        return 0;
      }
      if ((byte)(*pcVar4 + 0x7dU) < 2) {
        if (uVar2 < 0x18) {
          return 0;
        }
        handle_mld_input_part_0(iVar1,iVar3);
        return 0;
      }
      if (*pcVar4 == -0x71) {
        uVar5 = handle_mldv2_input(iVar1,pcVar4);
        return uVar5;
      }
    }
    if (((*(uint *)(iVar1 + 0x18) & 0x8fff) != 0x1ff) && (1 < *(byte *)(iVar1 + 7))) {
      esp_openthread_multicast_forward_packet(param_1,param_2);
    }
  }
  return 0;
}

