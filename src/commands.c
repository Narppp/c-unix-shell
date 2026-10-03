
#include "shell.h"

bool exec_builtin(char **tokens){

  if(strcmp(tokens[0], "out") == 0 && tokens[1] == NULL){
    printf("Exited shell successfully.\n");
    free(tokens);
    exit(0);
  }
  else if(strcmp(tokens[0], "help") == 0 && tokens[1] == NULL){
    printf("\nCustom Commands:\n\n");
    printf("out - exit the shell\n");
    printf("jmp - change directories\n\n");
    return true;
  }
  else if(strcmp(tokens[0], "jmp") == 0){
    char *home = tokens[1];

    if(home == NULL){
      home = getenv("HOME");
      if(home == NULL){
        fprintf(stderr, "Home Error: %s\n", strerror(errno));
        return true;
      }
    }
    if(chdir(home) < 0){
      fprintf(stderr, "Directory Error: %s\n", strerror(errno));
      return true;
    }
    return true;
  }

  return false;
}
