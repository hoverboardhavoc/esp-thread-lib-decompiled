/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_clear
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_route_table_clear(void)

{
  undefined1 *puVar1;
  int *piVar2;
  
  puVar1 = s_route_entries;
  do {
    if ((*(int *)(puVar1 + 0x34) != 0) && (*(int *)(puVar1 + 0x30) != -1)) {
      sys_untimeout(route_timeout_handler,puVar1);
    }
    puVar1 = puVar1 + 0x38;
  } while (puVar1 != s_route_entries);
  memset(s_route_entries,0,0x230);
  piVar2 = &s_on_link_prefixes;
  do {
    if (*piVar2 != 0) {
      if (piVar2[7] != -1) {
        sys_untimeout(0x10000,piVar2);
      }
      *piVar2 = 0;
    }
    piVar2 = piVar2 + 8;
  } while (piVar2 != &s_on_link_prefixes);
  return;
}

