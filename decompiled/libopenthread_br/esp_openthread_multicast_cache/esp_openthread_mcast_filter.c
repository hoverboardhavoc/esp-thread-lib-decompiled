/*
 * Last changed at upstream commit baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * https://github.com/espressif/esp-thread-lib/commit/baa93a0cffc57c2f9cb0518d2e5ab3518ae5fa88
 * Upstream date: 2025-10-23 04:21:23 +0000
 * Upstream subject: feat(openthread): update thread-lib for new OT upstream 36b14d3ef
 * Source: libopenthread_br -> esp_openthread_multicast_cache.o -> esp_openthread_mcast_filter
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_openthread_mcast_filter(int *param_1,int *param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int iVar13;
  
  iVar13 = *param_1;
  iVar12 = param_1[1];
  iVar11 = param_1[2];
  iVar10 = param_1[3];
  iVar9 = *param_2;
  iVar8 = param_2[1];
  iVar7 = param_2[2];
  iVar6 = param_2[3];
  puVar5 = s_mf_cache_list;
  do {
    if (puVar5 == (undefined4 *)0x0) {
      iVar1 = param_2[4];
      iVar2 = param_1[4];
      uVar4 = esp_openthread_get_alloc_caps();
      puVar5 = (undefined4 *)heap_caps_calloc(1,0x38,uVar4);
      if (puVar5 == (undefined4 *)0x0) {
_L14:
        uVar4 = 0;
      }
      else {
        puVar5[2] = iVar13;
        puVar5[3] = iVar12;
        puVar5[4] = iVar11;
        puVar5[5] = iVar10;
        *(char *)(puVar5 + 6) = (char)iVar2;
        puVar5[7] = iVar9;
        puVar5[8] = iVar8;
        puVar5[9] = iVar7;
        puVar5[10] = iVar6;
        *(char *)(puVar5 + 0xb) = (char)iVar1;
        puVar5[0xd] = param_4;
        puVar5[0xc] = param_3;
        *puVar5 = 0;
        puVar5[1] = 0;
        puVar3 = puVar5;
        if (s_mf_cache_list != (undefined4 *)0x0) {
          *puVar5 = s_mf_cache_list;
          s_mf_cache_list[1] = puVar5;
        }
_L25:
        s_mf_cache_list = puVar3;
        sys_timeout(10000,0x10000,puVar5);
        uVar4 = 1;
      }
      return uVar4;
    }
    if (((((puVar5[2] == iVar13) && (puVar5[3] == iVar12)) && (puVar5[4] == iVar11)) &&
        ((puVar5[5] == iVar10 && (puVar5[7] == iVar9)))) &&
       ((puVar5[8] == iVar8 && ((puVar5[9] == iVar7 && (puVar5[10] == iVar6)))))) {
      if ((puVar5[0xc] != param_3) || (puVar5[0xd] != param_4)) goto _L14;
      sys_untimeout(0x10000,puVar5);
      puVar3 = s_mf_cache_list;
      goto _L25;
    }
    puVar5 = (undefined4 *)*puVar5;
  } while( true );
}

