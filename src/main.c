// Main File

#include "shell.h"

int main(int argc, char **argv){
  char *line = NULL;
  size_t buffer_size = 0;
  ssize_t chars_read = 0;

  while(1){
    printf("<ushell> ");
    fflush(stdout);

    chars_read = getline(&line, &buffer_size, stdin);

    if(chars_read == -1){
      fprintf(stderr, "Force Exiting Shell: %s\n", strerror(errno));
      exit(0);
    }

    if(strcmp(line, "out") == 0){
      printf("Out\n");
      exit(0);
    }
  }
  free(line);
  line = NULL;

  return 0;
}
