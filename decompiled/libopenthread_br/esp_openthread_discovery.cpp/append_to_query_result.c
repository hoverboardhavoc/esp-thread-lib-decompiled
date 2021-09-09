/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> append_to_query_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* append_to_query_result(pending_query_t*, mdns_result_s*) */

void append_to_query_result(pending_query_t *param_1,mdns_result_s *param_2)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  size_t __n;
  size_t __n_00;
  pending_query_t *ppVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  
  if (*(int *)(param_2 + 0x1c) != 0) {
    snprintf((char *)(param_1 + 0x100),0x100,"%s%s");
    if (*(int *)(param_1 + 0x328) == 2) {
      iVar2 = get_mdns_num_ipv6_addresses(*(mdns_result_s **)(param_2 + 0x30));
      param_1[0x300] = SUB41(iVar2,0);
      *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_2 + 8);
      if (iVar2 != 0) {
        uVar3 = convert_mdns_addresses_to_array(param_2);
        *(undefined4 *)(param_1 + 0x304) = uVar3;
      }
    }
    else {
      *(pending_query_t **)(param_1 + 0x304) = param_1 + 0x100;
      iVar2 = get_mdns_num_ipv6_addresses(*(mdns_result_s **)(param_2 + 0x30));
      param_1[0x308] = SUB41(iVar2,0);
      if (iVar2 != 0) {
        uVar3 = convert_mdns_addresses_to_array(param_2);
        *(undefined4 *)(param_1 + 0x30c) = uVar3;
      }
    }
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    uVar6 = 0;
    ppVar4 = param_1 + 0x200;
    for (uVar7 = 0; uVar7 < *(uint *)(param_2 + 0x2c); uVar7 = uVar7 + 1) {
      puVar5 = (undefined4 *)(uVar7 * 8 + *(int *)(param_2 + 0x24));
      __n = strnlen((char *)*puVar5,0x40);
      if (((char *)puVar5[1] == (char *)0x0) ||
         (__n_00 = strnlen((char *)puVar5[1],0x40), __n_00 == 0)) {
        __n_00 = 0;
        uVar1 = __n;
      }
      else {
        uVar1 = __n + 1 + __n_00;
      }
      if (0x100 < uVar6 + (uVar1 & 0xff)) break;
      *ppVar4 = SUB41(uVar1,0);
      uVar6 = uVar6 + (uVar1 & 0xff) + 1 & 0xffff;
      memcpy(ppVar4 + 1,(void *)*puVar5,__n);
      ppVar4 = ppVar4 + 1 + __n;
      if (__n_00 != 0) {
        *ppVar4 = (pending_query_t)0x3d;
        memcpy(ppVar4 + 1,(void *)puVar5[1],__n_00);
        ppVar4 = ppVar4 + 1 + __n_00;
      }
    }
    *(short *)(param_1 + 0x316) = (short)uVar6;
    *(pending_query_t **)(param_1 + 0x318) = param_1 + 0x200;
  }
  if (*(int *)(param_2 + 0x18) != 0) {
    snprintf((char *)param_1,0x100,"%s.%s.%s%s");
    *(pending_query_t **)(param_1 + 0x300) = param_1;
    *(undefined2 *)(param_1 + 0x310) = *(undefined2 *)(param_2 + 0x20);
    *(undefined4 *)(param_1 + 0x31c) = *(undefined4 *)(param_2 + 8);
  }
  return;
}

