/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> Match
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::Match(ip6_addr const&, unsigned short, ip4_addr const&) */

bool __thiscall
idf::IcmpSession::Match(IcmpSession *this,ip6_addr *param_1,ushort param_2,ip4_addr *param_3)

{
  bool bVar1;
  int iVar2;
  undefined2 in_register_00002032;
  
  iVar2 = memcmp(this + 4,param_1,0x10);
  if ((iVar2 == 0) && ((uint)*(ushort *)(this + 0x18) == CONCAT22(in_register_00002032,param_2))) {
    bVar1 = *(int *)param_3 == *(int *)(this + 0x1c);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

