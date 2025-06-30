/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_border_router.o -> multicast_probe_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void multicast_probe_task(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = esp_openthread_probe_backbone_listeners();
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: Failed to probe backbone multicast listeners\n",uVar2);
    return;
  }
  return;
}

