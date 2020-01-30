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

 int getValue (char card_name[3], int count, int val) {
   /*
    * gets card value from user, creates the corresponding value,
    * keeps track of cards
   */

 do {
   puts("Enter the card_name: ");
   scanf("%2s", card_name);


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

 } while(card_name[0] != 'X');
   return 0;
 }


int main() {
  /*
   * main loop
   * declares variables card_name, count, and val
   * calls functions for card counting program
  */

  char card_name[3];
  int count = 0;
  int val = 0;
  getValue(card_name, count, val);

  return 0;
 }
