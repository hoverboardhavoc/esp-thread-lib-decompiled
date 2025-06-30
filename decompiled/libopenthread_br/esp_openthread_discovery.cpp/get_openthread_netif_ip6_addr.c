/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
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
  void *pvVar1;
  int iVar2;
  void *__dest;
  undefined4 uVar3;
  
  esp_openthread_get_instance();
  pvVar1 = (void *)otIp6GetUnicastAddresses();
  __ptr = (void *)0x0;
  do {
    if (pvVar1 == (void *)0x0) {
      return __ptr;
    }
    iVar2 = is_openthread_internal_mesh_local_addr(pvVar1);
    __dest = __ptr;
    if ((iVar2 == 0) && ((*(ushort *)((int)pvVar1 + 0x12) & 1) != 0)) {
      __dest = malloc(0x1c);
      if (__dest == (void *)0x0) {
        uVar3 = esp_log_timestamp();
        esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to alloc memory for mdns_ip_addr_t\n",uVar3);
        while (__ptr != (void *)0x0) {
          pvVar1 = *(void **)((int)__ptr + 0x18);
          free(__ptr);
          __ptr = pvVar1;
        }
        return (void *)0x0;
      }
      *(undefined1 *)((int)__dest + 0x14) = 6;
      memcpy(__dest,pvVar1,0x10);
      *(void **)((int)__dest + 0x18) = __ptr;
    }
    pvVar1 = *(void **)((int)pvVar1 + 0x14);
    __ptr = __dest;
  } while( true );
}

