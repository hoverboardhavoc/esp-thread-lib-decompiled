/*
 * Last changed at upstream commit 56af58057c259405aa90c478e294f6216cc2f6db
 * https://github.com/espressif/esp-thread-lib/commit/56af58057c259405aa90c478e294f6216cc2f6db
 * Upstream date: 2024-09-09 14:04:56 +0200
 * Upstream subject: update(ot_lib): Rebuild with lwip 2.2.0-esp
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
                    (*(char *)(s_netif + 0x212) + '\x01',*(byte *)(s_netif + 0x20f) & 1);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD");
    return;
  }
  return;
}

