/*
 * Last changed at upstream commit 75a1adad77ac6a3a45ec0806c4f680520823fdba
 * https://github.com/espressif/esp-thread-lib/commit/75a1adad77ac6a3a45ec0806c4f680520823fdba
 * Upstream date: 2026-05-19 03:52:07 +0000
 * Upstream subject: feat(openthread): support s31 openthread br lib
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
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  undefined4 uVar5;
  uint uVar6;
  undefined4 uVar7;
  int iVar8;
  char *pcVar9;
  uint *puVar10;
  uint auStack_298 [8];
  int iStack_278;
  int iStack_274;
  int iStack_270;
  char cStack_268;
  undefined1 auStack_264 [24];
  undefined1 uStack_24c;
  undefined1 uStack_24b;
  undefined2 uStack_24a;
  undefined1 auStack_244 [16];
  uint uStack_234;
  undefined1 auStack_230 [512];
  
  this = g_resolver;
  if (g_resolver == (Resolver *)0x0) {
    return;
  }
  auStack_298[3] = 0;
  auStack_298[4] = 0;
  auStack_298[5] = 0;
  auStack_298[6] = 0;
  memset(&uStack_24c,0,0x1c);
  memset(auStack_298 + 7,0,0x18);
  memset(auStack_264,0,0x18);
  uVar3 = esp_openthread_get_backbone_netif();
  uVar4 = otMessageGetLength(param_2);
  if (uVar4 < 0x200) {
    uVar6 = otMessageRead(param_2,0,auStack_230,0x200);
    if (uVar6 == uVar4) {
      auStack_298[1] = 1;
      auStack_298[0] = 0;
      auStack_298[2] = 2;
      puVar10 = auStack_298;
      iVar2 = 0;
      iVar1 = 0;
      do {
        esp_openthread_task_switching_lock_release();
        esp_netif_get_dns_info(uVar3,*puVar10,auStack_264);
        esp_openthread_task_switching_lock_acquire(0xffffffff);
        memcpy(auStack_298 + 7,auStack_264,0x18);
        if (cStack_268 == '\x06') {
          if (((auStack_298[7] != 0 || iStack_278 != 0) || iStack_274 != 0) || iStack_270 != 0) {
            uVar5 = esp_log_timestamp();
            uVar7 = ipaddr_ntoa(auStack_298 + 7);
            esp_log(3,"Resolver","I (%lu) %s: Forward DNS query to v6: %s\n",uVar5,uVar7);
            if ((iVar1 == 0) &&
               (iVar1 = Resolver::FindOrAllocateTransaction(this,param_1,'\n'), iVar1 == 0)) {
              uVar5 = esp_log_timestamp();
              pcVar9 = "E (%lu) %s: Failed to allocate ipv6 transaction\n";
_L67:
              esp_log(1,"Resolver",pcVar9,uVar5);
            }
            else {
              memset(&uStack_24c,0,0x1c);
              uStack_24b = 10;
              uStack_24a = 0x3500;
              memcpy(auStack_244,auStack_298 + 7,0x10);
              if ((auStack_298[7] & 0xc0ff) == 0x80fe) {
                iVar8 = esp_openthread_get_lwip_backbone_netif();
                if (iVar8 != 0) {
                  uStack_234 = *(byte *)(iVar8 + 0x212) + 1 & 0xff;
                }
                if (uStack_234 == 0) {
                  uVar5 = esp_log_timestamp();
                  uVar3 = 0x96;
                  pcVar9 = 
                  "E (%lu) %s: %s(%d): Failed to resolve scope id for link-local DNS server\n";
                  goto _L68;
                }
              }
              esp_openthread_task_switching_lock_release();
              iVar8 = lwip_sendto(*(undefined4 *)(iVar1 + 4),auStack_230,uVar4,8,&uStack_24c,0x1c);
              esp_openthread_task_switching_lock_acquire(0xffffffff);
              if (iVar8 < 0) {
                uVar5 = esp_log_timestamp();
                _ZTH5errno(uVar5);
                uVar7 = *tp;
                uVar3 = 0x9d;
                pcVar9 = "E (%lu) %s: %s(%d): Failed to forward DNS query to v6 server: errno=%d\n";
_L69:
                esp_log(1,"Resolver",pcVar9,uVar5,"Query",uVar3,uVar7);
                return;
              }
            }
          }
        }
        else if ((auStack_298[7] != 0) && (cStack_268 == '\0')) {
          uVar5 = esp_log_timestamp();
          uVar7 = ipaddr_ntoa(auStack_298 + 7);
          esp_log(3,"Resolver","I (%lu) %s: Forward DNS query to v4: %s\n",uVar5,uVar7);
          if ((iVar2 == 0) &&
             (iVar2 = Resolver::FindOrAllocateTransaction(this,param_1,'\x02'), iVar2 == 0)) {
            uVar5 = esp_log_timestamp();
            pcVar9 = "E (%lu) %s: Failed to allocate ipv4 transaction\n";
            goto _L67;
          }
          auStack_298[3] = 0x35000200;
          auStack_298[5] = 0;
          auStack_298[6] = 0;
          auStack_298[4] = auStack_298[7];
          esp_openthread_task_switching_lock_release();
          iVar8 = lwip_sendto(*(undefined4 *)(iVar2 + 4),auStack_230,uVar4,8,auStack_298 + 3,0x10);
          esp_openthread_task_switching_lock_acquire(0xffffffff);
          if (iVar8 < 0) {
            uVar5 = esp_log_timestamp();
            _ZTH5errno(uVar5);
            uVar7 = *tp;
            uVar3 = 0x82;
            pcVar9 = "E (%lu) %s: %s(%d): Failed to forward DNS query to v4 server: errno=%d\n";
            goto _L69;
          }
        }
        puVar10 = puVar10 + 1;
        if (auStack_298 + 3 == puVar10) {
          return;
        }
      } while( true );
    }
    uVar5 = esp_log_timestamp();
    uVar3 = 0x67;
    pcVar9 = "E (%lu) %s: %s(%d): Failed to read query message\n";
  }
  else {
    uVar5 = esp_log_timestamp();
    uVar3 = 0x66;
    pcVar9 = "E (%lu) %s: %s(%d): No DNS query buffer\n";
  }
_L68:
  esp_log(1,"Resolver",pcVar9,uVar5,"Query",uVar3);
  return;
}

