#include <stdio.h>

int main(){

	FILE *file1, *file2;
	int char1, char2;
	char file_name1[40], file_name2[40];

	printf ("Enter the first file name: \n");
	gets (file_name1);
	printf ("Enter the second file name: \n");
	gets(file_name2);

	file_pointer1 = fopen(file_name1, "r");
	file_pointer2 = fopen(file_name2, "r");

	// test the validity of the file.
	if (file_pointer1 == NULL){
		printf ("The first file does not exit.");
		exit(1);
	}else if (file_pointer2 == NULL){
		printf ("The second file does not exit.");
		exit(1);
	}

	// compare the two files
	char1 = getc(file_pointer1);
	char2 = getc(file_pointer2);

	while

}