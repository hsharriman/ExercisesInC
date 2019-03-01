#include <stdio.h>
#include <string.h>

void strsplit(char *str, char sep, char* first, char *second){
  char temp[strlen(str)];
  strcpy(temp, str);
  first = strtok(temp, sep);
  second = strtok(NULL, sep);
}

int main(){
  char string = "Hello World";
  char first[10];
  char second[10];
  const char sep = ' ';
  strsplit(&string, *sep, &first, &second);
  printf("first %s second %s\n", first, second);
  return 0;
}
