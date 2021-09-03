/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> discovery_delegate_update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* discovery_delegate_update(esp_openthread_mainloop_context_t*) */

void discovery_delegate_update(esp_openthread_mainloop_context_t *param_1)

{
  uint uVar1;
  
  uVar1 = s_mdns_event_fd;
  if (-1 < (int)s_mdns_event_fd) {
    if (s_mdns_event_fd < 0x40) {
      *(uint *)(param_1 + (s_mdns_event_fd >> 5) * 4) =
           *(uint *)(param_1 + (s_mdns_event_fd >> 5) * 4) | 1 << (s_mdns_event_fd & 0x1f);
      *(uint *)(param_1 + ((uVar1 >> 5) + 4) * 4) =
           *(uint *)(param_1 + ((uVar1 >> 5) + 4) * 4) | 1 << (uVar1 & 0x1f);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  return;
}

