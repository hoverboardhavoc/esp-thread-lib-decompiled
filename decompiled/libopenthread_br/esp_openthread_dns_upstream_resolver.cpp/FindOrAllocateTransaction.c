/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
  int iVar6;
  undefined3 in_register_00002031;
  otPlatDnsUpstreamQuery *poVar7;
  undefined4 *puVar8;
  uint uVar9;
  int iVar10;
  uint auStack_40 [2];
  undefined1 auStack_38 [20];
  
  iVar6 = CONCAT31(in_register_00002031,param_2);
  uVar1 = *(uint *)(this + 4);
  iVar2 = esp_openthread_get_backbone_netif();
  if (iVar2 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,"Resolver","E (%lu) %s: Backbone netif not set\n",uVar3,"Resolver");
    return (undefined4 *)0x0;
  }
  auStack_40[0] = 0;
  auStack_40[1] = 4;
  for (uVar9 = 0; uVar9 < *(uint *)(this + 4); uVar9 = uVar9 + 1) {
    puVar8 = (undefined4 *)(*(int *)this + uVar9 * 8);
    poVar7 = (otPlatDnsUpstreamQuery *)*puVar8;
    if ((poVar7 == (otPlatDnsUpstreamQuery *)0x0) || ((int)puVar8[1] < 0)) {
      if (uVar9 < uVar1) {
        uVar1 = uVar9;
      }
    }
    else if ((poVar7 == param_1) &&
            (lwip_getsockopt(0x29,0x1b,auStack_40,auStack_40 + 1), (iVar6 == 10) == auStack_40[0]))
    {
      return (undefined4 *)(*(int *)this + uVar9 * 8);
    }
  }
  if (*(uint *)(this + 4) == uVar1) {
    if (uVar1 < 0x10) {
      uVar4 = *(undefined4 *)this;
      uVar3 = esp_openthread_get_alloc_caps();
      iVar10 = (uVar1 + 1) * 8;
      iVar5 = heap_caps_realloc(uVar4,iVar10,uVar3);
      if (iVar5 != 0) {
        *(int *)this = iVar5;
        *(int *)(this + 4) = *(int *)(this + 4) + 1;
        puVar8 = (undefined4 *)(iVar5 + iVar10 + -8);
        puVar8[1] = 0xffffffff;
        *puVar8 = 0;
        goto _L0;
      }
      uVar4 = esp_log_timestamp();
      uVar3 = 0xb5;
    }
    else {
      uVar4 = esp_log_timestamp();
      uVar3 = 0xb1;
    }
    esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to allocate new transaction\n",uVar4,"Resolver"
            ,"FindOrAllocateTransaction",uVar3);
  }
  else {
_L0:
    uVar3 = 0;
    if (iVar6 == 10) {
      uVar3 = 0x29;
    }
    iVar6 = lwip_socket(iVar6,2,uVar3);
    if (iVar6 < 0) {
      uVar3 = esp_log_timestamp();
      esp_log(1,"Resolver","E (%lu) %s: %s(%d): Failed to create socket for upstream resolver: %d\n"
              ,uVar3,"Resolver","FindOrAllocateTransaction",0xbd,iVar6);
    }
    else {
      esp_netif_get_netif_impl_name(iVar2,auStack_38);
      iVar2 = lwip_setsockopt(iVar6,0xfff,0x100b,auStack_38,6);
      if (-1 < iVar2) {
        puVar8 = (undefined4 *)(*(int *)this + uVar1 * 8);
        puVar8[1] = iVar6;
        *puVar8 = param_1;
        return puVar8;
      }
      uVar3 = esp_log_timestamp();
      puVar8 = (undefined4 *)__errno();
      esp_log(1,"Resolver","E (%lu) %s: Unable to bind socket: errno %d\n",uVar3,"Resolver",*puVar8)
      ;
      close(iVar6);
    }
  }
  return (undefined4 *)0x0;
}

