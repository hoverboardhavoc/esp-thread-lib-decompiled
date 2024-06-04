/*
 * Last changed at upstream commit 34d698a274940730901b934caa023a3281aca53e
 * https://github.com/espressif/esp-thread-lib/commit/34d698a274940730901b934caa023a3281aca53e
 * Upstream date: 2024-06-04 12:02:17 +0800
 * Upstream subject: feat(openthread): update br lib
 * Source: libopenthread_br -> esp_openthread_route_table.o -> route_table_remove_all_routes
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 route_table_remove_all_routes(void)

{
  undefined1 *puVar1;
  
  puVar1 = s_route_entries;
  do {
    if ((*(int *)(puVar1 + 0x34) != 0) && (*(int *)(puVar1 + 0x30) != -1)) {
      sys_untimeout(route_timeout_handler,puVar1);
    }
    puVar1 = puVar1 + 0x38;
  } while (puVar1 != s_route_entries);
  memset(s_route_entries,0,0x230);
  return 0;
}

