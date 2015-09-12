#include <ctype.h>

/*
Bring anything to float number
Able to take scientific expression like 123.45e-6
Allow 'e' and 'E'
*/

/*
The reason to use /10 instead of *o.1 when calculate exponential value is that accuracy of dividing by 10 is better then multiplying by 0.1
*/

double atof (char s[]){
	double val, power;
	int exp, i, sign;

	for (i=0; isspace(s[i]); i++) 	/* skip white space */
		;

	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;

	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')	/* need to consider if this number is an integer */
		i++;
	for (power = 1.0; isdigit(s[i]); i++){
		val = 10.0 * val + (s[i] - '0');
		power *= 10;
	}

	val = sign * val / power;

	if (s[i] == 'e' || s[i] == 'E'){
		sign = (s[++i] == '-') ? -1 : 1;
		if (s[i] == '+' || s[i] == '-')
			i++;
		for (exp = 0; isdigit(s[i]); i++)
			exp = 10 * exp + (s[i] - '0');
		if (sign == 1)
			while (exp-- > 0)	/* positive exponent */
				val *= 10;
		else 
			while (exp -- >0)	/* negative exponent */
				val /= 10;
	}

	return val;
}