/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_on_link_prefix_timeout_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_on_link_prefix_timeout_handler(undefined4 *param_1)

{
  int *piVar1;
  
  *param_1 = 0;
  do {
    if (param_1 == &s_on_link_prefixes) {
      return;
    }
    piVar1 = (int *)memcpy(param_1,param_1 + 8,0x20);
    param_1 = param_1 + 8;
  } while (*piVar1 != 0);
  return;
}

