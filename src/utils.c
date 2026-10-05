
#include "shell.h"

void print_shell_intro(void){
  puts(" /\\_/\\\n"
     "( o.o )  nerpsh 0.21\n"
     " > ^ <   type 'help' for commands\n");
  fflush(stdout);
}

void free_all(char **token_arr){
  
  if(token_arr == NULL){
    fprintf(stderr, "Invalid free: %s\n", strerror(errno));
    exit(1);
  }

  for(int i = 0; token_arr[i] != NULL; i++){
    free(token_arr[i]);
  }

  free(token_arr);
}

void clear_newline(char *str, size_t len){
  if(len > 0 && str[len - 1] == '\n'){
    str[len - 1] = '\0';
  }

  return;
}

