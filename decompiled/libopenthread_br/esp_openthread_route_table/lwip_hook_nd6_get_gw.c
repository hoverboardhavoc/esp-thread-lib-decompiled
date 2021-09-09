/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_nd6_get_gw
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

char * lwip_hook_nd6_get_gw(int param_1,char *param_2)

{
  byte bVar1;
  int *piVar2;
  undefined1 *__s2;
  char *pcVar3;
  int iVar4;
  
  piVar2 = &s_on_link_prefixes;
  do {
    if (*piVar2 == 0) break;
    iVar4 = memcmp(param_2,piVar2 + 1,(uint)(*(byte *)(piVar2 + 6) >> 3));
    if (iVar4 == 0) {
      return param_2;
    }
    piVar2 = piVar2 + 8;
  } while (piVar2 != (int *)s_route_entries);
  __s2 = s_route_entries;
  pcVar3 = (char *)0x0;
  do {
    if (*(int *)(__s2 + 0x34) == 0) break;
    if (*(int *)(__s2 + 0x34) == param_1) {
      bVar1 = __s2[0x14];
      iVar4 = memcmp(param_2,__s2,(uint)(bVar1 >> 3));
      if (iVar4 == 0) {
        if (pcVar3 != (char *)0x0) {
          if (((char)__s2[0x2c] <= pcVar3[0x2c]) &&
             ((__s2[0x2c] != pcVar3[0x2c] || (bVar1 <= (byte)pcVar3[0x14])))) goto _L0;
        }
        pcVar3 = __s2;
      }
    }
_L0:
    __s2 = __s2 + 0x38;
  } while (__s2 != "OPENTHREAD");
  if (pcVar3 != (char *)0x0) {
    pcVar3 = pcVar3 + 0x18;
  }
  return pcVar3;
}

