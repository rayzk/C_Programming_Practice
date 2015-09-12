#include <stdio.h>

/*

Convert string of hex to the corresponding string of integer
Hex number has prefix '0x' or '0X'

*/

#define YES 1
#define NO 0

int htoi (char s[]){

	int hexdigit, i, inhex, n;

	i=0;
	if (s[i] == '0'){
		++i;
		if (s[i] == 'x' || s[i] == 'X')
			++i;
	}

	n=0;	/* integer value to be returned */
	inhex = YES;	/*assume valid hex digit */
	for ( ; inhex == YES; ++i){
		if (s[i] >= '0' && s[i] <= '9')
			hexdigit = s[i] - '0';
		else if (s[i] >= 'a' && s[i] <= 'f')
			hexdigit = s[i] - 'a' + 10;
		else if (s[i] >= 'A' && s[i] <= 'F')
			hexdigit = s[i] - 'A' + 10;
		else 
			inhex = NO; 	/* not a valid hex digit */

		if (inhex == YES)
			n = 16 * n + hexdigit;
	}

	return n;
}

int main (){
	char hex_string[] = "0x93F64";
	printf ("hex %s is equal to integer %d\n", hex_string, htoi(hex_string));
}