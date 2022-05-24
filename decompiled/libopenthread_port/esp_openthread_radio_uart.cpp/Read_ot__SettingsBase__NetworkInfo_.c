/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Read_ot__SettingsBase__NetworkInfo_
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* otError ot::Settings::Read<ot::SettingsBase::NetworkInfo>(ot::SettingsBase::NetworkInfo&) const
    */

void __thiscall
ot::Settings::Read<ot::SettingsBase::NetworkInfo>(Settings *this,NetworkInfo *param_1)

{
  void *pvVar1;
  
  pvVar1 = memset(param_1,0,0x26);
  *(undefined1 *)((int)pvVar1 + 0x24) = 2;
  ot::Settings::ReadEntry(this,3,pvVar1,0x26);
  return;
}

