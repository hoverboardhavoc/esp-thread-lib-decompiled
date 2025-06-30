/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_icmp_session.cpp.o -> IcmpSession
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::IcmpSession::IcmpSession(raw_pcb*, ip6_addr const&, unsigned short, ip4_addr const&,
   unsigned short) */

void __thiscall
idf::IcmpSession::IcmpSession
          (IcmpSession *this,raw_pcb *param_1,ip6_addr *param_2,ushort param_3,ip4_addr *param_4,
          ushort param_5)

{
  undefined4 uVar1;
  
  *(raw_pcb **)this = param_1;
  memcpy(this + 4,param_2,0x14);
  uVar1 = *(undefined4 *)param_4;
  *(ushort *)(this + 0x18) = param_3;
  *(undefined4 *)(this + 0x1c) = uVar1;
  *(ushort *)(this + 0x20) = param_5;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

