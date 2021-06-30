/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> otPlatUdpSend
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

otError otPlatUdpSend(otUdpSocket *udp_socket,otMessage *message,otMessageInfo *message_info)

{
  _Bool _Var1;
  uint8_t uVar2;
  undefined4 *puVar3;
  undefined3 extraout_var;
  undefined3 extraout_var_00;
  otNetifIdentifier netif_identifier;
  otError oVar4;
  otIp6Address *address;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  puVar3 = (undefined4 *)malloc(0x28);
  if (puVar3 == (undefined4 *)0x0) {
    oVar4 = OT_ERROR_NO_BUFS;
  }
  else {
    *puVar3 = udp_socket->mHandle;
    puVar3[1] = message;
    *(uint16_t *)(puVar3 + 8) = message_info->mPeerPort;
    *(byte *)((int)puVar3 + 0x22) = (byte)(*(uint *)&message_info->mHopLimit >> 10) & 1;
    *(uint8_t *)((int)puVar3 + 0x23) = message_info->mHopLimit;
    *(undefined1 *)(puVar3 + 9) = 0;
    address = &message_info->mPeerAddr;
    map_openthread_addr_to_lwip_addr(address);
    puVar3[2] = local_40;
    puVar3[3] = uStack_3c;
    puVar3[4] = uStack_38;
    puVar3[5] = uStack_34;
    puVar3[6] = uStack_30;
    puVar3[7] = uStack_2c;
    _Var1 = is_link_local(address);
    if ((CONCAT31(extraout_var,_Var1) != 0) ||
       (_Var1 = is_multicast(address), CONCAT31(extraout_var_00,_Var1) != 0)) {
      if ((message_info->field_0x29 & 1) == 0) {
        netif_identifier = OT_NETIF_THREAD;
      }
      else {
        netif_identifier = OT_NETIF_BACKBONE;
      }
      uVar2 = get_netif_index(netif_identifier);
      *(uint8_t *)(puVar3 + 9) = uVar2;
    }
    tcpip_callback(udp_send_task,puVar3);
    oVar4 = OT_ERROR_NONE;
  }
  return oVar4;
}

