/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> free_addresses_in_pending_query
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* free_addresses_in_pending_query(pending_query_t*) */

void free_addresses_in_pending_query(pending_query_t *param_1)

{
  if (*(int *)(param_1 + 0x328) == 2) {
    if (*(void **)(param_1 + 0x304) != (void *)0x0) {
      free(*(void **)(param_1 + 0x304));
    }
  }
  else if (*(void **)(param_1 + 0x30c) != (void *)0x0) {
    free(*(void **)(param_1 + 0x30c));
  }
  return;
}

