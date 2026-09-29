// Main File

#include "shell.h"

int main(void){
  char cwd[CWD] = {0};
  char *line = NULL;
  size_t buffer_size = 0;
  ssize_t chars_read = 0;

  while(1){
    if(getcwd(cwd, sizeof(cwd)) == NULL){
      fprintf(stderr, "Directory Error: %s\n", strerror(errno));
      printf("<nerp-shell [%s]> ", cwd);
    }
    printf("<nerp-shell [%s]> ", cwd);
    fflush(stdout);

    chars_read = getline(&line, &buffer_size, stdin);

    if(chars_read == 1 /* empty input */){
      free(line);
      line = NULL;
      buffer_size = 0;
      continue;
    }

    if(chars_read == -1 /* EOF Error */){
      free(line);
      fprintf(stderr, "Force Exiting Shell: %s\n", strerror(errno));
      exit(0);
    }

    char **words = parse_line(line); 

    // check if input is whitespace
    if(words == NULL || words[0] == NULL){
      free(words);
      free(line);
      line = NULL;
      buffer_size = 0;
      continue;
    }

    if(exec_builtin(words)){
      free(words);
      free(line);
      line = NULL;
      buffer_size = 0;
      continue;
    }

    exec_commands(words);
    free(words);
    free(line);
    line = NULL;
    buffer_size = 0;
  }
  free(line);
  line = NULL;
  buffer_size = 0;

  return 0;
}
