#include <stdio.h>
/*
Maintain a buffer for reading charactors from user input.
*/

#define BUFSIZE 100

int bufp = 0;	/* next free position in buffer */
char buf[BUFSIZE]; 	/* buffer for ungetch() */

int getch (void) {
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch (int var) {
	if (bufp >= BUFSIZE)
		printf ("Error, buffer over flow.\n");
	else 
		buf[bufp++] = var;
}