#ifndef _TOKENIZER_
#define _TOKENIZER_

int string_length(char* str);

int find_word_start(char* str, int pos);

int find_word_end(char* str, int pos);

int count_words(char* str);

char* find_word(char* str, int pos, int end);

char* copy(char* str1, char* str2);

char** argtok(char* str);
  
#endif
