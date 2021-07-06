/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpSend
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatUdpSend(int param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  puVar2 = (undefined4 *)malloc(0x28);
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 3;
  }
  else {
    *puVar2 = *(undefined4 *)(param_1 + 0x2c);
    puVar2[1] = param_2;
    *(undefined2 *)(puVar2 + 8) = *(undefined2 *)(param_3 + 0x22);
    *(byte *)((int)puVar2 + 0x22) = (byte)(*(uint *)(param_3 + 0x28) >> 10) & 1;
    *(undefined1 *)((int)puVar2 + 0x23) = *(undefined1 *)(param_3 + 0x28);
    *(undefined1 *)(puVar2 + 9) = 0;
    iVar5 = param_3 + 0x10;
    map_openthread_addr_to_lwip_addr(&local_40,iVar5);
    puVar2[2] = local_40;
    puVar2[3] = uStack_3c;
    puVar2[4] = uStack_38;
    puVar2[5] = uStack_34;
    puVar2[6] = uStack_30;
    puVar2[7] = uStack_2c;
    iVar3 = is_link_local(iVar5);
    if ((iVar3 != 0) || (iVar3 = is_multicast(iVar5), iVar3 != 0)) {
      if ((*(byte *)(param_3 + 0x29) & 1) == 0) {
        uVar4 = 1;
      }
      else {
        uVar4 = 2;
      }
      uVar1 = get_netif_index(uVar4);
      *(undefined1 *)(puVar2 + 9) = uVar1;
    }
    tcpip_callback(udp_send_task,puVar2);
    uVar4 = 0;
  }
  return uVar4;
}

