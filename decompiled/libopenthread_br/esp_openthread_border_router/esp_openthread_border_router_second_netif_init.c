/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_border_router.o -> esp_openthread_border_router_second_netif_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_border_router_second_netif_init(int param_1,void *param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  char *pcVar4;
  undefined1 auStack_30 [32];
  
  if (param_1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): Second netif not set\n",uVar3,0x10000,
            "esp_openthread_border_router_second_netif_init",0xc4);
    iVar2 = 0x103;
    iVar1 = s_second_netif;
  }
  else if ((s_backbone_netif == param_1) || (iVar2 = esp_openthread_get_netif(), param_1 == iVar2))
  {
    uVar3 = esp_log_timestamp();
    if (s_backbone_netif == param_1) {
      pcVar4 = "backbone netif";
    }
    else {
      pcVar4 = "openthread netif";
    }
    esp_log(1,0x10000,"E (%lu) %s: %s(%d): The second netif cannot be same with %s\n",uVar3,0x10000,
            "esp_openthread_border_router_second_netif_init",0xc5,pcVar4);
    iVar2 = -1;
    iVar1 = s_second_netif;
  }
  else {
    memcpy(auStack_30,param_2,0x14);
    iVar2 = esp_openthread_second_netif_nd6_init(param_1,auStack_30,param_3);
    iVar1 = param_1;
    if (iVar2 != 0) {
      uVar3 = esp_log_timestamp();
      esp_log(1,0x10000,"E (%lu) %s: %s(%d): Failed to initialize nd6 of the second netif\n",uVar3,
              0x10000,"esp_openthread_border_router_second_netif_init",200);
      iVar1 = s_second_netif;
    }
  }
  s_second_netif = iVar1;
  return iVar2;
}

