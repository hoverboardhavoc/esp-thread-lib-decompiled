/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> Matches
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::Matches(ip6_addr const&, unsigned short, ip6_addr const&, unsigned short) */

bool __thiscall
idf::TcpSession::Matches
          (TcpSession *this,ip6_addr *param_1,ushort param_2,ip6_addr *param_3,ushort param_4)

{
  bool bVar1;
  int iVar2;
  undefined2 in_register_00002032;
  undefined2 in_register_0000203a;
  int iVar3;
  
  iVar2 = memcmp(this + 4,param_1,0x10);
  if (((iVar2 == 0) && ((uint)*(ushort *)(this + 0x18) == CONCAT22(in_register_00002032,param_2)))
     && (iVar3 = *(int *)(this + 0x1c), iVar2 = idf::nat64_get_embedded_ip4_addr(param_3),
        iVar3 == iVar2)) {
    bVar1 = (uint)*(ushort *)(this + 0x22) == CONCAT22(in_register_0000203a,param_4);
  }
  else {
    bVar1 = false;
  }
  return bVar1;
}

