/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> esp_openthread_dns_upstream_resolver_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_dns_upstream_resolver_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = 0x103;
  if (g_resolver == (Resolver *)0x0) {
    uVar2 = esp_openthread_get_alloc_caps();
    g_resolver = (Resolver *)heap_caps_calloc(1,8,uVar2);
    if (g_resolver == (Resolver *)0x0) {
      g_resolver = (Resolver *)0x0;
      iVar1 = 0x101;
    }
    else {
      *(undefined4 *)g_resolver = 0;
      *(undefined4 *)(g_resolver + 4) = 0;
      iVar3 = Resolver::Init(g_resolver);
      iVar1 = 0x101;
      if (iVar3 == 0) {
        iVar1 = esp_openthread_platform_workflow_register
                          (dns_upstream_resolver_update,dns_upstream_resolver_process,
                           "dns_upstream_query");
        if (iVar1 == 0) {
          return 0;
        }
        Resolver::Deinit(g_resolver);
      }
      if (g_resolver != (Resolver *)0x0) {
        operator_delete(g_resolver,8);
      }
      g_resolver = (Resolver *)0x0;
      uVar2 = esp_log_timestamp();
      esp_log(1,"Resolver","E (%lu) %s: Failed to initialize dns upstream resolver\n",uVar2,
              "Resolver");
    }
  }
  return iVar1;
}

