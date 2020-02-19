/*
tee -
read from standard input and write to standard output and files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main () {
  int opt;
  int a = 0;
  char input[256];
  while((opt = getopt(argc, argv, "a")) != -1)  {
    if (argv[]) {
      a = 1;
    }


  }

  while (fgets(input, 256, stdin)) {
    for(i=1; i<argc; i++) {
      FILE *out_file = fopen(argv[i], "a");
      fputs(input, out_file);
      fclose(out_file);
    }
  }

  return 0;
}
