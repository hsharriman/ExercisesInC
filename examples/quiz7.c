#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int counter = 0;

void *procreate(void *arg){
  if (counter > 2){
    printf("b ");
    pthread_exit(NULL);
  }
  pthread_t child;
  pthread_create(&child, NULL, procreate, NULL);
  printf("%d ", counter);
  counter++;

  pthread_join(child, NULL);
  printf("c ");
  pthread_exit(NULL);
}

void printhash(void* key, void* value, void* user_data){
  printf(user_data, *(float*)key, value);
}
int main(){
  // printf("a ");
  float key = 0.75;
  char value = 'a';
  printhash((void*)&key, (void*)&value, "%f, %s\n");
  // procreate(NULL);
  return 0;
}
