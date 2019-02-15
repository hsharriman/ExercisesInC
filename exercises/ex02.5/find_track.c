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
void find_track(char search_for[])
{
    int i;
    for (i=0; i<NUM_TRACKS; i++) {
        if (strstr(tracks[i], search_for)) {
            printf("Track %i: '%s'\n", i, tracks[i]);
        }
    }
}

// Finds all tracks that match the given pattern.
//pattern: the pattern to be searched
// szof: the length of pattern
//
// Prints track number and title. Throws error if match fails
void find_track_regex(char pattern[], int szof)
{
    char * regexString = pattern;
    regex_t regexComp;
    char msgbuf[100];

    if (regcomp(&regexComp, regexString, 0)){
      fprintf(stderr, "Could not compile regex\n");
      exit(1);
    }
    for (int i=0; i<NUM_TRACKS; i++){
      int reti = regexec(&regexComp, tracks[i], 0, NULL, 0);
      if (!reti){
        printf("Track number %d, track %s\n", i, tracks[i]);
      } else if (reti == REG_NOMATCH){
        continue;
      } else {
        regerror(reti, &regexComp, msgbuf, sizeof(msgbuf));
        fprintf(stderr, "Regex match failed: %s\n", msgbuf);
        exit(1);
      }
    }
    regfree(&regexComp);
}

// Truncates the string at the first newline, if there is one.
void rstrip(char s[])
{
    char *ptr = strchr(s, '\n');
    if (ptr) {
        *ptr = '\0';
    }
}

/* Prompts user for input, searches list of songs for match.
  Prints song title(s) if any matches are found.
*/
int main (int argc, char *argv[])
{
    char search_for[80];

    /* take input from the user and search */
    printf("Search for: ");
    fgets(search_for, 80, stdin);
    rstrip(search_for);

    //find_track(search_for);
    int szof = sizeof(search_for);
    find_track_regex(search_for, szof);

    return 0;
}
