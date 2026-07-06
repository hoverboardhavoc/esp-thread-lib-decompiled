/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
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
  mdns_result_s *pmVar3;
  int *__ptr_00;
  undefined4 uVar4;
  char *pcVar5;
  size_t __n;
  mdns_ip_addr_s *__ptr_01;
  int iVar6;
  undefined1 *puVar7;
  int *piVar8;
  mdns_ip_addr_s *pmVar9;
  mdns_result_s *pmStack_8c;
  undefined1 auStack_88 [8];
  mdns_result_s *apmStack_80 [19];
  
  if (0x3f < s_mdns_event_fd) {
    return 0;
  }
  if ((1 << (s_mdns_event_fd & 0x1f) & *(uint *)(param_2 + ((int)s_mdns_event_fd >> 5) * 4)) != 0) {
    read(s_mdns_event_fd,auStack_88,8);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    __ptr_00 = s_completed_searches_head;
    s_completed_searches_head = (int *)0x0;
    s_completed_searches_tail = 0;
    esp_openthread_task_switching_lock_release();
    while (__ptr_00 != (int *)0x0) {
      iVar6 = *__ptr_00;
      piVar8 = (int *)__ptr_00[1];
      pmStack_8c = (mdns_result_s *)0x0;
      free(__ptr_00);
      esp_openthread_task_switching_lock_release();
      mdns_query_async_get_results(iVar6,0xffffffff,&pmStack_8c,0);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      pmVar1 = pmStack_8c;
      __ptr = (pending_query_t *)s_pending_queries._1004_4_;
      puVar7 = s_pending_queries;
      while (__ptr != (pending_query_t *)0x0) {
        if (iVar6 != *(int *)(__ptr + 0x3e0)) {
          if (*(int *)(__ptr + 0x3e4) == iVar6) goto _L88;
          goto _L89;
        }
        *(undefined4 *)(__ptr + 0x3e0) = 0;
        if (*(int *)(__ptr + 0x3e4) == iVar6) {
_L88:
          *(undefined4 *)(__ptr + 0x3e4) = 0;
        }
        iVar2 = *(int *)(__ptr + 1000);
        if (iVar2 == 1) {
          apmStack_80[0] = (mdns_result_s *)0x0;
          pmVar3 = pmVar1;
          if (pmVar1 == (mdns_result_s *)0x0) {
            esp_openthread_task_switching_lock_release(0);
            iVar2 = mdns_lookup_selfhosted_service
                              (__ptr + 0x300,__ptr + 0x340,__ptr + 0x380,1,apmStack_80);
            esp_openthread_task_switching_lock_acquire(0xffffffff);
            pmVar3 = apmStack_80[0];
            if ((iVar2 == 0) && (apmStack_80[0] != (mdns_result_s *)0x0)) {
              uVar4 = get_openthread_netif_ip6_addr();
              *(undefined4 *)(pmVar3 + 0x30) = uVar4;
              pmVar3 = apmStack_80[0];
              goto _L139;
            }
          }
          else {
_L139:
            append_to_query_result(__ptr,pmVar3);
          }
          if ((*(int *)(__ptr + 0x3e0) == 0) && (*(int *)(__ptr + 0x3e4) == 0)) {
            if (*(char **)(__ptr + 0x3c0) != (char *)0x0) {
              pcVar5 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
              esp_openthread_get_instance();
              otDnssdQueryHandleDiscoveredServiceInstance(pcVar5 + 1,__ptr + 0x3c0);
            }
            free_addresses_in_pending_query(__ptr);
          }
_L100:
          if (apmStack_80[0] != (mdns_result_s *)0x0) {
            mdns_query_results_free_locked(apmStack_80[0]);
          }
        }
        else if (iVar2 == 2) {
          if (pmVar1 == (mdns_result_s *)0x0) {
            memset(apmStack_80,0,0x40);
            esp_openthread_task_switching_lock_release();
            iVar2 = mdns_hostname_get(apmStack_80);
            esp_openthread_task_switching_lock_acquire(0xffffffff);
            if (iVar2 == 0) {
              __n = strnlen((char *)apmStack_80,0x40);
              iVar2 = strncmp((char *)(__ptr + 0x300),(char *)apmStack_80,__n);
              if (iVar2 == 0) {
                snprintf((char *)(__ptr + 0x100),0x100,"%s%s");
                __ptr_01 = (mdns_ip_addr_s *)get_openthread_netif_ip6_addr();
                iVar2 = get_mdns_num_ipv6_addresses(__ptr_01);
                __ptr[0x3c0] = SUB41(iVar2,0);
                *(undefined4 *)(__ptr + 0x3c8) = 0x78;
                if (iVar2 != 0) {
                  uVar4 = convert_mdns_addresses_to_array(__ptr_01);
                  *(undefined4 *)(__ptr + 0x3c4) = uVar4;
                }
                while (__ptr_01 != (mdns_ip_addr_s *)0x0) {
                  pmVar9 = *(mdns_ip_addr_s **)(__ptr_01 + 0x18);
                  free(__ptr_01);
                  __ptr_01 = pmVar9;
                }
              }
            }
          }
          else {
            append_to_query_result(__ptr,pmVar1);
          }
          if ((*(int *)(__ptr + 0x3e0) == 0) && (*(int *)(__ptr + 0x3e4) == 0)) {
            if (__ptr[0x100] != (pending_query_t)0x0) {
              esp_openthread_get_instance();
              otDnssdQueryHandleDiscoveredHost(__ptr + 0x100,__ptr + 0x3c0);
            }
            free_addresses_in_pending_query(__ptr);
          }
        }
        else if (iVar2 == 0) {
          apmStack_80[0] = (mdns_result_s *)0x0;
          iVar2 = 0;
          for (pmVar3 = pmVar1; pmVar3 != (mdns_result_s *)0x0; pmVar3 = *(mdns_result_s **)pmVar3)
          {
            append_to_query_result(__ptr,pmVar3);
            iVar2 = iVar2 + 1;
            pcVar5 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
            esp_openthread_get_instance();
            otDnssdQueryHandleDiscoveredServiceInstance(pcVar5 + 1,__ptr + 0x3c0);
            free_addresses_in_pending_query(__ptr);
            memset(__ptr + 0x3c0,0,0x20);
          }
          esp_openthread_task_switching_lock_release();
          iVar2 = mdns_lookup_selfhosted_service
                            (0,__ptr + 0x340,__ptr + 0x380,5 - iVar2,apmStack_80);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          if (iVar2 != 0) goto _L89;
          for (pmVar3 = apmStack_80[0]; pmVar3 != (mdns_result_s *)0x0;
              pmVar3 = *(mdns_result_s **)pmVar3) {
            uVar4 = get_openthread_netif_ip6_addr();
            *(undefined4 *)(pmVar3 + 0x30) = uVar4;
            append_to_query_result(__ptr,pmVar3);
            pcVar5 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
            esp_openthread_get_instance();
            otDnssdQueryHandleDiscoveredServiceInstance(pcVar5 + 1,__ptr + 0x3c0);
            free_addresses_in_pending_query(__ptr);
            memset(__ptr + 0x3c0,0,0x20);
          }
          goto _L100;
        }
_L89:
        if ((*(int *)(__ptr + 0x3e0) == 0) && (*(int *)(__ptr + 0x3e4) == 0)) {
          *(pending_query_t **)(puVar7 + 0x3ec) = *(pending_query_t **)(__ptr + 0x3ec);
          free(__ptr);
          __ptr = *(pending_query_t **)(puVar7 + 0x3ec);
        }
        else {
          puVar7 = *(undefined1 **)(puVar7 + 0x3ec);
          __ptr = *(pending_query_t **)(__ptr + 0x3ec);
        }
      }
      mdns_query_results_free_locked(pmStack_8c);
      esp_openthread_task_switching_lock_release();
      mdns_query_async_delete(iVar6);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      __ptr_00 = piVar8;
    }
  }
  return 0;
}

