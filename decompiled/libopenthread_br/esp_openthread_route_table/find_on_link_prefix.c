/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_br -> esp_openthread_route_table.o -> find_on_link_prefix
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 * find_on_link_prefix(int param_1,void *param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  while( true ) {
    if (9 < uVar1) {
      return (undefined4 *)0x0;
    }
    if ((((&s_on_link_prefixes)[uVar1 * 8] == param_1) &&
        ((byte)(&DAT_0001072c)[uVar1 * 0x20] == param_3)) &&
       (iVar2 = memcmp(&DAT_00010718 + uVar1 * 0x20,param_2,param_3 >> 3), iVar2 == 0)) break;
    uVar1 = uVar1 + 1;
  }
  return &s_on_link_prefixes + uVar1 * 8;
}

