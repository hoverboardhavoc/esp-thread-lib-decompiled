/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> FindSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::FindSession(ip6_addr const&, unsigned short, ip4_addr const&) */

IcmpSession * idf::IcmpSession::FindSession(ip6_addr *param_1,ushort param_2,ip4_addr *param_3)

{
  IcmpSession *this;
  int iVar1;
  
  this = s_icmp_session_list;
  while ((this != (IcmpSession *)0x0 && (iVar1 = Match(this,param_1,param_2,param_3), iVar1 == 0)))
  {
    this = *(IcmpSession **)(this + 0x24);
  }
  return this;
}

