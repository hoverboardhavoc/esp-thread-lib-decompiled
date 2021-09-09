/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_port -> esp_openthread_platform.cpp.o -> esp_openthread_platform_workflow_register
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4
esp_openthread_platform_workflow_register(undefined4 param_1,undefined4 param_2,char *param_3)

{
  size_t sVar1;
  char *__dest;
  undefined4 uVar2;
  int iVar3;
  char *pcVar4;
  char *__s1;
  
  sVar1 = strnlen(param_3,0x10);
  __s1 = s_workflow_list;
  __dest = (char *)malloc(0x1c);
  if (__dest == (char *)0x0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC1,uVar2,"OPENTHREAD",
                  "esp_openthread_platform_workflow_register",0x32);
    uVar2 = 0x101;
  }
  else {
    strncpy(__dest,param_3,sVar1 & 0xff);
    *(undefined4 *)(__dest + 0x10) = param_1;
    *(undefined4 *)(__dest + 0x14) = param_2;
    __dest[0x18] = '\0';
    __dest[0x19] = '\0';
    __dest[0x1a] = '\0';
    __dest[0x1b] = '\0';
    pcVar4 = (char *)0x0;
    for (; __s1 != (char *)0x0; __s1 = *(char **)(__s1 + 0x18)) {
      iVar3 = strncmp(__s1,param_3,sVar1 & 0xff);
      if (iVar3 == 0) {
        free(__dest);
        return 0;
      }
      pcVar4 = __s1;
    }
    if (pcVar4 != (char *)0x0) {
      *(char **)(pcVar4 + 0x18) = __dest;
      __dest = s_workflow_list;
    }
    s_workflow_list = __dest;
    uVar2 = 0;
  }
  return uVar2;
}

