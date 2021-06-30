/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> esp_openthread_netif_glue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_openthread_netif_glue_update(esp_openthread_mainloop_context_t *mainloop)

{
  fd_mask *pfVar1;
  
  if (-1 < s_openthread_netif_glue.event_fd) {
    if ((uint)s_openthread_netif_glue.event_fd < 0x40) {
      pfVar1 = (mainloop->read_fds).fds_bits + ((uint)s_openthread_netif_glue.event_fd >> 5);
      *pfVar1 = *pfVar1 | 1 << (s_openthread_netif_glue.event_fd & 0x1fU);
    }
    if (mainloop->max_fd < s_openthread_netif_glue.event_fd) {
      mainloop->max_fd = s_openthread_netif_glue.event_fd;
    }
  }
  return;
}

