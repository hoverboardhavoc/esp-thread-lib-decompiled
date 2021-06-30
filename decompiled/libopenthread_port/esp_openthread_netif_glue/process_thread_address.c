/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_netif_glue.o -> process_thread_address
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: addr */
/* WARNING: Unknown calling convention */

void process_thread_address(otIp6AddressInfo *address_info,_Bool is_added,void *context)

{
  uint8_t uVar1;
  int iVar2;
  undefined3 in_register_0000202d;
  undefined4 uStack_3c;
  ip_event_add_ip6_t add_addr;
  esp_ip6_addr_t addr;
  
  uVar1 = (address_info->mAddress->mFields).m8[0];
  memcpy(&add_addr.preferred,address_info->mAddress,0x10);
  if (CONCAT31(in_register_0000202d,is_added) == 0) {
    if (uVar1 == 0xff) {
      iVar2 = esp_event_post(OPENTHREAD_EVENT,7,&add_addr.preferred,0x14,0);
      if (iVar2 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread leave multicast group event");
      }
    }
    else {
      iVar2 = esp_event_post(OPENTHREAD_EVENT,5,&add_addr.preferred,0x14,0);
      if (iVar2 != 0) {
        otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread lost ip6 address event");
      }
    }
  }
  else if (uVar1 == 0xff) {
    iVar2 = esp_event_post(OPENTHREAD_EVENT,6,&add_addr.preferred,0x14,0);
    if (iVar2 != 0) {
      otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread join multicast group event");
    }
  }
  else {
    uStack_3c._0_1_ = add_addr.preferred;
    uStack_3c._1_3_ = add_addr._21_3_;
    add_addr.addr.zone = (byte)(*(uint *)&address_info->mPrefixLength >> 0xc) & 1;
    iVar2 = esp_event_post(OPENTHREAD_EVENT,4,&uStack_3c,0x18,0);
    if (iVar2 != 0) {
      otLogCrit(0xc,"-PLAT----: ","Failed to post OpenThread got ip6 address event");
    }
  }
  return;
}

