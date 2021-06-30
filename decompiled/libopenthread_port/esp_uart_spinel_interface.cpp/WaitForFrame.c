/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> WaitForFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError WaitForFrame(UartSpinelInterface * this, uint64_t timeout_us)
    */

otError __thiscall
esp::openthread::UartSpinelInterface::WaitForFrame(UartSpinelInterface *this,uint64_t timeout_us)

{
  int iVar1;
  esp_err_t eVar2;
  fd_mask *pfVar3;
  otError *poVar4;
  uint uVar5;
  otError local_38;
  _types_fd_set error_fds;
  _types_fd_set read_fds;
  timeval timeout;
  
  pfVar3 = error_fds.fds_bits + 1;
  for (uVar5 = 0; uVar5 < 8; uVar5 = uVar5 + 1) {
    *(undefined1 *)pfVar3 = 0;
    pfVar3 = (fd_mask *)((int)pfVar3 + 1);
  }
  poVar4 = &local_38;
  for (uVar5 = 0; uVar5 < 8; uVar5 = uVar5 + 1) {
    *(undefined1 *)poVar4 = OT_ERROR_NONE;
    poVar4 = (otError *)((int)poVar4 + 1);
  }
  uVar5 = this->m_uart_fd;
  if (uVar5 < 0x40) {
    error_fds.fds_bits[(uVar5 >> 5) + 1] =
         error_fds.fds_bits[(uVar5 >> 5) + 1] | 1 << (uVar5 & 0x1f);
    error_fds.fds_bits[(uVar5 >> 5) - 1] =
         error_fds.fds_bits[(uVar5 >> 5) - 1] | 1 << (uVar5 & 0x1f);
  }
  read_fds.fds_bits[1] = __udivdi3(1000000,0);
  __umoddi3(1000000,0);
  iVar1 = select(uVar5 + 1,(fd_set *)(error_fds.fds_bits + 1),(fd_set *)0x0,(fd_set *)&local_38,
                 (timeval *)(read_fds.fds_bits + 1));
  if (0 < iVar1) {
    uVar5 = this->m_uart_fd;
    if ((uVar5 < 0x40) && ((error_fds.fds_bits[(uVar5 >> 5) + 1] & 1 << (uVar5 & 0x1f)) != 0)) {
      TryReadAndDecode(this);
      return OT_ERROR_NONE;
    }
    if (0x3f < uVar5) {
      return OT_ERROR_NONE;
    }
    if ((error_fds.fds_bits[(uVar5 >> 5) - 1] & 1 << (uVar5 & 0x1f)) == 0) {
      return OT_ERROR_NONE;
    }
    eVar2 = TryRecoverUart(this);
    if (eVar2 == 0) {
      return OT_ERROR_FAILED;
    }
    iVar1 = _esp_error_check_failed
                      ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                       ,0xe5,"otError esp::openthread::UartSpinelInterface::WaitForFrame(uint64_t)",
                       "TryRecoverUart()");
  }
  if (iVar1 == 0) {
    return OT_ERROR_RESPONSE_TIMEOUT;
  }
  eVar2 = TryRecoverUart(this);
  if (eVar2 != 0) {
    _esp_error_check_failed
              ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
               ,0xeb,"otError esp::openthread::UartSpinelInterface::WaitForFrame(uint64_t)",
               "TryRecoverUart()");
    return OT_ERROR_NONE;
  }
  return OT_ERROR_FAILED;
}

