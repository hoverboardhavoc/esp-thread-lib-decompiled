/*
 * Last changed at upstream commit 7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * https://github.com/espressif/esp-thread-lib/commit/7fe22acb144430d5e688cde8c51e0b2e42a8059d
 * Upstream date: 2021-11-03 15:55:12 +0800
 * Upstream subject: openthread: mdns & RCP ota update(3571cf8)
 * Source: libopenthread_port -> esp_openthread_cli.o -> ot_cli_loop
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ot_cli_loop(void)

{
  int iVar1;
  char *__string;
  size_t sVar2;
  undefined4 local_20 [4];
  
  memcpy(local_20,&_LANCHOR2,0x10);
  iVar1 = esp_console_init(local_20);
  if (iVar1 != 0) {
                    /* WARNING: Subroutine does not return */
    abort();
  }
  linenoiseSetMultiLine(1);
  linenoiseHistorySetMaxLen(100);
  linenoiseSetMaxLineLen(local_20[0]);
  linenoiseAllowEmpty(0);
  do {
    __string = (char *)linenoise(&_LC1);
    if ((__string != (char *)0x0) && (sVar2 = strnlen(__string,0x100), sVar2 != 0)) {
      puts("\r");
      esp_openthread_cli_input(__string);
      linenoiseHistoryAdd(__string);
      xTaskGenericNotifyWait(0,0,0,0,0xffffffff);
    }
    linenoiseFree(__string);
  } while( true );
}

