/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
      iVar2 = esp_partition_find_first(1,0xff,param_1[0x16]);
      if (iVar2 != 0) {
        memcpy(s_platform_config,param_1,0x60);
        esp_openthread_flash_set_partition(iVar2);
        iVar2 = esp_openthread_lock_init();
        if (iVar2 == 0) {
          iVar2 = esp_openthread_alarm_init();
          if (iVar2 == 0) {
            if ((param_1[0xb] - 1 < 2) && (iVar2 = esp_openthread_uart_init(param_1), iVar2 != 0)) {
              uVar1 = esp_log_timestamp();
              uVar4 = 0x76;
              puVar3 = &_LC8;
            }
            else {
              iVar2 = esp_openthread_task_queue_init(param_1);
              if (iVar2 == 0) {
                iVar2 = esp_openthread_radio_init(param_1);
                if (iVar2 == 0) {
                  return 0;
                }
                uVar1 = esp_log_timestamp();
                uVar4 = 0x7a;
                puVar3 = &_LC10;
              }
              else {
                uVar1 = esp_log_timestamp();
                uVar4 = 0x79;
                puVar3 = &_LC9;
              }
            }
          }
          else {
            uVar1 = esp_log_timestamp();
            uVar4 = 0x73;
            puVar3 = &_LC7;
          }
        }
        else {
          uVar1 = esp_log_timestamp();
          uVar4 = 0x72;
          puVar3 = &_LC6;
        }
        esp_log_write(1,"OPENTHREAD",puVar3,uVar1,"OPENTHREAD","esp_openthread_platform_init",uVar4)
        ;
        esp_openthread_platform_deinit();
        return iVar2;
      }
      uVar1 = esp_log_timestamp();
      uVar4 = 0x6e;
      puVar3 = &_LC5;
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

