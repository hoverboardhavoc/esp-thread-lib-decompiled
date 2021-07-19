/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> esp_openthread_route_table_add_route_entry
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * esp_openthread_route_table_add_route_entry(undefined4 *param_1)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  char cVar6;
  int iVar7;
  uint uVar8;
  
  if (param_1 == (undefined4 *)0x0) {
    puVar1 = (undefined4 *)0x0;
  }
  else {
    puVar1 = (undefined4 *)find_route_entry();
    if (puVar1 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)find_empty_route_entry();
      if (puVar1 == (undefined4 *)0x0) {
        return (undefined4 *)0x0;
      }
      iVar7 = param_1[0xd];
      puVar1[0xd] = iVar7;
      uVar8 = param_1[6];
      uVar2 = param_1[7];
      uVar3 = param_1[8];
      uVar4 = param_1[9];
      uVar5 = param_1[10];
      puVar1[6] = uVar8;
      puVar1[7] = uVar2;
      puVar1[8] = uVar3;
      puVar1[9] = uVar4;
      puVar1[10] = uVar5;
      if ((uVar8 & 0xc0ff) == 0x80fe) {
        cVar6 = *(char *)(iVar7 + 0x196) + '\x01';
      }
      else {
        cVar6 = '\0';
      }
      *(char *)(puVar1 + 10) = cVar6;
      uVar2 = param_1[1];
      uVar3 = param_1[2];
      uVar4 = param_1[3];
      uVar5 = param_1[4];
      *puVar1 = *param_1;
      puVar1[1] = uVar2;
      puVar1[2] = uVar3;
      puVar1[3] = uVar4;
      puVar1[4] = uVar5;
      *(undefined1 *)(puVar1 + 5) = *(undefined1 *)(param_1 + 5);
    }
    else {
      sys_untimeout(route_timeout_handler,puVar1);
    }
    *(undefined1 *)(puVar1 + 0xb) = *(undefined1 *)(param_1 + 0xb);
    iVar7 = param_1[0xc];
    puVar1[0xc] = iVar7;
    sys_timeout(iVar7 * 1000,route_timeout_handler,puVar1);
  }
  return puVar1;
}

