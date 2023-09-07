/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
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

