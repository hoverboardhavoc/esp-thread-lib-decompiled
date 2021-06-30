/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> TryReadAndDecode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: int TryReadAndDecode(UartSpinelInterface * this) */

int __thiscall esp::openthread::UartSpinelInterface::TryReadAndDecode(UartSpinelInterface *this)

{
  ssize_t sVar1;
  int *piVar2;
  esp_err_t eVar3;
  UartSpinelInterface *this_00;
  int iVar4;
  int extraout_a1;
  uint uVar5;
  undefined1 auStack_90 [4];
  uint8_t buffer [128];
  
  while (sVar1 = read(this->m_uart_fd,auStack_90,0x80), 0 < sVar1) {
    ot::Hdlc::Decoder::Decode((uchar *)&this->m_hdlc_decoder,(ushort)auStack_90);
  }
  if (sVar1 < 0) {
    piVar2 = (int *)__errno();
    if (((*piVar2 != 0xb) && (piVar2 = (int *)__errno(), *piVar2 != 0xb)) &&
       (eVar3 = TryRecoverUart(this), eVar3 != 0)) {
      this_00 = (UartSpinelInterface *)
                _esp_error_check_failed
                          ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                           ,0x80,"int esp::openthread::UartSpinelInterface::TryReadAndDecode()",
                           "TryRecoverUart()");
      uVar5 = this_00->m_uart_fd;
      if ((uVar5 < 0x40) && ((1 << (uVar5 & 0x1f) & *(uint *)(extraout_a1 + (uVar5 >> 5) * 4)) != 0)
         ) {
        iVar4 = TryReadAndDecode(this_00);
        return iVar4;
      }
      return (int)this_00;
    }
  }
  return sVar1;
}

