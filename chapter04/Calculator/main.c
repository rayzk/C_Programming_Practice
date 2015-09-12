#include <stdio.h>
#include <stdlib.h> 	/* for atof() */
#include <math.h> 	/* for fmod() */
#include <string.h> 	/* for strcmp() */

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */
#define NAME 'n' 	/* signal that a math function name was found */

int getop (char []);

/* for stack : */
void push (double);
double pop (void);
void clear (void);

/* extended functions : */
void mathfn (char []);

int main (){

	int i, type, var; 	/* var is used to hold previous variable name */
	double op1, op2; 	
	char s[MAXOP];
	double variable[26]; 

	/* init variables */
	for (i=0; i<26; i++)
		variable[i] = 0.0;

	while ((type = getop(s)) != EOF){
		switch (type) {
			case NUMBER:
				push (atof(s));
				break;
			case NAME: 	/* for extended math functions */
				mathfn(s);
				break;
			case '+':
				push (pop() + pop());
				break;
			case '-':
				op2 = pop();
				push (pop() - op2);
				break;
			case '*':
				push (pop() * pop());
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push (pop() / op2);
				else 
					printf ("Error, zero divisor.\n");
				break;
			case '%':
				op2 = pop();
				if (op2 != 0.0)
					push (fmod (pop(), op2));
				else
					printf ("Error, zero divisor.\n");
				break;
			case '=': 	/* sign value to variable */
				pop(); 	/* pop out the old variable value */
				if (var >= 'A' && var <= 'Z'){
					variable[var - 'A'] = pop();
					push (variable[var - 'A']);
				}
				else 
					printf ("Error, no variable name.\n");
				break;
			case '?': 	/* print top element of the stack */
				op2 = pop();
				printf ("\t%g\n", op2);
				push (op2);
				break;
			case 'c': 	/* clear the stack */
				clear();
				break;
			case 'd': 	/* duplicate top element of the stack */
				op2 = pop();
				push (op2);
				push (op2);
				break;
			case 's': 	/* swap the top two elements */
				op1 = pop();
				op2 = pop();
				push (op1);
				push (op2);
				break;
			case '\n':
				printf ("\t%.8g\n", pop());
				break;
			default:
				if (type >= 'A' && type <= 'Z')
					push (variable[type - 'A']);
				else 
					printf ("Error, unknown command : %s", s);
				break;
		}
		var = type; 	/* store the previous variable name, if there is*/
	}
	return 0;
}

/* mathfn : check string s for supported math functions */
void mathfn (char s[]){
	
	double op2;

	if (strcmp(s, "sin") == 0)
		push (sin(pop()));
	else if (strcmp(s, "exp") == 0)
		push (exp(pop()));
	else if (strcmp(s, "cos") == 0)
		push (cos(pop()));
	else if (strcmp(s, "pow") == 0){
		op2 = pop();
		push (pow(pop(), op2));
	}else {
		printf ("Error, %s is not supported.\n", s);
	}
}


