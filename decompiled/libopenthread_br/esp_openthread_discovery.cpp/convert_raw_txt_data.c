/*
 * Last changed at upstream commit ea50a6be280755ad026c0b1774efe61c48171ad6
 * https://github.com/espressif/esp-thread-lib/commit/ea50a6be280755ad026c0b1774efe61c48171ad6
 * Upstream date: 2021-09-03 15:31:55 +0800
 * Upstream subject: br: add discovery delegate(f7cecf0)
 * Source: libopenthread_br -> esp_openthread_discovery.cpp.o -> convert_raw_txt_data
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* convert_raw_txt_data(mdns_result_s const*, unsigned char*, unsigned short) */

uint convert_raw_txt_data(mdns_result_s *param_1,uchar *param_2,ushort param_3)

{
  uint uVar1;
  uint uVar2;
  size_t __n;
  size_t __n_00;
  undefined2 in_register_00002032;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  
  uVar5 = 0;
  uVar2 = 0;
  while( true ) {
    if (*(uint *)(param_1 + 0x2c) <= uVar5) {
      return uVar2;
    }
    puVar4 = (undefined4 *)(*(int *)(param_1 + 0x24) + uVar5 * 8);
    __n = strnlen((char *)*puVar4,0x40);
    uVar1 = __n;
    if ((char *)puVar4[1] == (char *)0x0) {
      __n_00 = 0;
    }
    else {
      __n_00 = strnlen((char *)puVar4[1],0x40);
      if (__n_00 != 0) {
        uVar1 = (__n + __n_00 & 0xff) + 1;
      }
    }
    uVar3 = uVar2 + (uVar1 & 0xff);
    if (CONCAT22(in_register_00002032,param_3) < (int)uVar3) break;
    uVar2 = (uVar3 & 0xffff) + 1 & 0xffff;
    *param_2 = (uchar)uVar1;
    memcpy(param_2 + 1,(void *)*puVar4,__n);
    param_2 = param_2 + 1 + __n;
    if (__n_00 != 0) {
      *param_2 = '=';
      memcpy(param_2 + 1,(void *)puVar4[1],__n_00);
      param_2 = param_2 + 1 + __n_00;
    }
    uVar5 = uVar5 + 1;
  }
  return uVar2;
}

