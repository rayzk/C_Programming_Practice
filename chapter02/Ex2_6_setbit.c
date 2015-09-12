#include <stdio.h>

/*

return x with n bits start from position p with the rightmost n bits of y with the other bits unchanged

*/

unsigned setbits(unsigned x, int p, int n, unsigned y){

	return x & ~(~(~0 << n) << (p+1-n)) | (y & ~(~0 << n)) << (p+1-n);
}