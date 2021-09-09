/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_task_queue.o -> esp_openthread_task_queue_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_task_queue_update(int param_1)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = s_task_queue_event_fd;
  if (-1 < (int)s_task_queue_event_fd) {
    if ((int)s_task_queue_event_fd < 0x40) {
      puVar2 = (uint *)((s_task_queue_event_fd >> 5) * 4 + param_1);
      *puVar2 = *puVar2 | 1 << (s_task_queue_event_fd & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  return;
}

