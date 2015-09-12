#include <stdio.h>

/*
Use only one if statement inside the loop, and suffice more test outisde the loop
*/

/* bisearch : find x in v[0] <= v[1] <= ... <= v[n-1] */
int bisearch (int x, int v[], int n) {

	int low, high, mid;

	low = 0;
	high = n-1;
	mid = (low + high) / 2;
	while (low <= high && x != v[mid]){
		if (x < v[mid])
			high = mid - 1;
		else 
			low = mid + 1;
		mid = (low + high) / 2;
	}

	if (x == v[mid]){
		return mid;
	}else {
		return -1; 	/* no match */
	}
}

int main (){
	int v[] = {1,2,3,4,5,6};
	int x = 4;

	printf ("search result : %d\n", bisearch(x, v, sizeof(v)));
}