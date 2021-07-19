/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_remove_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_route_table_remove_route_entry(char *param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  char *pcVar7;
  
  if (param_1 < s_route_entries) {
    return 0x102;
  }
  if (param_1 < "ailed to add slaac address") {
    param_1[0x34] = '\0';
    param_1[0x35] = '\0';
    param_1[0x36] = '\0';
    param_1[0x37] = '\0';
    while( true ) {
      if (s_route_entries + 0x1f7 < param_1) {
        return 0;
      }
      pcVar1 = param_1;
      pcVar7 = param_1 + 0x38;
      do {
        pcVar6 = pcVar7;
        pcVar5 = pcVar1;
        uVar2 = *(undefined4 *)(pcVar6 + 4);
        uVar3 = *(undefined4 *)(pcVar6 + 8);
        uVar4 = *(undefined4 *)(pcVar6 + 0xc);
        *(undefined4 *)pcVar5 = *(undefined4 *)pcVar6;
        *(undefined4 *)(pcVar5 + 4) = uVar2;
        *(undefined4 *)(pcVar5 + 8) = uVar3;
        *(undefined4 *)(pcVar5 + 0xc) = uVar4;
        pcVar7 = pcVar6 + 0x10;
        pcVar1 = pcVar5 + 0x10;
      } while (pcVar7 != param_1 + 0x68);
      uVar2 = *(undefined4 *)(pcVar6 + 0x14);
      *(undefined4 *)(pcVar5 + 0x10) = *(undefined4 *)pcVar7;
      *(undefined4 *)(pcVar5 + 0x14) = uVar2;
      if (*(int *)(param_1 + 0x34) == 0) break;
      param_1 = param_1 + 0x38;
    }
    return 0;
  }
  return 0x102;
}

