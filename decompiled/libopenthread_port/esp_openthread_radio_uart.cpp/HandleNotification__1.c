/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> HandleNotification__1
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void
   HandleNotification(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
   * this, uint8_t * aFrame, uint16_t aLength) */

void __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
HandleNotification(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>
                   *this,uint8_t *aFrame,uint16_t aLength)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 in_register_00002032;
  byte bStack_21;
  int iStack_20;
  uint8_t header;
  uint32_t cmd;
  uint8_t *data;
  spinel_size_t len;
  spinel_prop_key_t key;
  
  data = (uint8_t *)0x0;
  cmd = 0;
  iVar1 = spinel_datatype_unpack
                    (aFrame,CONCAT22(in_register_00002032,aLength),&_LC58,&bStack_21,
                     &stack0xffffffe0,&len,&cmd,&data);
  if (iVar1 < 1) {
    iVar1 = 6;
  }
  else if ((bStack_21 & 0xf) == 0) {
    if (iStack_20 == 6) {
      HandleValueIs(this,len,(uint8_t *)cmd,(uint16_t)data);
      iVar1 = 0;
    }
    else {
      iVar1 = 0;
    }
  }
  else {
    iVar1 = 6;
  }
  if (iVar1 != 0) {
    uVar2 = otThreadErrorToString();
    otLogWarn(0xc,_LC2,"%s: %s","Error processing saved notification",uVar2);
  }
  return;
}

