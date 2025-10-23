/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> otPlatInfraIfDhcp6PdClientSetListeningEnabled
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatInfraIfDhcp6PdClientSetListeningEnabled(undefined1 param_1,undefined4 param_2)

{
  undefined1 auStack_18 [4];
  undefined4 uStack_14;
  
  auStack_18[0] = param_1;
  uStack_14 = param_2;
  esp_openthread_task_switching_lock_release();
  esp_netif_tcpip_exec(dhcp6_pd_listen_task,auStack_18);
  esp_openthread_task_switching_lock_acquire(0xffffffff);
  return;
}

