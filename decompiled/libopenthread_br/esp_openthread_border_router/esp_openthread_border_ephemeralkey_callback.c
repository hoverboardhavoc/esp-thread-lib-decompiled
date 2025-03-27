/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_ephemeralkey_callback
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_border_ephemeralkey_callback(void)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  esp_openthread_get_instance();
  iVar1 = otBorderAgentEphemeralKeyGetState();
  if (iVar1 == 2) {
    esp_openthread_publish_meshcope_mdns(s_meshcop_instance_name);
    return;
  }
  if (iVar1 == 1) {
    esp_openthread_remove_meshcope_mdns();
    return;
  }
  uVar2 = esp_log_timestamp();
  uVar3 = otBorderAgentEphemeralKeyStateToString(iVar1);
  esp_log(2,0x10000,"W (%lu) %s: EphemeralKeyState changed: %s\n",uVar2,0x10000,uVar3);
  return;
}

