/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SendReset
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::SendReset(unsigned char) */

int __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
SendReset(RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *this,
         uchar param_1)

{
  int iVar1;
  int iVar2;
  undefined3 in_register_0000202d;
  uchar auStack_524 [1304];
  
  iVar2 = spinel_datatype_pack
                    (auStack_524,0x514,&_LC96,0x80,1,CONCAT31(in_register_0000202d,param_1));
  iVar1 = 3;
  if (iVar2 - 1U < 0x514) {
    iVar1 = esp::openthread::UartSpinelInterface::SendFrame
                      ((uchar *)(this + 0x410),(ushort)auStack_524);
    if (iVar1 == 0) {
      LogSpinelFrame(this,auStack_524,(ushort)iVar2,true);
    }
  }
  return iVar1;
}

