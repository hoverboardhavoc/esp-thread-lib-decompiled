/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> find_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * find_route_entry(void *param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  while( true ) {
    if (9 < uVar2) {
      return (undefined1 *)0x0;
    }
    iVar3 = uVar2 * 0x38;
    if (*(int *)(s_route_entries + iVar3 + 0x34) == 0) break;
    if ((((*(int *)(s_route_entries + iVar3 + 0x34) == *(int *)((int)param_1 + 0x34)) &&
         (bVar1 = *(byte *)((int)param_1 + 0x14), s_route_entries[iVar3 + 0x14] == bVar1)) &&
        (iVar3 = memcmp(s_route_entries + iVar3 + 0x18,(void *)((int)param_1 + 0x18),0x10),
        iVar3 == 0)) &&
       (iVar3 = memcmp(s_route_entries + uVar2 * 0x38,param_1,(uint)(bVar1 >> 3)), iVar3 == 0)) {
      return s_route_entries + uVar2 * 0x38;
    }
    uVar2 = uVar2 + 1;
  }
  return (undefined1 *)0x0;
}

