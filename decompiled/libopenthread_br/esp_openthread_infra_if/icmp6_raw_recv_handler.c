/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> icmp6_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_raw_recv_handler(int param_1)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  ushort uVar4;
  int iVar5;
  uint __size;
  uint uVar6;
  char *pcVar7;
  undefined4 uVar8;
  char *pcVar9;
  undefined4 uVar10;
  uint __n;
  uint uVar11;
  undefined1 auStack_a4 [16];
  undefined1 uStack_94;
  undefined1 auStack_90 [20];
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_68 [20];
  char cStack_54;
  undefined1 auStack_50 [20];
  char cStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  uVar4 = *(ushort *)(param_1 + 8);
  if (uVar4 < 0x29) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 4);
  uStack_94 = 0;
  memcpy(auStack_a4,(void *)(iVar5 + 8),0x10);
  memcpy(auStack_90,(void *)(iVar5 + 0x18),0x10);
  if ((*(uint3 *)(iVar5 + 0x18) & 0xff) == 0xff) {
    if (*(int *)(iVar5 + 0x18) != 0x2ff) {
      return 0;
    }
    if (*(int *)(iVar5 + 0x1c) != 0) {
      return 0;
    }
    if (*(int *)(iVar5 + 0x20) != 0) {
      return 0;
    }
    if ((*(int *)(iVar5 + 0x24) != 0x1000000) && (*(int *)(iVar5 + 0x24) != 0x2000000)) {
      return 0;
    }
  }
  if (*(char *)(iVar5 + 7) != -1) {
    return 0;
  }
  if (*(char *)(iVar5 + 6) != ':') {
    return 0;
  }
  uVar4 = uVar4 - 0x28;
  __size = (uint)uVar4;
  pcVar7 = (char *)malloc(__size);
  if (pcVar7 == (char *)0x0) {
    uVar8 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate icmp6 buffer\n",uVar8,"OPENTHREAD");
    return 0;
  }
  pbuf_copy_partial(param_1,pcVar7,__size,0x28);
  cVar1 = *pcVar7;
  if ((byte)(cVar1 + 0x7bU) < 2) {
    if (cVar1 == -0x7a) {
      for (uVar11 = 0x10; uVar11 + 1 < __size; uVar11 = uVar6 + uVar11 & 0xffff) {
        pcVar9 = pcVar7 + uVar11;
        uVar6 = ((byte)pcVar9[1] & 0x1f) * 8;
        if (((pcVar9[1] & 0x1fU) == 0) || (__size < uVar6)) {
          uVar8 = esp_log_timestamp();
          esp_log(2,"OPENTHREAD","W (%lu) %s: Invalid RA packets, ignored\n",uVar8,"OPENTHREAD");
          break;
        }
        if (*pcVar9 == '\x18') {
          uStack_94 = 0;
          iVar5 = is_self_address(auStack_a4);
          if (iVar5 == 0) {
            bVar2 = pcVar9[2];
            bVar3 = pcVar9[3];
            uVar8 = esp_log_timestamp();
            esp_log(3,"OPENTHREAD","I (%lu) %s: Received RIO\n",uVar8,"OPENTHREAD");
            if (bVar2 < 8) {
              uVar8 = esp_log_timestamp();
              pcVar9 = "I (%lu) %s: Prefix length: 0, skip to add this RIO\n";
_L0:
              esp_log(3,"OPENTHREAD",pcVar9,uVar8,"OPENTHREAD");
            }
            else {
              __n = (uint)(bVar2 >> 3);
              if (__n + 8 <= uVar6) {
                uStack_7c = 0;
                uStack_78 = 0;
                uStack_74 = 0;
                uStack_70 = 0;
                uStack_6c = 0;
                memcpy(&uStack_7c,pcVar7 + uVar11 + 8,__n);
                uStack_34 = s_netif;
                memcpy(auStack_50,auStack_a4,0x14);
                cStack_54 = pcVar9[2];
                memcpy(auStack_68,&uStack_7c,0x14);
                cStack_3c = ((byte)((int)((uint)bVar3 << 0x1b) >> 0x1f) & 0xfe) + (bVar3 >> 3 & 1);
                uStack_38 = lwip_htonl(*(undefined4 *)(pcVar9 + 4));
                uVar8 = esp_log_timestamp();
                uVar10 = ip6addr_ntoa(&uStack_7c);
                esp_log(3,"OPENTHREAD","I (%lu) %s: prefix %s lifetime %lu\n\n",uVar8,"OPENTHREAD",
                        uVar10,uStack_38);
                iVar5 = esp_openthread_route_table_add_route_entry(auStack_68);
                if (iVar5 == 0) {
                  uVar8 = esp_log_timestamp();
                  pcVar9 = "I (%lu) %s: Failed to add route table entry\n\n";
                  goto _L0;
                }
              }
            }
          }
        }
      }
    }
  }
  else {
    pcVar9 = pcVar7;
    if (cVar1 != -0x78) goto _L53;
  }
  pcVar9 = (char *)malloc(0x1c);
  uStack_94 = 0;
  memcpy(pcVar9,auStack_a4,0x14);
  *(char **)(pcVar9 + 0x14) = pcVar7;
  *(ushort *)(pcVar9 + 0x18) = uVar4;
  iVar5 = esp_openthread_task_queue_post(handle_netif_receive_task,pcVar9);
  if (iVar5 == 0) {
    return 0;
  }
  uVar8 = esp_log_timestamp();
  esp_log(2,"OPENTHREAD","W (%lu) %s: failed to send task to ot queue\n",uVar8,"OPENTHREAD");
  free(*(void **)(pcVar9 + 0x14));
_L53:
  free(pcVar9);
  return 0;
}

