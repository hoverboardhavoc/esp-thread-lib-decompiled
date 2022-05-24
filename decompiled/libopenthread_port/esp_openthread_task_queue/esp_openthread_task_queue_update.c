/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
      puVar2 = (uint *)(((int)s_task_queue_event_fd >> 5) * 4 + param_1);
      *puVar2 = *puVar2 | 1 << (s_task_queue_event_fd & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  return;
}

