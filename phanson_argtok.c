#include <stdio.h>
#include <stdlib.h>
#include "phanson_argtok.h"

/*input of function is the entire user input
string, output is an integer, the function returns
the number of chars in the input*/
int string_length(char* str){
  int count = 0;
  while(*str != '\0'){
    *str++;
    count += 1;
  }
  return count;
}

/*input of function is the entire user input
string and the position index, output is
the index where the start of a new word is
found, function finds the starting char of each word 
after a space*/
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

/*input for function is the user input
string and an index position, output 
is the index at the end of a word before
a space or null char, function finds the 
final index of each word*/
int find_word_end(char* str, int pos){
  while(str[pos] != ' ' && str[pos] != '\0'){
    pos++;
  }
  return pos;
}

/*input is the user string, output is
the number of words found in the user
string between spaces, function finds
the number of words found between spaces
and before the null char*/
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

/*input is user string, position of starting
word index and ending word index, output is a pointer,
function takes a word out of the user input to be used
for further functions*/
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

/*input is a pointer location within a double pointer
and the output of the find_word function, output is
a pointer, function copys the string from find_word
and stores it within the double pointer index*/
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

/*input is the user string, output is a double
pointer containing an individual word in each
separate index of the double pointer. The function
uses several methods to find the individual words
of the user string and stores them within a double
pointer using malloc to save on memory*/
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
