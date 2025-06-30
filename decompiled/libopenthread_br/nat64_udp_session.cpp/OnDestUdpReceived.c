/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  short sVar1;
  ushort uVar2;
  undefined1 *puVar3;
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
      puVar3 = *(undefined1 **)(iVar6 + 4);
      uVar7 = lwip_htonl((*(byte *)(iVar8 + 1) | 0x600) << 0x14);
      *puVar3 = (char)uVar7;
      puVar3[1] = (char)((uint)uVar7 >> 8);
      puVar3[3] = (char)((uint)uVar7 >> 0x18);
      sVar1 = *(short *)(param_1 + 8);
      puVar3[2] = (char)((uint)uVar7 >> 0x10);
      uVar5 = lwip_htons(sVar1 + 8);
      puVar3[4] = (char)uVar5;
      puVar3[5] = (char)((ushort)uVar5 >> 8);
      puVar3[6] = *(undefined1 *)(iVar8 + 9);
      puVar3[7] = *(char *)(iVar8 + 8) + -1;
      memcpy(puVar3 + 8,aiStack_34,0x10);
      memcpy(puVar3 + 0x18,this,0x10);
      pbuf_remove_header(iVar6,0x28);
      uVar5 = *(undefined2 *)(this + 0x1c);
      uVar2 = *(ushort *)(param_1 + 8);
      puVar3[0x28] = (char)((ushort)uVar5 >> 8);
      puVar3[0x29] = (char)uVar5;
      uVar5 = *(undefined2 *)(this + 0x14);
      puVar3[0x2e] = 0;
      puVar3[0x2a] = (char)((ushort)uVar5 >> 8);
      puVar3[0x2b] = (char)uVar5;
      puVar3[0x2c] = (char)((uVar2 + 8) * 0x10000 >> 0x18);
      puVar3[0x2d] = (char)((uVar2 + 8) * 0x100 >> 8);
      puVar3[0x2f] = 0;
      pbuf_copy_partial(param_1,puVar3 + 0x30,0);
      uVar5 = ip6_chksum_pseudo(iVar6,0x11,*(undefined2 *)(iVar6 + 8),aiStack_34,this);
      puVar3[0x2e] = (char)uVar5;
      puVar3[0x2f] = (char)((ushort)uVar5 >> 8);
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

