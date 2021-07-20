/*
 * Last changed at upstream commit 08668646075c5769e7fed75699d8b1011e8d845a
 * https://github.com/espressif/esp-thread-lib/commit/08668646075c5769e7fed75699d8b1011e8d845a
 * Upstream date: 2021-07-20 16:06:37 +0800
 * Upstream subject: bugfix: add missing calloc/free port
 * Source: libopenthread_port -> esp_openthread_memory.o -> otPlatFree
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatFree(void *param_1)

{
  free(param_1);
  return;
}

