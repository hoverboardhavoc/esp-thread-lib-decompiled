/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> Matches__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::Matches(ip4_addr const&, unsigned short, unsigned short) */

bool __thiscall
idf::TcpSession::Matches(TcpSession *this,ip4_addr *param_1,ushort param_2,ushort param_3)

{
  undefined2 in_register_00002032;
  undefined2 in_register_00002036;
  
  if ((*(int *)(this + 0x1c) == *(int *)param_1) &&
     ((uint)*(ushort *)(this + 0x22) == CONCAT22(in_register_00002032,param_2))) {
    return (uint)*(ushort *)(this + 0x20) == CONCAT22(in_register_00002036,param_3);
  }
  return false;
}

