/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumArray(int array[], int length) {
  int i;
  int sum = 0;

  for(i=0; i <= length; i++) {
   sum += array[i];
  }

  return sum;
}

int main () {
  int nums[256];
  char input[8];
  int val;

  // keep track of how many times through loop to add to array
  int i = 0;

  // get user inputs
  fgets(input, 8, stdin);

  do {

    // convert input to an int, and display it
    val = atoi(input);
    printf("Number: %i\n", val);

    // add values to array
    nums[i] = val;
    i++;

  // breaks out of loop when user enters control-D (null value)
    puts("Enter: ");
  } while(fgets(input, 8, stdin) != NULL);

    // sum array
    int sum = sumArray(nums, sizeof(nums));
    printf("Sum: %i\n", sum);

    return 0;
}
