/*
 * Last changed at upstream commit cab1c6e26ac83c30886f00567c15643b5a501cec
 * https://github.com/espressif/esp-thread-lib/commit/cab1c6e26ac83c30886f00567c15643b5a501cec
 * Upstream date: 2022-05-06 21:42:07 +0800
 * Upstream subject: br: update host openthread libraries for rcp update(af058a8)
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> esp_openthread_radio_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_openthread_radio_init(void)

{
  int iVar1;
  undefined4 uVar2;
  int __status;
  bool local_11;
  
  iVar1 = esp::openthread::UartSpinelInterface::Init((esp_openthread_uart_config_t *)&DAT_000140d8);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC52,uVar2,"OPENTHREAD","esp_openthread_radio_init",0x28);
    return iVar1;
  }
  DAT_000143cc = DAT_000143cc | 0x10;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SendReset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio,'\x02');
  if ((iVar1 == 0) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              WaitResponse((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                            *)&s_radio), iVar1 == 0)) {
    while (DAT_00014470 << 0x11 < 0) {
      ot::Spinel::
      RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
      RecoverFromRcpFailure
                ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)&s_radio);
    }
    if ((DAT_000143cc >> 1 & 1) != 0) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              CheckSpinelVersion((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                  *)&s_radio);
      if (((iVar1 == 0) &&
          (iVar1 = ot::Spinel::
                   RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   ::Get(0x13cc8,(char *)0x2,&_LC29,&DAT_00014340,0x80), iVar1 == 0)) &&
         (iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::Get(0x13cc8,(char *)0x8,&_LC17,&DAT_000143c0), iVar1 == 0)) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::IsRcp((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio,&local_11);
        if (iVar1 == 0) {
          uVar2 = otExitCodeToString(3);
          otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x10b,uVar2);
          __status = 3;
        }
        else {
          iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::CheckRcpApiVersion
                            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)&s_radio,local_11);
          if (iVar1 == 0) {
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRadioCapabilities
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio);
            if (iVar1 == 0) {
              DAT_000142c8 = &DAT_00014148;
              DAT_000142e8 = &DAT_000141c7;
              DAT_00014308 = &DAT_00014246;
              iVar1 = esp_openthread_platform_workflow_register
                                (esp_openthread_radio_update,esp_openthread_radio_process,
                                 "radio_uart");
              return iVar1;
            }
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRadioCapabilities
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio);
            uVar2 = 2;
            if (iVar1 != 7) {
              uVar2 = 1;
            }
            uVar2 = otExitCodeToString(uVar2);
            otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x111,uVar2);
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRadioCapabilities
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio);
          }
          else {
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRcpApiVersion
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio,local_11);
            uVar2 = 2;
            if (iVar1 != 7) {
              uVar2 = 1;
            }
            uVar2 = otExitCodeToString(uVar2);
            otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x110,uVar2);
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRcpApiVersion
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio,local_11);
          }
          __status = 2;
          if (iVar1 != 7) {
            __status = 1;
          }
        }
        goto _L0;
      }
      goto _L594;
    }
    iVar1 = 1;
    uVar2 = 1;
  }
  else {
_L594:
    uVar2 = 1;
    if (iVar1 == 7) {
      uVar2 = 2;
    }
  }
  uVar2 = otExitCodeToString(uVar2);
  otLogCritPlat("%s() at %s:%d: %s","BSD TCP function",
                "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x119,
                uVar2);
  __status = 2;
  if (iVar1 != 7) {
    __status = 1;
  }
_L0:
                    /* WARNING: Subroutine does not return */
  exit(__status);
}

