/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
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
  
  Close(this);
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

