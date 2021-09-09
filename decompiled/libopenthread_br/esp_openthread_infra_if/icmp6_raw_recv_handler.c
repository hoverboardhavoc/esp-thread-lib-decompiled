/*
 * Last changed at upstream commit 8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * https://github.com/espressif/esp-thread-lib/commit/8fdeda2b9b6e94761ab7fead714391e6bd27d486
 * Upstream date: 2021-09-09 20:40:32 +0800
 * Upstream subject: br: fix router solicitation handling(e82fe0d)
 * Source: libopenthread_br -> esp_openthread_infra_if.o -> icmp6_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_raw_recv_handler(int param_1)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  char *pcVar5;
  char *__ptr;
  undefined4 uVar6;
  void *pvVar7;
  undefined4 uVar8;
  ushort uVar9;
  uint __size;
  uint uVar10;
  uint uVar11;
  undefined1 auStack_b4 [16];
  undefined1 uStack_a4;
  undefined1 auStack_a0 [20];
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined1 auStack_74 [16];
  undefined4 uStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  char cStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  
  uVar9 = *(ushort *)(param_1 + 8);
  if (0x28 < uVar9) {
    iVar4 = *(int *)(param_1 + 4);
    memcpy(auStack_b4,(void *)(iVar4 + 8),0x10);
    memcpy(auStack_a0,(void *)(iVar4 + 0x18),0x10);
    uStack_a4 = 0;
    if ((((*(uint *)(iVar4 + 0x18) & 0xff) != 0xff) ||
        (((*(uint *)(iVar4 + 0x18) == 0x2ff && (*(int *)(iVar4 + 0x1c) == 0)) &&
         (((*(int *)(iVar4 + 0x20) == 0 && (*(int *)(iVar4 + 0x24) == 0x1000000)) ||
          ((*(int *)(iVar4 + 0x20) == 0 && (*(int *)(iVar4 + 0x24) == 0x2000000)))))))) &&
       ((*(char *)(iVar4 + 7) == -1 && (*(char *)(iVar4 + 6) == ':')))) {
      uVar9 = uVar9 - 0x28;
      __size = (uint)uVar9;
      __ptr = (char *)malloc(__size);
      if (__ptr == (char *)0x0) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC2,uVar6,"OPENTHREAD");
      }
      else {
        pbuf_copy_partial(param_1,__ptr,__size,0x28);
        if ((byte)(*__ptr + 0x7bU) < 2) {
          if (*__ptr == -0x7a) {
            for (uVar10 = 0x10; uVar10 + 1 < __size; uVar10 = uVar10 + (bVar1 & 0x1f) * 8 & 0xffff)
            {
              pcVar5 = __ptr + uVar10;
              bVar1 = pcVar5[1];
              if (*pcVar5 == '\x18') {
                iVar4 = is_self_address(auStack_b4);
                if (iVar4 == 0) {
                  bVar2 = pcVar5[3];
                  bVar3 = pcVar5[2];
                  uVar6 = esp_log_timestamp();
                  esp_log_write(3,"OPENTHREAD",&_LC3,uVar6,"OPENTHREAD");
                  for (uVar11 = 8; uVar11 < ((bVar1 & 0x1f) << 0x13) >> 0x10;
                      uVar11 = uVar11 + (bVar3 >> 3) & 0xffff) {
                    uStack_8c = 0;
                    uStack_88 = 0;
                    uStack_84 = 0;
                    uStack_80 = 0;
                    uStack_7c = 0;
                    memcpy(&uStack_8c,__ptr + uVar11 + uVar10,(uint)(bVar3 >> 3));
                    uStack_44 = s_netif;
                    memcpy(&uStack_60,auStack_b4,0x14);
                    uStack_64 = CONCAT31(uStack_64._1_3_,pcVar5[2]);
                    memcpy(&uStack_78,&uStack_8c,0x14);
                    cStack_4c = (bVar2 >> 4 & 1) * -2 + (bVar2 >> 3 & 1);
                    uStack_48 = lwip_htonl(*(undefined4 *)(pcVar5 + 4));
                    uVar6 = esp_log_timestamp();
                    uVar8 = ip6addr_ntoa(&uStack_8c);
                    esp_log_write(3,"OPENTHREAD",&_LC4,uVar6,"OPENTHREAD",uVar8,uStack_48);
                    iVar4 = esp_openthread_route_table_add_route_entry(&uStack_78);
                    if (iVar4 == 0) {
                      uVar6 = esp_log_timestamp();
                      esp_log_write(3,"OPENTHREAD",&_LC5,uVar6,"OPENTHREAD");
                    }
                  }
                }
              }
              else if (*pcVar5 == '\x03') {
                uVar6 = esp_log_timestamp();
                esp_log_write(3,"OPENTHREAD",&_LC6,uVar6,"OPENTHREAD");
                if (pcVar5[3] < '\0') {
                  uStack_64 = 0;
                  uStack_60 = 0;
                  uStack_5c = 0;
                  memcpy(auStack_74,pcVar5 + 0x10,0x10);
                  uStack_78 = s_netif;
                  uStack_60 = CONCAT31(uStack_60._1_3_,pcVar5[2]);
                  uVar6 = lwip_htonl(*(undefined4 *)(pcVar5 + 8));
                  iVar4 = esp_openthread_route_table_add_onlink_prefix
                                    (&uStack_78,uVar6,(byte)pcVar5[3] >> 6 & 1);
                  if (iVar4 != 0) {
                    uVar6 = esp_log_timestamp();
                    esp_log_write(1,"OPENTHREAD",&_LC7,uVar6,"OPENTHREAD");
                  }
                }
              }
            }
          }
          pvVar7 = malloc(0x1c);
          pvVar7 = memcpy(pvVar7,auStack_b4,0x14);
          *(char **)((int)pvVar7 + 0x14) = __ptr;
          *(ushort *)((int)pvVar7 + 0x18) = uVar9;
          esp_openthread_task_queue_post(handle_netif_receive_task,pvVar7);
        }
        else {
          free(__ptr);
        }
      }
    }
  }
  return 0;
}

