/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> OnDestUdpReceived
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* idf::UdpSession::OnDestUdpReceived(pbuf*) */

void __thiscall idf::UdpSession::OnDestUdpReceived(UdpSession *this,pbuf *param_1)

{
  ushort uVar1;
  ushort uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  ip4_addr aiStack_34 [28];
  
  iVar6 = pbuf_alloc(0xe,*(short *)(param_1 + 8) + 0x30,0x280);
  iVar8 = _esp_log_timestamp;
  idf::nat64_translate_to_ip6_addr(aiStack_34);
  sys_untimeout(OnSessionTimeout,this);
  sys_timeout(3600000,OnSessionTimeout,this);
  if (iVar6 == 0) {
    uVar7 = esp_log_timestamp();
    esp_log(1,"NAT64","E (%lu) %s: %s(%d): Failed to forward nat64 packet: cannot allocate\n",uVar7,
            "OnDestUdpReceived",0x80);
  }
  else {
    if (*(byte *)(iVar8 + 8) < 2) {
      uVar7 = esp_log_timestamp();
      esp_log(1,"NAT64","E (%lu) %s: %s(%d): Drop nat64 packet: ttl\n",uVar7,"OnDestUdpReceived",
              0x82);
    }
    else {
      puVar3 = *(undefined4 **)(iVar6 + 4);
      uVar7 = lwip_htonl((*(byte *)(iVar8 + 1) | 0x600) << 0x14);
      *puVar3 = uVar7;
      uVar5 = lwip_htons(*(short *)(param_1 + 8) + 8);
      *(undefined2 *)(puVar3 + 1) = uVar5;
      *(undefined1 *)((int)puVar3 + 6) = *(undefined1 *)(iVar8 + 9);
      *(char *)((int)puVar3 + 7) = *(char *)(iVar8 + 8) + -1;
      memcpy(puVar3 + 2,aiStack_34,0x10);
      memcpy(puVar3 + 6,this,0x10);
      pbuf_remove_header(iVar6,0x28);
      uVar1 = *(ushort *)(param_1 + 8);
      *(ushort *)(puVar3 + 10) = *(ushort *)(this + 0x1c) >> 8 | *(ushort *)(this + 0x1c) << 8;
      uVar2 = *(ushort *)(this + 0x14);
      *(undefined2 *)((int)puVar3 + 0x2e) = 0;
      *(ushort *)((int)puVar3 + 0x2a) = uVar2 >> 8 | uVar2 << 8;
      *(ushort *)(puVar3 + 0xb) =
           (ushort)(byte)((uVar1 + 8) * 0x10000 >> 0x18) | (short)(uVar1 + 8) * 0x100;
      pbuf_copy_partial(param_1,puVar3 + 0xc,0);
      uVar5 = ip6_chksum_pseudo(iVar6,0x11,*(undefined2 *)(iVar6 + 8),aiStack_34,this);
      *(undefined2 *)((int)puVar3 + 0x2e) = uVar5;
      pbuf_add_header(iVar6,0x28);
      iVar8 = nat64_netif_get();
      pcVar4 = *(code **)(iVar8 + 0x1d8);
      uVar7 = nat64_netif_get();
      iVar8 = (*pcVar4)(iVar6,uVar7);
      if (iVar8 == 0) {
        return;
      }
    }
    pbuf_free(iVar6);
  }
  uVar7 = esp_log_timestamp();
  esp_log(1,"NAT64","E (%lu) %s: Failed to forward nat64 message\n",uVar7);
  return;
}

