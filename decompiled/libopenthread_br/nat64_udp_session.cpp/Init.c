/*
 * Last changed at upstream commit e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * https://github.com/espressif/esp-thread-lib/commit/e03f5d45ad69eb97243fdb2790c4ac815a3a888c
 * Upstream date: 2023-09-07 16:10:51 +0800
 * Upstream subject: feat(br): support br deinit
 * Source: libopenthread_br -> nat64_udp_session.cpp.o -> Init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* idf::UdpSession::Init(unsigned short) */

undefined4 __thiscall idf::UdpSession::Init(UdpSession *this,ushort param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined2 in_register_0000202e;
  undefined *puVar3;
  undefined4 uVar4;
  undefined4 auStack_28 [5];
  undefined1 uStack_14;
  
  sys_timeout(3600000,OnSessionTimeout,this);
  iVar1 = udp_new();
  *(int *)(this + 0x24) = iVar1;
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x40;
    puVar3 = &_LC6;
  }
  else {
    iVar1 = udp_bind(0,CONCAT22(in_register_0000202e,param_1));
    if (iVar1 == -8) {
      udp_bind(*(undefined4 *)(this + 0x24),0,0);
    }
    auStack_28[0] = *(undefined4 *)(this + 0x18);
    uStack_14 = 0;
    iVar1 = udp_connect(*(undefined4 *)(this + 0x24),auStack_28,*(undefined2 *)(this + 0x1c));
    if (iVar1 == 0) {
      udp_recv(*(undefined4 *)(this + 0x24),OnDestUdpReceived,this);
      return 0;
    }
    uVar2 = esp_log_timestamp();
    uVar4 = 0x4c;
    puVar3 = &_LC7;
  }
  esp_log_write(1,"NAT64",puVar3,uVar2,"NAT64",&::_L0,uVar4);
  Close(this);
  return 0xffffffff;
}

