/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> infra_if_raw_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void infra_if_raw_send_task(void *param_1)

{
  raw_sendto(s_raw_pcb,*(undefined4 *)((int)param_1 + 0x18),param_1);
  pbuf_free(*(undefined4 *)((int)param_1 + 0x18));
  free(param_1);
  return;
}

