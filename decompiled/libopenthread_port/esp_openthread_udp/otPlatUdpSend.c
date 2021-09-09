/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpSend
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatUdpSend(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  undefined1 uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char cVar5;
  char cVar6;
  undefined1 auStack_30 [32];
  
  puVar3 = (undefined4 *)malloc(0x40);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 3;
  }
  else {
    *puVar3 = *(undefined4 *)(param_1 + 0x2c);
    uVar1 = *(undefined2 *)(param_3 + 0x22);
    puVar3[1] = param_2;
    *(undefined1 *)(puVar3 + 0xf) = 0;
    *(undefined2 *)(puVar3 + 0xe) = uVar1;
    *(byte *)((int)puVar3 + 0x3a) = (byte)(*(uint *)(param_3 + 0x28) >> 10) & 1;
    *(undefined1 *)((int)puVar3 + 0x3b) = *(undefined1 *)(param_3 + 0x28);
    map_openthread_addr_to_lwip_addr(auStack_30,param_3);
    memcpy(puVar3 + 2,auStack_30,0x18);
    map_openthread_addr_to_lwip_addr(auStack_30,param_3 + 0x10);
    memcpy(puVar3 + 8,auStack_30,0x18);
    if ((((*(char *)(puVar3 + 0xd) == '\0') && (*(char *)(puVar3 + 7) == '\x06')) &&
        (puVar3[2] == 0)) && (((puVar3[3] == 0 && (puVar3[4] == 0)) && (puVar3[5] == 0)))) {
      *(undefined1 *)(puVar3 + 7) = 0x2e;
    }
    cVar6 = *(char *)(param_3 + 0x10);
    if (cVar6 == -2) {
      cVar5 = *(char *)(param_3 + 0x11);
      cVar6 = -0x80;
    }
    else {
      cVar5 = -1;
    }
    if (cVar6 == cVar5) {
      uVar2 = get_netif_index((*(byte *)(param_3 + 0x29) & 1) + 1);
      *(undefined1 *)(puVar3 + 0xf) = uVar2;
    }
    tcpip_callback(udp_send_task,puVar3);
    uVar4 = 0;
  }
  return uVar4;
}

