/*
 * Last changed at upstream commit b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * https://github.com/espressif/esp-thread-lib/commit/b50de92c3b8b2adb5528b46d24a37f9fadb65708
 * Upstream date: 2022-08-18 14:47:55 +0800
 * Upstream subject: br: support nat64 icmp
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
  *(ushort *)(this + 0x20) = param_5;
  *(undefined4 *)(this + 0x1c) = uVar1;
  *(undefined4 *)(this + 0x24) = 0;
  *(undefined4 *)(this + 0x28) = 0;
  return;
}

