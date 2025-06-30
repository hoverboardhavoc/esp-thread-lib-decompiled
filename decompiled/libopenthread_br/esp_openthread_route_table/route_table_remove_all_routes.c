/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
      sys_untimeout(route_timeout_handler);
    }
    puVar1 = puVar1 + 0x38;
  } while (puVar1 != s_route_entries);
  memset(s_route_entries,0,0x230);
  return 0;
}

