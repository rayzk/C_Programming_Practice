#include <stdio.h>
/*
Maintain a buffer for reading charactors from user input.

EOF (-1) should be allowed to push into the stack, thus the type of buf should be int, although each time there is only one char inside the buffer. 

If we set the type of buf[] to be char, the convertion between -1 to char will lead to false value.
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