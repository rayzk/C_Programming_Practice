
/* strend : return 1 if the string t occurs at the end of the string s and zero otherwise */
int strend (char *s, char *t){

	char *bs * bt;

	// store the beginning of each string 
	bs = s;
	bt = t;

	// goto the end of each string
	while (*s) s++;
	while (*t) t++;

	while (*s-- == *t--){
		if (s == bs || t == bt)
			break;
	}
	// have not compare *s and *t yet
	if (*s == *t && t == bt && *s != '\0')
		return 1;
	else 
		return 0;
}