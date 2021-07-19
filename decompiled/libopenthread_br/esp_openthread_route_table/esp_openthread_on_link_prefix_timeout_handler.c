/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_on_link_prefix_timeout_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_on_link_prefix_timeout_handler(int *param_1)

{
  *param_1 = 0;
  while( true ) {
    if (param_1 == (int *)0x10824) {
      return;
    }
    *param_1 = param_1[8];
    param_1[1] = param_1[9];
    param_1[2] = param_1[10];
    param_1[3] = param_1[0xb];
    param_1[4] = param_1[0xc];
    param_1[5] = param_1[0xd];
    param_1[6] = param_1[0xe];
    param_1[7] = param_1[0xf];
    if (param_1[8] == 0) break;
    param_1 = param_1 + 8;
  }
  return;
}

