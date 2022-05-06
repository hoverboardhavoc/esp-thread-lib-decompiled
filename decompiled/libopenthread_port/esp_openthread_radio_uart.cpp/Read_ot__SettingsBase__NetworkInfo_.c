/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
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
  
  pvVar1 = memset(param_1,0,0x24);
  *(undefined1 *)((int)pvVar1 + 0x24) = 2;
  *(undefined1 *)((int)pvVar1 + 0x25) = 0;
  ot::Settings::ReadEntry(this,3,pvVar1,0x26);
  return;
}

