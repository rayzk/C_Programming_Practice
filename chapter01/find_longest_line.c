#include <stdio.h>

#define MAXLINE	1000 /*maximum input line length*/

int getoneline (char line[], int maxline);
void copy (char dest[], char init[]);

/* print the longest input line */
int main() {

	int len;				/* current line length*/
	int max;				/* maximum length seen so far*/
	char line[MAXLINE];		/* current input line */
	char longest[MAXLINE];	/* longest line saved here */

	max = 0;
	while ((len = getoneline(line, MAXLINE)) > 0){
		if (len > max){
			max = len;
			copy(longest, line);
		}
	}
	
	if (max > 0){	
		/* there was a line */
		printf ("%s", longest);
	}

	return 0;
}


/* getoneline : read a line into s, return length */
int getoneline (char s[], int lim){

	int c, i;

	for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i)
		s[i] = c;
	if (c != '\n' && i == lim-2)
		printf ("Warning! The length of line exceed the maximum length.");
	if (c == '\n'){
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}


/* copy : copy 'init' to 'dest'; assume 'dest' is big enough */
void copy (char dest[], char init[]){

	int i;

	i=0;
	while ((dest[i] = init[i]) != '\0')
		++i;
}