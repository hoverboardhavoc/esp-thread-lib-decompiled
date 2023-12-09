/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> ForwardV4
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::ForwardV4(unsigned char*, unsigned short) */

undefined4 __thiscall idf::TcpSession::ForwardV4(TcpSession *this,uchar *param_1,ushort param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  code *pcVar3;
  undefined2 uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined2 in_register_00002032;
  undefined4 uVar8;
  uint uVar9;
  ip4_addr aiStack_34 [24];
  
  uVar9 = CONCAT22(in_register_00002032,param_2);
  if (*(int *)(this + 0x24) == 0) {
    return 0x103;
  }
  if (uVar9 < 0x28) {
    return 0x102;
  }
  if (param_1[8] < 2) {
    return 0;
  }
  iVar5 = pbuf_alloc(0xe,uVar9 + 0x14 & 0xffff,0x280);
  idf::nat64_translate_to_ip6_addr(aiStack_34);
  if (iVar5 == 0) {
    return 0x101;
  }
  sys_untimeout(OnSessionTimeout,this);
  uVar6 = lwip_htons(*(undefined2 *)(param_1 + 0x20));
  if (((uVar6 & 2) != 0) && (*(int *)(this + 0x24) == 1)) {
    *(undefined4 *)(this + 0x24) = 3;
  }
  if ((uVar6 & 4) == 0) {
    if ((uVar6 & 1) == 0) {
      if (*(int *)(this + 0x24) == 2) {
        uVar8 = 3;
        goto _L0;
      }
    }
    else {
      if (*(int *)(this + 0x24) == 5) {
        uVar8 = 6;
        goto _L0;
      }
      uVar8 = 4;
_L0:
      *(undefined4 *)(this + 0x24) = uVar8;
    }
    uVar8 = 9000000;
  }
  else {
    uVar8 = 2;
_L0:
    *(undefined4 *)(this + 0x24) = uVar8;
    uVar8 = 240000;
  }
  sys_timeout(uVar8,OnSessionTimeout,this);
  puVar2 = *(undefined1 **)(iVar5 + 4);
  uVar8 = lwip_htonl((uint)param_1[1] << 0x14 | 0x60000000);
  *puVar2 = (char)uVar8;
  puVar2[1] = (char)((uint)uVar8 >> 8);
  uVar9 = uVar9 - 0x14 & 0xffff;
  puVar2[2] = (char)((uint)uVar8 >> 0x10);
  puVar2[3] = (char)((uint)uVar8 >> 0x18);
  uVar4 = lwip_htons(uVar9);
  puVar2[4] = (char)uVar4;
  puVar2[5] = (char)((ushort)uVar4 >> 8);
  puVar2[6] = param_1[9];
  puVar2[7] = param_1[8] + 0xff;
  memcpy(puVar2 + 8,aiStack_34,0x10);
  memcpy(puVar2 + 0x18,this + 4,0x10);
  memcpy(puVar2 + 0x28,param_1 + 0x14,uVar9);
  uVar4 = *(undefined2 *)(this + 0x22);
  puVar2[0x28] = (char)((ushort)uVar4 >> 8);
  uVar1 = *(undefined2 *)(this + 0x18);
  puVar2[0x29] = (char)uVar4;
  puVar2[0x2a] = (char)((ushort)uVar1 >> 8);
  puVar2[0x2b] = (char)uVar1;
  pbuf_remove_header(iVar5,0x28);
  uVar4 = *(undefined2 *)(iVar5 + 8);
  puVar2[0x38] = 0;
  puVar2[0x39] = 0;
  uVar4 = ip6_chksum_pseudo(iVar5,6,uVar4,aiStack_34,this + 4);
  puVar2[0x38] = (char)uVar4;
  puVar2[0x39] = (char)((ushort)uVar4 >> 8);
  pbuf_add_header(iVar5,0x28);
  iVar7 = nat64_netif_get();
  pcVar3 = *(code **)(iVar7 + 0x154);
  uVar8 = nat64_netif_get();
  iVar7 = (*pcVar3)(iVar5,uVar8);
  if (iVar7 == 0) {
    return 0;
  }
  pbuf_free(iVar5);
  return 0xffffffff;
}

