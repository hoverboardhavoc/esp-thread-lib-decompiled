/*
 * Last changed at upstream commit 6520d5e47f259df6f895b7994dd6cfda4b04d195
 * https://github.com/espressif/esp-thread-lib/commit/6520d5e47f259df6f895b7994dd6cfda4b04d195
 * Upstream date: 2022-07-26 19:02:38 +0800
 * Upstream subject: br: add NAT64 and fix discovery delegate crashes
 * Source: libopenthread_br -> nat64_tcp_session.cpp.o -> ForwardV6
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::TcpSession::ForwardV6(unsigned char*, unsigned short) */

undefined4 __thiscall idf::TcpSession::ForwardV6(TcpSession *this,uchar *param_1,ushort param_2)

{
  undefined2 uVar1;
  undefined1 *puVar2;
  undefined2 uVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  undefined2 in_register_00002032;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  undefined4 auStack_38 [5];
  char cStack_24;
  
  uVar7 = CONCAT22(in_register_00002032,param_2);
  if (uVar7 < 0x14) {
    return 0x102;
  }
  iVar4 = pbuf_alloc(0x36,uVar7,0x280);
  if (iVar4 == 0) {
    return 0x101;
  }
  sys_untimeout(OnSessionTimeout,this);
  uVar5 = lwip_htons(*(undefined2 *)(param_1 + 0xc));
  if (((uVar5 & 2) != 0) && (*(int *)(this + 0x24) == 0)) {
    *(undefined4 *)(this + 0x24) = 1;
  }
  if ((uVar5 & 4) == 0) {
    if ((uVar5 & 1) == 0) {
      uVar8 = 9000000;
      if (*(int *)(this + 0x24) == 2) {
        *(undefined4 *)(this + 0x24) = 3;
      }
      goto _L0;
    }
    if (*(int *)(this + 0x24) != 4) {
      *(undefined4 *)(this + 0x24) = 5;
      uVar8 = 9000000;
      goto _L0;
    }
    uVar8 = 6;
  }
  else {
    uVar8 = 2;
  }
  *(undefined4 *)(this + 0x24) = uVar8;
  uVar8 = 24000;
_L0:
  sys_untimeout(OnSessionTimeout,this);
  sys_timeout(uVar8,OnSessionTimeout,this);
  if (*(int *)(this + 0x24) != 0) {
    pbuf_take(iVar4,param_1,uVar7);
    uVar3 = *(undefined2 *)(this + 0x20);
    puVar2 = *(undefined1 **)(iVar4 + 4);
    iVar9 = 0;
    *puVar2 = (char)((ushort)uVar3 >> 8);
    uVar1 = *(undefined2 *)(this + 0x22);
    puVar2[1] = (char)uVar3;
    puVar2[0x10] = 0;
    puVar2[2] = (char)((ushort)uVar1 >> 8);
    puVar2[3] = (char)uVar1;
    auStack_38[0] = *(undefined4 *)(this + 0x1c);
    puVar2[0x11] = 0;
    cStack_24 = '\0';
    esp_openthread_get_backbone_netif();
    iVar6 = to_underlying_lwip_netif();
    if (cStack_24 == '\x06') {
      if (iVar6 != 0) {
        iVar9 = ip6_select_source_address(auStack_38);
      }
    }
    else if (iVar6 != 0) {
      iVar9 = iVar6 + 4;
    }
    uVar3 = ip_chksum_pseudo(iVar4,6,*(undefined2 *)(iVar4 + 8),iVar9,auStack_38);
    puVar2[0x10] = (char)uVar3;
    puVar2[0x11] = (char)((ushort)uVar3 >> 8);
    raw_sendto_if_src(*(undefined4 *)this,iVar4,auStack_38,iVar6,iVar9);
  }
  pbuf_free(iVar4);
  return 0;
}

