/*
 * Last changed at upstream commit 3638c36b340b5976df2e1fcef8ff28160ef622c3
 * https://github.com/espressif/esp-thread-lib/commit/3638c36b340b5976df2e1fcef8ff28160ef622c3
 * Upstream date: 2025-01-08 16:16:11 +0800
 * Upstream subject: feat(br): add lib for release/v5.5 * esp-openthread: 278d4fc29 * openthread: 005c5cefc * esp-idf: a150b999b
 * Source: libopenthread_br -> esp_openthread_compat_test.o -> esp_openthread_check_netif_ip6_addr_state_offset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_check_netif_ip6_addr_state_offset(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0x16c) {
    uVar1 = esp_log_timestamp();
    esp_log_write(1,"OT_TEST",
                  "E (%lu) %s: The offset of `%s` is mismatched, %d in lib but %d in IDF\n",uVar1,
                  "OT_TEST","ip6_addr_state",0x16c,param_1);
    return 0;
  }
  return 1;
}

