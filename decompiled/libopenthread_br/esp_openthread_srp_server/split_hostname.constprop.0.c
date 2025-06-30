/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> split_hostname.constprop.0
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void split_hostname_constprop_0(char *param_1,char *param_2)

{
  char *pcVar1;
  size_t __n;
  
  pcVar1 = strchr(param_1,0x2e);
  __n = (int)pcVar1 - (int)param_1;
  if (0x40 < __n) {
    __n = 0x40;
  }
  strncpy(param_2,param_1,__n);
  param_2[__n] = '\0';
  return;
}

