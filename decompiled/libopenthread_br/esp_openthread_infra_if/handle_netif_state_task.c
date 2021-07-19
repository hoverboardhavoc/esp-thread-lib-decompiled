/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> handle_netif_state_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void handle_netif_state_task(void)

{
  int iVar1;
  
  esp_openthread_get_instance();
  iVar1 = otPlatInfraIfStateChanged
                    (*(char *)(s_netif + 0x196) + '\x01',*(byte *)(s_netif + 0x193) & 1);
  if (iVar1 != 0) {
    otLogCrit(0xc,"-PLAT----: ","otPlatInfraIfStateChanged error");
  }
  return;
}

