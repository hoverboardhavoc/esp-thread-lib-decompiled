/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
    esp_log_write(1,0x10000,"E (%lu) %s: Failed to probe backbone multicast listeners\n",uVar2,
                  0x10000);
    return;
  }
  return;
}

