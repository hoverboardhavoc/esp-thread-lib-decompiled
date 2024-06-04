/*
 * Last changed at upstream commit 34d698a274940730901b934caa023a3281aca53e
 * https://github.com/espressif/esp-thread-lib/commit/34d698a274940730901b934caa023a3281aca53e
 * Upstream date: 2024-06-04 12:02:17 +0800
 * Upstream subject: feat(openthread): update br lib
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
  char *__ptr;
  undefined4 uVar6;
  void *__dest;
  undefined4 uVar7;
  undefined *puVar8;
  uint __n;
  uint uVar9;
  char *pcVar10;
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
  iVar5 = *(int *)(param_1 + 4);
  if (0x28 < uVar4) {
    memcpy(auStack_a4,(void *)(iVar5 + 8),0x10);
    memcpy(auStack_90,(void *)(iVar5 + 0x18),0x10);
    uStack_94 = 0;
    if (((((*(uint3 *)(iVar5 + 0x18) & 0xff) != 0xff) ||
         ((((*(int *)(iVar5 + 0x18) == 0x2ff && (*(int *)(iVar5 + 0x1c) == 0)) &&
           (*(int *)(iVar5 + 0x20) == 0)) &&
          ((*(int *)(iVar5 + 0x24) == 0x1000000 || (*(int *)(iVar5 + 0x24) == 0x2000000)))))) &&
        (*(char *)(iVar5 + 7) == -1)) && (*(char *)(iVar5 + 6) == ':')) {
      uVar4 = uVar4 - 0x28;
      __size = (uint)uVar4;
      __ptr = (char *)malloc(__size);
      if (__ptr == (char *)0x0) {
        uVar6 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_L0,uVar6,"OPENTHREAD");
      }
      else {
        pbuf_copy_partial(param_1,__ptr,__size,0x28);
        cVar1 = *__ptr;
        if ((byte)(cVar1 + 0x7bU) < 2) {
          uVar11 = 0x10;
          if (cVar1 == -0x7a) {
            for (; uVar11 + 1 < __size; uVar11 = uVar9 + uVar11 & 0xffff) {
              pcVar10 = __ptr + uVar11;
              uVar9 = ((byte)pcVar10[1] & 0x1f) * 8;
              if ((*pcVar10 == '\x18') && (iVar5 = is_self_address(auStack_a4), iVar5 == 0)) {
                bVar2 = pcVar10[2];
                bVar3 = pcVar10[3];
                uVar6 = esp_log_timestamp();
                esp_log_write(3,"OPENTHREAD",&_LC4,uVar6,"OPENTHREAD");
                if (bVar2 < 8) {
                  uVar6 = esp_log_timestamp();
                  puVar8 = &_LC5;
_L0:
                  esp_log_write(3,"OPENTHREAD",puVar8,uVar6,"OPENTHREAD");
                }
                else {
                  __n = (uint)(bVar2 >> 3);
                  if (__n + 8 <= uVar9) {
                    uStack_7c = 0;
                    uStack_78 = 0;
                    uStack_74 = 0;
                    uStack_70 = 0;
                    uStack_6c = 0;
                    memcpy(&uStack_7c,__ptr + uVar11 + 8,__n);
                    uStack_34 = s_netif;
                    memcpy(auStack_50,auStack_a4,0x14);
                    cStack_54 = pcVar10[2];
                    memcpy(auStack_68,&uStack_7c,0x14);
                    cStack_3c = ((byte)((int)((uint)bVar3 << 0x1b) >> 0x1f) & 0xfe) +
                                (bVar3 >> 3 & 1);
                    uStack_38 = lwip_htonl(*(undefined4 *)(pcVar10 + 4));
                    uVar6 = esp_log_timestamp();
                    uVar7 = ip6addr_ntoa(&uStack_7c);
                    esp_log_write(3,"OPENTHREAD",&_LC6,uVar6,"OPENTHREAD",uVar7,uStack_38);
                    iVar5 = esp_openthread_route_table_add_route_entry(auStack_68);
                    if (iVar5 == 0) {
                      uVar6 = esp_log_timestamp();
                      puVar8 = &_LC7;
                      goto _L0;
                    }
                  }
                }
              }
            }
          }
        }
        else if (cVar1 != -0x78) {
          free(__ptr);
          return 0;
        }
        __dest = malloc(0x1c);
        memcpy(__dest,auStack_a4,0x14);
        *(char **)((int)__dest + 0x14) = __ptr;
        *(ushort *)((int)__dest + 0x18) = uVar4;
        esp_openthread_task_queue_post(handle_netif_receive_task,__dest);
      }
    }
  }
  return 0;
}

