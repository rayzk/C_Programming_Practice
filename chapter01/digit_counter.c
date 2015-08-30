#include <stdio.h>

// count the digit from 0 to 9.

int main(){


	int c, i, nwhite, nother;
	int ndigit[10];

	nwhite = nother = 0;

	// initialize the array to be 0 everywhere
	for (i=0; i<10; ++i){
		ndigit[i] = 0;
	}

	while ((c=getchar()) != EOF){
		if (c >= '0' && c <= '9'){
			++ndigit[c-'0'];
		}else if (c == ' ' || c == '\n' || c == '\t'){
			++nwhite;
		}else{
			++nother;
		}
	}

	for (i=0; i<10; ++i){
		printf ("Digit %d shows %d times.", i, ndigit[i]);
		for (int j=0; j<ndigit[i]; j++)
			printf ("|");	// prints the histogram of the digits
		printf ("\n");
	}
	printf (", white space = %d, other = %d\n", nwhite, nother);
}