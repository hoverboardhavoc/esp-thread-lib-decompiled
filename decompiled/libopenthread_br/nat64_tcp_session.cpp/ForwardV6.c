/*
 * Last changed at upstream commit be3cf518ee046640e217baf52315665cd7798a32
 * https://github.com/espressif/esp-thread-lib/commit/be3cf518ee046640e217baf52315665cd7798a32
 * Upstream date: 2026-07-06 09:06:22 +0000
 * Upstream subject: feat(openthread): update thread-lib for upstream b678a4f6
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> ForwardV6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::ForwardV6(unsigned char*, unsigned short) */

undefined4 __thiscall idf::TcpSession::ForwardV6(TcpSession *this,uchar *param_1,ushort param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined2 in_register_00002032;
  uint uVar5;
  int iVar6;
  undefined4 uVar7;
  ushort *puVar8;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  uVar5 = CONCAT22(in_register_00002032,param_2);
  if (uVar5 < 0x14) {
    return 0x102;
  }
  iVar2 = pbuf_alloc(0x36,uVar5,0x280);
  if (iVar2 == 0) {
    return 0x101;
  }
  sys_untimeout(OnSessionTimeout,this);
  uVar3 = lwip_htons(*(undefined2 *)(param_1 + 0xc));
  if (((uVar3 & 2) != 0) && (*(int *)(this + 0x24) == 0)) {
    *(undefined4 *)(this + 0x24) = 1;
  }
  if ((uVar3 & 4) == 0) {
    if ((uVar3 & 1) == 0) {
      if (*(int *)(this + 0x24) == 2) {
        uVar7 = 3;
        goto _L67;
      }
    }
    else {
      if (*(int *)(this + 0x24) == 4) {
        uVar7 = 6;
        goto _L68;
      }
      uVar7 = 5;
_L67:
      *(undefined4 *)(this + 0x24) = uVar7;
    }
    uVar7 = 9000000;
  }
  else {
    uVar7 = 2;
_L68:
    *(undefined4 *)(this + 0x24) = uVar7;
    uVar7 = 240000;
  }
  sys_timeout(uVar7,OnSessionTimeout,this);
  if (*(int *)(this + 0x24) == 0) goto _L47;
  pbuf_take(iVar2,param_1,uVar5);
  puVar8 = *(ushort **)(iVar2 + 4);
  *puVar8 = *(ushort *)(this + 0x20) >> 8 | *(ushort *)(this + 0x20) << 8;
  uVar1 = *(ushort *)(this + 0x22);
  puVar8[8] = 0;
  puVar8[1] = uVar1 >> 8 | uVar1 << 8;
  auStack_38[0] = *(undefined4 *)(this + 0x1c);
  cStack_24 = '\0';
  esp_openthread_get_backbone_netif();
  iVar4 = to_underlying_lwip_netif();
  if (cStack_24 == '\x06') {
    if (iVar4 == 0) {
_L51:
      iVar6 = 0;
    }
    else {
      iVar6 = ip6_select_source_address(auStack_38);
    }
  }
  else {
    if (iVar4 == 0) goto _L51;
    iVar6 = iVar4 + 4;
  }
  uVar1 = ip_chksum_pseudo(iVar2,6,*(undefined2 *)(iVar2 + 8),auStack_38);
  puVar8[8] = uVar1;
  raw_sendto_if_src(*(undefined4 *)this,iVar2,auStack_38,iVar4,iVar6);
_L47:
  pbuf_free(iVar2);
  return 0;
}

