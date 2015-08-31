#include <stdio.h>

int main(){

	FILE *file_pointer1, *file_pointer2;
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
		printf ("The first file %s does not exit.", file_name1);
		exit(1);
	}else if (file_pointer2 == NULL){
		printf ("The second file %s does not exit.", file_name2);
		exit(1);
	}

	// compare the two files
	char1 = getc(file_pointer1);
	char2 = getc(file_pointer2);

	while((char1 != EOF) && (char2 != EOF) && (char1 == char2)){
		char1 = getc(file_pointer1);
		char2 = getc(file_pointer2);
	}

	if (char1 == char2){
		printf ("Files are identical.\n");
	}else {
		printf ("Files are not identical\n");
	}

	fclose(file_pointer1);
	fclose(file_pointer2);

	return (0);
}