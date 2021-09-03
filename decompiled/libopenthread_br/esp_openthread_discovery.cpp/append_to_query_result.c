/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> append_to_query_result
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* append_to_query_result(pending_query_t*, mdns_result_s*) */

void append_to_query_result(pending_query_t *param_1,mdns_result_s *param_2)

{
  undefined2 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  if (*(int *)(param_2 + 0x1c) != 0) {
    snprintf((char *)(param_1 + 0x100),0x100,"%s%s");
    if (*(int *)(param_1 + 0x328) == 2) {
      iVar2 = get_mdns_num_ipv6_addresses(param_2);
      param_1[0x300] = SUB41(iVar2,0);
      *(undefined4 *)(param_1 + 0x308) = *(undefined4 *)(param_2 + 8);
      if (iVar2 != 0) {
        uVar3 = convert_mdns_addresses_to_array(param_2);
        *(undefined4 *)(param_1 + 0x304) = uVar3;
      }
    }
    else {
      *(pending_query_t **)(param_1 + 0x304) = param_1 + 0x100;
      iVar2 = get_mdns_num_ipv6_addresses(param_2);
      param_1[0x308] = SUB41(iVar2,0);
      if (iVar2 != 0) {
        uVar3 = convert_mdns_addresses_to_array(param_2);
        *(undefined4 *)(param_1 + 0x30c) = uVar3;
      }
    }
  }
  if (*(int *)(param_2 + 0x24) != 0) {
    uVar1 = convert_raw_txt_data(param_2,(uchar *)(param_1 + 0x200),0x100);
    *(undefined2 *)(param_1 + 0x316) = uVar1;
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

