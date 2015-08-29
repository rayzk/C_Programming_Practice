#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20


main(){
	printf ("Table of Fahr and cels:\n");
	int fahr;

	for (fahr = LOWER; fahr <= UPPER; fahr += STEP){

		// only one of 5.0/9.0 need to be float number, the result will be float number.
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}