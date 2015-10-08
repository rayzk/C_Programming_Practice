
/* strcat : copys string t to the end of string s*/
void strcat (char *s, char *t){

	while (*s++ != '\0')
		;
	while ((*s++ = *t++) != '\0')
		;
}

/* const char* pointer's value can be changed (ie, point to the next char); it points to a location containing a char that cannot be changed */

/* strcat : in the source file */
char *strcat (char *dst, const char *src){ 

	char *cp = dst;
	while (*cp) cp++;
	while (*cp++ = *src++);
	return dst;
}
