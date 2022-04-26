/*
 * Last changed at upstream commit 90d32076b158280332a6f931440e2145c0d51b08
 * https://github.com/espressif/esp-thread-lib/commit/90d32076b158280332a6f931440e2145c0d51b08
 * Upstream date: 2022-04-26 15:33:17 +0800
 * Upstream subject: openthread: support esp32h2beta1 & esp32h2beta2
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
  undefined1 auStack_524 [1308];
  
  iVar1 = spinel_datatype_pack
                    (auStack_524,0x514,&_LC3,0x80,1,CONCAT31(in_register_0000202d,param_1));
  if (iVar1 - 1U < 0x514) {
    uVar2 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_524);
  }
  else {
    uVar2 = 3;
  }
  return uVar2;
}

