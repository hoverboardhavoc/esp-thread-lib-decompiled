/*
 * Last changed at upstream commit ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * https://github.com/espressif/esp-thread-lib/commit/ff450cf809ca63a6ca6c833ccf4377b4848a5fa6
 * Upstream date: 2021-07-19 15:27:16 +0800
 * Upstream subject: openthread: support 1.3 border routing features
 * Source: libopenthread_br -> esp_openthread_route_table.o -> lwip_hook_ip6_route
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 * lwip_hook_ip6_route(void *param_1)

{
  byte bVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  undefined1 *puVar5;
  
  for (uVar2 = 0; uVar2 < 10; uVar2 = uVar2 + 1) {
    puVar5 = (undefined1 *)(&s_on_link_prefixes)[uVar2 * 8];
    if (puVar5 == (undefined1 *)0x0) {
      uVar2 = 0;
      puVar5 = (undefined1 *)0x0;
      goto _L0;
    }
    iVar4 = memcmp(param_1,&DAT_00010708 + uVar2 * 0x20,
                   (uint)((byte)(&DAT_0001071c)[uVar2 * 0x20] >> 3));
    if (iVar4 == 0) {
      return puVar5;
    }
  }
  uVar2 = 0;
  puVar5 = (undefined1 *)0x0;
_L0:
  do {
    if ((9 < uVar2) || (iVar4 = uVar2 * 0x38, *(int *)(s_route_entries + iVar4 + 0x34) == 0)) {
      if (puVar5 != (undefined1 *)0x0) {
        puVar5 = *(undefined1 **)(puVar5 + 0x34);
      }
      return puVar5;
    }
    bVar1 = s_route_entries[iVar4 + 0x14];
    iVar4 = memcmp(param_1,s_route_entries + iVar4,(uint)(bVar1 >> 3));
    if (iVar4 == 0) {
      if (puVar5 != (undefined1 *)0x0) {
        if ((char)puVar5[0x2c] < (char)s_route_entries[uVar2 * 0x38 + 0x2c]) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
          if ((s_route_entries[uVar2 * 0x38 + 0x2c] == puVar5[0x2c]) && ((byte)puVar5[0x14] < bVar1)
             ) {
            bVar3 = true;
          }
        }
        if (!bVar3) goto _L0;
      }
      puVar5 = s_route_entries + uVar2 * 0x38;
    }
_L0:
    uVar2 = uVar2 + 1;
  } while( true );
}

