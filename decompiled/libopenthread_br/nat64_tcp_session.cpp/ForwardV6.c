/*
 * Last changed at upstream commit b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * https://github.com/espressif/esp-thread-lib/commit/b00731fc12cbd7aa49c00b5828ee468bbd51c9b3
 * Upstream date: 2023-12-09 16:01:37 +0800
 * Upstream subject: feat(br): update border router lib     esp-openthread: 8d18b44     openthread: 41ef807
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
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  undefined2 in_register_00002032;
  uint uVar6;
  undefined4 uVar7;
  undefined1 *puVar8;
  int iVar9;
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
        uVar7 = 3;
        goto _L0;
      }
    }
    else {
      if (*(int *)(this + 0x24) == 4) {
        uVar7 = 6;
        goto _L0;
      }
      uVar7 = 5;
_L0:
      *(undefined4 *)(this + 0x24) = uVar7;
    }
    uVar7 = 9000000;
  }
  else {
    uVar7 = 2;
_L0:
    *(undefined4 *)(this + 0x24) = uVar7;
    uVar7 = 240000;
  }
  sys_timeout(uVar7,OnSessionTimeout,this);
  if (*(int *)(this + 0x24) != 0) {
    pbuf_take(iVar3,param_1,uVar6);
    uVar2 = *(undefined2 *)(this + 0x20);
    puVar8 = *(undefined1 **)(iVar3 + 4);
    iVar9 = 0;
    *puVar8 = (char)((ushort)uVar2 >> 8);
    uVar1 = *(undefined2 *)(this + 0x22);
    puVar8[1] = (char)uVar2;
    puVar8[0x10] = 0;
    puVar8[2] = (char)((ushort)uVar1 >> 8);
    puVar8[3] = (char)uVar1;
    auStack_38[0] = *(undefined4 *)(this + 0x1c);
    puVar8[0x11] = 0;
    cStack_24 = '\0';
    esp_openthread_get_backbone_netif();
    iVar5 = to_underlying_lwip_netif();
    if (cStack_24 == '\x06') {
      if (iVar5 != 0) {
        iVar9 = ip6_select_source_address(auStack_38);
      }
    }
    else if (iVar5 != 0) {
      iVar9 = iVar5 + 4;
    }
    uVar2 = ip_chksum_pseudo(iVar3,6,*(undefined2 *)(iVar3 + 8),iVar9,auStack_38);
    puVar8[0x10] = (char)uVar2;
    puVar8[0x11] = (char)((ushort)uVar2 >> 8);
    raw_sendto_if_src(*(undefined4 *)this,iVar3,auStack_38,iVar5,iVar9);
  }
  pbuf_free(iVar3);
  return 0;
}

