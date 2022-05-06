/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_platform_init(uint *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined *puVar3;
  undefined4 uVar4;
  
  if (*param_1 < 2) {
    if (param_1[0xb] < 3) {
      if (s_openthread_platform_initialized != '\0') {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC5,uVar4,"OPENTHREAD","esp_openthread_platform_init",0x68);
        return 0x103;
      }
      s_openthread_platform_initialized = '\x01';
      iVar2 = esp_partition_find_first(1,0xff,param_1[0x16]);
      if (iVar2 != 0) {
        memcpy(&s_platform_config,param_1,0x60);
        esp_openthread_flash_set_partition(iVar2);
        iVar2 = esp_openthread_lock_init();
        if (iVar2 == 0) {
          iVar2 = esp_openthread_alarm_init();
          if (iVar2 == 0) {
            if ((param_1[0xb] - 1 < 2) && (iVar2 = esp_openthread_uart_init(param_1), iVar2 != 0)) {
              uVar1 = esp_log_timestamp();
              uVar4 = 0x77;
              puVar3 = &_LC9;
            }
            else {
              iVar2 = esp_openthread_task_queue_init(param_1);
              if (iVar2 == 0) {
                iVar2 = esp_openthread_radio_init(param_1);
                if (iVar2 == 0) {
                  return 0;
                }
                uVar1 = esp_log_timestamp();
                uVar4 = 0x7b;
                puVar3 = &_LC11;
              }
              else {
                uVar1 = esp_log_timestamp();
                uVar4 = 0x7a;
                puVar3 = &_LC10;
              }
            }
          }
          else {
            uVar1 = esp_log_timestamp();
            uVar4 = 0x74;
            puVar3 = &_LC8;
          }
        }
        else {
          uVar1 = esp_log_timestamp();
          uVar4 = 0x73;
          puVar3 = &_LC7;
        }
        esp_log_write(1,"OPENTHREAD",puVar3,uVar1,"OPENTHREAD","esp_openthread_platform_init",uVar4)
        ;
        esp_openthread_platform_deinit();
        return iVar2;
      }
      uVar1 = esp_log_timestamp();
      uVar4 = 0x6f;
      puVar3 = &_LC6;
    }
    else {
      uVar1 = esp_log_timestamp();
      uVar4 = 0x66;
      puVar3 = &_LC4;
    }
  }
  else {
    uVar1 = esp_log_timestamp();
    uVar4 = 0x62;
    puVar3 = &_LC3;
  }
  esp_log_write(1,"OPENTHREAD",puVar3,uVar1,"OPENTHREAD","esp_openthread_platform_init",uVar4);
  return 0x102;
}

