/*

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumArray(int array[]) {
  // make this work
  return array[0];
}

int main () {
  int nums[256];
  char input[8];
  int val;

  do {
    puts("Enter: ");
    fgets(input, 8, stdin);

    val = atoi(input);

    printf("Input: %i\n", input);

    // add number to array

  } while(input != NULL); // make this work
    return 0;

  int sum = sumArray(nums);

    return 0;
}
