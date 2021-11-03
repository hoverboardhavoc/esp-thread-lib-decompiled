/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
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
  bool local_21 [9];
  
  iVar1 = esp::openthread::UartSpinelInterface::Init((esp_openthread_uart_config_t *)&DAT_000131d0);
  if (iVar1 != 0) {
    uVar2 = esp_log_timestamp();
    esp_log_write(1,"OPENTHREAD",&_LC23,uVar2,"OPENTHREAD","esp_openthread_radio_init",0x27);
    return iVar1;
  }
  iVar1 = ot::Spinel::
          RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
          SendReset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)&s_radio,'\x02');
  if ((iVar1 == 0) &&
     (iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              WaitResponse((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                            *)&s_radio), iVar1 == 0)) {
    if ((DAT_000134c4 >> 1 & 1) != 0) {
      iVar1 = ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              CheckSpinelVersion((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                  *)&s_radio);
      if (((iVar1 == 0) &&
          (iVar1 = ot::Spinel::
                   RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                   ::Get(0x12dc0,(char *)0x2,&_LC24,&DAT_00013438,0x80), iVar1 == 0)) &&
         (iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::Get(0x12dc0,(char *)0x8,&_LC25,&DAT_000134b8), iVar1 == 0)) {
        iVar1 = ot::Spinel::
                RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                ::IsRcp((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                         *)&s_radio,local_21);
        if (iVar1 == 0) {
          uVar2 = otExitCodeToString(3);
          _otLogCrit(0xd,"%s() at %s:%d: %s",
                     &ot::Spinel::
                      RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                      ::Init(bool,bool,bool)::__func__,
                     "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                     0x103,uVar2);
          __status = 3;
        }
        else {
          iVar1 = ot::Spinel::
                  RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                  ::CheckRcpApiVersion
                            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                              *)&s_radio,local_21[0]);
          if (iVar1 == 0) {
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRadioCapabilities
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio);
            if (iVar1 == 0) {
              DAT_000133c0 = &DAT_0001323c;
              DAT_000133e0 = &DAT_000132bb;
              DAT_00013400 = &DAT_0001333a;
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
            _otLogCrit(0xd,"%s() at %s:%d: %s",
                       &ot::Spinel::
                        RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        ::Init(bool,bool,bool)::__func__,
                       "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                       0x109,uVar2);
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
                                *)&s_radio,local_21[0]);
            uVar2 = 2;
            if (iVar1 != 7) {
              uVar2 = 1;
            }
            uVar2 = otExitCodeToString(uVar2);
            _otLogCrit(0xd,"%s() at %s:%d: %s",
                       &ot::Spinel::
                        RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                        ::Init(bool,bool,bool)::__func__,
                       "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",
                       0x108,uVar2);
            iVar1 = ot::Spinel::
                    RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                    ::CheckRcpApiVersion
                              ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                                *)&s_radio,local_21[0]);
          }
          __status = 2;
          if (iVar1 != 7) {
            __status = 1;
          }
        }
        goto _L0;
      }
      goto _L179;
    }
    iVar1 = 1;
    uVar2 = 1;
  }
  else {
_L179:
    uVar2 = 1;
    if (iVar1 == 7) {
      uVar2 = 2;
    }
  }
  uVar2 = otExitCodeToString(uVar2);
  _otLogCrit(0xd,"%s() at %s:%d: %s",
             &ot::Spinel::
              RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>::
              Init(bool,bool,bool)::__func__,
             "IDF/components/openthread/openthread/src/lib/spinel/radio_spinel_impl.hpp",0x111,uVar2
            );
  __status = 2;
  if (iVar1 != 7) {
    __status = 1;
  }
_L0:
                    /* WARNING: Subroutine does not return */
  exit(__status);
}

