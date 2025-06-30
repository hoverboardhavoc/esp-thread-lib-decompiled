/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> Matches
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::Matches(ip6_addr const&, unsigned short, ip6_addr const&, unsigned short) */

bool __thiscall
idf::UdpSession::Matches
          (UdpSession *this,ip6_addr *param_1,ushort param_2,ip6_addr *param_3,ushort param_4)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  undefined2 in_register_00002032;
  undefined2 in_register_0000203a;
  
  iVar2 = memcmp(this,param_1,0x10);
  if (((iVar2 == 0) && ((uint)*(ushort *)(this + 0x14) == CONCAT22(in_register_00002032,param_2)))
     && (iVar2 = *(int *)(this + 0x18), iVar3 = idf::nat64_get_embedded_ip4_addr(param_3),
        iVar2 == iVar3)) {
    bVar1 = (uint)*(ushort *)(this + 0x1c) == CONCAT22(in_register_0000203a,param_4);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

