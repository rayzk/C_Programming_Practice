#include <string.h>

#define MAXLEN 1000 	/* maximum length of a line */
#define MAXSTOR 5000 	/* size of avaliable storage space */

int getline (char *, int);

/* readline : read input lines */
int readline (char *pline[], char *linestor, int maxlines){

	int len, nlines;
	char line[MAXLEN];
	char *p = linestor;
	char *linestop = linestor + MAXSTOR;

	nlines = 0;
	while ((len = getline(line, MAXLEN)) > 0){
		if (nlines >= maxlines || p+len > linestop)
			return -1;
		else {
			line[len-1] = '\0';
			strcpy (p, line);
			pline[nlines++] = p;
			p += len;
		}
	}
	return nlines;
}