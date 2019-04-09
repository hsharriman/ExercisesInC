/*1.



*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <errno.h>

#define BUFFER 1024
void print_results(gpointer key, gpointer value, gpointer usrdata){
  printf(usrdata, key,  GPOINTER_TO_INT(value));
}

void update_histogram(GHashTable* hash, char* input){
  gpointer res = g_hash_table_lookup(hash, input);
  if (res==NULL){
    g_hash_table_insert(hash, input, GINT_TO_POINTER(1));
  } else{
    g_hash_table_replace(hash, input, GPOINTER_TO_INT(res) + 1);
  }
}

int read(GHashTable* hash, char* input){
  int c;
  FILE *inFile;
  char word[BUFFER];
  unsigned int word_index = 0U;
  inFile =fopen(input, "r");

  if (inFile == 0){
    fprintf(stderr, "Cannot open file\n");
    return EXIT_FAILURE;
  } else {
    int found_word = 0;
    while ((c=fgetc(inFile)) != EOF){
      if (line == BUFFER){
        fprintf(stderr, "line is too long, increase BUFFER_MAX_LENGTH");
        return EXIT_FAILURE;
      } else if (c == '\n'){
        if (found_word){
          word[word_index] = '\0';
          word_index = 0U;
          found_word = 0;
        }
        line = 0U;
        continue;
      }
      if (!isalpha(c)){
        if (found_word){
          word[word_index] = '\0';
          found_word = 0;
          word_index = 0U;
          update_histogram(hash, strdup(word));
        }
      }
      else {
        found_word = 1;
        c = tolower(c);
        word[word_index++] =(char)c;
      }
      line++;
    }
  }
  return 0;
}

int main(int argc, char** argv){
  char *input = argv[1];
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  read(hash, input);
  g_hash_table_foreach(hash, (GHFunc)print_results, "%s: %d\n");
}
