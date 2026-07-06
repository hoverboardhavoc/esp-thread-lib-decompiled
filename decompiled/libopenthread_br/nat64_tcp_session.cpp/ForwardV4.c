/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> ForwardV4
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::ForwardV4(unsigned char*, unsigned short) */

undefined4 __thiscall idf::TcpSession::ForwardV4(TcpSession *this,uchar *param_1,ushort param_2)

{
  code *pcVar1;
  undefined4 *puVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 in_register_00002032;
  undefined4 uVar7;
  uint __n;
  ip4_addr aiStack_34 [24];
  
  uVar5 = CONCAT22(in_register_00002032,param_2);
  if (*(int *)(this + 0x24) == 0) {
    return 0x103;
  }
  if (uVar5 < 0x28) {
    return 0x102;
  }
  if (param_1[8] < 2) {
    return 0;
  }
  iVar4 = pbuf_alloc(0xe,uVar5 + 0x14 & 0xffff,0x280);
  idf::nat64_translate_to_ip6_addr(aiStack_34);
  if (iVar4 == 0) {
    return 0x101;
  }
  sys_untimeout(OnSessionTimeout,this);
  __n = uVar5 - 0x14 & 0xffff;
  uVar5 = lwip_htons(*(undefined2 *)(param_1 + 0x20));
  if (((uVar5 & 2) != 0) && (*(int *)(this + 0x24) == 1)) {
    *(undefined4 *)(this + 0x24) = 3;
  }
  if ((uVar5 & 4) == 0) {
    if ((uVar5 & 1) == 0) {
      if (*(int *)(this + 0x24) == 2) {
        uVar7 = 3;
        goto _L36;
      }
    }
    else {
      if (*(int *)(this + 0x24) == 5) {
        uVar7 = 6;
        goto _L37;
      }
      uVar7 = 4;
_L36:
      *(undefined4 *)(this + 0x24) = uVar7;
    }
    uVar7 = 9000000;
  }
  else {
    uVar7 = 2;
_L37:
    *(undefined4 *)(this + 0x24) = uVar7;
    uVar7 = 240000;
  }
  sys_timeout(uVar7,OnSessionTimeout,this);
  puVar2 = *(undefined4 **)(iVar4 + 4);
  uVar7 = lwip_htonl((param_1[1] | 0x600) << 0x14);
  *puVar2 = uVar7;
  uVar3 = lwip_htons(__n);
  *(undefined2 *)(puVar2 + 1) = uVar3;
  *(uchar *)((int)puVar2 + 6) = param_1[9];
  *(uchar *)((int)puVar2 + 7) = param_1[8] + 0xff;
  memcpy(puVar2 + 2,aiStack_34,0x10);
  memcpy(puVar2 + 6,this + 4,0x10);
  memcpy(puVar2 + 10,param_1 + 0x14,__n);
  *(ushort *)(puVar2 + 10) = *(ushort *)(this + 0x22) >> 8 | *(ushort *)(this + 0x22) << 8;
  *(ushort *)((int)puVar2 + 0x2a) = *(ushort *)(this + 0x18) >> 8 | *(ushort *)(this + 0x18) << 8;
  pbuf_remove_header(iVar4,0x28);
  uVar3 = *(undefined2 *)(iVar4 + 8);
  *(undefined2 *)(puVar2 + 0xe) = 0;
  uVar3 = ip6_chksum_pseudo(iVar4,6,uVar3,aiStack_34,this + 4);
  *(undefined2 *)(puVar2 + 0xe) = uVar3;
  pbuf_add_header(iVar4,0x28);
  iVar6 = nat64_netif_get();
  pcVar1 = *(code **)(iVar6 + 0x1d8);
  uVar7 = nat64_netif_get();
  iVar6 = (*pcVar1)(iVar4,uVar7);
  if (iVar6 == 0) {
    return 0;
  }
  pbuf_free(iVar4);
  return 0xffffffff;
}

