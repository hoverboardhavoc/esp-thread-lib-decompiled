/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
  undefined2 uVar3;
  undefined1 *puVar4;
  code *pcVar5;
  undefined2 uVar6;
  int iVar7;
  undefined4 uVar8;
  int iVar9;
  ip4_addr aiStack_34 [28];
  
  iVar7 = pbuf_alloc(0xe,*(short *)(param_1 + 8) + 0x30,0x280);
  iVar9 = _esp_log_timestamp;
  idf::nat64_translate_to_ip6_addr(aiStack_34);
  sys_untimeout(OnSessionTimeout,this);
  sys_timeout(3600000,OnSessionTimeout,this);
  if (iVar7 == 0) {
    uVar8 = esp_log_timestamp();
    esp_log(1,"NAT64","E (%lu) %s: %s(%d): Failed to forward nat64 packet: cannot allocate\n",uVar8,
            "NAT64","OnDestUdpReceived",0x80);
  }
  else {
    if (*(byte *)(iVar9 + 8) < 2) {
      uVar8 = esp_log_timestamp();
      esp_log(1,"NAT64","E (%lu) %s: %s(%d): Drop nat64 packet: ttl\n",uVar8,"NAT64",
              "OnDestUdpReceived",0x82);
    }
    else {
      puVar4 = *(undefined1 **)(iVar7 + 4);
      uVar8 = lwip_htonl((uint)*(byte *)(iVar9 + 1) << 0x14 | 0x60000000);
      *puVar4 = (char)uVar8;
      puVar4[1] = (char)((uint)uVar8 >> 8);
      puVar4[3] = (char)((uint)uVar8 >> 0x18);
      sVar1 = *(short *)(param_1 + 8);
      puVar4[2] = (char)((uint)uVar8 >> 0x10);
      uVar6 = lwip_htons(sVar1 + 8);
      puVar4[4] = (char)uVar6;
      puVar4[5] = (char)((ushort)uVar6 >> 8);
      puVar4[6] = *(undefined1 *)(iVar9 + 9);
      puVar4[7] = *(char *)(iVar9 + 8) + -1;
      memcpy(puVar4 + 8,aiStack_34,0x10);
      memcpy(puVar4 + 0x18,this,0x10);
      pbuf_remove_header(iVar7,0x28);
      uVar6 = *(undefined2 *)(this + 0x1c);
      uVar2 = *(ushort *)(param_1 + 8);
      puVar4[0x28] = (char)((ushort)uVar6 >> 8);
      uVar3 = *(undefined2 *)(this + 0x14);
      puVar4[0x29] = (char)uVar6;
      puVar4[0x2e] = 0;
      puVar4[0x2a] = (char)((ushort)uVar3 >> 8);
      puVar4[0x2b] = (char)uVar3;
      puVar4[0x2c] = (char)(uVar2 + 8 >> 8);
      puVar4[0x2d] = (char)((uVar2 + 8) * 0x100 >> 8);
      puVar4[0x2f] = 0;
      pbuf_copy_partial(param_1,puVar4 + 0x30,0);
      uVar6 = ip6_chksum_pseudo(iVar7,0x11,*(undefined2 *)(iVar7 + 8),aiStack_34,this);
      puVar4[0x2e] = (char)uVar6;
      puVar4[0x2f] = (char)((ushort)uVar6 >> 8);
      pbuf_add_header(iVar7,0x28);
      iVar9 = nat64_netif_get();
      pcVar5 = *(code **)(iVar9 + 0x1d8);
      uVar8 = nat64_netif_get();
      iVar9 = (*pcVar5)(iVar7,uVar8);
      if (iVar9 == 0) {
        return;
      }
    }
    pbuf_free(iVar7);
  }
  uVar8 = esp_log_timestamp();
  esp_log(1,"NAT64","E (%lu) %s: Failed to forward nat64 message\n",uVar8,"NAT64");
  return;
}

