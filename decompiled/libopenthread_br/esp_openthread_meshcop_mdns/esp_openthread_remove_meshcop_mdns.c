/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_meshcop_mdns.o -> esp_openthread_remove_meshcop_mdns
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_remove_meshcop_mdns(void)

{
  int iVar1;
  
  iVar1 = 0;
  if ((s_service_published != '\0') && (iVar1 = mdns_service_remove("_meshcop",&_LC15), iVar1 == 0))
  {
    s_service_published = '\0';
  }
  return iVar1;
}

