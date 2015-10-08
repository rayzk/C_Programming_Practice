#include <stdio.h>
#include <string.h>

/*
This program will sort a set of text lines into alphabetic order
A stripped-down version of the UNIX program sort
*/

#define MAXLINES 5000 	/* max number of lines to be sorted */
#define MAXLEN 1000 	/* max number of characters in one line */
char *pline[MAXLINES]; 	/* pointers to text lines; each element of pline is a pointer pointing to an array of character */

/* two functions from alloc.c */
char *alloc (int n);
void afree (char *);

int readlines (char *pline[], int nlines);
void writelines (char *pline[], int nlines);
void qsort (char *pline[], int left, int right);

int main (){

	int nlines;

	if ((nlines = readlines(pline, MAXLINES)) >= 0){
		qsort (pline, 0, nlines-1);
		writelines (pline, nlines);
		return 0;
	}else {
		printf ("error : input is too big.\n");
		return 1;
	}
}

/* readlines : read at most nlines from user input, copy the lines to pline; return the number of lines input */
int readlines (char *pline[], int maxlines){

	int len, nlines;
	int maxlength = MAXLEN; 
	char *p;
	char *line[MAXLEN];


	nlines = 0;
	while ((len = getline(line, &maxlength, stdin)) > 0){
		// reach the max number of lines or cannot allocate arrays
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';
			p = strcpy (p, line);
			pline[nlines++] = p; 	/* store the pointer to line */
		}
	}
	return nlines;
}

/* writelines : write output lines */
void writelines (char *pline[], int nlines){
	
	int i;

	for (i=0; i<nlines; i++){
		printf ("%s\n", pline[i]); 	/* each element of pline is a pointer to string */
	}
	printf ("Finish writing lines.\n");
}

/* qsort : sort into increasing order */
void qsort (char *v[], int left, int right){

	int i, last;
	void swap (char *v[], int i, int j);

	if (left >= right)
		return;
	swap (v, left, (left + right)/2);
	last = left;

	for (i=left+1; i<=right; i++){
		if (strcmp(v[i], v[left]) < 0){
			swap (v, ++last, i);
		}
	}
	swap (v, left, last - 1);
	swap (v, last + 1, right);
}

/* swap : interchange v[i] and v[j] */
void swap (char *v[], int i, int j){
	
	char *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}







