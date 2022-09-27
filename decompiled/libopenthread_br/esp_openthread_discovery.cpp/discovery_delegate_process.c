/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> discovery_delegate_process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* discovery_delegate_process(otInstance*, esp_openthread_mainloop_context_t const*) */

undefined4
discovery_delegate_process(otInstance *param_1,esp_openthread_mainloop_context_t *param_2)

{
  mdns_result_s *pmVar1;
  pending_query_t *__ptr;
  int iVar2;
  char *pcVar3;
  int iVar4;
  undefined1 *puVar5;
  mdns_result_s *pmVar6;
  int local_50;
  mdns_result_s *pmStack_4c;
  undefined1 auStack_48 [20];
  
  if ((0x3f < s_mdns_event_fd) ||
     ((1 << (s_mdns_event_fd & 0x1f) & *(uint *)(param_2 + ((int)s_mdns_event_fd >> 5) * 4)) == 0))
  {
    return 0;
  }
  read(s_mdns_event_fd,auStack_48,8);
  do {
    iVar2 = xQueueReceive(s_mdns_result_queue,&local_50,0);
    if (iVar2 != 1) {
      return 0;
    }
    mdns_query_async_get_results(local_50,0xffffffff,&pmStack_4c,0);
    pmVar1 = pmStack_4c;
    iVar2 = local_50;
    puVar5 = s_pending_queries;
    __ptr = (pending_query_t *)s_pending_queries._812_4_;
    while (__ptr != (pending_query_t *)0x0) {
      if (iVar2 == *(int *)(__ptr + 800)) {
        *(undefined4 *)(__ptr + 800) = 0;
        if (iVar2 == *(int *)(__ptr + 0x324)) goto _L0;
_L0:
        iVar4 = *(int *)(__ptr + 0x328);
        if (iVar4 == 1) {
          if (pmVar1 != (mdns_result_s *)0x0) {
            append_to_query_result(__ptr,pmVar1);
          }
          if ((*(int *)(__ptr + 800) == 0) && (*(int *)(__ptr + 0x324) == 0)) {
            if (*(char **)(__ptr + 0x300) != (char *)0x0) {
              pcVar3 = strchr(*(char **)(__ptr + 0x300),0x2e);
              esp_openthread_get_instance();
              otDnssdQueryHandleDiscoveredServiceInstance(pcVar3 + 1,__ptr + 0x300);
            }
_L0:
            free_addresses_in_pending_query(__ptr);
          }
        }
        else if (iVar4 == 2) {
          if (pmVar1 != (mdns_result_s *)0x0) {
            append_to_query_result(__ptr,pmVar1);
          }
          if ((*(int *)(__ptr + 800) == 0) && (*(int *)(__ptr + 0x324) == 0)) {
            if (__ptr[0x100] != (pending_query_t)0x0) {
              esp_openthread_get_instance();
              otDnssdQueryHandleDiscoveredHost(__ptr + 0x100,__ptr + 0x300);
            }
            goto _L0;
          }
        }
        else if (iVar4 == 0) {
          for (pmVar6 = pmVar1; pmVar6 != (mdns_result_s *)0x0; pmVar6 = *(mdns_result_s **)pmVar6)
          {
            append_to_query_result(__ptr,pmVar6);
            pcVar3 = strchr(*(char **)(__ptr + 0x300),0x2e);
            esp_openthread_get_instance();
            otDnssdQueryHandleDiscoveredServiceInstance(pcVar3 + 1,__ptr + 0x300);
            free_addresses_in_pending_query(__ptr);
            memset(__ptr + 0x300,0,0x20);
          }
        }
      }
      else if (iVar2 == *(int *)(__ptr + 0x324)) {
_L0:
        *(undefined4 *)(__ptr + 0x324) = 0;
        goto _L0;
      }
      if ((*(int *)(__ptr + 800) == 0) && (*(int *)(__ptr + 0x324) == 0)) {
        *(pending_query_t **)(puVar5 + 0x32c) = *(pending_query_t **)(__ptr + 0x32c);
        free(__ptr);
        __ptr = *(pending_query_t **)(puVar5 + 0x32c);
      }
      else {
        puVar5 = *(undefined1 **)(puVar5 + 0x32c);
        __ptr = *(pending_query_t **)(__ptr + 0x32c);
      }
    }
    mdns_query_results_free(pmStack_4c);
    mdns_query_async_delete(local_50);
  } while( true );
}

