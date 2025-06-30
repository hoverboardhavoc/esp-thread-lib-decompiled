/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> convert_to_ot_srp_error_code
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 convert_to_ot_srp_error_code(int param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 != 0) && (uVar1 = 3, param_1 != 0x101)) {
    uVar1 = 1;
  }
  return uVar1;
}

