/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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
    iVar1 = s_session_list;
  }
  s_session_list = iVar1;
  if (iVar3 != 0) {
    *(int *)(iVar3 + 0x2c) = iVar2;
  }
  return;
}

