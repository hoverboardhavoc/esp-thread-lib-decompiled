/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  char cVar4;
  char cVar5;
  undefined4 uVar6;
  
  puVar3 = (undefined4 *)malloc(0x44);
  if (puVar3 == (undefined4 *)0x0) {
    uVar6 = 3;
  }
  else {
    uVar6 = *(undefined4 *)(param_1 + 0x2c);
    *(undefined1 *)(puVar3 + 0x10) = 0;
    *puVar3 = uVar6;
    uVar1 = *(undefined2 *)(param_3 + 0x20);
    puVar3[1] = param_2;
    *(undefined2 *)(puVar3 + 8) = uVar1;
    *(undefined2 *)(puVar3 + 0xf) = *(undefined2 *)(param_3 + 0x22);
    *(byte *)((int)puVar3 + 0x3e) = (byte)(*(uint *)(param_3 + 0x28) >> 0xc) & 1;
    *(undefined1 *)((int)puVar3 + 0x3f) = *(undefined1 *)(param_3 + 0x28);
    map_openthread_addr_to_lwip_addr(param_3);
    map_openthread_addr_to_lwip_addr(puVar3 + 9,param_3 + 0x10);
    if ((((*(char *)(puVar3 + 0xe) == '\0') && (*(char *)(puVar3 + 7) == '\x06')) &&
        (puVar3[2] == 0)) && (((puVar3[3] == 0 && (puVar3[4] == 0)) && (puVar3[5] == 0)))) {
      *(undefined1 *)(puVar3 + 7) = 0x2e;
    }
    cVar5 = *(char *)(param_3 + 0x10);
    if (cVar5 == -2) {
      cVar4 = *(char *)(param_3 + 0x11);
      cVar5 = -0x80;
    }
    else {
      cVar4 = -1;
    }
    if (cVar5 == cVar4) {
      uVar2 = get_netif_index(((*(byte *)(param_3 + 0x29) & 4) != 0) + '\x01');
      *(undefined1 *)(puVar3 + 0x10) = uVar2;
    }
    tcpip_callback(udp_send_task,puVar3);
    uVar6 = 0;
  }
  return uVar6;
}

