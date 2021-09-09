/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> TryReadAndDecode
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::TryReadAndDecode() */

ssize_t __thiscall esp::openthread::UartSpinelInterface::TryReadAndDecode(UartSpinelInterface *this)

{
  ssize_t sVar1;
  int *piVar2;
  int iVar3;
  undefined1 auStack_90 [128];
  
  while (sVar1 = read(*(int *)(this + 0x4c),auStack_90,0x80), 0 < sVar1) {
    ot::Hdlc::Decoder::Decode((uchar *)(this + 0xc),(ushort)auStack_90);
  }
  if (sVar1 != 0) {
    piVar2 = (int *)__errno();
    if (((*piVar2 != 0xb) && (piVar2 = (int *)__errno(), *piVar2 != 0xb)) &&
       (iVar3 = TryRecoverUart(this), iVar3 != 0)) {
                    /* WARNING: Subroutine does not return */
      abort();
    }
  }
  return sVar1;
}

