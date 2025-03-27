/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> esp_openthread_dns_upstream_resolver_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_dns_upstream_resolver_init(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0x103;
  if (g_resolver == (Resolver *)0x0) {
    g_resolver = (Resolver *)operator_new(8);
    *(undefined4 *)g_resolver = 0;
    *(undefined4 *)(g_resolver + 4) = 0;
    iVar2 = Resolver::Init(g_resolver);
    if (iVar2 == 0) {
      uVar1 = esp_openthread_platform_workflow_register
                        (dns_upstream_resolver_update,dns_upstream_resolver_process,
                         "dns_upstream_query");
      return uVar1;
    }
    uVar1 = esp_log_timestamp();
    esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to init openthread DNS upstream resolver\n",
            uVar1,"Resolver","esp_openthread_dns_upstream_resolver_init",0x124);
    uVar1 = 0x101;
  }
  return uVar1;
}

