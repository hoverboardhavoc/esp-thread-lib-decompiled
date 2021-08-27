/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
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
  bool bVar5;
  int iVar6;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  uint uStack_2c;
  
  puVar2 = (undefined4 *)malloc(0x40);
  if (puVar2 == (undefined4 *)0x0) {
    uVar4 = 3;
  }
  else {
    *puVar2 = *(undefined4 *)(param_1 + 0x2c);
    puVar2[1] = param_2;
    *(undefined2 *)(puVar2 + 0xe) = *(undefined2 *)(param_3 + 0x22);
    *(byte *)((int)puVar2 + 0x3a) = (byte)(*(uint *)(param_3 + 0x28) >> 10) & 1;
    *(undefined1 *)((int)puVar2 + 0x3b) = *(undefined1 *)(param_3 + 0x28);
    *(undefined1 *)(puVar2 + 0xf) = 0;
    map_openthread_addr_to_lwip_addr(&local_40,param_3);
    puVar2[2] = local_40;
    puVar2[3] = uStack_3c;
    puVar2[4] = uStack_38;
    puVar2[5] = uStack_34;
    puVar2[6] = uStack_30;
    puVar2[7] = uStack_2c;
    iVar6 = param_3 + 0x10;
    map_openthread_addr_to_lwip_addr(&local_40,iVar6);
    puVar2[8] = local_40;
    puVar2[9] = uStack_3c;
    puVar2[10] = uStack_38;
    puVar2[0xb] = uStack_34;
    puVar2[0xc] = uStack_30;
    puVar2[0xd] = uStack_2c;
    if ((uStack_2c & 0xff) == 0) {
      if (*(char *)(puVar2 + 7) == '\x06') {
        if (puVar2[2] == 0) {
          if (puVar2[3] == 0) {
            if (puVar2[4] == 0) {
              if (puVar2[5] == 0) {
                bVar5 = true;
              }
              else {
                bVar5 = false;
              }
            }
            else {
              bVar5 = false;
            }
          }
          else {
            bVar5 = false;
          }
        }
        else {
          bVar5 = false;
        }
      }
      else {
        bVar5 = false;
      }
      if (bVar5) {
        *(undefined1 *)(puVar2 + 7) = 0x2e;
      }
    }
    iVar3 = is_link_local(iVar6);
    if ((iVar3 != 0) || (iVar6 = is_multicast(iVar6), iVar6 != 0)) {
      if ((*(byte *)(param_3 + 0x29) & 1) == 0) {
        uVar4 = 1;
      }
      else {
        uVar4 = 2;
      }
      uVar1 = get_netif_index(uVar4);
      *(undefined1 *)(puVar2 + 0xf) = uVar1;
    }
    tcpip_callback(udp_send_task,puVar2);
    uVar4 = 0;
  }
  return uVar4;
}

