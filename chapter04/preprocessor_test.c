#include <stdio.h>

/* be careful of the '()' to use */
#define max(A, B) ((A) > (B) ? (A) : (B))

/* #parameter to stringlize parameter and concate strings */
#define debugprint(expr) printf (#expr " = %g\n", expr)

/* concatenation parameters */
#define paste(front, back) (front ## back)

int main (){

	int i = 2;
	int name1;

	printf ("maximum of 1 and 2 : %d\n", max(1, 2));

	printf ("debug print an double number \'1.1\'\n");
	debugprint (1.1);

	printf ("concatenation of two parameters : \'a\' and \'b\'\n");
	paste (nam, e1) = 9;
	printf ("%d\n", name1);

	


	return 0;
}