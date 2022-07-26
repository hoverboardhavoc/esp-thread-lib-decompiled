/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> FindOrNewSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::FindOrNewSession(raw_pcb*, ip6_addr const&, unsigned short, ip6_addr const&,
   unsigned short) */

TcpSession *
idf::TcpSession::FindOrNewSession
          (raw_pcb *param_1,ip6_addr *param_2,ushort param_3,ip6_addr *param_4,ushort param_5)

{
  TcpSession *this;
  int iVar1;
  
  this = (TcpSession *)FindSession(param_2,param_3,param_4,param_5);
  if (this == (TcpSession *)0x0) {
    iVar1 = FindNextLocalPort();
    if (iVar1 != 0) {
      this = (TcpSession *)operator_new(0x30);
      TcpSession(this,param_1,param_2,param_3,param_4,param_5,(ushort)iVar1);
      if (s_session_list != (TcpSession *)0x0) {
        *(TcpSession **)(s_session_list + 0x2c) = this;
      }
      *(TcpSession **)(this + 0x28) = s_session_list;
      s_session_list = this;
    }
  }
  return this;
}

