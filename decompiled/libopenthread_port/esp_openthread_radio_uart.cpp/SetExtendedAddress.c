/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> SetExtendedAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   SetExtendedAddress(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, otExtAddress * aExtAddress) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
SetExtendedAddress(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                   *this,otExtAddress *aExtAddress)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  otError oVar8;
  
  oVar8 = Set(this,0x34,"E");
  if (oVar8 == OT_ERROR_NONE) {
    uVar1 = aExtAddress->m8[1];
    uVar2 = aExtAddress->m8[2];
    uVar3 = aExtAddress->m8[3];
    uVar4 = aExtAddress->m8[4];
    uVar5 = aExtAddress->m8[5];
    uVar6 = aExtAddress->m8[6];
    uVar7 = aExtAddress->m8[7];
    (this->mExtendedAddress).m8[0] = aExtAddress->m8[0];
    (this->mExtendedAddress).m8[1] = uVar1;
    (this->mExtendedAddress).m8[2] = uVar2;
    (this->mExtendedAddress).m8[3] = uVar3;
    (this->mExtendedAddress).m8[4] = uVar4;
    (this->mExtendedAddress).m8[5] = uVar5;
    (this->mExtendedAddress).m8[6] = uVar6;
    (this->mExtendedAddress).m8[7] = uVar7;
  }
  return oVar8;
}

