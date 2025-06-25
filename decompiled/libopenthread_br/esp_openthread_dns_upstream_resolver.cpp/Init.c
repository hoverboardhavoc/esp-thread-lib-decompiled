/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::Init() */

undefined4 __thiscall Resolver::Init(Resolver *this)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = esp_openthread_get_alloc_caps();
  iVar2 = heap_caps_calloc(1,8,uVar1);
  *(int *)this = iVar2;
  if (iVar2 == 0) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"Resolver",
            "E (%lu) %s: %s(%d): No free memory for creating a DNS forwarding transaction\n",uVar1,
            "Resolver",0x10000,0x47);
    uVar1 = 0x101;
  }
  else {
    *(undefined4 *)(this + 4) = 1;
    uVar1 = 0;
  }
  return uVar1;
}

