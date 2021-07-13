/*
 * Last changed at upstream commit d84f8967f8ce14490e19433b85c8c363d424f4c1
 * https://github.com/espressif/esp-thread-lib/commit/d84f8967f8ce14490e19433b85c8c363d424f4c1
 * Upstream date: 2021-07-13 21:21:08 +0800
 * Upstream subject: openthread: add ot library for esp32h2
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_platform_init(uint *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  
  if (*param_1 < 2) {
    if (param_1[0xb] < 2) {
      iVar1 = esp_partition_find_first(1,0xff,param_1[0x16]);
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x39);
        iVar1 = 0x102;
      }
      else {
        puVar6 = &s_platform_config;
        puVar7 = param_1;
        do {
          uVar3 = puVar7[1];
          uVar4 = puVar7[2];
          uVar5 = puVar7[3];
          *puVar6 = *puVar7;
          puVar6[1] = uVar3;
          puVar6[2] = uVar4;
          puVar6[3] = uVar5;
          puVar7 = puVar7 + 4;
          puVar6 = puVar6 + 4;
        } while (puVar7 != param_1 + 0x18);
        esp_openthread_flash_set_partition();
        iVar1 = esp_openthread_lock_init();
        if (iVar1 == 0) {
          if ((param_1[0xb] == 1) && (iVar1 = esp_openthread_uart_init(param_1), iVar1 != 0)) {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                          0x3f);
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
                            0x43);
            }
            else {
              uVar2 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                            0x42);
            }
          }
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x3d)
          ;
        }
        if (iVar1 != 0) {
          esp_openthread_platform_deinit();
        }
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x31);
      iVar1 = 0x102;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC2,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x2e);
    iVar1 = 0x102;
  }
  return iVar1;
}

