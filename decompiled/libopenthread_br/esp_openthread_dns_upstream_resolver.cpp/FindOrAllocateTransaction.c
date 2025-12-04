/*
 * Last changed at upstream commit 66e81acb8df80dbc52a2b0841a8ae3153557e131
 * https://github.com/espressif/esp-thread-lib/commit/66e81acb8df80dbc52a2b0841a8ae3153557e131
 * Upstream date: 2025-12-04 07:38:20 +0000
 * Upstream subject: fix(openthread): resolve deadlock issues due to switching_lock
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
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  int iVar5;
  undefined4 *puVar6;
  int iVar7;
  undefined3 in_register_00002031;
  otPlatDnsUpstreamQuery *poVar8;
  uint uVar9;
  uint auStack_40 [2];
  undefined1 auStack_38 [20];
  
  iVar7 = CONCAT31(in_register_00002031,param_2);
  uVar1 = *(uint *)(this + 4);
  iVar2 = esp_openthread_get_backbone_netif();
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"Resolver","E (%lu) %s: Backbone netif not set\n",uVar3);
    return (undefined4 *)0x0;
  }
  auStack_40[0] = 0;
  auStack_40[1] = 4;
  for (uVar9 = 0; uVar9 < *(uint *)(this + 4); uVar9 = uVar9 + 1) {
    iVar5 = uVar9 * 8;
    poVar8 = *(otPlatDnsUpstreamQuery **)(*(int *)this + iVar5);
    if ((poVar8 == (otPlatDnsUpstreamQuery *)0x0) ||
       ((int)((undefined4 *)(*(int *)this + iVar5))[1] < 0)) {
      if (uVar9 < uVar1) {
        uVar1 = uVar9;
      }
    }
    else if (poVar8 == param_1) {
      esp_openthread_task_switching_lock_release();
      lwip_getsockopt(*(undefined4 *)(*(int *)this + iVar5 + 4),0x29,0x1b,auStack_40,auStack_40 + 1)
      ;
      esp_openthread_task_switching_lock_acquire(0xffffffff);
      if ((iVar7 == 10) == auStack_40[0]) {
        return (undefined4 *)(*(int *)this + iVar5);
      }
    }
  }
  if (*(uint *)(this + 4) == uVar1) {
    if (uVar1 < 0x10) {
      uVar4 = *(undefined4 *)this;
      uVar3 = esp_openthread_get_alloc_caps();
      iVar5 = heap_caps_realloc(uVar4,(uVar1 + 1) * 8,uVar3);
      if (iVar5 != 0) {
        *(int *)this = iVar5;
        *(int *)(this + 4) = *(int *)(this + 4) + 1;
        puVar6 = (undefined4 *)(iVar5 + uVar1 * 8);
        puVar6[1] = 0xffffffff;
        *puVar6 = 0;
        goto _L17;
      }
      uVar4 = esp_log_timestamp();
      uVar3 = 0xbf;
    }
    else {
      uVar4 = esp_log_timestamp();
      uVar3 = 0xbb;
    }
    esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to allocate new transaction\n",uVar4,
            "FindOrAllocateTransaction",uVar3);
  }
  else {
_L17:
    esp_openthread_task_switching_lock_release();
    uVar3 = 0;
    if (iVar7 == 10) {
      uVar3 = 0x29;
    }
    iVar7 = lwip_socket(iVar7,2,uVar3);
    esp_openthread_task_switching_lock_acquire(0xffffffff);
    if (iVar7 < 0) {
      uVar3 = esp_log_timestamp();
      esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to create socket for upstream resolver: %d\n"
              ,uVar3,"FindOrAllocateTransaction",0xc9,iVar7);
    }
    else {
      esp_openthread_task_switching_lock_release();
      esp_netif_get_netif_impl_name(iVar2,auStack_38);
      iVar2 = lwip_setsockopt(iVar7,0xfff,0x100b,auStack_38,6);
      if (-1 < iVar2) {
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        puVar6 = (undefined4 *)(*(int *)this + uVar1 * 8);
        puVar6[1] = iVar7;
        *puVar6 = param_1;
        return puVar6;
      }
      uVar3 = esp_log_timestamp();
      _ZTH5errno(uVar3);
      esp_log(1,"Resolver","E (%lu) %s: Unable to bind socket: errno %d\n",uVar3,*tp);
      close(iVar7);
      esp_openthread_task_switching_lock_acquire(0xffffffff);
    }
  }
  return (undefined4 *)0x0;
}

