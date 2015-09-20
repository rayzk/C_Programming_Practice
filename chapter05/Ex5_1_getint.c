#include <stdio.h>
#include <ctype.h>

/*
getint from user input, treats a '+' or '-' not followed by a digit as a valid expression of zero.
*/

int getch(void);
void ungetch(int);

int getint(int *pn){

	int c, d, sign;

	while (isspace(c = getch()))
		;
	if (!isdigit(c) && c!='-' && c!=EOF && c!='+'){
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1; 	/* all the other possibility is treated as positive sign */
	if (c == '+' || c == '-'){
		d = c; 	/* remember the sign char */
		if (!isdigit (c = getch())){
			if (c != EOF)
				ungetch(c); 	/* push back non-digit */
			ungetch(d); 	/* push back sign char */
			return d; 	/* return sign char */
		}
	}
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}
