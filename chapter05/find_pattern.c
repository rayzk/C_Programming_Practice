#include <stdio.h>
#include <string.h>

/*
NAME 
	find : print lines that match pattern (which is one word, i.e., me) from 1st arg

SYNOPSES 
	find -x -n pattern

ESSENTIAL COMMAND
	-x : print all the lines except those that match the pattern
	-n : precede each printed line by its line number

*/


#define MAXLINE 1000 	/* max number of input lines */
int getline (char *line, int max);

int main (int argc, char *argv[]){

	char line[MAXLINE];
	long lineno = 0;
	int c, except = 0, number = 0, found = 0;

	// precess command
	// argv[0] has higher precedence then ++arg[0]
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c){
				case 'x':
					except = 1;
					break;
				case 'n':
					number = 1;
					break;
				default:
					printf ("find : illegal option %c\n", c);
					argc = 0;
					found = -1;
					break;
			}
	if (argc != 1)
		printf ("Usage : find -x -n pattern\n");
	else {
		while (getline(line, MAXLINE) > 0){
			lineno++;
			if ((strstr(line, *argv) != NULL) != except){
				if (number)
					printf ("%ld:", lineno);
				printf ("%s", line);
				found++;
			}
		}
	}
	return found;
}


