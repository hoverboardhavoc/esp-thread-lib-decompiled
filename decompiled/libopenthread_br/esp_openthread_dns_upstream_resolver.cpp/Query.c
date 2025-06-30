/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> esp_openthread_dns_upstream_resolver.cpp.o -> Query
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* Resolver::Query(otPlatDnsUpstreamQuery*, otMessage const*) */

void __thiscall Resolver::Query(Resolver *this,otPlatDnsUpstreamQuery *param_1,otMessage *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  undefined4 *puVar10;
  undefined4 local_298 [3];
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
  
  memset(&iStack_27c,0,0x18);
  memset(auStack_264,0,0x18);
  uVar3 = esp_openthread_get_backbone_netif();
  uVar4 = otMessageGetLength(param_2);
  if (uVar4 < 0x200) {
    uVar6 = otMessageRead(param_2,0,auStack_230,0x200);
    if (uVar6 == uVar4) {
      local_298[1] = 1;
      local_298[0] = 0;
      local_298[2] = 2;
      puVar10 = local_298;
      iVar2 = 0;
      iVar1 = 0;
      do {
        esp_netif_get_dns_info(uVar3,*puVar10,auStack_264);
        memcpy(&iStack_27c,auStack_264,0x18);
        if (cStack_268 == '\x06') {
          if (((iStack_27c != 0 || iStack_278 != 0) || iStack_274 != 0) || iStack_270 != 0) {
            uVar5 = esp_log_timestamp();
            uVar7 = ipaddr_ntoa(&iStack_27c);
            esp_log(3,"Resolver","I (%lu) %s: Forward DNS query to v6: %s\n",uVar5,uVar7);
            if ((iVar1 == 0) && (iVar1 = FindOrAllocateTransaction(this,param_1,'\n'), iVar1 == 0))
            {
              uVar5 = esp_log_timestamp();
              pcVar9 = "E (%lu) %s: Failed to allocate ipv6 transaction\n";
_L50:
              esp_log(1,"Resolver",pcVar9,uVar5);
            }
            else {
              uStack_24b = 10;
              uStack_24a = 0x3500;
              memcpy(auStack_244,&iStack_27c,0x10);
              esp_openthread_task_switching_lock_release();
              iVar8 = lwip_sendto(*(undefined4 *)(iVar1 + 4),auStack_230,uVar4,8,&uStack_24c,0x1c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              if (iVar8 == 0) {
                uVar5 = esp_log_timestamp();
                uVar3 = 0x90;
_L51:
                pcVar9 = "E (%lu) %s: %s(%d): Failed to forward the Query message\n";
                goto _L52;
              }
            }
          }
        }
        else if ((iStack_27c != 0) && (cStack_268 == '\0')) {
          uVar5 = esp_log_timestamp();
          uVar7 = ipaddr_ntoa(&iStack_27c);
          esp_log(3,"Resolver","I (%lu) %s: Forward DNS query to v4: %s\n",uVar5,uVar7);
          if ((iVar2 == 0) && (iVar2 = FindOrAllocateTransaction(this,param_1,'\x02'), iVar2 == 0))
          {
            uVar5 = esp_log_timestamp();
            pcVar9 = "E (%lu) %s: Failed to allocate ipv4 transaction\n";
            goto _L50;
          }
          uStack_28b = 2;
          uStack_28a = 0x3500;
          iStack_288 = iStack_27c;
          esp_openthread_task_switching_lock_release();
          iVar8 = lwip_sendto(*(undefined4 *)(iVar2 + 4),auStack_230,uVar4,8,&stack0xfffffd74,0x10);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          if (iVar8 == 0) {
            uVar5 = esp_log_timestamp();
            uVar3 = 0x7e;
            goto _L51;
          }
        }
        puVar10 = puVar10 + 1;
        if (puVar10 == (undefined4 *)&stack0xfffffd74) {
          return;
        }
      } while( true );
    }
    uVar5 = esp_log_timestamp();
    uVar3 = 0x66;
    pcVar9 = "E (%lu) %s: %s(%d): Failed to read query message\n";
  }
  else {
    uVar5 = esp_log_timestamp();
    uVar3 = 0x65;
    pcVar9 = "E (%lu) %s: %s(%d): No DNS query buffer\n";
  }
_L52:
  esp_log(1,"Resolver",pcVar9,uVar5,"Query",uVar3);
  return;
}

