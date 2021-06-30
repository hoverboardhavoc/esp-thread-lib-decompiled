/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_new_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void udp_new_task(void *ctx)

{
  undefined4 uVar1;
  
  uVar1 = udp_new();
  *(undefined4 *)((int)ctx + 8) = uVar1;
  udp_recv(handle_udp_recv,*(undefined4 *)((int)ctx + 4));
                    /* WARNING: Load size is inaccurate */
  xTaskGenericNotify(*ctx,0,2,0);
  return;
}

