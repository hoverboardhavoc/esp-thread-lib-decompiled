/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_multicast_router.o -> free_multicast_listener
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void free_multicast_listener(void *param_1)

{
  void *pvVar1;
  void *__ptr;
  
  __ptr = *(void **)((int)param_1 + 0x14);
  while (__ptr != (void *)0x0) {
    pvVar1 = *(void **)((int)__ptr + 0x14);
    free(__ptr);
    __ptr = pvVar1;
  }
  free(param_1);
  return;
}

