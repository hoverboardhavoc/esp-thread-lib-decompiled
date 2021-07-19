/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> TryReadAndDecode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::TryReadAndDecode() */

UartSpinelInterface * __thiscall
esp::openthread::UartSpinelInterface::TryReadAndDecode(UartSpinelInterface *this)

{
  UartSpinelInterface *pUVar1;
  int *piVar2;
  int iVar3;
  int extraout_a1;
  uint uVar4;
  undefined1 auStack_90 [132];
  
  while (pUVar1 = (UartSpinelInterface *)read(*(int *)(this + 0x4c),auStack_90,0x80),
        0 < (int)pUVar1) {
    ot::Hdlc::Decoder::Decode((uchar *)(this + 0xc),(ushort)auStack_90);
  }
  if ((int)pUVar1 < 0) {
    piVar2 = (int *)__errno();
    if (((*piVar2 != 0xb) && (piVar2 = (int *)__errno(), *piVar2 != 0xb)) &&
       (iVar3 = TryRecoverUart(this), iVar3 != 0)) {
      pUVar1 = (UartSpinelInterface *)
               _esp_error_check_failed
                         ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                          ,0x80,"int esp::openthread::UartSpinelInterface::TryReadAndDecode()",
                          "TryRecoverUart()");
      uVar4 = *(uint *)(pUVar1 + 0x4c);
      if ((uVar4 < 0x40) && ((1 << (uVar4 & 0x1f) & *(uint *)(extraout_a1 + (uVar4 >> 5) * 4)) != 0)
         ) {
        pUVar1 = (UartSpinelInterface *)TryReadAndDecode(pUVar1);
        return pUVar1;
      }
      return pUVar1;
    }
  }
  return pUVar1;
}

