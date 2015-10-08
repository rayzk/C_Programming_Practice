
/* strcmp : return <0 if s<t, 0 if s==t, >0 if s>t*/
int strcmp(char *s, char *t){

	int i;

	for (i=0; s[i] == t[i]; i++)
		if (s[i] == '\0')
			return 0;
	return s[i] - t[i];
}

/* strcmp : pointer version */
int strcmp (char *s, char *t){

	while (*s++ == *t++){ 	/* '++' and '--' have higher precedence then '*' operation */
		if (*s = '\0')
			return 0;
	}
	return *s - *t;
} 