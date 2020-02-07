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

    if (sizeof(input) > 8) {
      puts("Your input exceeds the maximum length");
      continue;
    }

    // convert input to an int, and display it
    val = atoi(input);
    printf("Number: %i\n", val);

    if (val == 0){
      puts("It appears you have entered either 0 or a value that cannot be interpreted. Perhaps your value includes characters. Your input has been ignored. Please don't do that again. Or do, I'm a computer, you don't have to take orders from me....yet :)");
    } else {
      // add values to array
      nums[i] = val;
      i++;
    }

    if (i> 256) {
      puts("You have reached the maximum number of elements you can enter. I will calculate your sum now.");
      break;
    }

  // breaks out of loop when user enters control-D (null value)
  // continue to get user inputs
    puts("Enter: ");
  } while(fgets(input, 8, stdin) != NULL);

    // sum array
    int sum = sumArray(nums, i);
    printf("Sum: %i\n", sum);

    return 0;
}
