/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
  undefined1 auStack_110 [244];
  
  __src = auStack_110;
  esp_openthread_get_netif();
  iVar1 = esp_netif_get_all_ip6(auStack_110);
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
  esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to alloc memory for mdns_ip_addr_t\n",uVar3,
          "OPENTHREAD");
  while (__ptr != (void *)0x0) {
    pvVar2 = *(void **)((int)__ptr + 0x18);
    free(__ptr);
    __ptr = pvVar2;
  }
  return (void *)0x0;
}

