/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_ncp.cpp.o -> VendorSetPropertyHandler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Ncp::NcpBase::VendorSetPropertyHandler(unsigned long) */

int __thiscall ot::Ncp::NcpBase::VendorSetPropertyHandler(NcpBase *this,ulong param_1)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uchar *local_14;
  
  local_14 = (uchar *)0x0;
  if (param_1 == 0x3c01) {
    iVar1 = 0xd;
    if (s_ota_triggered != '\0') {
      iVar1 = ot::Spinel::Decoder::ReadDataWithLen((uchar **)(this + 0x88),(ushort *)&local_14);
      if (s_header_checked == '\0') {
        iVar1 = start_ota(local_14,0);
      }
      iVar2 = esp_ota_write(s_update_handle,local_14,0);
      if (iVar2 == 0) {
        if (iVar1 == 0) {
          return 0;
        }
      }
      else {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC6,uVar3,"OPENTHREAD");
        iVar1 = 1;
      }
      esp_ota_abort(s_update_handle);
      s_ota_triggered = '\0';
    }
  }
  else if (param_1 == 0x3c02) {
    if (s_ota_triggered != '\0') {
      if (s_header_checked == '\0') {
        return 0xd;
      }
      iVar1 = esp_ota_set_boot_partition(s_update_partition);
      if (iVar1 != 0) {
        uVar3 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC7,uVar3,"OPENTHREAD");
        return 1;
      }
      esp_restart();
    }
    iVar1 = 0xd;
  }
  else {
    iVar1 = 0x17;
    if (param_1 == 0x3c00) {
      s_ota_triggered = '\x01';
      iVar1 = 0;
    }
  }
  return iVar1;
}

