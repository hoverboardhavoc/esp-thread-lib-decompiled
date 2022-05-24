/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
    esp_log_write(1,0x10000,&_LC2,uVar2,0x10000);
    return;
  }
  return;
}

