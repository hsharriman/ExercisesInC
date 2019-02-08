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
void changeCount(int val){
  static int count;
  if ((val > 2) && (val < 7)){
    count++;
  } else if (val == 10){
    count--;
  }
  printf("Current count: %i\n", count);
}

/* Prompts user for input, puts reply in given buffer.

  User input truncated to first two characters.

  card_name: buffer where result is stored
*/
void userOutput(char *card_name){
  puts("Enter the card name or 'X' to quit: ");
  scanf("%2s", card_name);
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
      val = 10;
      break;
    case 'A':
      break;
    case 'X':
      val = -1;
      break;
    default:
      val = atoi(card_name);
      if ((val < 1) || (val > 10)){
        puts("I don't understand that value!");
      }
    }
    return val;
}

/* Repeatedly asks user for card, updates and prints count
  until user types 'X' when prompted.

  card_name: buffer array, stores user's latest card
  val: result of card classification
*/
int main(){
  char card_name[3];
  int val;
  while (card_name[0] != 'X'){
    userOutput(card_name);
    val = checkType(card_name);
    if (val == -1){
      continue;
    }
    changeCount(val);
  }
  return 0;
}
