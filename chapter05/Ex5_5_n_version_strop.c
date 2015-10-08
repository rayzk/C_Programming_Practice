#include <string.h>

/* strcpyn : copy the first n character of the string t to the string s*/
void strcpyn (char *s, char *t, int n){

	int i;

	i = 0;
	while ((*s++ = *t++) && i++<n);
}

/* strcatn : copy the n character of string t to the end of the string s */
void strcatn (char *s, char *t, int n){

	while (*s) s++;
	while (*s++ = *t++ && n-- > 0);
}

/* the second version : */
void strcatn (char *s, char *t, int n){

	// declaration :
	void strcpyn (char *s, char *t, int n);
	int strlen (char *);

	strcpyn (s+strlen(s), t, n);
}

/* strcmpn : compare at most n characters of string s and string t */
int strcmpn (char *s, char *t, int n){

	while (*s++ == *t++)
		if (*s == '\0' || --n <= 0)
			return 0;
	return *s - *t;
}
