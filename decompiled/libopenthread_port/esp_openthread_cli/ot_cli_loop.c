/*
 * Last changed at upstream commit bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * https://github.com/espressif/esp-thread-lib/commit/bae77aafb352b24fe8b4ccb14c27a5eb65824d06
 * Upstream date: 2021-10-12 17:30:45 +0800
 * Upstream subject: openthread: add various features(6c40ca6)
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
  
  memcpy(local_20,&_L0,0x10);
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
    putchar(0xd);
    __string = (char *)linenoise(&_LC3);
    if ((__string != (char *)0x0) && (sVar2 = strnlen(__string,0x100), sVar2 != 0)) {
      puts("\r");
      esp_openthread_cli_input(__string);
      linenoiseHistoryAdd(__string);
    }
    linenoiseFree(__string);
  } while( true );
}

