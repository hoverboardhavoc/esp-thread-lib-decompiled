/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> free_addresses_in_pending_query
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* free_addresses_in_pending_query(pending_query_t*) */

void free_addresses_in_pending_query(pending_query_t *param_1)

{
  void *__ptr;
  
  if (*(int *)(param_1 + 0x328) == 2) {
    __ptr = *(void **)(param_1 + 0x304);
  }
  else {
    __ptr = *(void **)(param_1 + 0x30c);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
    return;
  }
  return;
}

