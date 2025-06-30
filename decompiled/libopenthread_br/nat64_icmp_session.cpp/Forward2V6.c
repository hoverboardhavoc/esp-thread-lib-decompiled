/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> Forward2V6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::Forward2V6(unsigned char*, unsigned short) */

undefined4 __thiscall idf::IcmpSession::Forward2V6(IcmpSession *this,uchar *param_1,ushort param_2)

{
  uchar uVar1;
  uchar uVar2;
  undefined1 *puVar3;
  code *pcVar4;
  undefined2 uVar5;
  int iVar6;
  undefined4 uVar7;
  int iVar8;
  undefined2 in_register_00002032;
  size_t __n;
  ip4_addr aiStack_34 [28];
  
  __n = CONCAT22(in_register_00002032,param_2);
  iVar6 = pbuf_alloc(0xe,__n + 0x28 & 0xffff,0x280);
  iVar8 = iVar6;
  if (param_1[0x14] == '\0') {
    puVar3 = *(undefined1 **)(iVar6 + 4);
    memcpy(puVar3 + 0x28,param_1 + 0x14,__n);
    uVar7 = lwip_htonl((param_1[1] | 0x600) << 0x14);
    *puVar3 = (char)uVar7;
    puVar3[1] = (char)((uint)uVar7 >> 8);
    puVar3[2] = (char)((uint)uVar7 >> 0x10);
    puVar3[3] = (char)((uint)uVar7 >> 0x18);
    uVar5 = lwip_htons(__n);
    puVar3[4] = (char)uVar5;
    puVar3[5] = (char)((ushort)uVar5 >> 8);
    puVar3[6] = 0x3a;
    puVar3[7] = param_1[8] + 0xff;
    idf::nat64_translate_to_ip6_addr(aiStack_34);
    memcpy(puVar3 + 8,aiStack_34,0x10);
    memcpy(puVar3 + 0x18,this + 4,0x10);
    puVar3[0x28] = 0x81;
    uVar5 = *(undefined2 *)(this + 0x18);
    puVar3[0x2c] = (char)((ushort)uVar5 >> 8);
    puVar3[0x2d] = (char)uVar5;
    uVar1 = param_1[0x1b];
    uVar2 = param_1[0x1a];
    puVar3[0x2a] = 0;
    puVar3[0x2f] = uVar1;
    puVar3[0x2e] = uVar2;
    puVar3[0x2b] = 0;
    pbuf_remove_header(iVar6,0x28);
    uVar5 = ip6_chksum_pseudo(iVar6,0x3a,*(undefined2 *)(iVar6 + 8),aiStack_34,this + 4);
    puVar3[0x2a] = (char)uVar5;
    puVar3[0x2b] = (char)((ushort)uVar5 >> 8);
    pbuf_add_header(iVar6,0x28);
    iVar8 = nat64_netif_get();
    pcVar4 = *(code **)(iVar8 + 0x1d8);
    uVar7 = nat64_netif_get();
    iVar8 = (*pcVar4)(iVar6,uVar7);
  }
  if (iVar8 != 0) {
    pbuf_free(iVar6);
  }
  return 0;
}

