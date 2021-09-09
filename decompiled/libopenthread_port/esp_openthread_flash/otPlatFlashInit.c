/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_flash.o -> otPlatFlashInit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatFlashInit(void)

{
  uint *puVar1;
  undefined4 unaff_retaddr;
  undefined1 *puVar2;
  int iVar3;
  
  puVar2 = (undefined1 *)register0x00002008;
  iVar3 = s_ot_partition;
  if (s_ot_partition != 0) goto _L0;
  do {
    register0x00002008 = (BADSPACEBASE *)(puVar2 + -0x10);
    *(undefined4 *)(puVar2 + -4) = unaff_retaddr;
    unaff_retaddr = 0x10028;
    __assert_func(0,0,0,0);
_L0:
    puVar1 = (uint *)(iVar3 + 0x10);
    iVar3 = 0x1000;
    puVar2 = (undefined1 *)register0x00002008;
  } while (*puVar1 < 0x1000);
  return;
}

