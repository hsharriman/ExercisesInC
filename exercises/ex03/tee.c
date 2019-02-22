/* Amateur implementation of tee.c. Copies standard input to any numbers
of given output files. Takes optional command-line tag "-a" to append stdin
to outputs instead of overwriting.

@Author: Hwei-Shin Harriman
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  char buf[1];
  int i = 0;
  FILE *names[argc-1];
  int ch;
  char* app = "w";

  while ((ch=getopt(argc, argv, "api"))!=EOF)
    switch(ch){
      case 'a':
        app = "a";
        puts("append");
        break;
     case 'i':
     default:
        app = "w";
        puts("overwrite");
        break;
  }
  //Reset to start at after the optional tags
  argc -= optind;
  argv += optind;

  //Print stdin to file(s)
  while (argv[i] != '\0'){
    //Test if file can opened
    if ((names[i-1]=fopen(argv[i], app)) == NULL){
        printf("Cannot open file.\n");
        exit(1);
    }
    i++;
  }
  //Copy one byte at a time to argv[i] file
  while(fread(buf, 1, 1, stdin) == 1){
    for (int n=0; n<argc-1; n++){
      fwrite(buf, 1, 1, names[n]);
    }
  }

  //Close the files
  for (int n=0; n<argc-1; n++){
    fclose(names[n]);
  }
  return 0;
}

/* 3. I found that starting building up my function incrementally really helped
my process. This allowed me to develop a more clear understanding of next steps
to develop the function. I started with trying to open a file given a command-
line argument, and close it after writing a byte to it. What slowed me down was
definitely figuring out which read/write functions I wanted to use. All the
examples I found online involved fscanf and fprintf, but I was not having much
success with them. Using fread and fwrite gave me a bit more of an intuitive
understanding of their use and allowed for greater control. Also, understanding
how to use the switch statements with getopt took a bit of time. Basically,
figuring out how to do anything in C via Google took forever. Next time, I would
like to try seeking out help in more thorough C textbooks than Head First C or
consult classmates or NINJAs a bit earlier on in the process, since I find that
speaking with others helps to expedite my process.

4. The first thing I notice is that the professional implementations have a lot
more infrastructure in place to deal with potential errors that may occur.
Additionally, they separate their code into multiple functions instead, one to
classify the command line arguments and one to actually enter the data into the
files. Because of this, the array of pointers used to enter bytes into fwrite
are dynamically allocated outside of main, and then freed before the function
returns. They also have fancy things like structs and ternary operators.
*/
