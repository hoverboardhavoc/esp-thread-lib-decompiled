/*
 * Last changed at upstream commit 55f18e4cc6a249974247fd408aad79b1049d4b31
 * https://github.com/espressif/esp-thread-lib/commit/55f18e4cc6a249974247fd408aad79b1049d4b31
 * Upstream date: 2024-11-01 17:03:49 +0800
 * Upstream subject: feat(br): update br lib
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
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  size_t __n;
  mdns_ip_addr_s *__ptr_00;
  int iVar6;
  mdns_result_s *pmVar7;
  mdns_ip_addr_s *pmVar8;
  int local_90;
  mdns_result_s *pmStack_8c;
  undefined1 auStack_88 [8];
  mdns_result_s *apmStack_80 [19];
  
  if (0x3f < s_mdns_event_fd) {
    return 0;
  }
  if ((1 << (s_mdns_event_fd & 0x1f) & *(uint *)(param_2 + ((int)s_mdns_event_fd >> 5) * 4)) != 0) {
    read(s_mdns_event_fd,auStack_88,8);
    while (iVar3 = xQueueReceive(s_mdns_result_queue,&local_90,0), iVar3 == 1) {
      mdns_query_async_get_results(local_90,0xffffffff,&pmStack_8c,0);
      pmVar1 = pmStack_8c;
      iVar3 = local_90;
      puVar2 = s_pending_queries;
      __ptr = (pending_query_t *)s_pending_queries._1004_4_;
      while (__ptr != (pending_query_t *)0x0) {
        if (iVar3 != *(int *)(__ptr + 0x3e0)) {
          if (iVar3 == *(int *)(__ptr + 0x3e4)) goto _L0;
          goto _L0;
        }
        *(undefined4 *)(__ptr + 0x3e0) = 0;
        if (iVar3 == *(int *)(__ptr + 0x3e4)) {
_L0:
          *(undefined4 *)(__ptr + 0x3e4) = 0;
        }
        iVar6 = *(int *)(__ptr + 1000);
        if (iVar6 == 1) {
          apmStack_80[0] = (mdns_result_s *)0x0;
          pmVar7 = pmVar1;
          if (pmVar1 == (mdns_result_s *)0x0) {
            iVar6 = mdns_lookup_selfhosted_service
                              (__ptr + 0x300,__ptr + 0x340,__ptr + 0x380,1,apmStack_80);
            pmVar7 = apmStack_80[0];
            if ((iVar6 == 0) && (apmStack_80[0] != (mdns_result_s *)0x0)) {
              uVar4 = get_openthread_netif_ip6_addr();
              *(undefined4 *)(pmVar7 + 0x30) = uVar4;
              pmVar7 = apmStack_80[0];
              goto _L0;
            }
          }
          else {
_L0:
            append_to_query_result(__ptr,pmVar7);
          }
          if ((*(int *)(__ptr + 0x3e0) == 0) && (*(int *)(__ptr + 0x3e4) == 0)) {
            if (*(char **)(__ptr + 0x3c0) != (char *)0x0) {
              pcVar5 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
              esp_openthread_get_instance();
              otDnssdQueryHandleDiscoveredServiceInstance(pcVar5 + 1,__ptr + 0x3c0);
            }
            free_addresses_in_pending_query(__ptr);
          }
_L0:
          if (apmStack_80[0] != (mdns_result_s *)0x0) {
            mdns_query_results_free();
          }
        }
        else if (iVar6 == 2) {
          if (pmVar1 == (mdns_result_s *)0x0) {
            memset(apmStack_80,0,0x40);
            iVar6 = mdns_hostname_get(apmStack_80);
            if (iVar6 == 0) {
              __n = strnlen((char *)apmStack_80,0x40);
              iVar6 = strncmp((char *)(__ptr + 0x300),(char *)apmStack_80,__n);
              if (iVar6 == 0) {
                snprintf((char *)(__ptr + 0x100),0x100,"%s%s");
                __ptr_00 = (mdns_ip_addr_s *)get_openthread_netif_ip6_addr();
                iVar6 = get_mdns_num_ipv6_addresses(__ptr_00);
                __ptr[0x3c0] = SUB41(iVar6,0);
                *(undefined4 *)(__ptr + 0x3c8) = 0x78;
                if (iVar6 != 0) {
                  uVar4 = convert_mdns_addresses_to_array(__ptr_00);
                  *(undefined4 *)(__ptr + 0x3c4) = uVar4;
                }
                while (__ptr_00 != (mdns_ip_addr_s *)0x0) {
                  pmVar8 = *(mdns_ip_addr_s **)(__ptr_00 + 0x18);
                  free(__ptr_00);
                  __ptr_00 = pmVar8;
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
        else if (iVar6 == 0) {
          apmStack_80[0] = (mdns_result_s *)0x0;
          iVar6 = 0;
          for (pmVar7 = pmVar1; pmVar7 != (mdns_result_s *)0x0; pmVar7 = *(mdns_result_s **)pmVar7)
          {
            append_to_query_result(__ptr,pmVar7);
            iVar6 = iVar6 + 1;
            pcVar5 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
            esp_openthread_get_instance();
            otDnssdQueryHandleDiscoveredServiceInstance(pcVar5 + 1,__ptr + 0x3c0);
            free_addresses_in_pending_query(__ptr);
            memset(__ptr + 0x3c0,0,0x20);
          }
          iVar6 = mdns_lookup_selfhosted_service
                            (0,__ptr + 0x340,__ptr + 0x380,5 - iVar6,apmStack_80);
          if (iVar6 != 0) goto _L0;
          for (pmVar7 = apmStack_80[0]; pmVar7 != (mdns_result_s *)0x0;
              pmVar7 = *(mdns_result_s **)pmVar7) {
            uVar4 = get_openthread_netif_ip6_addr();
            *(undefined4 *)(pmVar7 + 0x30) = uVar4;
            append_to_query_result(__ptr,pmVar7);
            pcVar5 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
            esp_openthread_get_instance();
            otDnssdQueryHandleDiscoveredServiceInstance(pcVar5 + 1,__ptr + 0x3c0);
            free_addresses_in_pending_query(__ptr);
            memset(__ptr + 0x3c0,0,0x20);
          }
          goto _L0;
        }
_L0:
        if ((*(int *)(__ptr + 0x3e0) == 0) && (*(int *)(__ptr + 0x3e4) == 0)) {
          *(pending_query_t **)(puVar2 + 0x3ec) = *(pending_query_t **)(__ptr + 0x3ec);
          free(__ptr);
          __ptr = *(pending_query_t **)(puVar2 + 0x3ec);
        }
        else {
          puVar2 = *(undefined1 **)(puVar2 + 0x3ec);
          __ptr = *(pending_query_t **)(__ptr + 0x3ec);
        }
      }
      mdns_query_results_free(pmStack_8c);
      mdns_query_async_delete(local_90);
    }
  }
  return 0;
}

