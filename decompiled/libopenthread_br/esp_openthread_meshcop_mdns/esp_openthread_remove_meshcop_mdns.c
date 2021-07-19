/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_remove_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_remove_meshcop_mdns(void)

{
  int iVar1;
  
  if (s_service_published == '\0') {
    return 0;
  }
  iVar1 = mdns_service_remove("_meshcop",&_LC9);
  if (iVar1 == 0) {
    s_service_published = '\0';
  }
  return iVar1;
}

