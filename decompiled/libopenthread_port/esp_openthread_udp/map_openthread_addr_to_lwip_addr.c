/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_udp.o -> map_openthread_addr_to_lwip_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * map_openthread_addr_to_lwip_addr(void *param_1,void *param_2)

{
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_14;
  
  memcpy(&iStack_28,param_2,0x10);
  if ((iStack_28 == 0 && iStack_24 == 0) && (iStack_20 == -0x10000)) {
    uStack_14 = 0;
    iStack_28 = iStack_1c;
  }
  else {
    uStack_14 = 6;
    uStack_18 = 0;
  }
  memcpy(param_1,&iStack_28,0x18);
  return param_1;
}

