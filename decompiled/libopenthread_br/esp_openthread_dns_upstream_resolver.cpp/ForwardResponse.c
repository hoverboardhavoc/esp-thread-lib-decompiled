/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> ForwardResponse
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::ForwardResponse(Resolver::Transaction*) */

void Resolver::ForwardResponse(Transaction *param_1)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  undefined4 *in_a1;
  undefined1 auStack_210 [512];
  
  uVar1 = read(in_a1[1],auStack_210,0x200);
  if (0 < (int)uVar1) {
    esp_openthread_get_instance();
    iVar2 = otUdpNewMessage(0);
    if (iVar2 != 0) {
      iVar3 = otMessageAppend(auStack_210,uVar1 & 0xffff);
      if (iVar3 == 0) {
        esp_openthread_get_instance();
        otPlatDnsUpstreamQueryDone(*in_a1,iVar2);
      }
      else {
        otMessageFree(iVar2);
      }
    }
  }
  return;
}

