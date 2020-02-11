/* Example code for Exercises in C.

Modified version of an example from Chapter 2.5 of Head First C.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define NUM_TRACKS 5

char tracks[][80] = {
    "So What",
    "Freddie Freeloader",
    "Blue in Green",
    "All Blues",
    "Flamenco Sketches"
};


// Finds all tracks that contain the given string.
//
// Prints track number and title.
void find_track(char search_for[]) {
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//
// Prints track number and title.
void find_track_regex(char pattern[]) {
    regex_t re;
    // define regular expression reg
    int reg = regcomp(&re, pattern, REG_EXTENDED|REG_NOSUB|REG_ICASE);
    int result;
    int matched = 0; //keep track of if a match was found
    for(int i=0; i <= NUM_TRACKS; i++){ // iterate through tracks
      result = regexec(&re, tracks[i], (size_t) 0, NULL, 0);
      if (result == 0) {
        printf("Track %i: '%s'\n", i, tracks[i]);
        matched = 1;
      } else if (result == REG_BADPAT){
        puts("Invalid regular expression.");
      }
    }
    if (matched == 0) {
      // print out error if no match was found in all tracks
      puts("Your query did not match any tracks :(");
    }
    exit(1);
    regfree(&re);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[]) {
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

int main (int argc, char *argv[]) {
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    // find_track(search_for);
    find_track_regex(search_for);

    return 0;
}
