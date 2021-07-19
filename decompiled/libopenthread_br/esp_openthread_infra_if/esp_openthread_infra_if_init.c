/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> esp_openthread_infra_if_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_infra_if_init(int param_1)

{
  int iVar1;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  uStack_28 = 0x2ff;
  uStack_24 = 0;
  uStack_20 = 0;
  uStack_1c = 0x2000000;
  uStack_18 = 0;
  uStack_14 = 6;
  if (s_raw_pcb == 0) {
    if (param_1 == 0) {
      iVar1 = 0x102;
    }
    else {
      iVar1 = mld6_joingroup_netif(&uStack_28);
      if (iVar1 == 0) {
        iVar1 = raw_new_ip_type(6,0x3a);
        s_raw_pcb = iVar1;
        *(byte *)(iVar1 + 0x39) = *(byte *)(iVar1 + 0x39) | 4;
        *(undefined1 *)(iVar1 + 0x46) = 1;
        *(undefined2 *)(iVar1 + 0x44) = 2;
        raw_bind_netif(param_1);
        raw_recv(s_raw_pcb,icmp6_raw_recv_handler,param_1);
        netif_set_status_callback(param_1,0x10000);
        s_netif = param_1;
        esp_openthread_get_instance();
        iVar1 = otBorderRoutingInit(*(char *)(param_1 + 0x196) + '\x01',
                                    *(byte *)(param_1 + 0x193) & 1);
        if (iVar1 == 0) {
          esp_openthread_get_instance();
          iVar1 = otBorderRoutingSetEnabled(1);
          if (iVar1 != 0) {
            iVar1 = -1;
          }
        }
        else {
          iVar1 = -1;
        }
      }
      else {
        iVar1 = -1;
      }
    }
  }
  else {
    iVar1 = 0x103;
  }
  return iVar1;
}

