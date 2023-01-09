/*
 * Last changed at upstream commit af5d67ed3acb06cac9e06986b08781b93bd6dade
 * https://github.com/espressif/esp-thread-lib/commit/af5d67ed3acb06cac9e06986b08781b93bd6dade
 * Upstream date: 2023-01-09 11:37:28 +0100
 * Upstream subject: lib: Address lwip thread safety
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> handle_netif_state_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_netif_state_task(void)

{
  int iVar1;
  undefined4 uVar2;
  
  esp_openthread_get_instance();
  iVar1 = otPlatInfraIfStateChanged
                    (*(char *)(s_netif + 0x18a) + '\x01',*(byte *)(s_netif + 0x187) & 1);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD");
    return;
  }
  return;
}

