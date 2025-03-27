/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> FindAndCloseTransaction
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::FindAndCloseTransaction(otPlatDnsUpstreamQuery*) */

void __thiscall Resolver::FindAndCloseTransaction(Resolver *this,otPlatDnsUpstreamQuery *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  
  for (uVar1 = 0; uVar1 < *(uint *)(this + 4); uVar1 = uVar1 + 1) {
    puVar2 = (undefined4 *)(*(int *)this + uVar1 * 8);
    if ((otPlatDnsUpstreamQuery *)*puVar2 == param_1) {
      if (-1 < (int)puVar2[1]) {
        close(puVar2[1]);
        puVar2 = (undefined4 *)(*(int *)this + uVar1 * 8);
        puVar2[1] = 0xffffffff;
      }
      *puVar2 = 0;
    }
  }
  return;
}

