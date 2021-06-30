/*
 * Last changed at upstream commit 42db25b3f71f29085e6f6065b22939bc090787db
 * https://github.com/espressif/esp-thread-lib/commit/42db25b3f71f29085e6f6065b22939bc090787db
 * Upstream date: 2021-06-30 15:48:18 +0800
 * Upstream subject: openthread: initial libraries
 * Source: libopenthread_port -> esp_openthread_udp.o -> map_openthread_addr_to_lwip_addr
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void map_openthread_addr_to_lwip_addr(otIp6Address *address)

{
  u32_t *in_a0;
  u32_t uStack_28;
  ip_addr_t addr;
  
  memcpy(&uStack_28,address,0x10);
  if (((uStack_28 == 0) && (addr.u_addr.ip6.addr[0] == 0)) &&
     (addr.u_addr.ip6.addr[1] == 0xffff0000)) {
    uStack_28 = addr.u_addr.ip6.addr[2];
    addr.u_addr._16_4_ = (uint)(uint3)addr.u_addr._17_3_ << 8;
  }
  else {
    addr.u_addr.ip6.zone = 6;
    addr.u_addr.ip6.addr[3] = addr.u_addr.ip6.addr[3] & 0xffffff00;
  }
  *in_a0 = uStack_28;
  in_a0[1] = addr.u_addr.ip6.addr[0];
  in_a0[2] = addr.u_addr.ip6.addr[1];
  in_a0[3] = addr.u_addr.ip6.addr[2];
  in_a0[4] = addr.u_addr.ip6.addr[3];
  in_a0[5] = addr.u_addr._16_4_;
  return;
}

