/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  esp_log_write(1,"OPENTHREAD",&_LC12,uVar3,"OPENTHREAD","esp_openthread_platform_process",0xa7,
                iVar1);
  return iVar2;
}

