/*
 * Last changed at upstream commit 7d57b18006da6e182ddb87698abdced1566f3b56
 * https://github.com/espressif/esp-thread-lib/commit/7d57b18006da6e182ddb87698abdced1566f3b56
 * Upstream date: 2023-01-10 14:40:17 +0800
 * Upstream subject: openthread: add thread_br lib for esp32c2 and esp32c6 * esp_openthread: c558ac0 * ot-repo: 19e1875
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
  uint uVar4;
  undefined4 uVar5;
  int iVar6;
  void *pvVar7;
  ushort *puVar8;
  undefined4 uVar9;
  uchar *puVar10;
  undefined *puVar11;
  void *__ptr;
  char cStack_51;
  undefined4 uStack_50;
  ip6_addr aiStack_4c [20];
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  uVar4 = (uint)*(ushort *)(param_2 + 8);
  nat64_get_prefix(auStack_38);
  if (uVar4 < 0x29) {
    uVar5 = esp_log_timestamp();
    esp_log_write(1,"NAT64",&_LC6,uVar5,"NAT64","nat64_translate_ip6",0x66);
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
    uVar1 = *(ushort *)(param_2 + 8);
    pvVar7 = malloc((uint)uVar1);
    pbuf_copy_partial(param_2,pvVar7,(uint)uVar1,0);
    __ptr = pvVar7;
    if (pvVar7 == (void *)0x0) {
      uVar5 = esp_log_timestamp();
      esp_log_write(1,"NAT64",&_LC7,uVar5,"NAT64","nat64_translate_ip6",0x70);
      return 0xffffffff;
    }
  }
  memcpy(aiStack_4c,(void *)((int)pvVar7 + 8),0x10);
  puVar8 = (ushort *)skip_ipv6_header_and_extensions(pvVar7,uVar4,&cStack_51);
  prVar3 = s_backbone_icmp_raw_pcb;
  if (*(byte *)((int)pvVar7 + 7) < 2) goto _L0;
  uVar4 = uVar4 - ((int)puVar8 - (int)pvVar7) & 0xffff;
  uVar1 = (ushort)puVar8;
  if (cStack_51 == '\x11') {
    if (7 < uVar4) {
      puVar10 = (uchar *)idf::UdpSession::GetSession
                                   (aiStack_4c,*puVar8 << 8 | *puVar8 >> 8,param_3,
                                    puVar8[1] << 8 | puVar8[1] >> 8);
      if (puVar10 != (uchar *)0x0) {
        idf::UdpSession::Send(puVar10,uVar1 + 8);
      }
      goto _L0;
    }
    uVar9 = esp_log_timestamp();
    uVar5 = 0x7f;
    puVar11 = &_LC8;
  }
  else if (cStack_51 == ':') {
    if (7 < uVar4) {
      if ((char)*puVar8 == -0x80) {
        uVar2 = puVar8[2];
        uStack_50 = idf::nat64_get_embedded_ip4_addr(param_3);
        puVar10 = (uchar *)idf::IcmpSession::FindOrNewSession
                                     (prVar3,aiStack_4c,(ushort)((uVar2 & 0xff) << 8) | uVar2 >> 8,
                                      (ip4_addr *)&uStack_50);
        if (puVar10 != (uchar *)0x0) {
          idf::IcmpSession::Forward2V4(puVar10,uVar1);
        }
      }
      goto _L0;
    }
    uVar9 = esp_log_timestamp();
    uVar5 = 0x89;
    puVar11 = &_LC10;
  }
  else {
    if (cStack_51 != '\x06') {
      uVar5 = esp_log_timestamp();
      esp_log_write(2,"NAT64",&_LC11,uVar5,"NAT64");
      goto _L0;
    }
    if (0x13 < uVar4) {
      puVar10 = (uchar *)idf::TcpSession::FindOrNewSession
                                   (s_backbone_raw_pcb,aiStack_4c,*puVar8 << 8 | *puVar8 >> 8,
                                    param_3,puVar8[1] << 8 | puVar8[1] >> 8);
      if (puVar10 != (uchar *)0x0) {
        idf::TcpSession::ForwardV6(puVar10,uVar1);
      }
      goto _L0;
    }
    uVar9 = esp_log_timestamp();
    uVar5 = 0x84;
    puVar11 = &_LC9;
  }
  esp_log_write(1,"NAT64",puVar11,uVar9,"NAT64","nat64_translate_ip6",uVar5);
_L0:
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  return 0xfffffff4;
}

