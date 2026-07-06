/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> dns_upstream_resolver_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dns_upstream_resolver_process(otInstance*, esp_openthread_mainloop_context_t const*) */

int dns_upstream_resolver_process(otInstance *param_1,esp_openthread_mainloop_context_t *param_2)

{
  int iVar1;
  
  iVar1 = 0x103;
  if (g_resolver != (Resolver *)0x0) {
    Resolver::Process(g_resolver,param_2);
    iVar1 = (-(uint)(g_resolver != (Resolver *)0x0) & 0xfffffefd) + 0x103;
  }
  return iVar1;
}

