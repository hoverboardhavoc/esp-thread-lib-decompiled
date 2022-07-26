/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  void *pvVar5;
  ushort *puVar6;
  undefined4 uVar7;
  uchar *puVar8;
  undefined *puVar9;
  void *__ptr;
  char cStack_4d;
  ip6_addr aiStack_4c [20];
  undefined1 auStack_38 [20];
  byte bStack_24;
  
  uVar2 = (uint)*(ushort *)(param_2 + 8);
  nat64_get_prefix(auStack_38);
  if (uVar2 < 0x29) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,"NAT64",&_LC4,uVar3,"NAT64","nat64_translate_ip6",0x4f);
    return 0xfffffff4;
  }
  iVar4 = memcmp(param_3,auStack_38,(uint)(bStack_24 >> 3));
  if (iVar4 != 0) {
    return 0;
  }
  if (*(int *)param_2 == 0) {
    pvVar5 = *(void **)(param_2 + 4);
    __ptr = (void *)0x0;
  }
  else {
    uVar1 = *(ushort *)(param_2 + 8);
    pvVar5 = malloc((uint)uVar1);
    pbuf_copy_partial(param_2,pvVar5,(uint)uVar1,0);
    __ptr = pvVar5;
    if (pvVar5 == (void *)0x0) {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,"NAT64",&_LC5,uVar3,"NAT64","nat64_translate_ip6",0x59);
      return 0xffffffff;
    }
  }
  memcpy(aiStack_4c,(void *)((int)pvVar5 + 8),0x10);
  puVar6 = (ushort *)skip_ipv6_header_and_extensions(pvVar5,uVar2,&cStack_4d);
  if (*(byte *)((int)pvVar5 + 7) < 2) goto _L0;
  uVar2 = uVar2 - ((int)puVar6 - (int)pvVar5) & 0xffff;
  if (cStack_4d == '\x06') {
    if (0x13 < uVar2) {
      puVar8 = (uchar *)idf::TcpSession::FindOrNewSession
                                  (s_backbone_raw_pcb,aiStack_4c,*puVar6 << 8 | *puVar6 >> 8,param_3
                                   ,puVar6[1] << 8 | puVar6[1] >> 8);
      if (puVar8 != (uchar *)0x0) {
        idf::TcpSession::ForwardV6(puVar8,(ushort)puVar6);
      }
      goto _L0;
    }
    uVar7 = esp_log_timestamp();
    uVar3 = 0x6c;
    puVar9 = &_LC7;
  }
  else {
    if (cStack_4d != '\x11') {
      uVar3 = esp_log_timestamp();
      esp_log_write(2,"NAT64",&_LC8,uVar3,"NAT64");
      goto _L0;
    }
    if (7 < uVar2) {
      puVar8 = (uchar *)idf::UdpSession::GetSession
                                  (aiStack_4c,*puVar6 << 8 | *puVar6 >> 8,param_3,
                                   puVar6[1] << 8 | puVar6[1] >> 8);
      if (puVar8 != (uchar *)0x0) {
        idf::UdpSession::Send(puVar8,(ushort)puVar6 + 8);
      }
      goto _L0;
    }
    uVar7 = esp_log_timestamp();
    uVar3 = 0x67;
    puVar9 = &_LC6;
  }
  esp_log_write(1,"NAT64",puVar9,uVar7,"NAT64","nat64_translate_ip6",uVar3);
_L0:
  if (__ptr != (void *)0x0) {
    free(__ptr);
  }
  return 0xfffffff4;
}

