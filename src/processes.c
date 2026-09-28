// Multiple Processes for calling commands

#include "shell.h"

void exec_commands(char **tokens){
  if(tokens == NULL || tokens[0] == NULL){
    // if user inputs nothing, go back
    return;
  }

  pid_t id = fork();

  if(id < 0){
    perror("Fork failed");
    return;
  }

  if(id == 0 /* child process */){
    if(execvp(tokens[0], tokens) < 0){
      perror("Command failed");
      exit(EXIT_FAILURE);
    }
    exit(EXIT_FAILURE);
  }
  else{
    // parent process
    int id_status = 0;
    waitpid(id, &id_status, 0);
  }
}
