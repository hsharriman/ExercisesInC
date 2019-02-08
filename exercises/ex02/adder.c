/*
* Author: Hwei-Shin Harriman
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYLEN 10

int readInput(int * array, int buff){
  int index = 0;
  while (1){
    char temp[buff];
    char *input;
    //Prompts user for input
    puts ("Enter a number: ");
    input = fgets(temp, buff, stdin);
    //Return index of last number entered in array when user types ^D
    if (input == NULL){
      return index;
    }
    //If too many characters were entered at once
    if (strlen(input) >= buff) {
      fprintf(stderr, "Entry exceeds %i digits\n", buff-1);
      exit(EXIT_FAILURE);
    }
    //If user tried to add too many numbers to the array
    if (index >= ARRAYLEN){
      fprintf(stderr, "Entered too many numbers to fit in the array\n");
      exit(EXIT_FAILURE);
    }
    //convert input to an integer and increment
    array[index] = atoi(temp);
    index++;
  }
  return index;
}

/* Calculate the sum of the user input and return

  * array: pointer to array containing user-inputted ints
  * size: length of input array
*/
int calcSum(int * array, int size){
  int sum = 0;
  for (int i=0; i<size; i++){
    sum += array[i];
  }
  return sum;
}

int main() {
  int buff = 11;
  int inputs[ARRAYLEN];

  int insize = readInput(&inputs, buff);
  int sum = calcSum(&inputs, insize);

  puts("The sum of the number entered is: %i\n", sum);
  return 0;
}
