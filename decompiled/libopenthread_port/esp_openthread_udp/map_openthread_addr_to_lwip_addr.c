/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_udp.o -> map_openthread_addr_to_lwip_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int * map_openthread_addr_to_lwip_addr(int *param_1,void *param_2)

{
  int iStack_28;
  int iStack_24;
  int iStack_20;
  int iStack_1c;
  uint uStack_18;
  int iStack_14;
  
  memcpy(&iStack_28,param_2,0x10);
  if (((iStack_28 == 0) && (iStack_24 == 0)) && (iStack_20 == -0x10000)) {
    iStack_28 = iStack_1c;
    iStack_14 = (uint)iStack_14._1_3_ << 8;
  }
  else {
    iStack_14 = CONCAT31(iStack_14._1_3_,6);
    uStack_18 = uStack_18 & 0xffffff00;
  }
  *param_1 = iStack_28;
  param_1[1] = iStack_24;
  param_1[2] = iStack_20;
  param_1[3] = iStack_1c;
  param_1[4] = uStack_18;
  param_1[5] = iStack_14;
  return param_1;
}

