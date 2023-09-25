/*
 * Last changed at upstream commit 12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * https://github.com/espressif/esp-thread-lib/commit/12f563ee490236f7332eb22f568e71c7c1d4a3b7
 * Upstream date: 2023-09-25 16:27:03 +0800
 * Upstream subject: lib(openthread): update otbr lib
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
  int iVar4;
  undefined4 uVar5;
  char *pcVar6;
  size_t __n;
  mdns_ip_addr_s *__ptr_00;
  undefined1 *puVar7;
  mdns_ip_addr_s *pmVar8;
  int iStack_90;
  mdns_result_s *pmStack_8c;
  undefined1 auStack_88 [8];
  mdns_result_s *pmStack_80;
  undefined1 auStack_7c [72];
  
  if ((0x3f < s_mdns_event_fd) ||
     ((1 << (s_mdns_event_fd & 0x1f) & *(uint *)(param_2 + ((int)s_mdns_event_fd >> 5) * 4)) == 0))
  {
    return 0;
  }
  read(s_mdns_event_fd,auStack_88,8);
  do {
    iVar4 = xQueueReceive(s_mdns_result_queue,&iStack_90,0);
    if (iVar4 != 1) {
      return 0;
    }
    mdns_query_async_get_results(iStack_90,0xffffffff,&pmStack_8c,0);
    pmVar1 = pmStack_8c;
    iVar4 = iStack_90;
    puVar7 = s_pending_queries;
    __ptr = (pending_query_t *)s_pending_queries._1004_4_;
    while (__ptr != (pending_query_t *)0x0) {
      if (iVar4 != *(int *)(__ptr + 0x3e0)) {
        if (*(int *)(__ptr + 0x3e4) == iVar4) goto _L0;
        goto _L0;
      }
      *(undefined4 *)(__ptr + 0x3e0) = 0;
      if (*(int *)(__ptr + 0x3e4) == iVar4) {
_L0:
        *(undefined4 *)(__ptr + 0x3e4) = 0;
      }
      iVar2 = *(int *)(__ptr + 1000);
      if (iVar2 == 1) {
        pmStack_80 = (mdns_result_s *)0x0;
        pmVar3 = pmVar1;
        if (pmVar1 == (mdns_result_s *)0x0) {
          iVar2 = mdns_lookup_selfhosted_service
                            (__ptr + 0x300,__ptr + 0x340,__ptr + 0x380,1,&pmStack_80);
          pmVar3 = pmStack_80;
          if ((iVar2 == 0) && (pmStack_80 != (mdns_result_s *)0x0)) {
            uVar5 = get_openthread_netif_ip6_addr();
            *(undefined4 *)(pmVar3 + 0x30) = uVar5;
            pmVar3 = pmStack_80;
            goto _L0;
          }
        }
        else {
_L0:
          append_to_query_result(__ptr,pmVar3);
        }
        if ((*(int *)(__ptr + 0x3e0) == 0) && (*(int *)(__ptr + 0x3e4) == 0)) {
          if (*(char **)(__ptr + 0x3c0) != (char *)0x0) {
            pcVar6 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
            esp_openthread_get_instance();
            otDnssdQueryHandleDiscoveredServiceInstance(pcVar6 + 1,__ptr + 0x3c0);
          }
          free_addresses_in_pending_query(__ptr);
        }
_L0:
        if (pmStack_80 != (mdns_result_s *)0x0) {
          mdns_query_results_free();
        }
      }
      else if (iVar2 == 2) {
        if (pmVar1 == (mdns_result_s *)0x0) {
          pmStack_80 = (mdns_result_s *)0x0;
          memset(auStack_7c,0,0x3c);
          iVar2 = mdns_hostname_get(&pmStack_80);
          if (iVar2 == 0) {
            __n = strnlen((char *)&pmStack_80,0x40);
            iVar2 = strncmp((char *)(__ptr + 0x300),(char *)&pmStack_80,__n);
            if (iVar2 == 0) {
              snprintf((char *)(__ptr + 0x100),0x100,"%s%s");
              __ptr_00 = (mdns_ip_addr_s *)get_openthread_netif_ip6_addr();
              iVar2 = get_mdns_num_ipv6_addresses(__ptr_00);
              __ptr[0x3c0] = SUB41(iVar2,0);
              *(undefined4 *)(__ptr + 0x3c8) = 0x78;
              if (iVar2 != 0) {
                uVar5 = convert_mdns_addresses_to_array(__ptr_00);
                *(undefined4 *)(__ptr + 0x3c4) = uVar5;
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
      else if (iVar2 == 0) {
        pmStack_80 = (mdns_result_s *)0x0;
        iVar2 = 0;
        for (pmVar3 = pmVar1; pmVar3 != (mdns_result_s *)0x0; pmVar3 = *(mdns_result_s **)pmVar3) {
          append_to_query_result(__ptr,pmVar3);
          iVar2 = iVar2 + 1;
          pcVar6 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
          esp_openthread_get_instance();
          otDnssdQueryHandleDiscoveredServiceInstance(pcVar6 + 1,__ptr + 0x3c0);
          free_addresses_in_pending_query(__ptr);
          memset(__ptr + 0x3c0,0,0x20);
        }
        iVar2 = mdns_lookup_selfhosted_service(0,__ptr + 0x340,__ptr + 0x380,5 - iVar2,&pmStack_80);
        if (iVar2 != 0) goto _L0;
        for (pmVar3 = pmStack_80; pmVar3 != (mdns_result_s *)0x0; pmVar3 = *(mdns_result_s **)pmVar3
            ) {
          uVar5 = get_openthread_netif_ip6_addr();
          *(undefined4 *)(pmVar3 + 0x30) = uVar5;
          append_to_query_result(__ptr,pmVar3);
          pcVar6 = strchr(*(char **)(__ptr + 0x3c0),0x2e);
          esp_openthread_get_instance();
          otDnssdQueryHandleDiscoveredServiceInstance(pcVar6 + 1,__ptr + 0x3c0);
          free_addresses_in_pending_query(__ptr);
          memset(__ptr + 0x3c0,0,0x20);
        }
        goto _L0;
      }
_L0:
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
    mdns_query_results_free(pmStack_8c);
    mdns_query_async_delete(iStack_90);
  } while( true );
}

