# Fuhahh bugs

# v0.21
1. (parser.c) INSANE memory leaks everywhere, annoying asf **PATCHED**
2. (parser.c) newline not removed when using quotation marks **PATCHED**
3. (main.c) mem leak bug by setting buffer_size to 0 every iteration **PATCHED**
4. (parser.c) segfault when there is no closing quotation mark **PATCHED**

# v0.20
1. (main/parser.c) persistent reachable memory on the heap caused by improper freeing

# v0.10
1. (parser.c) mem leak bug when typing "out" (exit command) **PATCHED**
2. (parser.c) failed proper heap realloc after exceeded token count **PATCHED**
3. (processes.c) weird exit bug caused by not closing child processes properly **PATCHED**
4. (main.c) pressing enter crashes program (SIGSEGV) **PATCHED**
5. (main.c) crash bug when just entering spaces on input **PATCHED**
6. (parser.c) mem leak after whitespace spam **PATCHED**

