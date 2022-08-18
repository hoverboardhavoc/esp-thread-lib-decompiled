/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> _IcmpSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::~IcmpSession() */

void __thiscall idf::IcmpSession::~IcmpSession(IcmpSession *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(this + 0x28);
  iVar3 = *(int *)(this + 0x24);
  iVar1 = iVar3;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x24) = iVar3;
    iVar1 = s_icmp_session_list;
  }
  s_icmp_session_list = iVar1;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x28) = iVar2;
  }
  return;
}

