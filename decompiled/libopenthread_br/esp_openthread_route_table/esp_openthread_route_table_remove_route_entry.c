/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(char *param_1)

{
  void *pvVar1;
  
  if (param_1 < s_route_entries) {
    return 0x102;
  }
  if (param_1 <= "OPENTHREAD") {
    param_1[0x34] = '\0';
    param_1[0x35] = '\0';
    param_1[0x36] = '\0';
    param_1[0x37] = '\0';
    do {
      if (s_route_entries + 0x1f8 <= param_1) {
        return 0;
      }
      pvVar1 = memcpy(param_1,param_1 + 0x38,0x38);
      param_1 = param_1 + 0x38;
    } while (*(int *)((int)pvVar1 + 0x34) != 0);
    return 0;
  }
  return 0x102;
}

