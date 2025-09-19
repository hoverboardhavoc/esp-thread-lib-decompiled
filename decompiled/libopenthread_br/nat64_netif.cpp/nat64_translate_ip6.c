/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> nat64_netif.cpp.o -> nat64_translate_ip6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* nat64_translate_ip6(netif*, pbuf*, ip6_addr const*) */

undefined4 nat64_translate_ip6(netif *param_1,pbuf *param_2,ip6_addr *param_3)

{
  ushort uVar1;
  ushort uVar2;
  raw_pcb *prVar3;
  undefined4 uVar4;
  int iVar5;
  void *pvVar6;
  ushort *puVar7;
  undefined4 uVar8;
  uchar *puVar9;
  char *pcVar10;
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
    uVar4 = esp_log_timestamp();
    esp_log(1,"NAT64","E (%lu) %s: %s(%d): Invalid nat64 packet\n",uVar4,"nat64_translate_ip6",0x69)
    ;
    return 0xfffffff4;
  }
  iVar5 = memcmp(param_3,auStack_38,(uint)(bStack_24 >> 3));
  if (iVar5 != 0) {
    return 0;
  }
  if (*(int *)param_2 == 0) {
    pvVar6 = *(void **)(param_2 + 4);
    __ptr = (void *)0x0;
  }
  else {
    uVar1 = *(ushort *)(param_2 + 8);
    pvVar6 = malloc((uint)uVar1);
    pbuf_copy_partial(param_2,pvVar6,(uint)uVar1,0);
    __ptr = pvVar6;
    if (pvVar6 == (void *)0x0) {
      uVar4 = esp_log_timestamp();
      esp_log(1,"NAT64","E (%lu) %s: %s(%d): Failed to copy nat64 packet\n",uVar4,
              "nat64_translate_ip6",0x73);
      return 0xffffffff;
    }
  }
  memcpy(aiStack_4c,(void *)((int)pvVar6 + 8),0x10);
  puVar7 = (ushort *)skip_ipv6_header_and_extensions(pvVar6,uVar11,&cStack_51);
  prVar3 = s_backbone_icmp_raw_pcb;
  if (*(byte *)((int)pvVar6 + 7) < 2) goto _L49;
  uVar11 = uVar11 - ((int)puVar7 - (int)pvVar6) & 0xffff;
  uVar1 = (ushort)puVar7;
  if (cStack_51 == '\x11') {
    if (7 < uVar11) {
      puVar9 = (uchar *)idf::UdpSession::GetSession
                                  (aiStack_4c,*puVar7 >> 8 | (ushort)((*puVar7 & 0xff) << 8),param_3
                                   ,puVar7[1] >> 8 | (ushort)((puVar7[1] & 0xff) << 8));
      if (puVar9 != (uchar *)0x0) {
        idf::UdpSession::Send(puVar9,uVar1 + 8);
      }
      goto _L49;
    }
    uVar8 = esp_log_timestamp();
    uVar4 = 0x82;
    pcVar10 = "E (%lu) %s: %s(%d): Invalid nat64 UDP packet\n";
  }
  else if (cStack_51 == ':') {
    if (7 < uVar11) {
      if ((char)*puVar7 == -0x80) {
        uVar2 = puVar7[2];
        uStack_50 = idf::nat64_get_embedded_ip4_addr(param_3);
        puVar9 = (uchar *)idf::IcmpSession::FindOrNewSession
                                    (prVar3,aiStack_4c,(ushort)((uVar2 & 0xff) << 8) | uVar2 >> 8,
                                     (ip4_addr *)&uStack_50);
        if (puVar9 != (uchar *)0x0) {
          idf::IcmpSession::Forward2V4(puVar9,uVar1);
        }
      }
      goto _L49;
    }
    uVar8 = esp_log_timestamp();
    uVar4 = 0x8c;
    pcVar10 = "E (%lu) %s: %s(%d): Invalid nat64 ICMP packet\n";
  }
  else {
    if (cStack_51 != '\x06') {
      uVar4 = esp_log_timestamp();
      esp_log(2,"NAT64","W (%lu) %s: nat64 packet type not supported yet\n\n",uVar4);
      goto _L49;
    }
    if (0x13 < uVar11) {
      puVar9 = (uchar *)idf::TcpSession::FindOrNewSession
                                  (s_backbone_raw_pcb,aiStack_4c,
                                   *puVar7 >> 8 | (ushort)((*puVar7 & 0xff) << 8),param_3,
                                   (ushort)((puVar7[1] & 0xff) << 8) | puVar7[1] >> 8);
      if (puVar9 != (uchar *)0x0) {
        idf::TcpSession::ForwardV6(puVar9,uVar1);
      }
      goto _L49;
    }
    uVar8 = esp_log_timestamp();
    uVar4 = 0x87;
    pcVar10 = "E (%lu) %s: %s(%d): Invalid nat64 TCP packet\n";
  }
  esp_log(1,"NAT64",pcVar10,uVar8,"nat64_translate_ip6",uVar4);
_L49:
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  return 0xfffffff4;
}

