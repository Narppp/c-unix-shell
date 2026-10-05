// Main File

#include "shell.h"

int main(void){
  char cwd[CWD] = {0};
  char *line = NULL;
  size_t buffer_size = 0;
  ssize_t chars_read = 0;

  print_shell_intro();
  while(1){
    if(getcwd(cwd, sizeof(cwd)) == NULL){
      fprintf(stderr, "Directory Error: %s\n", strerror(errno));
      printf("<nerpsh [%s]> ", cwd);
    }
    printf("<nerpsh [%s]> ", cwd);
    fflush(stdout);

    chars_read = getline(&line, &buffer_size, stdin);

    clear_newline(line, strlen(line));

    if(chars_read == 1 /* empty input */){
      free(line);
      line = NULL;
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
      free_all(words);
      continue;
    }

    if(exec_builtin(words) == 1){
      free_all(words);
      continue;
    }

    exec_commands(words);
    free_all(words);
  }
  free(line);
  line = NULL;
  buffer_size = 0;

  return 0;
}
