#include <stdio.h>

/* echo : command-line arguments; pointer version */
int main (int argc, char *argv[]){

	while (--argc > 0)
		// the first argument is "./a.out"
		printf ("%s%s", *++argv, (argc > 1) ? " " : "");
	printf ("\n");
	return 0;
}
