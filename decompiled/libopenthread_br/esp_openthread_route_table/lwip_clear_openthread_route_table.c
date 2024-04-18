/*
 * Last changed at upstream commit a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * https://github.com/espressif/esp-thread-lib/commit/a0f6a77960b36ebe357cc4bee280034f8c7120f1
 * Upstream date: 2024-04-18 16:47:55 +0800
 * Upstream subject: feat(br): update border router lib           esp-openthread: 07f637d           openthread: be7d36e
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_clear_openthread_route_table
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 lwip_clear_openthread_route_table(void)

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
  return 0;
}

