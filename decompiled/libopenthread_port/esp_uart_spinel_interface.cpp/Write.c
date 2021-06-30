/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Write
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* WARNING: Struct "FrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: otError Write(UartSpinelInterface * this, uint8_t * aFrame, uint16_t
   length) */

otError __thiscall
esp::openthread::UartSpinelInterface::Write
          (UartSpinelInterface *this,uint8_t *aFrame,uint16_t length)

{
  code *pcVar1;
  size_t __n;
  uint uVar2;
  esp_err_t eVar3;
  UartSpinelInterface *this_00;
  ushort extraout_a1;
  undefined2 in_register_00002032;
  otError oVar4;
  Encoder EStack_450;
  FrameWritePointer aFStack_448 [130];
  otError oStack_34;
  UartSpinelInterface *pUStack_30;
  uint8_t *puStack_2c;
  size_t sStack_28;
  code *pcStack_24;
  
  __n = CONCAT22(in_register_00002032,length);
  oVar4 = OT_ERROR_NONE;
_L0:
  do {
    if (__n == 0) {
      return oVar4;
    }
    uVar2 = write(this->m_uart_fd,aFrame,__n);
    if (0 < (int)uVar2) {
      if ((int)uVar2 <= (int)__n) {
        __n = __n - uVar2 & 0xffff;
        aFrame = aFrame + (uVar2 & 0xffff);
        goto _L0;
      }
      uVar2 = __assert_func("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                            ,0xbf,
                            "otError esp::openthread::UartSpinelInterface::Write(const uint8_t*, uint16_t)"
                            ,"rval <= length");
    }
    if ((int)uVar2 < 0) {
      eVar3 = TryRecoverUart(this);
      if (eVar3 == 0) {
        return OT_ERROR_FAILED;
      }
      pcVar1 = SendFrame;
      this_00 = (UartSpinelInterface *)
                _esp_error_check_failed
                          ("/home/guojiacheng/esp-openthread/components/openthread_port/src/esp_uart_spinel_interface.cpp"
                           ,0xc4,
                           "otError esp::openthread::UartSpinelInterface::Write(const uint8_t*, uint16_t)"
                           ,"TryRecoverUart()");
      aFStack_448[0].mWritePointer = &aFStack_448[0].field_0x6;
      aFStack_448[0].mRemainingLength = 0x400;
      oStack_34 = oVar4;
      pUStack_30 = this;
      puStack_2c = aFrame;
      sStack_28 = __n;
      pcStack_24 = pcVar1;
      ot::Hdlc::Encoder::Encoder(&EStack_450,aFStack_448);
      oVar4 = ot::Hdlc::Encoder::BeginFrame();
      if (((oVar4 == OT_ERROR_NONE) &&
          (oVar4 = ot::Hdlc::Encoder::Encode((uchar *)&EStack_450,extraout_a1),
          oVar4 == OT_ERROR_NONE)) &&
         (oVar4 = ot::Hdlc::Encoder::EndFrame(), oVar4 == OT_ERROR_NONE)) {
        oVar4 = Write(this_00,&aFStack_448[0].field_0x6,
                      (short)aFStack_448[0].mWritePointer - (short)&aFStack_448[0].field_0x6);
      }
      if (oVar4 != OT_ERROR_NONE) {
        otLogCrit(0xc,"-PLAT----: ","send radio frame failed");
      }
      return oVar4;
    }
    oVar4 = WaitForWritable(this);
    if (oVar4 != OT_ERROR_NONE) {
      return oVar4;
    }
  } while( true );
}

