#include <stdio.h>

/*

return the first location in s1 where any charactor in s2 occurs
or -1 if s1 contains no charactor from s2

*/

int any (char s1[], char s2[]){

	int i, j;

	for (i=0; s1[i] != '\0'; ++i){
		for (j=0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
			;
		if (s2[j] != '\0')
			return i;
	}
	return -1;
}

int main (){

	char s1[] = "ttttttstttttt";
	char s2[] = "s";

	printf ("string1 is %s, string2 is %s. result is %d.\n", s1, s2, any(s1,s2));

	return 0;
}