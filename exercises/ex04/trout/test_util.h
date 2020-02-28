/* 

*/

/* mu_assert: If test is false, returns message.

Note that because this is a macro, it returns from whatever
function it is used in.
*/
 #define mu_assert(message, test) do { if (!(test)) return message; } while (0)


/* mu_run_test: Runs the given test function.

If the function returns a non-null message, mu_run_test returns
the same message.

*/
 #define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)

/* Note from Allen: I'm not sure why this is here.
   `tests_run` is only used in the testing module, and I
   don't see a reason it should be accessible from the
   unit under test.

extern int tests_run;

*/
