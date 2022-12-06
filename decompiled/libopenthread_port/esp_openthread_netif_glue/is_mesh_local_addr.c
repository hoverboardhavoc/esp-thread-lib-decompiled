/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> is_mesh_local_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

bool is_mesh_local_addr(void *param_1)

{
  void *__s2;
  int iVar1;
  
  esp_openthread_get_instance();
  __s2 = (void *)otThreadGetMeshLocalPrefix();
  iVar1 = memcmp(param_1,__s2,8);
  return iVar1 == 0;
}

