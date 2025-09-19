/*
 * Last changed at upstream commit 984efc1578c856af215f33fcfeab645145949b46
 * https://github.com/espressif/esp-thread-lib/commit/984efc1578c856af215f33fcfeab645145949b46
 * Upstream date: 2025-09-19 08:31:45 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 3b3dd203
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
  
  if (0xf < param_1) {
    iVar1 = pbuf_alloc(0x36,param_1,0x280);
    if (iVar1 != 0) {
      puVar2 = *(undefined1 **)(iVar1 + 4);
      *(undefined4 *)(puVar2 + 5) = 0;
      *puVar2 = 0x86;
      *(undefined4 *)(puVar2 + 1) = 0;
      *(undefined4 *)(puVar2 + 9) = 0;
      *(undefined2 *)(puVar2 + 0xd) = 0;
      puVar2[0xf] = 0;
      puVar2[5] = 2;
      *(undefined4 *)(iVar1 + 8) = 0x100010;
    }
    return iVar1;
  }
  return 0;
}

