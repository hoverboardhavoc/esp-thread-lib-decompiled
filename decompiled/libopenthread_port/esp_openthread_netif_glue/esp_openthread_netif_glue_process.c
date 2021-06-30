/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

esp_err_t esp_openthread_netif_glue_process
                    (otInstance *instance,esp_openthread_mainloop_context_t *context)

{
  esp_err_t eVar1;
  
  if (s_openthread_netif_glue.event_fd < 0) {
    return 0;
  }
  if ((uint)s_openthread_netif_glue.event_fd < 0x40) {
    if ((1 << (s_openthread_netif_glue.event_fd & 0x1fU) &
        (context->read_fds).fds_bits[(uint)s_openthread_netif_glue.event_fd >> 5]) == 0) {
      return 0;
    }
    eVar1 = process_thread_transmit(instance);
    return eVar1;
  }
  return 0;
}

