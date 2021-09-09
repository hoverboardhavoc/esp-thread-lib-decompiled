/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> udp_new_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void udp_new_task(undefined4 *param_1)

{
  undefined4 uVar1;
  
  uVar1 = udp_new();
  param_1[2] = uVar1;
  udp_recv(handle_udp_recv,param_1[1]);
  xTaskGenericNotify(*param_1,0,0,2,0);
  return;
}

