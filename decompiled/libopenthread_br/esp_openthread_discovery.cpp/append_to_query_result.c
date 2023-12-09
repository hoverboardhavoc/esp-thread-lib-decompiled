/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> append_to_query_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* append_to_query_result(pending_query_t*, mdns_result_s*) */

void append_to_query_result(pending_query_t *param_1,mdns_result_s *param_2)

{
  mdns_ip_addr_s *pmVar1;
  int iVar2;
  undefined4 uVar3;
  size_t __n;
  pending_query_t *ppVar4;
  uint uVar5;
  uint uVar6;
  undefined4 *puVar7;
  uint uVar8;
  size_t __n_00;
  
  if (*(int *)(param_2 + 0x1c) != 0) {
    snprintf((char *)(param_1 + 0x100),0x100,"%s%s");
    pmVar1 = *(mdns_ip_addr_s **)(param_2 + 0x30);
    if (*(int *)(param_1 + 1000) == 2) {
      iVar2 = get_mdns_num_ipv6_addresses(pmVar1);
      param_1[0x3c0] = SUB41(iVar2,0);
      *(undefined4 *)(param_1 + 0x3c8) = *(undefined4 *)(param_2 + 8);
      if (iVar2 != 0) {
        uVar3 = convert_mdns_addresses_to_array(*(mdns_ip_addr_s **)(param_2 + 0x30));
        *(undefined4 *)(param_1 + 0x3c4) = uVar3;
      }
    }
    else {
      *(pending_query_t **)(param_1 + 0x3c4) = param_1 + 0x100;
      iVar2 = get_mdns_num_ipv6_addresses(pmVar1);
      param_1[0x3c8] = SUB41(iVar2,0);
      if (iVar2 != 0) {
        uVar3 = convert_mdns_addresses_to_array(*(mdns_ip_addr_s **)(param_2 + 0x30));
        *(undefined4 *)(param_1 + 0x3cc) = uVar3;
      }
    }
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    uVar6 = 0;
    ppVar4 = param_1 + 0x200;
    for (uVar8 = 0; uVar8 < *(uint *)(param_2 + 0x2c); uVar8 = uVar8 + 1) {
      puVar7 = (undefined4 *)(*(int *)(param_2 + 0x24) + uVar8 * 8);
      __n_00 = 0;
      __n = strnlen((char *)*puVar7,0x40);
      uVar5 = __n & 0xff;
      if (((char *)puVar7[1] != (char *)0x0) &&
         (__n_00 = strnlen((char *)puVar7[1],0x40), __n_00 != 0)) {
        uVar5 = uVar5 + 1 + __n_00 & 0xff;
      }
      if (0x100 < uVar6 + uVar5) break;
      *ppVar4 = SUB41(uVar5,0);
      uVar6 = uVar6 + 1 + uVar5 & 0xffff;
      memcpy(ppVar4 + 1,(void *)*puVar7,__n);
      ppVar4 = ppVar4 + 1 + __n;
      if (__n_00 != 0) {
        *ppVar4 = (pending_query_t)0x3d;
        memcpy(ppVar4 + 1,(void *)puVar7[1],__n_00);
        ppVar4 = ppVar4 + 1 + __n_00;
      }
    }
    *(short *)(param_1 + 0x3d6) = (short)uVar6;
    *(pending_query_t **)(param_1 + 0x3d8) = param_1 + 0x200;
  }
  if (*(int *)(param_2 + 0x18) != 0) {
    snprintf((char *)param_1,0x100,"%s.%s.%s%s");
    *(pending_query_t **)(param_1 + 0x3c0) = param_1;
    *(undefined2 *)(param_1 + 0x3d0) = *(undefined2 *)(param_2 + 0x20);
    *(undefined4 *)(param_1 + 0x3dc) = *(undefined4 *)(param_2 + 8);
  }
  return;
}

