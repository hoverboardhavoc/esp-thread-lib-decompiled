/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> esp_openthread_dns_upstream_resolver_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void esp_openthread_dns_upstream_resolver_deinit(void)

{
  if (g_resolver != (Resolver *)0x0) {
    Resolver::Deinit(g_resolver);
    if (g_resolver != (Resolver *)0x0) {
      operator_delete(g_resolver,8);
    }
    esp_openthread_platform_workflow_unregister("dns_upstream_query");
    g_resolver = (Resolver *)0x0;
  }
  return;
}

