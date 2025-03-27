/*
 * Last changed at upstream commit 151fd03b3353ca155fa974338a1361fcc6904cd9
 * https://github.com/espressif/esp-thread-lib/commit/151fd03b3353ca155fa974338a1361fcc6904cd9
 * Upstream date: 2025-03-27 16:04:28 +0800
 * Upstream subject: feat(openthread): update thread-lib to support BR DNS resolution
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
  char *pcVar3;
  undefined4 uVar4;
  undefined4 auStack_28 [5];
  undefined1 uStack_14;
  
  sys_timeout(3600000,OnSessionTimeout,this);
  iVar1 = udp_new();
  *(int *)(this + 0x24) = iVar1;
  if (iVar1 == 0) {
    uVar2 = esp_log_timestamp();
    uVar4 = 0x3d;
    pcVar3 = "E (%lu) %s: %s(%d): Failed to open udp pcb\n";
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
    uVar4 = 0x49;
    pcVar3 = "E (%lu) %s: %s(%d): Failed to connect to nat64 src\n";
  }
  esp_log(1,"NAT64",pcVar3,uVar2,"NAT64",&_LC5,uVar4);
  Close(this);
  return 0xffffffff;
}

