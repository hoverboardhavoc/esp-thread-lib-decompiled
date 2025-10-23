/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> esp_openthread_infra_if_deinit
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_infra_if_deinit(void)

{
  int iVar1;
  
  if (s_raw_pcb != 0) {
    esp_openthread_task_switching_lock_release();
    esp_netif_tcpip_exec(infra_if_do_deinit,0);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    esp_openthread_get_instance();
    iVar1 = otBorderRoutingSetEnabled(0);
    return -(uint)(iVar1 != 0);
  }
  return 0x103;
}

