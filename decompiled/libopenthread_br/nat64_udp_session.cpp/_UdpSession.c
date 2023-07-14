/*
 * Last changed at upstream commit 785e946222f6c6ab453d7d47c15c551d4a181f79
 * https://github.com/espressif/esp-thread-lib/commit/785e946222f6c6ab453d7d47c15c551d4a181f79
 * Upstream date: 2023-07-14 09:44:51 +0800
 * Upstream subject: lib(openthread): update ot lib
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> _UdpSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::~UdpSession() */

void __thiscall idf::UdpSession::~UdpSession(UdpSession *this)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = *(int *)(this + 0x2c);
  iVar3 = *(int *)(this + 0x28);
  iVar1 = iVar3;
  if (iVar2 != 0) {
    *(int *)(iVar2 + 0x28) = iVar3;
    iVar1 = (anonymous_namespace)::s_session_list;
  }
  (anonymous_namespace)::s_session_list = iVar1;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x2c) = iVar2;
  }
  return;
}

