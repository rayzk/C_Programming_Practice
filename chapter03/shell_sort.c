#include <stdio.h>

/*
Refactor this main function into several functions in this way:
	def shell(a, n):
	    gap = n / 2

	    while gap >= 1:
	            insertion(a, n, gap) # or bubble
	            gap /= 2

*/

int main (){

	int arr[30];
	int i, j, k, tmp, num;

	printf ("Enter total number of elements : ");
	scanf ("%d", &num);

	/* load the elements into array */
	for (k=0; k<num; ++k){
		printf ("\nEnter %d number : ", k);
		scanf ("%d", &arr[k]);
	}

	/* sort the array */
	for (i=num/2; i>0; i/=2){
		for (j=i; j<num; j++){
			for (k=j-i; k>=0; k-=i){
				if (arr[k+i] > arr[k])
					break;
				else {
					tmp = arr[k];
					arr[k] = arr[k+i];
					arr[k+i] = tmp;
				}
			}
		}
	}

	printf ("\t***** Shell Sorting *****");
	for (k=0; k<num; k++){
		printf ("%d\t", arr[k]);
	}
	printf ("\n");
	return 0;
}

/*
void shell_sort(char target[]){

}

void exchange (){
	
}
*/