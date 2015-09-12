#include <stdio.h>

#define MAXVAL 100 	/* max depth of value stack */

int sp = 0;
double val[MAXVAL];

/* push : push double type operant into stack val */
void push (double var){
	if (sp < MAXVAL)
		val[sp++] = var;
	else 
		printf ("Error, stack over flow : %g\n", var);
}

/* pop : pop out the most current operant from val stack */
double pop (void){
	if (sp > 0)
		return val[--sp];
	else 
		printf ("Error, stack empty.\n");
	return 0.0;
}

/* clear : set sp to be 0 */
void clear (void){
	sp = 0;
}