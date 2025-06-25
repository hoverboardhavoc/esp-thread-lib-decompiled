/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
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
  int iVar3;
  
  for (uVar1 = 0; uVar1 < *(uint *)(this + 4); uVar1 = uVar1 + 1) {
    iVar3 = uVar1 * 8;
    puVar2 = (undefined4 *)(*(int *)this + iVar3);
    if ((otPlatDnsUpstreamQuery *)*puVar2 == param_1) {
      if (-1 < (int)puVar2[1]) {
        esp_openthread_task_switching_lock_release();
        close(*(int *)(*(int *)this + iVar3 + 4));
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        puVar2 = (undefined4 *)(*(int *)this + iVar3);
        puVar2[1] = 0xffffffff;
      }
      *puVar2 = 0;
    }
  }
  return;
}

