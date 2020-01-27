/*
 * Program to prompt user for input of card value,
 * evaluate card value, and count cards.
*/

 #include <stdio.h>
 #include <stdlib.h>


 int keepCount (int card_value) {
   /*
    * takes in the value of the card and returns the change to be made
    * to the count depending on that number
   */
   if ((card_value > 2) && (card_value < 7)) {
     return 1;
   } else if (card_value == 10) {
     return -1;
   } else {
     return 0;
   }
 }


int main() {
  char card_name[3];
  int count = 0;

  int done = 0;

while ( card_name[0] != 'X' ) {
  // I could not get the "do" loop running, even while copyint the exact code from the book

  puts("Enter the card_name: ");
  scanf("%2s", card_name);

  int val = 0;
  switch(card_name[0]) {
    case 'K':
    case 'Q':
    case 'J':
      val = 10;
      break;
    case 'A':
      val = 11;
      break;
    case 'X':
      continue;
    default:
      val = atoi(card_name);
      if ((val < 1) || (val > 10)) {
        puts("I don't understand that value!");
        continue;
      }
  }

  count += keepCount(val);

  printf("Current count: %i\n", count);


}
  return 0;

 }
