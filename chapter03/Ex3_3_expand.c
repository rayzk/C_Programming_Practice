#include <stdio.h>

/*
Shorthand : a-z, 0-9, a-c-g, ...
Convert to : abcd...xyz, 0123...789, abcdefg, ...
*/

/* expand : expand shorthand notation in s1 into string s2 */
void expand (char s1[], char s2[]){

	char c;
	int i, j;

	i = j = 0;
	while ((c = s1[i++]) != '\0'){		/* fatch a char from s1 */
		if (s1[i] == '-' && s1[++i] >= c){
			while (c < s1[i])
				s2[j++] = c++;
		}else {
			s2[j++] = c;
		}
	}

	s2[j] = '\0';
}

int main (){

	char s1[] = "a-c-g";
	char s2[20];

	printf ("Shorthand : %s\n", s1);
	expand (s1, s2);
	printf ("After expand : %s\n", s2);
}