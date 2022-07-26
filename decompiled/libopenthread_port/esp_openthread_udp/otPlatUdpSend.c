/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
  char cVar3;
  char cVar4;
  undefined4 uVar5;
  
  puVar2 = (undefined4 *)malloc(0x44);
  if (puVar2 == (undefined4 *)0x0) {
    uVar5 = 3;
  }
  else {
    uVar5 = *(undefined4 *)(param_1 + 0x2c);
    puVar2[1] = param_2;
    *puVar2 = uVar5;
    *(undefined2 *)(puVar2 + 8) = *(undefined2 *)(param_3 + 0x20);
    *(undefined2 *)(puVar2 + 0xf) = *(undefined2 *)(param_3 + 0x22);
    *(byte *)((int)puVar2 + 0x3e) = (byte)(*(uint *)(param_3 + 0x28) >> 0xc) & 1;
    cVar4 = *(char *)(param_3 + 0x28);
    if (cVar4 == '\0') {
      cVar4 = -1;
    }
    *(char *)((int)puVar2 + 0x3f) = cVar4;
    *(undefined1 *)(puVar2 + 0x10) = 0;
    map_openthread_addr_to_lwip_addr(puVar2 + 2,param_3);
    map_openthread_addr_to_lwip_addr(puVar2 + 9,param_3 + 0x10);
    if ((((*(char *)(puVar2 + 0xe) == '\0') && (*(char *)(puVar2 + 7) == '\x06')) &&
        (puVar2[2] == 0)) && (((puVar2[3] == 0 && (puVar2[4] == 0)) && (puVar2[5] == 0)))) {
      *(undefined1 *)(puVar2 + 7) = 0x2e;
    }
    cVar4 = *(char *)(param_3 + 0x10);
    if (cVar4 == -2) {
      cVar3 = *(char *)(param_3 + 0x11);
      cVar4 = -0x80;
    }
    else {
      cVar3 = -1;
    }
    if (cVar4 == cVar3) {
      uVar1 = get_netif_index(((*(byte *)(param_3 + 0x29) & 4) != 0) + '\x01');
      *(undefined1 *)(puVar2 + 0x10) = uVar1;
    }
    tcpip_callback(udp_send_task,puVar2);
    uVar5 = 0;
  }
  return uVar5;
}

