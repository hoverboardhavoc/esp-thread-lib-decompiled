/*
 * Last changed at upstream commit 62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * https://github.com/espressif/esp-thread-lib/commit/62d501187e49d6ccf7b99bd6a59fdf47e0243219
 * Upstream date: 2022-12-06 21:56:45 +0800
 * Upstream subject: lib: fix multi br forwarding ping reply
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
  
  iVar1 = esp::openthread::UartSpinelInterface::Init((esp_openthread_uart_config_t *)&DAT_00015d30);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC146,uVar2,"OPENTHREAD","esp_openthread_radio_init",0x28);
    return iVar1;
  }
  DAT_00016024 = DAT_00016024 | 0x10;
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SendReset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio,'\x02');
  if ((iVar1 == 0) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              WaitResponse((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                            *)&s_radio), iVar1 == 0)) {
    while ((DAT_000160c8 >> 0xe & 1) != 0) {
      ot::Spinel::
      RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
      RecoverFromRcpFailure
                ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  *)&s_radio);
    }
    if ((DAT_00016024 >> 1 & 1) != 0) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              CheckSpinelVersion((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                  *)&s_radio);
      if (((iVar1 == 0) &&
          (iVar1 = ot::Spinel::
                   RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   ::Get(0x15920,(char *)0x2,&_LC52,&DAT_00015f98,0x80), iVar1 == 0)) &&
         (iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::Get(0x15920,(char *)0x8,&_LC66,&DAT_00016018), iVar1 == 0)) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::IsRcp((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio,&bStack_11);
        if (iVar1 == 0) {
          uVar2 = otExitCodeToString(3);
          otLogCritPlat("%s() at %s:%d: %s",&_LC147,
                        "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                        ,0x10f,uVar2);
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
              DAT_00015f20 = &DAT_00015da0;
              DAT_00015f40 = &DAT_00015e1f;
              DAT_00015f60 = &DAT_00015e9e;
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
            otLogCritPlat("%s() at %s:%d: %s",&_LC147,
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x115,uVar2);
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
            otLogCritPlat("%s() at %s:%d: %s",&_LC147,
                          "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp"
                          ,0x114,uVar2);
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
  otLogCritPlat("%s() at %s:%d: %s",&_LC147,
                "/IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x11d,
                uVar2);
  __status = 2;
  if (iVar1 != 7) {
    __status = 1;
  }
_L0:
                    /* WARNING: Subroutine does not return */
  exit(__status);
}

