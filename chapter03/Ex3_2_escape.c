#include <stdio.h>

/*
make a copy of string such that all escape characters like '\n' and '\t' are expressed explicitly as "\n" and "\t" in the copy
*/

/* escape : expand newline and tab into visible sequences while copying the string t to s */
void escape (char s[], char t[]) {

	int i, j;
	for (i = j = 0; t[i] != '\0'; ++i){
		switch (t[i]){
			case '\n': 	/* new line */
				s[j++] = '\\'; 	/* this count as one character */
				s[j++] = 'n';
				break;
			case '\t': 	/* new tab */
				s[j++] = '\\';
				s[j++] = 't';
				break;
			default:
				s[j++] = t[i];
				break;
		}
	}

	s[j] = '\0'; 	/* end the line */
}

int main (){

	char t[] = "there is two sentences in this string.\nthe second one contains a tab\there it is\n";
	char s[sizeof (t)+10]; 	/* make sure s has enough space */
	escape (s, t);
	printf ("the original string : %s,\n vs the converted string : %s\n", t, s);
}