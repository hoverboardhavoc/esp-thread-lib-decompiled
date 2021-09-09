/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> split_hostname.constprop.3
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void split_hostname_constprop_3(char *param_1,char *param_2)

{
  size_t __n;
  char *pcVar1;
  
  pcVar1 = strchr(param_1,0x2e);
  __n = (int)pcVar1 - (int)param_1;
  if (0x40 < __n) {
    __n = 0x40;
  }
  strncpy(param_2,param_1,__n);
  param_2[__n] = '\0';
  return;
}

