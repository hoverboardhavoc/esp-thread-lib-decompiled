/*
 * Last changed at upstream commit c9af7b259218417072614ad265e7e896db15b49a
 * https://github.com/espressif/esp-thread-lib/commit/c9af7b259218417072614ad265e7e896db15b49a
 * Upstream date: 2021-08-27 13:57:40 +0800
 * Upstream subject: openthread: support ESP32-H2 chip(00e1885)
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::Write(unsigned char const*, unsigned short) */

int __thiscall
esp::openthread::UartSpinelInterface::Write(UartSpinelInterface *this,uchar *param_1,ushort param_2)

{
  code *pcVar1;
  size_t __n;
  uint uVar2;
  int iVar3;
  UartSpinelInterface *this_00;
  undefined4 uVar4;
  ushort extraout_a1;
  undefined2 in_register_00002032;
  int iVar5;
  Encoder aEStack_450 [8];
  uchar *puStack_448;
  undefined2 uStack_444;
  uchar auStack_442 [1038];
  int iStack_34;
  UartSpinelInterface *pUStack_30;
  uchar *puStack_2c;
  size_t sStack_28;
  code *pcStack_24;
  
  __n = CONCAT22(in_register_00002032,param_2);
  iVar5 = 0;
_L0:
  do {
    if (__n == 0) {
      return iVar5;
    }
    uVar2 = write(*(int *)(this + 0x4c),param_1,__n);
    if (0 < (int)uVar2) {
      if ((int)uVar2 <= (int)__n) {
        __n = __n - uVar2 & 0xffff;
        param_1 = param_1 + (uVar2 & 0xffff);
        goto _L0;
      }
      uVar2 = __assert_func("//home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                            ,0xbd,
                            "otError esp::openthread::UartSpinelInterface::Write(const uint8_t*, uint16_t)"
                            ,"rval <= length");
    }
    if ((int)uVar2 < 0) {
      iVar3 = TryRecoverUart(this);
      if (iVar3 == 0) {
        return 1;
      }
      pcVar1 = SendFrame;
      this_00 = (UartSpinelInterface *)
                _esp_error_check_failed
                          ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                           ,0xc2,
                           "otError esp::openthread::UartSpinelInterface::Write(const uint8_t*, uint16_t)"
                           ,"TryRecoverUart()");
      puStack_448 = auStack_442;
      uStack_444 = 0x400;
      iStack_34 = iVar5;
      pUStack_30 = this;
      puStack_2c = param_1;
      sStack_28 = __n;
      pcStack_24 = pcVar1;
      ot::Hdlc::Encoder::Encoder(aEStack_450,(FrameWritePointer *)&puStack_448);
      iVar5 = ot::Hdlc::Encoder::BeginFrame();
      if (((iVar5 == 0) &&
          (iVar5 = ot::Hdlc::Encoder::Encode((uchar *)aEStack_450,extraout_a1), iVar5 == 0)) &&
         (iVar5 = ot::Hdlc::Encoder::EndFrame(), iVar5 == 0)) {
        iVar5 = Write(this_00,auStack_442,(short)puStack_448 - (short)auStack_442);
      }
      if (iVar5 != 0) {
        uVar4 = esp_log_timestamp();
        esp_log_write(1,"OPENTHREAD",&_LC10,uVar4,"OPENTHREAD");
      }
      return iVar5;
    }
    iVar5 = WaitForWritable(this);
    if (iVar5 != 0) {
      return iVar5;
    }
  } while( true );
}

