/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> otPlatInfraIfHasAddress
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool otPlatInfraIfHasAddress(void *param_1)

{
  int iVar1;
  undefined1 auStack_24 [32];
  
  memcpy(auStack_24,param_1,0x10);
  iVar1 = esp_netif_tcpip_exec(infra_if_is_self_address,auStack_24);
  return iVar1 == 0;
}

