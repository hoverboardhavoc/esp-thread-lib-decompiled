/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> WaitForWritable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError WaitForWritable(UartSpinelInterface * this) */

otError __thiscall esp::openthread::UartSpinelInterface::WaitForWritable(UartSpinelInterface *this)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  int *piVar5;
  esp_err_t eVar6;
  int extraout_a1;
  uint extraout_a1_00;
  uint extraout_a1_01;
  fd_mask *pfVar7;
  uint *puVar8;
  uint uVar9;
  uint local_38;
  _types_fd_set error_fds;
  _types_fd_set write_fds;
  timeval timeout;
  
  write_fds.fds_bits[1] = 2;
  uVar2 = otPlatTimeGet();
  uVar1 = uVar2 + 2000000;
  uVar2 = (uint)(uVar1 < uVar2) + extraout_a1;
  do {
    pfVar7 = error_fds.fds_bits + 1;
    for (uVar9 = 0; uVar9 < 8; uVar9 = uVar9 + 1) {
      *(undefined1 *)pfVar7 = 0;
      pfVar7 = (fd_mask *)((int)pfVar7 + 1);
    }
    puVar8 = &local_38;
    for (uVar9 = 0; uVar9 < 8; uVar9 = uVar9 + 1) {
      *(undefined1 *)puVar8 = 0;
      puVar8 = (uint *)((int)puVar8 + 1);
    }
    uVar9 = this->m_uart_fd;
    if (uVar9 < 0x40) {
      error_fds.fds_bits[(uVar9 >> 5) + 1] =
           error_fds.fds_bits[(uVar9 >> 5) + 1] | 1 << (uVar9 & 0x1f);
      error_fds.fds_bits[(uVar9 >> 5) - 1] =
           error_fds.fds_bits[(uVar9 >> 5) - 1] | 1 << (uVar9 & 0x1f);
    }
    iVar3 = select(uVar9 + 1,(fd_set *)0x0,(fd_set *)(error_fds.fds_bits + 1),(fd_set *)&local_38,
                   (timeval *)(write_fds.fds_bits + 1));
    if (iVar3 < 1) {
      if ((-1 < iVar3) || (piVar5 = (int *)__errno(), *piVar5 == 4)) goto _L0;
      eVar6 = TryRecoverUart(this);
      if (eVar6 == 0) {
        return OT_ERROR_FAILED;
      }
      uVar4 = _esp_error_check_failed
                        ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                         ,0x9f,"otError esp::openthread::UartSpinelInterface::WaitForWritable()",
                         "TryRecoverUart()");
      uVar9 = extraout_a1_01;
_L0:
      if ((uVar2 != uVar9) || (uVar1 <= uVar4)) {
        return OT_ERROR_FAILED;
      }
    }
    else {
      uVar9 = this->m_uart_fd;
      if ((uVar9 < 0x40) && ((error_fds.fds_bits[(uVar9 >> 5) + 1] & 1 << (uVar9 & 0x1f)) != 0)) {
        return OT_ERROR_NONE;
      }
      if ((uVar9 < 0x40) && ((1 << (uVar9 & 0x1f) & error_fds.fds_bits[(uVar9 >> 5) - 1]) != 0)) {
        return OT_ERROR_FAILED;
      }
_L0:
      uVar4 = otPlatTimeGet();
      uVar9 = extraout_a1_00;
      if (uVar2 <= extraout_a1_00) goto _L0;
    }
    uVar4 = uVar1 - uVar4;
    iVar3 = (uVar2 - uVar9) - (uint)(uVar1 < uVar4);
    write_fds.fds_bits[1] = __udivdi3(uVar4,iVar3,1000000,0);
    __umoddi3(uVar4,iVar3,1000000,0);
  } while( true );
}

