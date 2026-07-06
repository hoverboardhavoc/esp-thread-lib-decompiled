/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> mdns_query_results_free_locked
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* mdns_query_results_free_locked(mdns_result_s*) */

void mdns_query_results_free_locked(mdns_result_s *param_1)

{
  esp_openthread_task_switching_lock_release();
  mdns_query_results_free(param_1);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return;
}

