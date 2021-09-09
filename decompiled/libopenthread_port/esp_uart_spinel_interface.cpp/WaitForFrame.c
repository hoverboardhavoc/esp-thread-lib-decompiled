/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
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
  uint uVar2;
  int iVar3;
  uint uVar4;
  timeval tStack_38;
  uint local_30 [2];
  uint local_28 [5];
  
  iVar3 = 0;
  do {
    *(undefined1 *)((int)local_30 + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  iVar3 = 0;
  do {
    *(undefined1 *)((int)local_28 + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 != 8);
  uVar1 = *(uint *)(in_a0 + 0x4c);
  if (uVar1 < 0x40) {
    uVar4 = uVar1 >> 5;
    uVar2 = 1 << (uVar1 & 0x1f);
    local_30[uVar4] = local_30[uVar4] | uVar2;
    local_28[uVar4] = uVar2 | local_28[uVar4];
  }
  tStack_38.tv_sec = __udivdi3(1000000,0);
  tStack_38.tv_usec = __umoddi3(1000000,0);
  uVar1 = select(uVar1 + 1,(fd_set *)local_30,(fd_set *)0x0,(fd_set *)local_28,&tStack_38);
  if ((int)uVar1 < 1) {
    uVar2 = 0x1c;
joined_r0x00010730:
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
      if ((local_30[uVar1 >> 5] & uVar2) == 0) {
        uVar2 = uVar2 & local_28[uVar1 >> 5];
        uVar1 = uVar2;
        goto joined_r0x00010730;
      }
      TryReadAndDecode(in_a0);
    }
    uVar2 = 0;
  }
  return uVar2;
}

