/*
 * Last changed at upstream commit 852eceaf38f6d6304f3b446a4a26f861389f83be
 * https://github.com/espressif/esp-thread-lib/commit/852eceaf38f6d6304f3b446a4a26f861389f83be
 * Upstream date: 2021-07-06 14:49:24 +0800
 * Upstream subject: openthread: make queue size and partition configurable
 * Source: libopenthread_port -> esp_uart_spinel_interface.cpp.o -> HandleHdlcFrame
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* esp::openthread::UartSpinelInterface::HandleHdlcFrame(otError) */

void __thiscall
esp::openthread::UartSpinelInterface::HandleHdlcFrame(UartSpinelInterface *this,int param_2)

{
  short sVar1;
  undefined4 uVar2;
  int iVar3;
  int *piVar4;
  
  if (param_2 == 0) {
    (**(code **)this)(*(undefined4 *)(this + 4),*(code **)this);
  }
  else {
    uVar2 = otThreadErrorToString(param_2);
    otLogCrit(0xc,"-PLAT----: ","dropping radio frame: %s",uVar2);
    piVar4 = *(int **)(this + 8);
    iVar3 = piVar4[0x102];
    sVar1 = (short)((int)piVar4 + 0x406U);
    if (iVar3 + 4U <= (int)piVar4 + 0x406U) {
      *(undefined1 *)(iVar3 + 2) = 0;
      *(undefined1 *)(iVar3 + 3) = 0;
      iVar3 = piVar4[0x102] + *(ushort *)(piVar4[0x102] + 2) + 4;
      *piVar4 = iVar3;
      *(short *)(piVar4 + 1) = sVar1 - (short)iVar3;
    }
    iVar3 = piVar4[0x102] + *(ushort *)(piVar4[0x102] + 2) + 4;
    *piVar4 = iVar3;
    *(short *)(piVar4 + 1) = sVar1 - (short)iVar3;
  }
  return;
}

