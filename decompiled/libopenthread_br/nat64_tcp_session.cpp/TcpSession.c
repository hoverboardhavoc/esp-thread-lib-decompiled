/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> TcpSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::TcpSession(raw_pcb*, ip6_addr const&, unsigned short, ip6_addr const&, unsigned
   short, unsigned short) */

void __thiscall
idf::TcpSession::TcpSession
          (TcpSession *this,raw_pcb *param_1,ip6_addr *param_2,ushort param_3,ip6_addr *param_4,
          ushort param_5,ushort param_6)

{
  undefined4 uVar1;
  
  *(raw_pcb **)this = param_1;
  memcpy(this + 4,param_2,0x14);
  *(ushort *)(this + 0x18) = param_3;
  uVar1 = idf::nat64_get_embedded_ip4_addr(param_4);
  *(ushort *)(this + 0x20) = param_6;
  *(ushort *)(this + 0x22) = param_5;
  *(undefined4 *)(this + 0x1c) = uVar1;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

