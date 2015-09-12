#include <ctype.h>
#include <stdio.h> 	/* for EOF */
#include <String.h> 	/* for islower() */

#define NUMBER '0' 	/* signal that a number was found */
#define NAME 'n'	/* signal that a math function name was found */

int getch (void);
void ungetch (int);

/* getop : get operand or operation or math function name from user input to s[] */
int getop (char s[]){

	int i, c;

	while ((s[0] = c = getch()) == ' ' || c == '\t') 	/* jump blanks */
		;
	s[1] = '\0'; 	/* add ending null */
	i=0;

	/* command or NAME */
	if (islower(c)){
		while (islower(s[++i] = c = getch()))
			;
		s[i] = '\0';
		if (c != EOF)
			ungetch(c); 	/* one char is too far */
		if (strlen(s) > 1)
			return NAME; 	/* must be a NAME */
		else 
			return c;		/* maybe a command */
	}
	
	/* must be a command */
	if (!isdigit(c) && c != '.' && c != '-')
		return c;	/* not a number */

	/* maybe a numer */
	if (c == '-'){
		if (isdigit(c = getch()) || c == '.')
			s[++i] = c; 	/* negative number */
		else {
			if (c != EOF)
				ungetch(c);
			return '-';
		}
	}
	
	/* must be a number */
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.') 	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}