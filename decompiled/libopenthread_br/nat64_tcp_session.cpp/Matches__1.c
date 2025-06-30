/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  bool bVar1;
  
  if (*(int *)(this + 0x1c) == *(int *)param_1) {
    bVar1 = false;
    if ((uint)*(ushort *)(this + 0x22) == CONCAT22(in_register_00002032,param_2)) {
      bVar1 = (uint)*(ushort *)(this + 0x20) == CONCAT22(in_register_00002036,param_3);
    }
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

