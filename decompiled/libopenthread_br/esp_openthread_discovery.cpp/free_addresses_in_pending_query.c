/*
 * Last changed at upstream commit 12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * https://github.com/espressif/esp-thread-lib/commit/12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * Upstream date: 2023-09-25 16:27:03 +0800
 * Upstream subject: lib(openthread): update otbr lib
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
  
  if (*(int *)(param_1 + 1000) == 2) {
    __ptr = *(void **)(param_1 + 0x3c4);
  }
  else {
    __ptr = *(void **)(param_1 + 0x3cc);
  }
  if (__ptr != (void *)0x0) {
    free(__ptr);
    return;
  }
  return;
}

