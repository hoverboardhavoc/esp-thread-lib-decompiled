/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> Forward2V4
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::Forward2V4(unsigned char*, unsigned short) */

undefined4 __thiscall idf::IcmpSession::Forward2V4(IcmpSession *this,uchar *param_1,ushort param_2)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined2 in_register_00002032;
  int iVar5;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  iVar3 = pbuf_alloc(0x36,CONCAT22(in_register_00002032,param_2),0x280);
  pbuf_take(param_1,CONCAT22(in_register_00002032,param_2));
  puVar1 = *(undefined1 **)(iVar3 + 4);
  if (*param_1 == 0x80) {
    *puVar1 = 8;
  }
  *(ushort *)(puVar1 + 4) = *(ushort *)(this + 0x20) >> 8 | *(ushort *)(this + 0x20) << 8;
  uVar2 = *(undefined2 *)(param_1 + 6);
  *(undefined2 *)(puVar1 + 2) = 0;
  *(undefined2 *)(puVar1 + 6) = uVar2;
  uVar2 = inet_chksum_pbuf(iVar3);
  auStack_38[0] = *(undefined4 *)(this + 0x1c);
  *(undefined2 *)(puVar1 + 2) = uVar2;
  cStack_24 = '\0';
  esp_openthread_get_backbone_netif();
  iVar4 = to_underlying_lwip_netif();
  if (cStack_24 == '\x06') {
    iVar5 = 0;
    if (iVar4 != 0) {
      iVar5 = ip6_select_source_address(auStack_38,iVar4,0);
    }
  }
  else {
    iVar5 = 0;
    if (iVar4 != 0) {
      iVar5 = iVar4 + 4;
    }
  }
  raw_sendto_if_src(*(undefined4 *)this,iVar3,auStack_38,iVar4,iVar5);
  pbuf_free(iVar3);
  return 0;
}

