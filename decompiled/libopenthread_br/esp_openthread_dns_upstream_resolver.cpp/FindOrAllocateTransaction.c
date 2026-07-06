/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> FindOrAllocateTransaction
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Type propagation algorithm not settling */
/* Resolver::FindOrAllocateTransaction(otPlatDnsUpstreamQuery*, unsigned char) */

undefined4 * __thiscall
Resolver::FindOrAllocateTransaction(Resolver *this,otPlatDnsUpstreamQuery *param_1,uchar param_2)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  undefined3 in_register_00002031;
  otPlatDnsUpstreamQuery *poVar7;
  uint uVar8;
  uint uVar9;
  uint auStack_40 [2];
  undefined1 auStack_38 [20];
  
  iVar6 = CONCAT31(in_register_00002031,param_2);
  uVar8 = *(uint *)(this + 4);
  iVar1 = esp_openthread_get_backbone_netif();
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    esp_log(1,"Resolver","E (%lu) %s: Backbone netif not set\n",uVar2);
    return (undefined4 *)0x0;
  }
  auStack_40[0] = 0;
  auStack_40[1] = 4;
  for (uVar9 = 0; uVar9 < *(uint *)(this + 4); uVar9 = uVar9 + 1) {
    iVar4 = uVar9 * 8;
    poVar7 = *(otPlatDnsUpstreamQuery **)(*(int *)this + iVar4);
    if ((poVar7 == (otPlatDnsUpstreamQuery *)0x0) ||
       ((int)((undefined4 *)(*(int *)this + iVar4))[1] < 0)) {
      if (uVar9 < uVar8) {
        uVar8 = uVar9;
      }
    }
    else if (poVar7 == param_1) {
      esp_openthread_task_switching_lock_release();
      lwip_getsockopt(*(undefined4 *)(*(int *)this + iVar4 + 4),0x29,0x1b,auStack_40,auStack_40 + 1)
      ;
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      if ((iVar6 == 10) == auStack_40[0]) {
        return (undefined4 *)(*(int *)this + iVar4);
      }
    }
  }
  if (*(uint *)(this + 4) == uVar8) {
    if (uVar8 < 0x10) {
      uVar3 = *(undefined4 *)this;
      uVar2 = esp_openthread_get_alloc_caps();
      iVar4 = heap_caps_realloc(uVar3,(uVar8 + 1) * 8,uVar2);
      if (iVar4 != 0) {
        *(int *)this = iVar4;
        *(int *)(this + 4) = *(int *)(this + 4) + 1;
        puVar5 = (undefined4 *)(iVar4 + uVar8 * 8);
        puVar5[1] = 0xffffffff;
        *puVar5 = 0;
        goto _L15;
      }
      uVar3 = esp_log_timestamp();
      uVar2 = 0xca;
    }
    else {
      uVar3 = esp_log_timestamp();
      uVar2 = 0xc6;
    }
    esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to allocate new transaction\n",uVar3,
            "FindOrAllocateTransaction",uVar2);
  }
  else {
_L15:
    esp_openthread_task_switching_lock_release();
    uVar2 = 0;
    if (iVar6 == 10) {
      uVar2 = 0x29;
    }
    iVar6 = lwip_socket(iVar6,2,uVar2);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar6 < 0) {
      uVar2 = esp_log_timestamp();
      esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to create socket for upstream resolver: %d\n"
              ,uVar2,"FindOrAllocateTransaction",0xd4,iVar6);
    }
    else {
      esp_openthread_task_switching_lock_release();
      esp_netif_get_netif_impl_name(iVar1,auStack_38);
      iVar1 = lwip_setsockopt(iVar6,0xfff,0x100b,auStack_38,6);
      if (-1 < iVar1) {
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        puVar5 = (undefined4 *)(*(int *)this + uVar8 * 8);
        puVar5[1] = iVar6;
        *puVar5 = param_1;
        return puVar5;
      }
      uVar2 = esp_log_timestamp();
      _ZTH5errno(uVar2);
      esp_log(1,"Resolver","E (%lu) %s: Unable to bind socket: errno %d\n",uVar2,*tp);
      close(iVar6);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
    }
  }
  return (undefined4 *)0x0;
}

