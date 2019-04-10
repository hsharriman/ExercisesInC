/*Create a histogram of words that appear in a text file.

Run with:
$ make word_count
$ ./word_count pride.txt

Author: Hwei-Shin Harriman
*/
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <glib.h>
#include <errno.h>
#include <ctype.h>

#define BUFFER 1024
//Helper function to print the results of the program
void print_results(gpointer key, gpointer value, gpointer usrdata){
  printf(usrdata, key,  GPOINTER_TO_INT(value));
}

/*Looks up value in hash table, if exists +1, if not in table, adds to
table

hash: ptr to GHashTable object
input: ptr to word to be looked up in hash table
*/
void update_histogram(GHashTable* hash, char* input){
  gpointer res = g_hash_table_lookup(hash, input);
  if (res != NULL){
    g_hash_table_replace(hash, input, GINT_TO_POINTER(res) + 1);
  } else{
    g_hash_table_insert(hash, input, GINT_TO_POINTER(1));
  }
}

/* Scans the input file and counts up occurrences of each word

hash: ptr to GHashTable object
input: ptr to string with filename to be analyzed
*/
int read(GHashTable* hash, char* input){
  int c;
  FILE *inFile;
  char word[BUFFER];
  int wordlen = 0;

  if ((inFile = fopen(input, "r"))== 0){
    fprintf(stderr, "Cannot open file\n");
    return EXIT_FAILURE;
  }
  else {
    int isWord = 0;
    //scan file for words
    while ((c=fgetc(inFile)) != EOF){
      //If reach end of a line, reset the counters and end the word
      if (c == '\n'){
        if (isWord){
          word[wordlen] = '\0';
          wordlen = 0;
          isWord = 0;
        }
        continue;
      }
      //If find a char that is not a letter, reset counters and end
      //the current word
      if (!isalpha(c)){
        if (isWord){
          word[wordlen] = '\0';
          isWord = 0;
          wordlen = 0;
          update_histogram(hash, strdup(word));
        }
      }
      //Assume that a word is being looked at, add it to the word
      else {
        isWord = 1;
        word[wordlen++] =(char)(tolower(c));
      }
    }
  }
  return 0;
}
//Started the sorting section but ran out of time
// gpointer* sortResults(GHashTable* hash){
//   guint size = g_hash_table_size(hash);
//   gpointer* keys = g_hash_table_get_keys_as_array(hash, size);
//   qsort()
// }
int main(int argc, char** argv){
  char *input = argv[1];
  GHashTable* hash = g_hash_table_new(g_str_hash, g_str_equal);
  read(hash, input);
  g_hash_table_foreach(hash, (GHFunc)print_results, "%s: %d\n");
}
