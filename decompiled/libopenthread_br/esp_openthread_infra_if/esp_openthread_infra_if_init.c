/*
 * Last changed at upstream commit af5d67ed3acb06cac9e06986b08781b93bd6dade
 * https://github.com/espressif/esp-thread-lib/commit/af5d67ed3acb06cac9e06986b08781b93bd6dade
 * Upstream date: 2023-01-09 11:37:28 +0100
 * Upstream subject: lib: Address lwip thread safety
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> esp_openthread_infra_if_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_infra_if_init(int param_1)

{
  undefined4 uVar1;
  
  if (s_raw_pcb != 0) {
    return 0x103;
  }
  if (param_1 != 0) {
    s_netif = param_1;
    uVar1 = esp_netif_tcpip_exec(0x10000,0);
    return uVar1;
  }
  return 0x102;
}

