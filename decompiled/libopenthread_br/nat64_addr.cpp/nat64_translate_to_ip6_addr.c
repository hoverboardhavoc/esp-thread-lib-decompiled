/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_addr.cpp.o -> nat64_translate_to_ip6_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::nat64_translate_to_ip6_addr(ip4_addr const&) */

idf * __thiscall idf::nat64_translate_to_ip6_addr(idf *this,ip4_addr *param_1)

{
  undefined1 auStack_28 [28];
  
  nat64_get_prefix(auStack_28);
  memcpy(this,auStack_28,0x14);
  *(undefined4 *)(this + 0xc) = *(undefined4 *)param_1;
  return this;
}

