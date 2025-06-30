/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  *(undefined4 *)(this + 0x18) = uVar1;
  *(ushort *)(this + 0x1c) = param_4;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  *(undefined4 *)(this + 0x2c) = 0;
  return;
}

