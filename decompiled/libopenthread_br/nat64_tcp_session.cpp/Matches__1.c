/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> Matches__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::Matches(ip4_addr const&, unsigned short) */

bool __thiscall idf::TcpSession::Matches(TcpSession *this,ip4_addr *param_1,ushort param_2)

{
  undefined2 in_register_00002032;
  
  if (*(int *)(this + 0x1c) == *(int *)param_1) {
    return (uint)*(ushort *)(this + 0x22) == CONCAT22(in_register_00002032,param_2);
  }
  return false;
}

