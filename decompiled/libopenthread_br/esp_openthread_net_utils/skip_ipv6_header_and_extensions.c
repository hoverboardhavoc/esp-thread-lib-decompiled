/*
 * Last changed at upstream commit f8871fa4d9a7ad74c861d0108152165fc89044f5
 * https://github.com/espressif/esp-thread-lib/commit/f8871fa4d9a7ad74c861d0108152165fc89044f5
 * Upstream date: 2022-01-26 19:30:41 +0800
 * Upstream subject: br: support multicast routing
 * Source: libopenthread_br -> esp_openthread_net_utils.o -> skip_ipv6_header_and_extensions
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * skip_ipv6_header_and_extensions(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  char *pcVar2;
  uint uVar3;
  
  if (0x27 < param_2) {
    param_2 = param_2 - 0x28;
    cVar1 = *(char *)(param_1 + 6);
    pcVar2 = (char *)(param_1 + 0x28);
    while( true ) {
      param_2 = param_2 & 0xffff;
      if (((cVar1 == '\x06') || (cVar1 == '\x11')) || (cVar1 == ':')) {
        *param_3 = cVar1;
        return pcVar2;
      }
      if (param_2 < 8) break;
      cVar1 = *pcVar2;
      uVar3 = ((byte)pcVar2[1] + 1) * 8;
      if (param_2 < uVar3) {
        return (char *)0x0;
      }
      param_2 = param_2 + ((byte)pcVar2[1] + 1) * -8;
      pcVar2 = pcVar2 + uVar3;
    }
  }
  return (char *)0x0;
}

