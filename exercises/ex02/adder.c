/* Asks user to input integers, adds them up and prints the
result.

* Author: Hwei-Shin Harriman
* License: MIT license
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARRAYLEN 10

/*Prompts user to input integer, reads the string and converts to
int, adds to array.
* Returns index when user inputs ^D
* Throws errors if bad input, or array length exceeded.
*
* array: pointer to array to store integers
* buff: max length of single entry
* index: number of entries inputted by user
*/
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
    if (input[strlen(temp)-1] != '\n') {
      fprintf(stderr, "Entry exceeds %i digits\n", buff-1);
      exit(EXIT_FAILURE);
    }
    //If user tried to add too many numbers to the array
    if (index >= ARRAYLEN){
      fprintf(stderr, "Entered too many numbers to fit in the array\n");
      exit(EXIT_FAILURE);
    }
    //If user entered 0 or something other than an integer
    if (atoi(temp) == 0){
      fprintf(stderr, "bad input, did not enter an integer\n");
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

/*Creates array to store user inputted integers, adds them up,
prints the total when user presses ^D.

inputs: array with ARRAYLEN possible entries
insize: number of entries the user inputted
sum: total sum of user-inputted numbers
*/
int main() {
  int buff = 11;
  int inputs[ARRAYLEN];

  int insize = readInput(inputs, buff);
  int sum = calcSum(inputs, insize);

  printf("The sum of the number entered is: %i\n", sum);
  return 0;
}
