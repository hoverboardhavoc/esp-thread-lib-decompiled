/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_nd6.o -> nd6_append_option
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void nd6_append_option(int param_1,void *param_2,size_t param_3)

{
  memcpy((void *)(*(int *)(param_1 + 4) + (uint)*(ushort *)(param_1 + 10)),param_2,param_3);
  *(short *)(param_1 + 10) = *(short *)(param_1 + 10) + (short)param_3;
  *(short *)(param_1 + 8) = (short)param_3 + *(short *)(param_1 + 8);
  return;
}

