#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20


main(){

	int fahr;

	for (fahr = 0; fahr <= 300; fahr += 20){

		// only one of 5.0/9.0 need to be float number, the result will be float number.
		printf("%3d\t%6.1f\n", fahr, (5.0/9.0)*(fahr-32));
	}
}