/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> Deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::Deinit() */

void __thiscall Resolver::Deinit(Resolver *this)

{
  int *piVar1;
  uint uVar2;
  
  uVar2 = 0;
  while( true ) {
    if (*(uint *)(this + 4) <= uVar2) break;
    piVar1 = (int *)(*(int *)this + uVar2 * 8);
    if ((*piVar1 != 0) && (piVar1[1] != -1)) {
      esp_openthread_get_instance();
      otPlatDnsUpstreamQueryDone(*piVar1,0);
      FindAndCloseTransaction(this,(otPlatDnsUpstreamQuery *)*piVar1);
    }
    uVar2 = uVar2 + 1;
  }
  heap_caps_free();
  return;
}

