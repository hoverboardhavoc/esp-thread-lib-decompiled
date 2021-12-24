/*
 * Last changed at upstream commit d5196d896db7230669366a6468859aacccc0f68a
 * https://github.com/espressif/esp-thread-lib/commit/d5196d896db7230669366a6468859aacccc0f68a
 * Upstream date: 2021-12-24 17:07:02 +0800
 * Upstream subject: br: support new mdns interface
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
  int iVar3;
  ushort uVar4;
  uint __size;
  char *__ptr;
  undefined4 uVar5;
  void *pvVar6;
  undefined4 uVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  char *pcVar11;
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
  
  uVar4 = *(ushort *)(param_1 + 8);
  if (0x28 < uVar4) {
    iVar3 = *(int *)(param_1 + 4);
    memcpy(auStack_b4,(void *)(iVar3 + 8),0x10);
    memcpy(auStack_a0,(void *)(iVar3 + 0x18),0x10);
    uStack_a4 = 0;
    if ((((*(uint *)(iVar3 + 0x18) & 0xff) != 0xff) ||
        (((*(uint *)(iVar3 + 0x18) == 0x2ff && (*(int *)(iVar3 + 0x1c) == 0)) &&
         (((*(int *)(iVar3 + 0x20) == 0 && (*(int *)(iVar3 + 0x24) == 0x1000000)) ||
          ((*(int *)(iVar3 + 0x20) == 0 && (*(int *)(iVar3 + 0x24) == 0x2000000)))))))) &&
       ((*(char *)(iVar3 + 7) == -1 && (*(char *)(iVar3 + 6) == ':')))) {
      uVar4 = uVar4 - 0x28;
      __size = (uint)uVar4;
      __ptr = (char *)malloc(__size);
      if (__ptr == (char *)0x0) {
        uVar5 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC2,uVar5,"OPENTHREAD");
      }
      else {
        pbuf_copy_partial(param_1,__ptr,__size,0x28);
        if ((byte)(*__ptr + 0x7bU) < 2) {
          if (*__ptr == -0x7a) {
            for (uVar10 = 0x10; uVar10 + 1 < __size; uVar10 = uVar10 + uVar9 & 0xffff) {
              pcVar11 = __ptr + uVar10;
              uVar9 = ((byte)pcVar11[1] & 0x1f) * 8;
              if (*pcVar11 == '\x18') {
                iVar3 = is_self_address(auStack_b4);
                if (iVar3 == 0) {
                  bVar1 = pcVar11[2];
                  bVar2 = pcVar11[3];
                  uVar5 = esp_log_timestamp();
                  esp_log_write(3,"OPENTHREAD",&_LC3,uVar5,"OPENTHREAD");
                  if ((bVar1 >> 3) + 8 <= uVar9) {
                    uStack_8c = 0;
                    uStack_88 = 0;
                    uStack_84 = 0;
                    uStack_80 = 0;
                    uStack_7c = 0;
                    memcpy(&uStack_8c,__ptr + uVar10 + 8,(uint)(bVar1 >> 3));
                    uStack_44 = s_netif;
                    memcpy(&uStack_60,auStack_b4,0x14);
                    uStack_64 = CONCAT31(uStack_64._1_3_,pcVar11[2]);
                    memcpy(&uStack_78,&uStack_8c,0x14);
                    cStack_4c = (bVar2 >> 3 & 1) + (bVar2 >> 4 & 1) * -2;
                    uStack_48 = lwip_htonl(*(undefined4 *)(pcVar11 + 4));
                    uVar5 = esp_log_timestamp();
                    uVar7 = ip6addr_ntoa(&uStack_8c);
                    esp_log_write(3,"OPENTHREAD",&_LC4,uVar5,"OPENTHREAD",uVar7,uStack_48);
                    iVar3 = esp_openthread_route_table_add_route_entry(&uStack_78);
                    if (iVar3 == 0) {
                      uVar7 = esp_log_timestamp();
                      puVar8 = &_LC5;
                      uVar5 = 3;
_L0:
                      esp_log_write(uVar5,"OPENTHREAD",puVar8,uVar7,"OPENTHREAD");
                    }
                  }
                }
              }
              else if (*pcVar11 == '\x03') {
                uVar5 = esp_log_timestamp();
                esp_log_write(3,"OPENTHREAD",&_LC6,uVar5,"OPENTHREAD");
                if (pcVar11[3] < '\0') {
                  uStack_64 = 0;
                  uStack_60 = 0;
                  uStack_5c = 0;
                  memcpy(auStack_74,pcVar11 + 0x10,0x10);
                  uStack_78 = s_netif;
                  uStack_60 = CONCAT31(uStack_60._1_3_,pcVar11[2]);
                  uVar5 = lwip_htonl(*(undefined4 *)(pcVar11 + 8));
                  iVar3 = esp_openthread_route_table_add_onlink_prefix
                                    (&uStack_78,uVar5,(byte)pcVar11[3] >> 6 & 1);
                  if (iVar3 != 0) {
                    uVar7 = esp_log_timestamp();
                    puVar8 = &_LC7;
                    uVar5 = 1;
                    goto _L0;
                  }
                }
              }
            }
          }
          pvVar6 = malloc(0x1c);
          pvVar6 = memcpy(pvVar6,auStack_b4,0x14);
          *(char **)((int)pvVar6 + 0x14) = __ptr;
          *(ushort *)((int)pvVar6 + 0x18) = uVar4;
          esp_openthread_task_queue_post(handle_netif_receive_task,pvVar6);
        }
        else {
          free(__ptr);
        }
      }
    }
  }
  return 0;
}

