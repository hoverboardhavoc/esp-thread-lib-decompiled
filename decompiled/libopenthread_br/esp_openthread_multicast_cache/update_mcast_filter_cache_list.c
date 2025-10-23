/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_multicast_cache.o -> update_mcast_filter_cache_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void update_mcast_filter_cache_list(int *param_1)

{
  int *piVar1;
  int iVar2;
  
  if (s_mf_cache_list != 0) {
    piVar1 = (int *)param_1[1];
    iVar2 = *param_1;
    if (piVar1 == (int *)0x0) {
      s_mf_cache_list = iVar2;
      if (iVar2 != 0) {
        *(undefined4 *)(iVar2 + 4) = 0;
      }
    }
    else if (iVar2 == 0) {
      *piVar1 = 0;
    }
    else {
      *piVar1 = iVar2;
      *(int **)(iVar2 + 4) = piVar1;
    }
    heap_caps_free();
    return;
  }
  return;
}

