/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_platform_process(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = s_workflow_list;
  while( true ) {
    if (iVar1 == 0) {
      return 0;
    }
    iVar2 = (**(code **)(iVar1 + 0x14))(param_1,param_2,*(code **)(iVar1 + 0x14));
    if (iVar2 != 0) break;
    iVar1 = *(int *)(iVar1 + 0x18);
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC11,uVar3,"OPENTHREAD","esp_openthread_platform_process",0xa6,
                iVar1);
  return iVar2;
}

