/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_compat_test.o -> esp_openthread_check_netif_ip6_addr_pref_life_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_check_netif_ip6_addr_pref_life_offset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0x1a8) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OT_TEST","E (%lu) %s: The offset of `%s` is mismatched, %d in lib but %d in IDF\n",
            uVar1,"ip6_addr_pref_life",0x1a8,param_1);
    return 0;
  }
  return 1;
}

