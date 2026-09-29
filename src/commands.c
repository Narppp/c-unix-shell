
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
    printf("jmp - change directories\n");
    printf("lost - print working directory\n\n");
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
  else if(strcmp(tokens[0], "lost") == 0){
    char p_dir[CWD] = {0};

    if(getcwd(p_dir, sizeof(p_dir)) == NULL){
      fprintf(stderr, "Genuinely lost: %s\n", strerror(errno));
      return true;
    }
    printf("%s\n", p_dir);
    return true;
  }

  return false;
}
