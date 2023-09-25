/*
 * Last changed at upstream commit 12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * https://github.com/espressif/esp-thread-lib/commit/12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * Upstream date: 2023-09-25 16:27:03 +0800
 * Upstream subject: lib(openthread): update otbr lib
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> get_openthread_netif_ip6_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention -- yet parameter storage is locked */
/* get_openthread_netif_ip6_addr() */

void * get_openthread_netif_ip6_addr(void)

{
  void *__ptr;
  undefined1 *__src;
  int iVar1;
  void *pvVar2;
  undefined4 uVar3;
  int iVar4;
  undefined1 auStack_c0 [164];
  
  __src = auStack_c0;
  esp_openthread_get_netif();
  iVar1 = esp_netif_get_all_ip6(auStack_c0);
  iVar4 = 0;
  __ptr = (void *)0x0;
  while( true ) {
    if (iVar4 == iVar1) {
      return __ptr;
    }
    pvVar2 = malloc(0x1c);
    if (pvVar2 == (void *)0x0) break;
    *(undefined1 *)((int)pvVar2 + 0x14) = 6;
    memcpy(pvVar2,__src,0x14);
    iVar4 = iVar4 + 1;
    *(void **)((int)pvVar2 + 0x18) = __ptr;
    __src = __src + 0x14;
    __ptr = pvVar2;
  }
  uVar3 = esp_log_timestamp();
  esp_log_write(1,"OPENTHREAD",&_LC1,uVar3,"OPENTHREAD");
  while (__ptr != (void *)0x0) {
    pvVar2 = *(void **)((int)__ptr + 0x18);
    free(__ptr);
    __ptr = pvVar2;
  }
  return (void *)0x0;
}

