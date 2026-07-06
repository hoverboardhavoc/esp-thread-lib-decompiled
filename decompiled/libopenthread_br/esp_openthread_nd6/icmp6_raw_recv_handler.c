/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_nd6.o -> icmp6_raw_recv_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 icmp6_raw_recv_handler(int param_1,undefined4 param_2)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  int iVar4;
  uint uVar5;
  char *__ptr;
  undefined4 uVar6;
  undefined4 uVar7;
  uint uVar8;
  uint __size;
  uint uVar9;
  char *pcVar10;
  undefined1 auStack_90 [16];
  undefined1 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined1 auStack_68 [20];
  byte bStack_54;
  undefined1 auStack_50 [20];
  char cStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  
  iVar4 = *(int *)(param_1 + 4);
  memcpy(auStack_90,(void *)(iVar4 + 8),0x10);
  if (((((*(uint *)(iVar4 + 0x18) & 0xff) != 0xff) ||
       ((((*(uint *)(iVar4 + 0x18) == 0x2ff && (*(int *)(iVar4 + 0x1c) == 0)) &&
         (*(int *)(iVar4 + 0x20) == 0)) &&
        ((*(int *)(iVar4 + 0x24) == 0x1000000 || (*(int *)(iVar4 + 0x24) == 0x2000000)))))) &&
      (*(char *)(iVar4 + 7) == -1)) && (*(char *)(iVar4 + 6) == ':')) {
    __size = *(ushort *)(param_1 + 8) - 0x28 & 0xffff;
    __ptr = (char *)malloc(__size);
    if (__ptr != (char *)0x0) {
      pbuf_copy_partial(param_1,__ptr,__size,0x28);
      cVar1 = *__ptr;
      if ((byte)(cVar1 + 0x7bU) < 2) {
        if (cVar1 == -0x7a) {
          for (uVar9 = 0x10; uVar8 = uVar9 + 1 & 0xffff, uVar8 < __size;
              uVar9 = uVar5 + uVar9 & 0xffff) {
            uVar5 = ((byte)__ptr[uVar8] & 0x1f) * 8;
            if (((__ptr[uVar8] & 0x1fU) == 0) || (__size < uVar5)) {
              uVar6 = esp_log_timestamp();
              iVar4 = 0x29c;
_L55:
              esp_log(2,"OPENTHREAD",iVar4 + 0x10000,uVar6);
              break;
            }
            pcVar10 = __ptr + uVar9;
            if (*pcVar10 == '\x18') {
              uStack_80 = 0;
              iVar4 = is_address_from_netif(auStack_90,param_2);
              if (iVar4 == 0) {
                bVar2 = pcVar10[3];
                uVar6 = esp_log_timestamp();
                esp_log(3,"OPENTHREAD","I (%lu) %s: Received RIO\n",uVar6,"OPENTHREAD");
                bVar3 = pcVar10[2];
                if ((int)((bVar3 - 1) * 0x1000000) >> 0x18 < 0) {
                  uVar6 = esp_log_timestamp();
                  iVar4 = 0x2e4;
                  goto _L55;
                }
                if ((bVar3 >> 3) + 8 <= uVar5) {
                  uStack_7c = 0;
                  uStack_78 = 0;
                  uStack_74 = 0;
                  uStack_70 = 0;
                  uStack_6c = 0;
                  memcpy(&uStack_7c,__ptr + uVar9 + 8,(uint)(bVar3 >> 3));
                  uStack_34 = param_2;
                  memcpy(auStack_50,auStack_90,0x14);
                  bStack_54 = bVar3;
                  memcpy(auStack_68,&uStack_7c,0x14);
                  cStack_3c = ((byte)((int)((uint)bVar2 << 0x1b) >> 0x1f) & 0xfe) + (bVar2 >> 3 & 1)
                  ;
                  uStack_38 = lwip_htonl(*(undefined4 *)(pcVar10 + 4));
                  uVar6 = esp_log_timestamp();
                  uVar7 = ip6addr_ntoa(&uStack_7c);
                  esp_log(3,"OPENTHREAD","I (%lu) %s: prefix %s lifetime %lu\n\n",uVar6,"OPENTHREAD"
                          ,uVar7,uStack_38);
                  iVar4 = esp_openthread_route_table_add_route_entry(auStack_68);
                  if (iVar4 == 0) {
                    uVar6 = esp_log_timestamp();
                    esp_log(3,"OPENTHREAD","I (%lu) %s: Failed to add route table entry\n\n",uVar6,
                            "OPENTHREAD");
                  }
                }
              }
            }
          }
        }
      }
      else if (cVar1 != -0x78) {
        free(__ptr);
        return 0xffffffff;
      }
      free(__ptr);
      return 0;
    }
    uVar6 = esp_log_timestamp();
    esp_log(1,"OPENTHREAD","E (%lu) %s: Failed to allocate icmp6 buffer\n",uVar6);
  }
  return 0xffffffff;
}

