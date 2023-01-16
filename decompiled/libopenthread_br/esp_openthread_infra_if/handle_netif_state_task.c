/*
 * Last changed at upstream commit 99779af83df3c13d358e1dab7f19699237b1ffdc
 * https://github.com/espressif/esp-thread-lib/commit/99779af83df3c13d358e1dab7f19699237b1ffdc
 * Upstream date: 2023-01-16 10:21:19 +0100
 * Upstream subject: lib: Address lwip thread-safety/core-locking
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

