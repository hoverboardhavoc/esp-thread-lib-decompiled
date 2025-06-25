/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_nd6.o -> nd6_create_ra_with_hdr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int nd6_create_ra_with_hdr(uint param_1)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = 0;
  if ((0xf < param_1) && (iVar1 = pbuf_alloc(0x36,param_1,0x280), iVar1 != 0)) {
    puVar2 = *(undefined1 **)(iVar1 + 4);
    memset(puVar2 + 1,0,0xf);
    *puVar2 = 0x86;
    puVar2[5] = 2;
    *(undefined4 *)(iVar1 + 8) = 0x100010;
  }
  return iVar1;
}

