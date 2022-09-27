/*
 * Last changed at upstream commit 8351966d029cd95b6d0b22f0168defc1c713e0ab
 * https://github.com/espressif/esp-thread-lib/commit/8351966d029cd95b6d0b22f0168defc1c713e0ab
 * Upstream date: 2022-09-27 14:18:34 +0800
 * Upstream subject: port: add flash optimization options  * esp_openthread: bbf5b0ac8  * ot-repo: e64ba13fa
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
  bool bStack_11;
  
  iVar1 = esp::openthread::UartSpinelInterface::Init((esp_openthread_uart_config_t *)&DAT_00014980);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC70,uVar2,"OPENTHREAD","esp_openthread_radio_init",0x28);
    return iVar1;
  }
  DAT_00014c74 = DAT_00014c74 | 0x10;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SendReset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio,'\x02');
  if ((iVar1 == 0) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              WaitResponse((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                            *)&s_radio), iVar1 == 0)) {
    while ((DAT_00014d18 >> 0xe & 1) != 0) {
      ot::Spinel::
      RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
      RecoverFromRcpFailure
                ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)&s_radio);
    }
    if ((DAT_00014c74 >> 1 & 1) != 0) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              CheckSpinelVersion((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                  *)&s_radio);
      if (((iVar1 == 0) &&
          (iVar1 = ot::Spinel::
                   RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   ::Get(0x14570,(char *)0x2,&_LC40,&DAT_00014be8,0x80), iVar1 == 0)) &&
         (iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::Get(0x14570,(char *)0x8,&_LC19,&DAT_00014c68), iVar1 == 0)) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::IsRcp((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio,&bStack_11);
        if (iVar1 == 0) {
          uVar2 = otExitCodeToString(3);
          otLogCritPlat("%s() at %s:%d: %s",&_LC71,
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x10c,uVar2);
          __status = 3;
        }
        else {
          iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::CheckRcpApiVersion
                            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)&s_radio,bStack_11);
          if (iVar1 == 0) {
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRadioCapabilities
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio);
            if (iVar1 == 0) {
              DAT_00014b70 = &DAT_000149f0;
              DAT_00014b90 = &DAT_00014a6f;
              DAT_00014bb0 = &DAT_00014aee;
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
            otLogCritPlat("%s() at %s:%d: %s",&_LC71,
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x112,uVar2);
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
                                *)&s_radio,bStack_11);
            uVar2 = 2;
            if (iVar1 != 7) {
              uVar2 = 1;
            }
            uVar2 = otExitCodeToString(uVar2);
            otLogCritPlat("%s() at %s:%d: %s",&_LC71,
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x111,uVar2);
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRcpApiVersion
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio,bStack_11);
          }
          __status = 2;
          if (iVar1 != 7) {
            __status = 1;
          }
        }
        goto _L0;
      }
      goto _L0;
    }
    iVar1 = 1;
    uVar2 = 1;
  }
  else {
_L0:
    uVar2 = 1;
    if (iVar1 == 7) {
      uVar2 = 2;
    }
  }
  uVar2 = otExitCodeToString(uVar2);
  otLogCritPlat("%s() at %s:%d: %s",&_LC71,
                "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x11a,
                uVar2);
  __status = 2;
  if (iVar1 != 7) {
    __status = 1;
  }
_L0:
                    /* WARNING: Subroutine does not return */
  exit(__status);
}

