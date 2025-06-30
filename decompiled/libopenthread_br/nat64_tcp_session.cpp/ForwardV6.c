/*
 * Last changed at upstream commit 8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * https://github.com/espressif/esp-thread-lib/commit/8f3bd568ba77a5194e501b849966bc0ea16a8aff
 * Upstream date: 2025-06-30 12:13:17 +0000
 * Upstream subject: fix(discovery): use mesh local for self-hosted service if OMR is not preferred
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> ForwardV6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::ForwardV6(unsigned char*, unsigned short) */

undefined4 __thiscall idf::TcpSession::ForwardV6(TcpSession *this,uchar *param_1,ushort param_2)

{
  undefined1 *puVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 in_register_00002032;
  uint uVar6;
  int iVar7;
  undefined4 uVar8;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  uVar6 = CONCAT22(in_register_00002032,param_2);
  if (uVar6 < 0x14) {
    return 0x102;
  }
  iVar3 = pbuf_alloc(0x36,uVar6,0x280);
  if (iVar3 == 0) {
    return 0x101;
  }
  sys_untimeout(OnSessionTimeout,this);
  uVar4 = lwip_htons(*(undefined2 *)(param_1 + 0xc));
  if (((uVar4 & 2) != 0) && (*(int *)(this + 0x24) == 0)) {
    *(undefined4 *)(this + 0x24) = 1;
  }
  if ((uVar4 & 4) == 0) {
    if ((uVar4 & 1) == 0) {
      if (*(int *)(this + 0x24) == 2) {
        uVar8 = 3;
        goto _L67;
      }
    }
    else {
      if (*(int *)(this + 0x24) == 4) {
        uVar8 = 6;
        goto _L68;
      }
      uVar8 = 5;
_L67:
      *(undefined4 *)(this + 0x24) = uVar8;
    }
    uVar8 = 9000000;
  }
  else {
    uVar8 = 2;
_L68:
    *(undefined4 *)(this + 0x24) = uVar8;
    uVar8 = 240000;
  }
  sys_timeout(uVar8,OnSessionTimeout,this);
  if (*(int *)(this + 0x24) != 0) {
    pbuf_take(iVar3,param_1,uVar6);
    uVar2 = *(undefined2 *)(this + 0x20);
    puVar1 = *(undefined1 **)(iVar3 + 4);
    *puVar1 = (char)((ushort)uVar2 >> 8);
    puVar1[1] = (char)uVar2;
    uVar2 = *(undefined2 *)(this + 0x22);
    puVar1[0x10] = 0;
    puVar1[0x11] = 0;
    puVar1[2] = (char)((ushort)uVar2 >> 8);
    puVar1[3] = (char)uVar2;
    auStack_38[0] = *(undefined4 *)(this + 0x1c);
    cStack_24 = '\0';
    esp_openthread_get_backbone_netif();
    iVar5 = to_underlying_lwip_netif();
    iVar7 = 0;
    if (cStack_24 == '\x06') {
      if (iVar5 != 0) {
        iVar7 = ip6_select_source_address(auStack_38);
      }
    }
    else if (iVar5 != 0) {
      iVar7 = iVar5 + 4;
    }
    uVar2 = ip_chksum_pseudo(iVar3,6,*(undefined2 *)(iVar3 + 8),auStack_38);
    puVar1[0x10] = (char)uVar2;
    puVar1[0x11] = (char)((ushort)uVar2 >> 8);
    raw_sendto_if_src(*(undefined4 *)this,iVar3,auStack_38,iVar5,iVar7);
  }
  pbuf_free(iVar3);
  return 0;
}

