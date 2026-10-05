
#include "shell.h"

char **parse_line(char *string){
  int token_count = 0;
  int storage_size = BUF_SIZE;
  char *user_input = string;
  char **token_holder = malloc(storage_size * sizeof(char*));

  if(token_holder == NULL){
    fprintf(stderr, "Memory Allocation Failed: %s\n", strerror(errno));
    exit(1);
  }

  // Looping with pointer arithmetic instead of strtok for better flexibility
  while(*user_input != '\0'){

    while(*user_input == ' ' || *user_input == '\n'){
      user_input++;
    }
    if(*user_input == '\0'){
      break;
    }

    int token_size = BUF_SIZE;
    int token_idx = 0;

    // allocate memory for EACH token
    char *token = malloc(token_size);

    if(token == NULL){
      fprintf(stderr, "Token Memory Allocation Failed: %s\n", strerror(errno));
      exit(1);
    }

    char is_quote = '\0';

    while(*user_input != '\0'){
      if(is_quote == '\0'){
        if(*user_input == ' ' || *user_input == '\n' || *user_input == '\t'){
          // This is when we are OUTSIDE the quotes, end the loop here.
          user_input++;
          break;
        }
        else if(*user_input == '"' || *user_input == '\''){
          // We got a quotation mark, set this to a null terminator to mask it
          is_quote = *user_input;
          user_input++;

          // Loops until there's a null terminator AND it finds a closing quotation mark
          while(*user_input != '\0' && *user_input != is_quote){

            // Reallocate new memory if the tokens inside the quotation mark is really big
            if(token_idx + 1 >= token_size){
              token_size *= 2;
              char *temp_size = realloc(token, token_size);

              if(temp_size == NULL){
                fprintf(stderr, "Token Reallocation inside quotation failed: %s\n", strerror(errno));
                exit(1);
              }
              
              token = temp_size;
            }

            token[token_idx++] = *user_input;
            user_input++;
          }

          if(*user_input == '\0'){ 
            continue;
          }

          user_input++;
        }
      }

      if(token_idx + 1 >= token_size){
        token_size *= 2;
        char *temp_storage = realloc(token, token_size);

        if(temp_storage == NULL){
          fprintf(stderr, "Token Reallocation Failed: %s\n", strerror(errno));
          exit(1);
        }

        token = temp_storage;
      }

      token[token_idx++] = *user_input;
      user_input++;
    }

    token[token_idx] = '\0';

    if(token_count + 1 >= storage_size){
      storage_size *= 2;
      char **temp_holder = realloc(token_holder, storage_size * sizeof(char*));

      if(temp_holder == NULL){
        fprintf(stderr, "Token Array Reallocation Failed: %s\n", strerror(errno));
        exit(1);
      }

      token_holder = temp_holder;
    }

    token_holder[token_count++] = token;
  }

  token_holder[token_count] = NULL;
  return token_holder;
}
