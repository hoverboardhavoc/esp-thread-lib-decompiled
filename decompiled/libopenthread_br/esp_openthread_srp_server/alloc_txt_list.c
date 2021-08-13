/*
 * Last changed at upstream commit 890c02a030889a748de31dd01d156f69430d6f15
 * https://github.com/espressif/esp-thread-lib/commit/890c02a030889a748de31dd01d156f69430d6f15
 * Upstream date: 2021-08-13 18:14:00 +0800
 * Upstream subject: update libopenthread_port.a
 * Source: libopenthread_br -> esp_openthread_srp_server.o -> alloc_txt_list
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void * alloc_txt_list(undefined1 *param_1)

{
  uint uVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  int iVar4;
  void *__s;
  int iVar5;
  char *pcVar6;
  size_t sVar7;
  char *pcStack_44;
  char *pcStack_40;
  ushort uStack_3c;
  undefined1 auStack_38 [22];
  undefined2 auStack_22 [5];
  
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
        pcVar6 = (char *)malloc(0x41);
        if ((pcVar6 == (char *)0x0) || (sVar7 = strnlen(pcStack_44,0x41), 0x40 < sVar7)) {
          free_txt_list(__s,uVar1);
          return (void *)0x0;
        }
        strncpy(pcVar6,pcStack_44,0x40);
        pcVar6[0x40] = '\0';
        puVar2 = (undefined4 *)(iVar4 * 8 + (int)__s);
        *puVar2 = pcVar6;
        pcVar6 = (char *)malloc(0x41);
        if ((pcVar6 == (char *)0x0) || (0x40 < uStack_3c)) {
          free_txt_list(__s,uVar1);
          return (void *)0x0;
        }
        strncpy(pcVar6,pcStack_40,(uint)uStack_3c);
        pcVar6[uStack_3c] = '\0';
        puVar2[1] = pcVar6;
        iVar4 = iVar4 + 1;
      }
    }
  }
  return __s;
}

