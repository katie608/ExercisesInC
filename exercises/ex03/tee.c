/*
(Earl Grey) tee -
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

/*
3.
  What worked was first figuring out what I could from the Head First C reading,
  and then googling the specific problem that I wanted to solve. I found most of
  the code that I used that way. I think that overall I need to try to make sure
  that I understand exactly what each line of code does, and how they interact
  with each other. The main things that I needed a NINJA's help to figure out
  could have been solved if I had a deeper understanding of the code that I
  used, both the code from the textbook and from other sources.
4.
  The main thing that the professional implementations have that my code does
  not have is error handling. The savannah version especially has a lot. 
*/
