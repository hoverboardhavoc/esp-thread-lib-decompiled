/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_compat_test.o -> esp_openthread_check_netif_ip_addr_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_check_netif_ip_addr_offset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 4) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OT_TEST","E (%lu) %s: The offset of `%s` is mismatched, %d in lib but %d in IDF\n",
            uVar1,"OT_TEST",0x10000,4,param_1);
    return 0;
  }
  return 1;
}

