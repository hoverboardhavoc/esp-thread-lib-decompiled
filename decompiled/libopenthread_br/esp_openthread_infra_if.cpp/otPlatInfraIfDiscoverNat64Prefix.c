/*
 * Last changed at upstream commit 70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * https://github.com/espressif/esp-thread-lib/commit/70a7322bfe4dd130c7cf9a94b8dbbeb0dbae0687
 * Upstream date: 2026-04-10 09:53:42 +0000
 * Upstream subject: feat(openthread/lib): update thread-lib for upstream a98813b30
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> otPlatInfraIfDiscoverNat64Prefix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 otPlatInfraIfDiscoverNat64Prefix(void)

{
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined1 uStack_14;
  
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  otPlatInfraIfDiscoverNat64PrefixDone(&uStack_24);
  return 0;
}

