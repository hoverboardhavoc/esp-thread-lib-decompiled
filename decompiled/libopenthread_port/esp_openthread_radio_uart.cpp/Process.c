/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_openthread_radio_uart.cpp.o -> Process
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,
   esp_openthread_mainloop_context_t>::Process(esp_openthread_mainloop_context_t const&) */

void ot::Spinel::RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
     ::Process(esp_openthread_mainloop_context_t *param_1)

{
  if (param_1 + 10 != *(esp_openthread_mainloop_context_t **)(param_1 + 0x40c)) {
    ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       *)param_1);
  }
  esp::openthread::UartSpinelInterface::Process(param_1 + 0x410);
  if (*(esp_openthread_mainloop_context_t **)(param_1 + 0x40c) != param_1 + 10) {
    ProcessFrameQueue((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                       *)param_1);
  }
  ProcessRadioStateMachine
            ((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t> *)
             param_1);
  CalcRcpTimeOffset((RadioSpinel<esp::openthread::UartSpinelInterface,esp_openthread_mainloop_context_t>
                     *)param_1);
  return;
}

