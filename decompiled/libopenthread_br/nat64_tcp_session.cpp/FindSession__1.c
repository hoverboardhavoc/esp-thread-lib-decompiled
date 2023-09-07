/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> FindSession__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::FindSession(ip4_addr const&, unsigned short, unsigned short) */

TcpSession * idf::TcpSession::FindSession(ip4_addr *param_1,ushort param_2,ushort param_3)

{
  TcpSession *this;
  int iVar1;
  
  this = s_session_list;
  while ((this != (TcpSession *)0x0 && (iVar1 = Matches(this,param_1,param_2,param_3), iVar1 == 0)))
  {
    this = *(TcpSession **)(this + 0x28);
  }
  return this;
}

