/*
 * Last changed at upstream commit 8943a3f95e316b1cdbca8680addf0474651235db
 * https://github.com/espressif/esp-thread-lib/commit/8943a3f95e316b1cdbca8680addf0474651235db
 * Upstream date: 2023-07-19 18:50:59 +0800
 * Upstream subject: feat(openthread): enable openthread border agent id esp-openthread: b703068 openthread:5beae14
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_remove_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_remove_meshcop_mdns(void)

{
  int iVar1;
  
  if (s_service_published != '\0') {
    iVar1 = mdns_service_remove("_meshcop",&_LC15);
    if (iVar1 != 0) {
      return iVar1;
    }
    s_service_published = '\0';
  }
  return 0;
}

