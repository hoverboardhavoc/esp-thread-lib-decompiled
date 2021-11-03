/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_ncp.cpp.o -> start_ota
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* start_ota(unsigned char const*, unsigned short) */

undefined4 start_ota(uchar *param_1,ushort param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined2 in_register_0000202e;
  undefined *puVar4;
  undefined1 auStack_320 [16];
  char acStack_310 [240];
  undefined1 auStack_220 [256];
  undefined1 auStack_120 [16];
  char acStack_110 [252];
  
  uVar1 = esp_ota_get_running_partition();
  uVar2 = esp_ota_get_last_invalid_partition();
  s_update_partition = esp_ota_get_next_update_partition(0);
  if (s_update_partition == 0) {
    uVar2 = esp_log_timestamp();
    uVar1 = 0x2a;
    puVar4 = &_LC1;
  }
  else {
    if (CONCAT22(in_register_0000202e,param_2) < 0x120) {
      uVar1 = esp_log_timestamp();
      esp_log_write(1,"OPENTHREAD",&_LC2,uVar1,"OPENTHREAD","start_ota",0x2d);
      return 7;
    }
    memcpy(auStack_320,param_1 + 0x20,0x100);
    iVar3 = esp_ota_get_partition_description(uVar1,auStack_220);
    if (iVar3 == 0) {
      iVar3 = esp_ota_get_partition_description(uVar2,auStack_120);
      if ((iVar3 == 0) && (iVar3 = strncmp(acStack_110,acStack_310,0x20), iVar3 == 0)) {
        uVar2 = esp_log_timestamp();
        uVar1 = 0x38;
        puVar4 = &_LC4;
      }
      else {
        iVar3 = esp_ota_begin(s_update_partition,0xfffffffe,&s_update_handle);
        if (iVar3 == 0) {
          s_header_checked = 1;
          return 0;
        }
        uVar2 = esp_log_timestamp();
        uVar1 = 0x3b;
        puVar4 = &_LC5;
      }
    }
    else {
      uVar2 = esp_log_timestamp();
      uVar1 = 0x32;
      puVar4 = &_LC3;
    }
  }
  esp_log_write(1,"OPENTHREAD",puVar4,uVar2,"OPENTHREAD","start_ota",uVar1);
  return 1;
}

