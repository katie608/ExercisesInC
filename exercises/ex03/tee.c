/*
tee -
read from standard input and write to standard output and files
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>



int main (int argc, char *argv[]) {
  int opt;
  int a = 0;
  char input[256];
  while((opt = getopt(argc, argv, "a")) != -1)  {
    switch(opt) {
      case 'a':
        a = 1;
    }
  }
  argc -= optind;
  argv += optind;
  while (fgets(input, 256, stdin)) {
    FILE *out_file;
    int i;
    for(i=0; i<argc; i++) {
      if (a) {
        out_file = fopen(argv[i], "a");
        a = 1;
      } else {
        out_file = fopen(argv[i], "w");
      }

      fputs(input, out_file);
      fclose(out_file);
    }
  }

  return 0;
}
