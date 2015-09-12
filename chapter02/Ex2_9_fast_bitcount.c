#include <stdio.h>

/*
Fast bitcount using the result that under 2's complement machine, x & (x - 1) removes the rightmost 1 in x

bitcount returns the number of 1 in given x

this bitcount is faster because it has less loops then comparing bit by bit. 

*/

int bitcount (unsigned x){

	int b;

	for (b=0; x != 0; x &= (x-1))
		++b;

	return b;
}

int main(){

	unsigned int x = 42;
	printf ("number of 1 in %u is %d\n", x, bitcount(x));

	return 0;
}