#include <stdio.h>

void quicksort(int [], int, int);
int partition(int [], int, int);
void swap(int [], int, int);
void printarray(int [], int lo, int hi);

int main (){

	int i;
	int arr[7] = {7, 6, 5, 4, 3, 2, 1};

	printf ("array size : 7.\n");

	printf ("\t ***** Test quicksort *****\n");

	quicksort (arr, 0, 6);
	printarray (arr, 0, 6);

	printf ("\n\t ***** End ******\n");

	return 0;
}

/* quicksort : partition the given array recursively */
void quicksort (int l[], int lo, int hi){

	int p; 	/* partition index */

	if (lo >= hi) 	/* lenght less then 2 */
		return;

	p = partition (l, lo, hi);
	quicksort (l, lo, p-1);
	quicksort (l, p+1, hi);

	return;
}

/* partition : partition according to the last value in the array */
int partition (int l[], int lo, int hi){

	int pivot, i, j;

	pivot = l[hi]; 	/* using the last value as pivot */
	i = lo;
	j = hi;

	while (i < j){
		while (l[i] < pivot && i < hi)
			i++;
		while (l[j] >= pivot && j > lo)
			j--;
		if (i < j)
			swap (l, i, j);
	}
	swap (l, i, hi);

	return i;
}

/* swap : exchange values in index i and j */
void swap (int l[], int i, int j){
	int temp;

	if (i == j)
		return;

	temp = l[i];
	l[i] = l[j];
	l[j] = temp;

	return;
}

/* helper function : print array */
void printarray(int arr[], int lo, int hi){
	int i;

	printf ("\n");
	for (i=lo; i <= hi; i++)
		printf ("\t%d", arr[i]);
	printf ("\n");

	return;
}