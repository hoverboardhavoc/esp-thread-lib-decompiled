/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
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
    if (param_1[0xb] < 3) {
      iVar1 = esp_partition_find_first(1,0xff,param_1[0x16]);
      if (iVar1 == 0) {
        uVar2 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC5,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x6e);
        iVar1 = 0x102;
      }
      else {
        puVar7 = &s_platform_config;
        puVar6 = param_1;
        do {
          uVar3 = puVar6[1];
          uVar4 = puVar6[2];
          uVar5 = puVar6[3];
          *puVar7 = *puVar6;
          puVar7[1] = uVar3;
          puVar7[2] = uVar4;
          puVar7[3] = uVar5;
          puVar6 = puVar6 + 4;
          puVar7 = puVar7 + 4;
        } while (puVar6 != param_1 + 0x18);
        esp_openthread_flash_set_partition();
        iVar1 = esp_openthread_lock_init();
        if (iVar1 == 0) {
          iVar1 = esp_openthread_alarm_init();
          if (iVar1 == 0) {
            if ((param_1[0xb] - 1 < 2) && (iVar1 = esp_openthread_uart_init(param_1), iVar1 != 0)) {
              uVar2 = esp_log_timestamp();
              esp_log_write(1,"OPENTHREAD",&_LC8,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                            0x76);
            }
            else {
              iVar1 = esp_openthread_task_queue_init(param_1);
              if (iVar1 == 0) {
                iVar1 = esp_openthread_radio_init(param_1);
                if (iVar1 == 0) {
                  return 0;
                }
                uVar2 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC10,uVar2,"OPENTHREAD",
                              "esp_openthread_platform_init",0x7a);
              }
              else {
                uVar2 = esp_log_timestamp();
                esp_log_write(1,"OPENTHREAD",&_LC9,uVar2,"OPENTHREAD","esp_openthread_platform_init"
                              ,0x79);
              }
            }
          }
          else {
            uVar2 = esp_log_timestamp();
            esp_log_write(1,"OPENTHREAD",&_LC7,uVar2,"OPENTHREAD","esp_openthread_platform_init",
                          0x73);
          }
        }
        else {
          uVar2 = esp_log_timestamp();
          esp_log_write(1,"OPENTHREAD",&_LC6,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x72)
          ;
        }
        if (iVar1 != 0) {
          esp_openthread_platform_deinit();
        }
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC4,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x66);
      iVar1 = 0x102;
    }
  }
  else {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC3,uVar2,"OPENTHREAD","esp_openthread_platform_init",0x62);
    iVar1 = 0x102;
  }
  return iVar1;
}

