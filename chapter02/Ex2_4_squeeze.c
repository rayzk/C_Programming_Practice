#include <stdio.h>

/*

delete all the characters in s1 that shows up in s2.

*/

void squeeze (char s1[], char s2[]){

	int i, j, k;

	for (i=k=0; s1[i] != '\0'; i++){
		for (j=0; s2[j] != '\0' && s2[j] != s1[i]; j++)
			;

		if (s2[j] == '\0')
			s1[k++] = s1[i];
	}
	s1[k] = '\0';
}

int main(){

	char string1[] = "there is nothing in this string.";
	char string2[] = "the";

	printf ("The original string is \'%s\'\n", string1);
	squeeze(string1, string2);
	printf ("After squeeze \'%s\', the result is \'%s\'\n", string2, string1);
}