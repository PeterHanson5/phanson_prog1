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

int string_length(char* str){
  int count = 0;
  while(*str != '\0'){
    *str++;
    count += 1;
  }
  return count;
}

int find_word_start(char* str, int pos){
  if(pos == 0){
    return pos;
  }
  while(str[pos] != ' ' && str[pos] != '\0'){
    pos++;
  }
  while(str[pos] == ' '){
    pos++;
  }
  if(str[pos] == '\0'){
    return -1;
  }
  return pos;
}

int find_word_end(char* str, int pos){
  while(str[pos] != ' ' && str[pos] != '\0'){
    pos++;
  }
  return pos;
}

int count_words(char* str){
  int count = 0;
  int index = 0;
  while(str[index] != '\0'){
    if(str[index] != ' ' && str[index + 1] == ' '){
      count++;
    }
    if(str[index] != ' ' && str[index + 1] == '\0'){
      count++;
    }
    index++;
  }
  return count;
}

char* find_word(char* str, int pos, int end){
  int index = pos;
  int temp = (end - pos) + 1;
  char* word = (char*)malloc((temp) * sizeof(char));
  for(int i = 0; i < (temp - 1); i++){
    word[i] = str[index];
    index++;
  }
  return word;
  free(word);
}

char* copy(char* str1, char* str2){
  char* temp = str1;
  while(*str2 != '\0'){
    *str1 = *str2;
    str1++;
    str2++;
  }
  *str1 = '\0';
  return temp;
}

char** argtok(char* str){
  int count = count_words(str);
  int len = string_length(str) - 1;
  int pos = 0;
  int end = 0;
  int temp = 0;
  int index = 0;
  char* temps;

  char** words = (char**)malloc((count + 1) * sizeof(char*));

  while(pos != -1){
    end = find_word_end(str, pos);
    temp = (end - pos) + 1;
    words[index] = (char*)malloc((temp) * sizeof(char));
    temps = find_word(str, pos, end);
    copy(words[index], temps);
    pos = find_word_start(str, end);
    index++;
  }
  return words;
  free(words);
}
