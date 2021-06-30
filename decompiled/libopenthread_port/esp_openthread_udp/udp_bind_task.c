/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_bind_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void udp_bind_task(void *ctx)

{
  undefined1 uVar1;
  
  uVar1 = udp_bind(*(undefined4 *)((int)ctx + 4),(int)ctx + 8,*(undefined2 *)((int)ctx + 0x20));
  *(undefined1 *)((int)ctx + 0x22) = uVar1;
                    /* WARNING: Load size is inaccurate */
  xTaskGenericNotify(*ctx,0,2,0);
  return;
}

