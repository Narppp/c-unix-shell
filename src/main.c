// Main File

#include "shell.h"

int main(void){
  char *line = NULL;
  size_t buffer_size = 0;
  ssize_t chars_read = 0;

  while(1){
    printf("<nerp-shell> ");
    fflush(stdout);

    chars_read = getline(&line, &buffer_size, stdin);

    if(chars_read == -1 /* EOF Error */){
      fprintf(stderr, "Force Exiting Shell: %s\n", strerror(errno));
      exit(0);
    }

    char **words = parse_line(line);
    
    if(words[0] != NULL && strcmp(words[0], "out") == 0){
      printf("Exited shell successfully.\n");
      free(words);
      break;
    }

    free(words);
  }
  free(line);
  line = NULL;

  return 0;
}
