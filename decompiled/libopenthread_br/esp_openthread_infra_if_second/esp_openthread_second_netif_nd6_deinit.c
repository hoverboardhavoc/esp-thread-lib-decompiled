/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if_second.o -> esp_openthread_second_netif_nd6_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_second_netif_nd6_deinit(void)

{
  if (s_raw_pcb != 0) {
    esp_openthread_task_switching_lock_release();
    esp_netif_tcpip_exec(second_netif_do_deinit,0);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    esp_openthread_get_instance();
    otRemoveStateChangeCallback(br_second_netif_callback,0);
    s_netif = 0;
    return 0;
  }
  return 0x103;
}

