/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  int *piVar3;
  int extraout_a1;
  uint extraout_a1_00;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  timeval tStack_48;
  uint local_40 [2];
  uint local_38 [5];
  
  tStack_48.tv_sec = 2;
  tStack_48.tv_usec = 0;
  uVar1 = otPlatTimeGet();
  uVar7 = uVar1 + 2000000;
  uVar1 = (uint)(uVar7 < uVar1) + extraout_a1;
  do {
    iVar5 = 0;
    do {
      *(undefined1 *)((int)local_40 + iVar5) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 8);
    iVar5 = 0;
    do {
      *(undefined1 *)((int)local_38 + iVar5) = 0;
      iVar5 = iVar5 + 1;
    } while (iVar5 != 8);
    uVar2 = *(uint *)(this + 0x4c);
    if (uVar2 < 0x40) {
      uVar6 = uVar2 >> 5;
      uVar4 = 1 << (uVar2 & 0x1f);
      local_40[uVar6] = local_40[uVar6] | uVar4;
      local_38[uVar6] = uVar4 | local_38[uVar6];
    }
    iVar5 = select(uVar2 + 1,(fd_set *)0x0,(fd_set *)local_40,(fd_set *)local_38,&tStack_48);
    if (iVar5 < 1) {
      if ((iVar5 != 0) && (piVar3 = (int *)__errno(), *piVar3 != 4)) {
        iVar5 = TryRecoverUart(this);
        if (iVar5 == 0) {
          return 1;
        }
                    /* WARNING: Subroutine does not return */
        abort();
      }
    }
    else {
      uVar2 = *(uint *)(this + 0x4c);
      if (uVar2 < 0x40) {
        uVar4 = 1 << (uVar2 & 0x1f);
        if ((local_40[uVar2 >> 5] & uVar4) != 0) {
          return 0;
        }
        if ((uVar4 & local_38[uVar2 >> 5]) != 0) {
          return 1;
        }
      }
    }
    uVar2 = otPlatTimeGet();
    if (uVar1 <= extraout_a1_00) {
      if (uVar1 != extraout_a1_00) {
        return 1;
      }
      if (uVar7 <= uVar2) {
        return 1;
      }
    }
    uVar2 = uVar7 - uVar2;
    iVar5 = (uVar1 - extraout_a1_00) - (uint)(uVar7 < uVar2);
    tStack_48.tv_sec = __udivdi3(uVar2,iVar5,1000000,0);
    tStack_48.tv_usec = __umoddi3(uVar2,iVar5,1000000,0);
  } while( true );
}

