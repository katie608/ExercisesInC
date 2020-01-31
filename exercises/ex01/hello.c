#include <stdio.h>

int main() {
  int x = 50;
  int y = x + 1;
     printf("%i\n", y);
    return 0;
}


/*
 * 	This is the line that corresponds to int x=5: movl	$5, -4(%rbp)
 * 2. The optimization flag makes the line corresponding to int x=5; go away
 * 3. The x declaration stays in the assembly code when optimized if printed
 * 4. The assembly code does not save the value of x when optimized, it only
 *    saves the value of y, because only y is used later.
 *
 * optimization works by getting rid of unused variables in the code when it
 * turns the c code into assembly
*/
