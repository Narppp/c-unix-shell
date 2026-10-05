
#include "shell.h"

// 0 - No Command | 1 - Executable Command | -1 - Exit Command

int exec_builtin(char **tokens){

  if(strcmp(tokens[0], "out") == 0 && tokens[1] == NULL){
    printf("Exited shell successfully.\n");
    free_all(tokens);
    exit(0);
  }
  else if(strcmp(tokens[0], "help") == 0 && tokens[1] == NULL){
    printf("\nCustom Commands:\n\n");
    printf("out - exit the shell\n");
    printf("jmp - change directories\n");
    printf("intro - show shell banner\n\n");
    return 1;
  }
  else if(strcmp(tokens[0], "jmp") == 0){
    char *home = tokens[1];

    if(home == NULL){
      home = getenv("HOME");
      if(home == NULL){
        fprintf(stderr, "Home Error: %s\n", strerror(errno));
        return 1;
      }
    }
    if(chdir(home) < 0){
      fprintf(stderr, "Directory Error: %s\n", strerror(errno));
      return 1;
    }
    return 1;
  }
  else if(strcmp(tokens[0], "intro") == 0 && tokens[1] == NULL){
    print_shell_intro();
    return 1;
  }

  return 0;
}
