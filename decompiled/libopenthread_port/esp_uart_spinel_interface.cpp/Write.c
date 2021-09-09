/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::Write(unsigned char const*, unsigned short) */

int __thiscall
esp::openthread::UartSpinelInterface::Write(UartSpinelInterface *this,uchar *param_1,ushort param_2)

{
  size_t __n;
  int iVar1;
  undefined2 in_register_00002032;
  
  __n = CONCAT22(in_register_00002032,param_2);
  while( true ) {
    while( true ) {
      if (__n == 0) {
        return 0;
      }
      iVar1 = write(*(int *)(this + 0x4c),param_1,__n);
      if (iVar1 < 1) break;
      if ((int)__n < iVar1) {
        iVar1 = __assert_func(0,0,0,0);
      }
      __n = __n - iVar1 & 0xffff;
      param_1 = param_1 + iVar1;
    }
    if (iVar1 != 0) break;
    iVar1 = WaitForWritable(this);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  iVar1 = TryRecoverUart(this);
  if (iVar1 == 0) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  abort();
}

