/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  
  puVar3 = (undefined4 *)malloc(0x44);
  if (puVar3 == (undefined4 *)0x0) {
    uVar4 = 3;
  }
  else {
    *puVar3 = *(undefined4 *)(param_1 + 0x2c);
    uVar1 = *(undefined2 *)(param_3 + 0x20);
    puVar3[1] = param_2;
    *(undefined1 *)(puVar3 + 0x10) = 0;
    *(undefined2 *)(puVar3 + 8) = uVar1;
    *(undefined2 *)(puVar3 + 0xf) = *(undefined2 *)(param_3 + 0x22);
    *(byte *)((int)puVar3 + 0x3e) = (byte)(*(uint *)(param_3 + 0x28) >> 0xc) & 1;
    *(undefined1 *)((int)puVar3 + 0x3f) = *(undefined1 *)(param_3 + 0x28);
    map_openthread_addr_to_lwip_addr(auStack_30,param_3);
    memcpy(puVar3 + 2,auStack_30,0x18);
    map_openthread_addr_to_lwip_addr(auStack_30,param_3 + 0x10);
    memcpy(puVar3 + 9,auStack_30,0x18);
    if ((((*(char *)(puVar3 + 0xe) == '\0') && (*(char *)(puVar3 + 7) == '\x06')) &&
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
      uVar2 = get_netif_index(((*(byte *)(param_3 + 0x29) & 4) != 0) + '\x01');
      *(undefined1 *)(puVar3 + 0x10) = uVar2;
    }
    tcpip_callback(udp_send_task,puVar3);
    uVar4 = 0;
  }
  return uVar4;
}

