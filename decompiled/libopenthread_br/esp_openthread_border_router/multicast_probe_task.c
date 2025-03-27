/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
    esp_log(1,0x10000,"E (%lu) %s: Failed to probe backbone multicast listeners\n",uVar2,0x10000);
    return;
  }
  return;
}

