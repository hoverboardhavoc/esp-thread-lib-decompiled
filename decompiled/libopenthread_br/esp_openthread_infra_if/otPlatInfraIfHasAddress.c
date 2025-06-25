/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> otPlatInfraIfHasAddress
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

