/*
 * Last changed at upstream commit fff1e900a1169e76ea06246100f81d005d5f7f44
 * https://github.com/espressif/esp-thread-lib/commit/fff1e900a1169e76ea06246100f81d005d5f7f44
 * Upstream date: 2025-06-25 11:20:59 +0000
 * Upstream subject: feat(openthread): update border router lib
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> otPlatDnsStartUpstreamQuery
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void otPlatDnsStartUpstreamQuery(otPlatDnsUpstreamQuery *param_1,undefined4 param_2)

{
  Resolver *this;
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined4 uVar6;
  int iVar7;
  char *pcVar8;
  int iVar9;
  undefined4 *puVar10;
  undefined4 auStack_298 [3];
  undefined1 uStack_28b;
  undefined2 uStack_28a;
  int iStack_288;
  int iStack_27c;
  int iStack_278;
  int iStack_274;
  int iStack_270;
  char cStack_268;
  undefined1 auStack_264 [24];
  undefined1 uStack_24c;
  undefined1 uStack_24b;
  undefined2 uStack_24a;
  undefined1 auStack_244 [20];
  undefined1 auStack_230 [512];
  
  this = g_resolver;
  if (g_resolver == (Resolver *)0x0) {
    return;
  }
  memset(&iStack_27c,0,0x18);
  memset(auStack_264,0,0x18);
  uVar2 = esp_openthread_get_backbone_netif();
  uVar3 = otMessageGetLength(param_2);
  if (uVar3 < 0x200) {
    uVar5 = otMessageRead(param_2,0,auStack_230,0x200);
    if (uVar5 == uVar3) {
      auStack_298[1] = 1;
      auStack_298[0] = 0;
      auStack_298[2] = 2;
      puVar10 = auStack_298;
      iVar9 = 0;
      iVar1 = 0;
      do {
        esp_netif_get_dns_info(uVar2,*puVar10,auStack_264);
        memcpy(&iStack_27c,auStack_264,0x18);
        if (cStack_268 == '\x06') {
          if (((iStack_27c != 0 || iStack_278 != 0) || iStack_274 != 0) || iStack_270 != 0) {
            uVar4 = esp_log_timestamp();
            uVar6 = ipaddr_ntoa(&iStack_27c);
            esp_log(3,"Resolver","I (%lu) %s: Forward DNS query to v6: %s\n",uVar4,"Resolver",uVar6)
            ;
            if ((iVar1 == 0) &&
               (iVar1 = Resolver::FindOrAllocateTransaction(this,param_1,'\n'), iVar1 == 0)) {
              uVar4 = esp_log_timestamp();
              pcVar8 = "E (%lu) %s: Failed to allocate ipv6 transaction\n";
_L0:
              esp_log(1,"Resolver",pcVar8,uVar4,"Resolver");
            }
            else {
              uStack_24b = 10;
              uStack_24a = 0x3500;
              memcpy(auStack_244,&iStack_27c,0x10);
              esp_openthread_task_switching_lock_release();
              iVar7 = lwip_sendto(*(undefined4 *)(iVar1 + 4),auStack_230,uVar3,8,&uStack_24c,0x1c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              if (iVar7 == 0) {
                uVar4 = esp_log_timestamp();
                uVar2 = 0x90;
_L0:
                pcVar8 = "E (%lu) %s: %s(%d): Failed to forward the Query message\n";
                goto _L0;
              }
            }
          }
        }
        else if ((iStack_27c != 0) && (cStack_268 == '\0')) {
          uVar4 = esp_log_timestamp();
          uVar6 = ipaddr_ntoa(&iStack_27c);
          esp_log(3,"Resolver","I (%lu) %s: Forward DNS query to v4: %s\n",uVar4,"Resolver",uVar6);
          if ((iVar9 == 0) &&
             (iVar9 = Resolver::FindOrAllocateTransaction(this,param_1,'\x02'), iVar9 == 0)) {
            uVar4 = esp_log_timestamp();
            pcVar8 = "E (%lu) %s: Failed to allocate ipv4 transaction\n";
            goto _L0;
          }
          uStack_28b = 2;
          uStack_28a = 0x3500;
          iStack_288 = iStack_27c;
          esp_openthread_task_switching_lock_release();
          iVar7 = lwip_sendto(*(undefined4 *)(iVar9 + 4),auStack_230,uVar3,8,&stack0xfffffd74,0x10);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          if (iVar7 == 0) {
            uVar4 = esp_log_timestamp();
            uVar2 = 0x7e;
            goto _L0;
          }
        }
        puVar10 = puVar10 + 1;
        if (puVar10 == (undefined4 *)&stack0xfffffd74) {
          return;
        }
      } while( true );
    }
    uVar4 = esp_log_timestamp();
    uVar2 = 0x66;
    pcVar8 = "E (%lu) %s: %s(%d): Failed to read query message\n";
  }
  else {
    uVar4 = esp_log_timestamp();
    uVar2 = 0x65;
    pcVar8 = "E (%lu) %s: %s(%d): No DNS query buffer\n";
  }
_L0:
  esp_log(1,"Resolver",pcVar8,uVar4,"Resolver","Query",uVar2);
  return;
}

