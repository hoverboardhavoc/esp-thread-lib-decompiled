/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> alloc_txt_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * alloc_txt_list(undefined1 *param_1)

{
  uint uVar1;
  int *piVar2;
  uint __n;
  undefined4 uVar3;
  int iVar4;
  void *__s;
  int iVar5;
  size_t sVar6;
  char *pcVar7;
  char *pcStack_44;
  char *pcStack_40;
  ushort uStack_3c;
  undefined1 auStack_38 [22];
  undefined2 auStack_22 [3];
  
  auStack_22[0] = 0;
  uVar3 = otSrpServerServiceGetTxtData(auStack_22);
  otDnsInitTxtEntryIterator(auStack_38,uVar3,auStack_22[0]);
  uVar1 = 0;
  while (iVar4 = otDnsGetNextTxtEntry(auStack_38,&pcStack_44), iVar4 == 0) {
    uVar1 = uVar1 + 1 & 0xff;
  }
  *param_1 = (char)uVar1;
  if (uVar1 == 0) {
    __s = (void *)0x0;
  }
  else {
    __s = malloc(uVar1 << 3);
    if (__s != (void *)0x0) {
      memset(__s,0,uVar1 << 3);
      otDnsInitTxtEntryIterator(auStack_38,uVar3,auStack_22[0]);
      iVar4 = 0;
      while (iVar5 = otDnsGetNextTxtEntry(auStack_38,&pcStack_44), iVar5 == 0) {
        sVar6 = strnlen(pcStack_44,0x40);
        pcVar7 = (char *)malloc(sVar6 + 1);
        piVar2 = (int *)(iVar4 * 8 + (int)__s);
        if (*piVar2 == 0) {
          free_txt_list(__s,uVar1);
          return (void *)0x0;
        }
        strncpy(pcVar7,pcStack_44,0x40);
        pcVar7[0x40] = '\0';
        *piVar2 = (int)pcVar7;
        __n = (uint)uStack_3c;
        pcVar7 = (char *)malloc(__n + 1);
        if (pcVar7 == (char *)0x0) {
          free_txt_list(__s,uVar1);
          return (void *)0x0;
        }
        strncpy(pcVar7,pcStack_40,__n);
        pcVar7[uStack_3c] = '\0';
        iVar4 = iVar4 + 1;
      }
    }
  }
  return __s;
}

