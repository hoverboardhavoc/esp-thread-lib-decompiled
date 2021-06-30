/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> IsRcp
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: bool
   IsRcp(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *
   this, bool * aSupportsRcpApiVersion) */

bool __thiscall
ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t>::
IsRcp(RadioSpinel<esp::openthread::UartSpinelInterface,_esp_openthread_mainloop_context_t> *this,
     bool *aSupportsRcpApiVersion)

{
  bool bVar1;
  bool bVar2;
  spinel_size_t *psVar3;
  otError oVar4;
  undefined4 uVar5;
  int iVar6;
  int iStack_8c;
  uint capability;
  spinel_size_t capsLength;
  uint8_t capsBuffer [100];
  
  capability = 100;
  *aSupportsRcpApiVersion = false;
  oVar4 = Get(this,5,"D",&capsLength,&capability);
  if (oVar4 != OT_ERROR_NONE) {
    oVar4 = Get(this,5,"D",&capsLength,&capability);
    if (oVar4 == OT_ERROR_INVALID_ARGS) {
      uVar5 = 2;
    }
    else {
      uVar5 = 1;
    }
    uVar5 = otExitCodeToString(uVar5);
    otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","IsRcp",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x137,
              uVar5);
    oVar4 = Get(this,5,"D",&capsLength,&capability);
    if (oVar4 == OT_ERROR_INVALID_ARGS) {
      iVar6 = 2;
    }
    else {
      iVar6 = 1;
    }
                    /* WARNING: Subroutine does not return */
    exit(iVar6);
  }
  bVar2 = false;
  bVar1 = false;
  psVar3 = &capsLength;
  for (; capability != 0; capability = capability - iVar6) {
    iVar6 = spinel_datatype_unpack(psVar3,&_LC14,&iStack_8c);
    if (iVar6 < 1) {
      uVar5 = otExitCodeToString(3);
      otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","IsRcp",
                "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x13f,
                uVar5);
                    /* WARNING: Subroutine does not return */
      exit(3);
    }
    if (iStack_8c == 0x201) {
      bVar1 = true;
    }
    if (iStack_8c == 0x22) {
      bVar2 = true;
    }
    if (iStack_8c == 0x206) {
      this->field_0x704 = this->field_0x704 | 4;
    }
    if (iStack_8c == 0x40) {
      *aSupportsRcpApiVersion = true;
    }
    psVar3 = (spinel_size_t *)((int)psVar3 + iVar6);
  }
  if ((!bVar1) && (bVar2)) {
    otLogCrit(0xc,_LC2,"RCP capability list does not include support for radio/raw mode");
    uVar5 = otExitCodeToString(3);
    otLogCrit(0xc,_LC2,"%s() at %s:%d: %s","IsRcp",
              "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x15c,
              uVar5);
                    /* WARNING: Subroutine does not return */
    exit(3);
  }
  return bVar2;
}

