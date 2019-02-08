/* Prompts user for card input, counts cards for
Blackjack.

Hwei-Shin Harriman
Software systems SP19--Olin College of Engineering
Program derived from Head First C.
*/
#include <stdio.h>
#include <stdlib.h>

/* Adjusts card count and prints updated total.

  val: value classifying low or high value card.
  count: total, accumulated count of the game.
*/
void changeCount(int *val, int *count){
  if ((*val > 2) && (*val < 7)){
    *count+= 1;
  } else if (*val == 10){
    (*count)--;
  }
}

/* Prompts user for input, puts reply in given buffer.

  User input truncated to first two characters.

  card_name: buffer where result is stored
*/
void userOutput(char *card_name){

}

/* Classifies card entry taken from userOutput() as
  high, low, neutral, invalid, or exit condition.
  Returns val, the result of classification.

  Assumes user typed letters in caps.
  card_name: stored result from userOutput()
  val: classifies card. note that 10 is high, -1 is
  used as a flag to check the exit condition.
*/
int checkType(char *card_name){
  int val = 0;
  switch(card_name[0]) {
    case 'K': case 'Q': case 'J':
      return 10;
    case 'A':
      return 11;
    default:
      val = atoi(card_name);
      if ((val >= 1) && (val <= 10)){
        return val;
      }
    }
    return -1;
}

/* Repeatedly asks user for card, updates and prints count
  until user types 'X' when prompted.

  card_name: buffer array, stores user's latest card
  val: result of card classification
*/
int main(){
  char card_name[3];
  int count = 0;
  while (card_name[0] != 'X'){
    puts("Enter the card name or 'X' to quit: ");
    scanf("%2s", card_name);
    int val = checkType(card_name);
    changeCount(&val, &count);
    printf("Current count: %i\n", count);
  }
  return 0;
}







//
// #include <stdio.h>
//
// int main() {
//   int x = 5;
//   int y = x + 1;
//   int array[10];
//   int* r = array + 1;
//   //printf("Hello World");
//   printf("%d\n", r);
//   return 0;
// }
/* Answers to Questions 1 through 4
1. The line that corresponds to setting the
value of 5 to a location in memory appears to be this:
  	movl	$5, -4(%rbp)
2. It deleted all mention of the x=5 line from the assembly code because it was
unused. Using the -O2 flag made the assembly code longer but also more
readable.
3. Generating assembly code with no optimization appears to result in the value
5 being moved to a few different locations before printf was called. In the -O2
version it appears as though the x=5 was immediately assigned to a place where
printf could access it.
4. In the unoptimized version, x is created, then the value of x is moved to a
new location where 1 is added. That value is stored and then moved a couple of
times before being called by printf. In the -O2 version, the value is
immediately stored as 6.
*/
