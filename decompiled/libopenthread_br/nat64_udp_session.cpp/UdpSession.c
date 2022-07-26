/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> UdpSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::UdpSession(ip6_addr const&, unsigned short, ip6_addr const&, unsigned short) */

void __thiscall
idf::UdpSession::UdpSession
          (UdpSession *this,ip6_addr *param_1,ushort param_2,ip6_addr *param_3,ushort param_4)

{
  undefined4 uVar1;
  
  memcpy(this,param_1,0x14);
  *(ushort *)(this + 0x14) = param_2;
  uVar1 = idf::nat64_get_embedded_ip4_addr(param_3);
  *(ushort *)(this + 0x1c) = param_4;
  *(undefined4 *)(this + 0x18) = uVar1;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

