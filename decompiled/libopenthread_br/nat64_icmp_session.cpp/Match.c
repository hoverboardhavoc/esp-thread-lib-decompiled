/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  if (iVar2 == 0) {
    bVar1 = false;
    if ((uint)*(ushort *)(this + 0x18) == CONCAT22(in_register_00002032,param_2)) {
      bVar1 = *(int *)param_3 == *(int *)(this + 0x1c);
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

