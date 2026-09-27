
#include "shell.h"

char **parse_line(char *charline){
  int buffer_size = BUF_SIZE;
  int line_pos = 0;
  char **tokens = malloc(buffer_size * sizeof(int));
  if(!tokens){
    fprintf(stderr, "Malloc failed: %s\n", strerror(errno));
    exit(EXIT_FAILURE);
  }

  char *token = NULL;

  token = strtok(charline, " \t\n");
  while(token != NULL){
    // LOOP UNTIL NO MORE TOKENS
    tokens[line_pos] = token;
    printf("Token %d: %s\n", line_pos, tokens[line_pos]);

    if(line_pos >= (buffer_size / 4)){
      buffer_size += BUF_SIZE;
      char **temp = realloc(tokens, buffer_size * sizeof(int));

      if(!temp){
        fprintf(stderr, "Realloc failed: %s\n", strerror(errno));
        exit(EXIT_FAILURE);
      }
      tokens = temp;
    }

    token = strtok(NULL, " \t\n");
    line_pos++;
  }
  tokens[line_pos] = NULL;

  return tokens;
}
