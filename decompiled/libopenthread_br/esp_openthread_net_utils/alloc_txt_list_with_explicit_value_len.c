/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> esp_openthread_net_utils.o -> alloc_txt_list_with_explicit_value_len
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * alloc_txt_list_with_explicit_value_len(int param_1,int param_2,undefined1 *param_3)

{
  size_t sVar1;
  undefined4 uVar2;
  int iVar3;
  void *pvVar4;
  size_t __n;
  void *__dest;
  void *__dest_00;
  char *pcVar5;
  undefined4 *puVar6;
  undefined4 uVar7;
  uint uVar8;
  char *__src;
  char *pcStack_88;
  char *pcStack_84;
  ushort uStack_80;
  undefined1 auStack_7c [80];
  
  if (param_3 == (undefined1 *)0x0) {
    uVar2 = esp_log_timestamp();
    uVar7 = 0x48;
    pcVar5 = "E (%lu) %s: %s(%d): txt_items_count is null\n";
  }
  else {
    *param_3 = 0;
    if ((param_1 == 0) || (param_2 == 0)) {
      uVar2 = esp_log_timestamp();
      uVar7 = 0x4a;
      pcVar5 = "E (%lu) %s: %s(%d): raw TXT data is invalid\n";
    }
    else {
      otDnsInitTxtEntryIterator(auStack_7c,param_1,param_2);
      sVar1 = 0;
      while (iVar3 = otDnsGetNextTxtEntry(auStack_7c,&pcStack_88), iVar3 == 0) {
        sVar1 = sVar1 + 1 & 0xff;
      }
      if (sVar1 != 0) {
        pvVar4 = calloc(sVar1,0xc);
        if (pvVar4 == (void *)0x0) {
          uVar7 = esp_log_timestamp();
          esp_log(1,"OPENTHREAD","E (%lu) %s: %s(%d): Failed to allocate TXT items array\n",uVar7,
                  "alloc_txt_list_with_explicit_value_len",0x53);
          return (void *)0x0;
        }
        otDnsInitTxtEntryIterator(auStack_7c,param_1,param_2);
        uVar8 = 0;
        do {
          do {
            iVar3 = otDnsGetNextTxtEntry(auStack_7c,&pcStack_88);
            __src = pcStack_84;
            pcVar5 = pcStack_88;
            if (iVar3 != 0) {
              *param_3 = (char)uVar8;
              return pvVar4;
            }
            sVar1 = uStack_80 & 0xff;
            if (pcStack_88 == (char *)0x0) {
              for (__n = 0; __n < uStack_80; __n = __n + 1) {
                if (pcStack_84[__n] == '=') goto _L39;
              }
              __n = 0;
_L39:
              sVar1 = (sVar1 - 1) - __n & 0xff;
              __src = pcStack_84 + __n + 1;
              pcVar5 = pcStack_84;
            }
            else {
              __n = strnlen(pcStack_88,0x41);
            }
          } while ((0x3f < __n - 1) || (pcVar5 == (char *)0x0));
          __dest = malloc(__n + 1);
          if (__dest == (void *)0x0) {
            uVar2 = esp_log_timestamp();
            uVar7 = 0x72;
            pcVar5 = "E (%lu) %s: %s(%d): Failed to allocate memory for TXT key\n";
_L58:
            esp_log(1,"OPENTHREAD",pcVar5,uVar2,"alloc_txt_list_with_explicit_value_len",uVar7);
            free_txt_list_with_explicit_value_len(pvVar4,uVar8);
            return (void *)0x0;
          }
          memcpy(__dest,pcVar5,__n);
          *(undefined1 *)(__n + (int)__dest) = 0;
          if ((sVar1 - 1 < 0x40) && (__src != (char *)0x0)) {
            __dest_00 = malloc(sVar1 + 1 & 0xff);
            if (__dest_00 == (void *)0x0) {
              free(__dest);
              uVar2 = esp_log_timestamp();
              uVar7 = 0x7b;
              pcVar5 = "E (%lu) %s: %s(%d): Failed to allocate memory for TXT value\n";
              goto _L58;
            }
            memcpy(__dest_00,__src,sVar1);
            *(undefined1 *)((int)__dest_00 + sVar1) = 0;
          }
          else {
            sVar1 = 0;
            __dest_00 = (void *)0x0;
          }
          iVar3 = uVar8 * 0xc;
          uVar8 = uVar8 + 1 & 0xff;
          puVar6 = (undefined4 *)(iVar3 + (int)pvVar4);
          *puVar6 = __dest;
          puVar6[1] = __dest_00;
          *(char *)(puVar6 + 2) = (char)sVar1;
        } while( true );
      }
      uVar2 = esp_log_timestamp();
      uVar7 = 0x50;
      pcVar5 = "E (%lu) %s: %s(%d): Failed to get TXT items\n";
    }
  }
  esp_log(1,"OPENTHREAD",pcVar5,uVar2,"alloc_txt_list_with_explicit_value_len",uVar7);
  return (void *)0x0;
}

