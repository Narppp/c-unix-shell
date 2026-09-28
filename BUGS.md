# Fuhahh bugs

1. (parser.c) mem leak bug when typing "out" (exit command) **PATCHED**
2. (parser.c) failed proper heap realloc after exceeded token count **PATCHED**
3. (processes.c) weird exit bug caused by not closing child processes properly **PATCHED**
4. (main.c) pressing enter crashes program (SIGSEGV) **PATCHED**
5. (main.c) crash bug when just entering spaces on input **PATCHED**
