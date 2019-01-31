#include <stdio.h>

int main() {
  int x = 5;
  int y = x + 1;
  //printf("Hello World");
  printf("%d\n", y);
  return 0;
}
/* Answers to Questions 1 through 4
1. The line that corresponds to setting the
value of 5 to a location in memory appears to be this:
  	movl	$5, -4(%rbp)
2. It deleted all mention of the x=5 line from the assembly code because it was
unused. Using the -O2 flag made the assembly code longer but also more
readable.
3. Generating assembly code with no optimization appears to result in the value
5 being moved to a few different locations before printf was called. In the -O2
version it appears as though the x=5 was immediately assigned to a place where
printf could access it.
4. In the unoptimized version, x is created, then the value of x is moved to a
new location where 1 is added. That value is stored and then moved a couple of
times before being called by printf. In the -O2 version, the value is
immediately stored as 6.
*/
