/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
  }
  esp_openthread_platform_workflow_unregister("dns_upstream_query");
  return;
}

