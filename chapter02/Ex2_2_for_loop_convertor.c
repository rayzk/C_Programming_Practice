#include <stdio.h>


/* 
Rewrite the for loop without '&&' and '||' 

for loop :
	for (i=0; i<lim-1 && (c=getchar()) != '\n' && c != EOF; ++i){
		s[i] = c;
	}

*/
int main(){
	int lim = 10;
	int i;
	char c;
	char s[2*lim-1];

	enum loop {NO, YES};
	enum loop okloop = YES;

	i=0;
	while (okloop == YES){

		if (i >= lim-1)
			okloop = NO;
		else if ((c=getchar()) == '\n')
			okloop = NO;
		else if (c == EOF)
			okloop = NO;
		else {
			s[i] = c;
			++i;
		}
	}


	return 0;
}