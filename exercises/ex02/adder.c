/* Gets user input, converts input to an integer, adds integer to list, and
sums list
Katie Foster, 2020
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumArray(int array[], int length) {
  int sum = 0;
  int in = 0;

  printf("length: %i\n", length);

  for(in=0; in < length; in++) {
   sum += array[in];
   // printf("i: %i\n", i);
  }

  return sum;
}



int main () {
  int nums[256];
  char input[8];
  int val;

  // keep track of how many times through loop to add to array
  int i = 0;


  // get first user input
  puts("Enter: ");
  fgets(input, 8, stdin);

  do {

    // convert input to an int, and display it
    val = atoi(input);
    printf("Number: %i\n", val);

    // add values to array
    nums[i] = val;
    i++;

  // breaks out of loop when user enters control-D (null value)
  // continue to get user inputs
    puts("Enter: ");
  } while(fgets(input, 8, stdin) != NULL);

    // sum array
    int sum = sumArray(nums, i);
    printf("Sum: %i\n", sum);

    return 0;
}
