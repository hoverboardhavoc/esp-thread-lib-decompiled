/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> find_empty_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * find_empty_route_entry(void)

{
  uint uVar1;
  
  uVar1 = 0;
  while( true ) {
    if (9 < uVar1) {
      return (undefined1 *)0x0;
    }
    if (*(int *)(s_route_entries + uVar1 * 0x38 + 0x34) == 0) break;
    uVar1 = uVar1 + 1;
  }
  return s_route_entries + uVar1 * 0x38;
}

