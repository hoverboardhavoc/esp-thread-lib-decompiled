/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> Forward2V4
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::Forward2V4(unsigned char*, unsigned short) */

undefined4 __thiscall idf::IcmpSession::Forward2V4(IcmpSession *this,uchar *param_1,ushort param_2)

{
  uchar uVar1;
  uchar uVar2;
  undefined1 *puVar3;
  undefined2 uVar4;
  int iVar5;
  int iVar6;
  undefined2 in_register_00002032;
  int iVar7;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  iVar5 = pbuf_alloc(0x36,CONCAT22(in_register_00002032,param_2),0x280);
  pbuf_take(param_1,CONCAT22(in_register_00002032,param_2));
  puVar3 = *(undefined1 **)(iVar5 + 4);
  if (*param_1 == 0x80) {
    *puVar3 = 8;
  }
  uVar4 = *(undefined2 *)(this + 0x20);
  puVar3[4] = (char)((ushort)uVar4 >> 8);
  puVar3[5] = (char)uVar4;
  uVar1 = param_1[6];
  uVar2 = param_1[7];
  puVar3[2] = 0;
  puVar3[6] = uVar1;
  puVar3[7] = uVar2;
  puVar3[3] = 0;
  uVar4 = inet_chksum_pbuf(iVar5);
  puVar3[3] = (char)((ushort)uVar4 >> 8);
  auStack_38[0] = *(undefined4 *)(this + 0x1c);
  puVar3[2] = (char)uVar4;
  cStack_24 = '\0';
  esp_openthread_get_backbone_netif();
  iVar6 = to_underlying_lwip_netif();
  if (cStack_24 == '\x06') {
    iVar7 = 0;
    if (iVar6 != 0) {
      iVar7 = ip6_select_source_address(auStack_38,iVar6,0);
    }
  }
  else {
    iVar7 = 0;
    if (iVar6 != 0) {
      iVar7 = iVar6 + 4;
    }
  }
  raw_sendto_if_src(*(undefined4 *)this,iVar5,auStack_38,iVar6,iVar7);
  pbuf_free(iVar5);
  return 0;
}

