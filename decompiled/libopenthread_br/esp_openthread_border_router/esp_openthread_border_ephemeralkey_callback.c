/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_ephemeralkey_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_ephemeralkey_callback(void)

{
  int iVar1;
  
  esp_openthread_get_instance();
  iVar1 = otBorderAgentIsEphemeralKeyActive();
  if (iVar1 != 0) {
    esp_openthread_publish_meshcope_mdns();
    return;
  }
  esp_openthread_remove_meshcope_mdns();
  return;
}

