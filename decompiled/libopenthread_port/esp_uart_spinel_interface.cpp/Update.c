/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> Update
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Struct "MultiFrameBuffer<1024>": ignoring overlapping field "mBuffer" */
/* DWARF original prototype: void Update(UartSpinelInterface * this,
   esp_openthread_mainloop_context_t * mainloop) */

void __thiscall
esp::openthread::UartSpinelInterface::Update
          (UartSpinelInterface *this,esp_openthread_mainloop_context_t *mainloop)

{
  uint uVar1;
  fd_mask *pfVar2;
  
  uVar1 = this->m_uart_fd;
  if (uVar1 < 0x40) {
    pfVar2 = (mainloop->read_fds).fds_bits + (uVar1 >> 5);
    *pfVar2 = *pfVar2 | 1 << (uVar1 & 0x1f);
  }
  if (mainloop->max_fd < this->m_uart_fd) {
    mainloop->max_fd = this->m_uart_fd;
  }
  return;
}

