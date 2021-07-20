/*
 * Last changed at upstream commit 4cea59c231dbf1b3ee2dcd12c631cc25cfa11d42
 * https://github.com/espressif/esp-thread-lib/commit/4cea59c231dbf1b3ee2dcd12c631cc25cfa11d42
 * Upstream date: 2021-07-20 11:34:17 +0800
 * Upstream subject: openthread: remove build dependency on border router in port library
 * Source: libopenthread_port -> esp_openthread.cpp.o -> esp_openthread_state_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp_openthread_state_callback(unsigned long, void*) */

void esp_openthread_state_callback(ulong param_1,void *param_2)

{
  esp_openthread_netif_glue_state_callback();
  return;
}

