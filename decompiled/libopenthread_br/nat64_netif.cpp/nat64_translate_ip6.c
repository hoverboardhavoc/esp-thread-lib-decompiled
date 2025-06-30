/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_translate_ip6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* nat64_translate_ip6(netif*, pbuf*, ip6_addr const*) */

undefined4 nat64_translate_ip6(netif *param_1,pbuf *param_2,ip6_addr *param_3)

{
  char cVar1;
  char cVar2;
  ushort uVar3;
  raw_pcb *prVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  char *pcVar8;
  undefined4 uVar9;
  uchar *puVar10;
  void *__ptr;
  uint uVar11;
  char cStack_51;
  undefined4 uStack_50;
  ip6_addr aiStack_4c [20];
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  uVar11 = (uint)*(ushort *)(param_2 + 8);
  nat64_get_prefix(auStack_38);
  if (uVar11 < 0x29) {
    uVar5 = esp_log_timestamp();
    esp_log(1,"NAT64","E (%lu) %s: %s(%d): Invalid nat64 packet\n",uVar5,"nat64_translate_ip6",0x69)
    ;
    return 0xfffffff4;
  }
  iVar6 = memcmp(param_3,auStack_38,(uint)(bStack_24 >> 3));
  if (iVar6 != 0) {
    return 0;
  }
  if (*(int *)param_2 == 0) {
    pvVar7 = *(void **)(param_2 + 4);
    __ptr = (void *)0x0;
  }
  else {
    uVar3 = *(ushort *)(param_2 + 8);
    pvVar7 = malloc((uint)uVar3);
    pbuf_copy_partial(param_2,pvVar7,(uint)uVar3,0);
    __ptr = pvVar7;
    if (pvVar7 == (void *)0x0) {
      uVar5 = esp_log_timestamp();
      esp_log(1,"NAT64","E (%lu) %s: %s(%d): Failed to copy nat64 packet\n",uVar5,
              "nat64_translate_ip6",0x73);
      return 0xffffffff;
    }
  }
  memcpy(aiStack_4c,(void *)((int)pvVar7 + 8),0x10);
  pcVar8 = (char *)skip_ipv6_header_and_extensions(pvVar7,uVar11,&cStack_51);
  prVar4 = s_backbone_icmp_raw_pcb;
  if (*(byte *)((int)pvVar7 + 7) < 2) goto _L49;
  uVar11 = uVar11 - ((int)pcVar8 - (int)pvVar7) & 0xffff;
  uVar3 = (ushort)pcVar8;
  if (cStack_51 == '\x11') {
    if (7 < uVar11) {
      puVar10 = (uchar *)idf::UdpSession::GetSession
                                   (aiStack_4c,CONCAT11(*pcVar8,pcVar8[1]),param_3,
                                    CONCAT11(pcVar8[2],pcVar8[3]));
      if (puVar10 != (uchar *)0x0) {
        idf::UdpSession::Send(puVar10,uVar3 + 8);
      }
      goto _L49;
    }
    uVar9 = esp_log_timestamp();
    uVar5 = 0x82;
    pcVar8 = "E (%lu) %s: %s(%d): Invalid nat64 UDP packet\n";
  }
  else if (cStack_51 == ':') {
    if (7 < uVar11) {
      if (*pcVar8 == -0x80) {
        cVar1 = pcVar8[5];
        cVar2 = pcVar8[4];
        uStack_50 = idf::nat64_get_embedded_ip4_addr(param_3);
        puVar10 = (uchar *)idf::IcmpSession::FindOrNewSession
                                     (prVar4,aiStack_4c,CONCAT11(cVar2,cVar1),(ip4_addr *)&uStack_50
                                     );
        if (puVar10 != (uchar *)0x0) {
          idf::IcmpSession::Forward2V4(puVar10,uVar3);
        }
      }
      goto _L49;
    }
    uVar9 = esp_log_timestamp();
    uVar5 = 0x8c;
    pcVar8 = "E (%lu) %s: %s(%d): Invalid nat64 ICMP packet\n";
  }
  else {
    if (cStack_51 != '\x06') {
      uVar5 = esp_log_timestamp();
      esp_log(2,"NAT64","W (%lu) %s: nat64 packet type not supported yet\n\n",uVar5);
      goto _L49;
    }
    if (0x13 < uVar11) {
      puVar10 = (uchar *)idf::TcpSession::FindOrNewSession
                                   (s_backbone_raw_pcb,aiStack_4c,CONCAT11(*pcVar8,pcVar8[1]),
                                    param_3,CONCAT11(pcVar8[2],pcVar8[3]));
      if (puVar10 != (uchar *)0x0) {
        idf::TcpSession::ForwardV6(puVar10,uVar3);
      }
      goto _L49;
    }
    uVar9 = esp_log_timestamp();
    uVar5 = 0x87;
    pcVar8 = "E (%lu) %s: %s(%d): Invalid nat64 TCP packet\n";
  }
  esp_log(1,"NAT64",pcVar8,uVar9,"nat64_translate_ip6",uVar5);
_L49:
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  return 0xfffffff4;
}

