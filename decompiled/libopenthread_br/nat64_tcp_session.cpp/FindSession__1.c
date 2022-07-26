/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> FindSession__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::FindSession(ip4_addr const&, unsigned short) */

TcpSession * idf::TcpSession::FindSession(ip4_addr *param_1,ushort param_2)

{
  TcpSession *this;
  int iVar1;
  
  this = s_session_list;
  while ((this != (TcpSession *)0x0 && (iVar1 = Matches(this,param_1,param_2), iVar1 == 0))) {
    this = *(TcpSession **)(this + 0x28);
  }
  return this;
}

