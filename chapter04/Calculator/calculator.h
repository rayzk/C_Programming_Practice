
/* constant values declaration */
#define NUMBER '0'	/* signal that a number was found */
#define NAME 'n' 	/* signal that a math function name was found */

/* shared functions declaration */
void push (double);
double pop (void);
int getop (char []);
int getch (void);
void ungetch (int);