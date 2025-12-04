/*
 * Last changed at upstream commit 66e81acb8df80dbc52a2b0841a8ae3153557e131
 * https://github.com/espressif/esp-thread-lib/commit/66e81acb8df80dbc52a2b0841a8ae3153557e131
 * Upstream date: 2025-12-04 07:38:20 +0000
 * Upstream subject: fix(openthread): resolve deadlock issues due to switching_lock
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> ForwardResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::ForwardResponse(Resolver::Transaction*) */

void Resolver::ForwardResponse(Transaction *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_a1;
  undefined1 auStack_210 [512];
  
  esp_openthread_task_switching_lock_release();
  uVar1 = read(in_a1[1],auStack_210,0x200);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  if (0 < (int)uVar1) {
    esp_openthread_get_instance();
    iVar2 = otUdpNewMessage(0);
    if (iVar2 != 0) {
      iVar3 = otMessageAppend(auStack_210,uVar1 & 0xffff);
      if (iVar3 == 0) {
        esp_openthread_get_instance();
        otPlatDnsUpstreamQueryDone(*in_a1,iVar2);
      }
      else {
        otMessageFree(iVar2);
      }
    }
  }
  return;
}

