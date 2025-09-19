/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> Forward2V6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::Forward2V6(unsigned char*, unsigned short) */

undefined4 __thiscall idf::IcmpSession::Forward2V6(IcmpSession *this,uchar *param_1,ushort param_2)

{
  undefined4 *puVar1;
  code *pcVar2;
  undefined2 uVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  undefined2 in_register_00002032;
  size_t __n;
  ip4_addr aiStack_34 [28];
  
  __n = CONCAT22(in_register_00002032,param_2);
  iVar4 = pbuf_alloc(0xe,__n + 0x28 & 0xffff,0x280);
  iVar6 = iVar4;
  if (param_1[0x14] == '\0') {
    puVar1 = *(undefined4 **)(iVar4 + 4);
    memcpy(puVar1 + 10,param_1 + 0x14,__n);
    uVar5 = lwip_htonl((param_1[1] | 0x600) << 0x14);
    *puVar1 = uVar5;
    uVar3 = lwip_htons(__n);
    *(undefined2 *)(puVar1 + 1) = uVar3;
    *(undefined1 *)((int)puVar1 + 6) = 0x3a;
    *(uchar *)((int)puVar1 + 7) = param_1[8] + 0xff;
    idf::nat64_translate_to_ip6_addr(aiStack_34);
    memcpy(puVar1 + 2,aiStack_34,0x10);
    memcpy(puVar1 + 6,this + 4,0x10);
    *(undefined1 *)(puVar1 + 10) = 0x81;
    *(ushort *)(puVar1 + 0xb) = *(ushort *)(this + 0x18) >> 8 | *(ushort *)(this + 0x18) << 8;
    uVar3 = *(undefined2 *)(param_1 + 0x1a);
    *(undefined2 *)((int)puVar1 + 0x2a) = 0;
    *(undefined2 *)((int)puVar1 + 0x2e) = uVar3;
    pbuf_remove_header(iVar4,0x28);
    uVar3 = ip6_chksum_pseudo(iVar4,0x3a,*(undefined2 *)(iVar4 + 8),aiStack_34,this + 4);
    *(undefined2 *)((int)puVar1 + 0x2a) = uVar3;
    pbuf_add_header(iVar4,0x28);
    iVar6 = nat64_netif_get();
    pcVar2 = *(code **)(iVar6 + 0x1d8);
    uVar5 = nat64_netif_get();
    iVar6 = (*pcVar2)(iVar4,uVar5);
  }
  if (iVar6 != 0) {
    pbuf_free(iVar4);
  }
  return 0;
}

