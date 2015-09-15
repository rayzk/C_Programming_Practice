#include <string.h>

void reverse (char []);

int main (){

	char s[] = "abcd";
	reverse (s);

	printf ("reversed string : %s\n", s);
	return 0;
}

void reverse (char s[]){

	void reverser (char s[], int left, int right);

	reverser (s, 0, strlen(s));
	return;
}

void reverser (char s[], int left, int right){

	char temp;

	if (left >= right)
		return;
	temp = s[left];
	s[left] = s[right];
	s[right] = temp;
	reverser (s, ++left, --right);
}