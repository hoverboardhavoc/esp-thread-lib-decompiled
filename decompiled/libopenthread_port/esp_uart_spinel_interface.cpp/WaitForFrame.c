/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> WaitForFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::WaitForFrame(unsigned long long) */

uint esp::openthread::UartSpinelInterface::WaitForFrame(ulonglong param_1)

{
  uint uVar1;
  UartSpinelInterface *in_a0;
  __fd_mask extraout_a1;
  uint uVar2;
  int iVar3;
  uint local_40 [4];
  timeval tStack_30;
  __fd_mask _Stack_28;
  
  uVar1 = *(uint *)(in_a0 + 0x4c);
  local_40[1] = 0;
  local_40[0] = 0;
  local_40[3] = 0;
  local_40[2] = 0;
  if (uVar1 < 0x40) {
    iVar3 = (int)uVar1 >> 5;
    uVar2 = 1 << (uVar1 & 0x1f);
    local_40[iVar3] = local_40[iVar3] | uVar2;
    local_40[iVar3 + 2] = uVar2 | local_40[iVar3 + 2];
  }
  tStack_30.tv_sec = __udivdi3(1000000,0);
  tStack_30.tv_usec = extraout_a1;
  _Stack_28 = __umoddi3(1000000,0);
  uVar1 = select(uVar1 + 1,(fd_set *)local_40,(fd_set *)0x0,(fd_set *)(local_40 + 2),&tStack_30);
  if ((int)uVar1 < 1) {
    uVar2 = 0x1c;
joined_r0x00010852:
    if (uVar1 != 0) {
      iVar3 = TryRecoverUart(in_a0);
      uVar2 = 1;
      if (iVar3 != 0) {
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
  }
  else {
    uVar1 = *(uint *)(in_a0 + 0x4c);
    if (uVar1 < 0x40) {
      uVar2 = 1 << (uVar1 & 0x1f);
      if ((local_40[(int)uVar1 >> 5] & uVar2) == 0) {
        uVar2 = uVar2 & local_40[((int)uVar1 >> 5) + 2];
        uVar1 = uVar2;
        goto joined_r0x00010852;
      }
      TryReadAndDecode(in_a0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

