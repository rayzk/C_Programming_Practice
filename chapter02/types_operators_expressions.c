#include <stdio.h>
#include <float.h>

/*
*/

int main () {

	printf ("======Size of data types======\n");
	printf ("Size of int : %lu\n", sizeof(int));
	printf ("Size of unsigned int : %lu\n", sizeof(unsigned int));
	printf ("Size of char : %lu\n", sizeof(char));
	printf ("Size of unsigned char : %lu\n", sizeof(unsigned char));
	printf ("Size of signed char : %lu\n", sizeof(signed char));
	printf ("Size of short : %lu\n", sizeof(short));
	printf ("Size of unsigned short : %lu\n", sizeof(unsigned short));
	printf ("Size of signed short : %lu\n", sizeof(signed short));
	printf ("Size of long : %lu\n", sizeof(long));
	printf ("Size of unsigned long : %lu\n", sizeof(unsigned long));
	printf ("Size of signed long : %lu\n", sizeof(signed long));
	printf ("Size of float : %lu\n", sizeof(float));


	printf ("======Constants======\n");
	printf ("\\0 printed as %%d: %d\n", '\0');
	printf ("\\n printed as %%d: %d\n", '\n');
	printf ("\\a printed as %%d: %d\n", '\a');
	printf ("\\b printed as %%d: %d\n", '\b');
	printf ("\\t printed as %%d: %d\n", '\t');



return 0;
}
