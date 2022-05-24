/*
 * Last changed at upstream commit 8d47b585cf4b5e717aa06b2897d27c843fafa343
 * https://github.com/espressif/esp-thread-lib/commit/8d47b585cf4b5e717aa06b2897d27c843fafa343
 * Upstream date: 2022-05-24 22:56:58 +0800
 * Upstream subject: openthread: rebuild the lib with new toolchain
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> WaitForWritable
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::WaitForWritable() */

undefined4 __thiscall
esp::openthread::UartSpinelInterface::WaitForWritable(UartSpinelInterface *this)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int *piVar4;
  int extraout_a1;
  uint extraout_a1_00;
  __fd_mask extraout_a1_01;
  uint uVar5;
  int iVar6;
  uint local_50 [4];
  timeval tStack_40;
  __fd_mask _Stack_38;
  
  tStack_40.tv_sec = 2;
  tStack_40.tv_usec = 0;
  _Stack_38 = 0;
  uVar2 = otPlatTimeGet();
  uVar1 = uVar2 + 2000000;
  uVar2 = (uint)(uVar1 < uVar2) + extraout_a1;
  do {
    uVar3 = *(uint *)(this + 0x4c);
    local_50[1] = 0;
    local_50[0] = 0;
    local_50[3] = 0;
    local_50[2] = 0;
    if (uVar3 < 0x40) {
      iVar6 = (int)uVar3 >> 5;
      uVar5 = 1 << (uVar3 & 0x1f);
      local_50[iVar6] = local_50[iVar6] | uVar5;
      local_50[iVar6 + 2] = uVar5 | local_50[iVar6 + 2];
    }
    iVar6 = select(uVar3 + 1,(fd_set *)0x0,(fd_set *)local_50,(fd_set *)(local_50 + 2),&tStack_40);
    if (iVar6 < 1) {
      if ((iVar6 != 0) && (piVar4 = (int *)__errno(), *piVar4 != 4)) {
        iVar6 = TryRecoverUart(this);
        if (iVar6 == 0) {
          return 1;
        }
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    else {
      uVar3 = *(uint *)(this + 0x4c);
      if (uVar3 < 0x40) {
        uVar5 = 1 << (uVar3 & 0x1f);
        if ((local_50[(int)uVar3 >> 5] & uVar5) != 0) {
          return 0;
        }
        if ((uVar5 & local_50[((int)uVar3 >> 5) + 2]) != 0) {
          return 1;
        }
      }
    }
    uVar3 = otPlatTimeGet();
    if (uVar2 <= extraout_a1_00) {
      if (uVar2 != extraout_a1_00) {
        return 1;
      }
      if (uVar1 <= uVar3) {
        return 1;
      }
    }
    uVar3 = uVar1 - uVar3;
    iVar6 = (uVar2 - extraout_a1_00) - (uint)(uVar1 < uVar3);
    tStack_40.tv_sec = __udivdi3(uVar3,iVar6,1000000,0);
    tStack_40.tv_usec = extraout_a1_01;
    _Stack_38 = __umoddi3(uVar3,iVar6,1000000,0);
  } while( true );
}

