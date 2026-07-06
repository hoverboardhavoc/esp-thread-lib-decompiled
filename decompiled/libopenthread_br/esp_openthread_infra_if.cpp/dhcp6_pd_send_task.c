/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_infra_if.cpp.o -> dhcp6_pd_send_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* dhcp6_pd_send_task(void*) */

undefined4 dhcp6_pd_send_task(void *param_1)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  undefined1 uStack_18;
  undefined1 uStack_14;
  
                    /* WARNING: Load size is inaccurate */
  uVar1 = otMessageGetLength(*param_1);
  iVar2 = pbuf_alloc(0x4a,uVar1,0x280);
  if (iVar2 == 0) {
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to allocate send pbuf\n",uVar1,
            "dhcp6_pd_send_task",0x180);
    uVar1 = 0x101;
  }
  else {
                    /* WARNING: Load size is inaccurate */
    otMessageRead(*param_1,0,*(undefined4 *)(iVar2 + 4),uVar1);
    uVar1 = s_dhcp6_pd_pcb;
    uStack_28 = *(undefined4 *)((int)param_1 + 4);
    uStack_24 = *(undefined4 *)((int)param_1 + 8);
    uStack_20 = *(undefined4 *)((int)param_1 + 0xc);
    uStack_1c = *(undefined4 *)((int)param_1 + 0x10);
    uStack_18 = *(undefined1 *)((int)param_1 + 0x14);
    uStack_14 = 6;
    uVar3 = netif_get_by_index(*(undefined1 *)((int)param_1 + 0x18));
    iVar4 = udp_sendto_if(uVar1,iVar2,&uStack_28,0x223,uVar3);
    uVar1 = 0;
    if (iVar4 == 0) goto _L57;
    uVar1 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): UDP send failed: %d\n",uVar1,"dhcp6_pd_send_task",
            0x18a,iVar4);
    uVar1 = 0xffffffff;
  }
  uVar3 = esp_log_timestamp();
  esp_log(1,"OPENTHREAD","E (%lu) %s: Finished dhcp6_pd_send_task with some errors\n",uVar3);
_L57:
  pbuf_free(iVar2);
                    /* WARNING: Load size is inaccurate */
  otMessageFree(*param_1);
  return uVar1;
}

