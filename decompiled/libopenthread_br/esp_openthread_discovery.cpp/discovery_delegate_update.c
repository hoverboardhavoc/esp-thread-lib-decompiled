/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
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
  uint uVar2;
  esp_openthread_mainloop_context_t *peVar3;
  
  uVar1 = s_mdns_event_fd;
  if (-1 < (int)s_mdns_event_fd) {
    if ((int)s_mdns_event_fd < 0x40) {
      peVar3 = param_1 + ((int)s_mdns_event_fd >> 5) * 4;
      uVar2 = 1 << (s_mdns_event_fd & 0x1f);
      *(uint *)peVar3 = *(uint *)peVar3 | uVar2;
      *(uint *)(peVar3 + 0x10) = uVar2 | *(uint *)(peVar3 + 0x10);
    }
    if (*(int *)(param_1 + 0x18) < (int)uVar1) {
      *(uint *)(param_1 + 0x18) = uVar1;
    }
  }
  return;
}

