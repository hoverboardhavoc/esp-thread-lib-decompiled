/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> dns_upstream_resolver_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dns_upstream_resolver_process(otInstance*, esp_openthread_mainloop_context_t const*) */

undefined4
dns_upstream_resolver_process(otInstance *param_1,esp_openthread_mainloop_context_t *param_2)

{
  if ((g_resolver != (Resolver *)0x0) &&
     (Resolver::Process(g_resolver,param_2), g_resolver != (Resolver *)0x0)) {
    return 0;
  }
  return 0x103;
}

