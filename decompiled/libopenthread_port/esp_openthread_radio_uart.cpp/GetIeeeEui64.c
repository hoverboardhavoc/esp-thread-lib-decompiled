/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> GetIeeeEui64
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError
   GetIeeeEui64(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint8_t * aIeeeEui64) */

otError __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
GetIeeeEui64(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
             *this,uint8_t *aIeeeEui64)

{
  uint8_t uVar1;
  uint8_t uVar2;
  uint8_t uVar3;
  uint8_t uVar4;
  uint8_t uVar5;
  uint8_t uVar6;
  uint8_t uVar7;
  
  uVar1 = (this->mIeeeEui64).m8[1];
  uVar2 = (this->mIeeeEui64).m8[2];
  uVar3 = (this->mIeeeEui64).m8[3];
  uVar4 = (this->mIeeeEui64).m8[4];
  uVar5 = (this->mIeeeEui64).m8[5];
  uVar6 = (this->mIeeeEui64).m8[6];
  uVar7 = (this->mIeeeEui64).m8[7];
  *aIeeeEui64 = (this->mIeeeEui64).m8[0];
  aIeeeEui64[1] = uVar1;
  aIeeeEui64[2] = uVar2;
  aIeeeEui64[3] = uVar3;
  aIeeeEui64[4] = uVar4;
  aIeeeEui64[5] = uVar5;
  aIeeeEui64[6] = uVar6;
  aIeeeEui64[7] = uVar7;
  return OT_ERROR_NONE;
}

