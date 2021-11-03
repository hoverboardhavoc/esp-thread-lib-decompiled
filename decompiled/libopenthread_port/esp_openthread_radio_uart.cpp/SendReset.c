/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SendReset(unsigned char) */

undefined4 __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SendReset(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
         uchar param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined3 in_register_0000202d;
  undefined1 auStack_410 [1032];
  
  iVar1 = spinel_datatype_pack
                    (auStack_410,0x400,&_LC3,0x80,1,CONCAT31(in_register_0000202d,param_1));
  if (iVar1 - 1U < 0x400) {
    uVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_410);
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

