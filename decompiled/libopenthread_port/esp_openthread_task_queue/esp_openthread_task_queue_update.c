/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void esp_openthread_task_queue_update(esp_openthread_mainloop_context_t *mainloop)

{
  int iVar1;
  fd_mask *pfVar2;
  
  iVar1 = s_task_queue_event_fd;
  if (-1 < s_task_queue_event_fd) {
    if ((uint)s_task_queue_event_fd < 0x40) {
      pfVar2 = (mainloop->read_fds).fds_bits + ((uint)s_task_queue_event_fd >> 5);
      *pfVar2 = *pfVar2 | 1 << (s_task_queue_event_fd & 0x1fU);
    }
    if (mainloop->max_fd < iVar1) {
      mainloop->max_fd = iVar1;
    }
  }
  return;
}

