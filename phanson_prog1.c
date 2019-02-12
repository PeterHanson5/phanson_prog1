#include <stdio.h>
#include <stdlib.h>
#include "phanson_argtok.h"

void main(){
  char* input;
  char** sent;
  int len = 0;

  printf("$ ");
  input = malloc(256);
  fgets(input, 255, stdin);

  sent = argtok(input);

  for(int i = 0; i < count_words(input); i++){
    printf("%s\n", sent[i]);
  }

  free(input);
}
