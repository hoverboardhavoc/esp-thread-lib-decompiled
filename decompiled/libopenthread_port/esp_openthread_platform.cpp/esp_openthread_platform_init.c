/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_platform_init(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  
  if (*param_1 == 0) {
    if ((uint)param_1[0xb] < 2) {
      iVar1 = esp_partition_find_first(1,0xff,param_1[0x16]);
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x38);
        iVar1 = 0x102;
      }
      else {
        piVar6 = &s_platform_config;
        piVar5 = param_1;
        do {
          iVar1 = piVar5[1];
          iVar3 = piVar5[2];
          iVar4 = piVar5[3];
          *piVar6 = *piVar5;
          piVar6[1] = iVar1;
          piVar6[2] = iVar3;
          piVar6[3] = iVar4;
          piVar5 = piVar5 + 4;
          piVar6 = piVar6 + 4;
        } while (piVar5 != param_1 + 0x18);
        esp_openthread_flash_set_partition();
        iVar1 = esp_openthread_lock_init();
        if (iVar1 == 0) {
          if ((param_1[0xb] == 1) && (iVar1 = esp_openthread_uart_init(param_1), iVar1 != 0)) {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                          0x3e);
          }
          else {
            iVar1 = esp_openthread_task_queue_init(param_1);
            if (iVar1 == 0) {
              iVar1 = esp_openthread_radio_init(param_1);
              if (iVar1 == 0) {
                return 0;
              }
              uVar2 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                            0x42);
            }
            else {
              uVar2 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                            0x41);
            }
          }
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x3c)
          ;
        }
        if (iVar1 != 0) {
          esp_openthread_platform_deinit();
        }
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x30);
      iVar1 = 0x102;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x2d);
    iVar1 = 0x102;
  }
  return iVar1;
}

