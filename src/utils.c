
#include "shell.h"

void print_shell_intro(void){
  puts(" /\\_/\\\n"
     "( o.o )  nerpsh 0.21\n"
     " > ^ <   type 'help' for commands\n");
  fflush(stdout);
}

void free_all(char *token, char **token_arr){
  free(token_arr);
  free(token);
  token = NULL;
}
