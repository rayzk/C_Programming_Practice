/*
define a swap (t, x, y) to swap parameters x and y in type t
*/

/* use \ to continue to the next line, _z is a local var. parameters x and y should not be _z */
#define swap(t, x, y) { \
	t _z; \
	_z = y; \
	y = x; \
	x = _z; \
}

int main (){

	int x, y;

	x = 1;
	y = 2;

	swap (int, x, y);
	printf ("x = %d, y = %d\n", x, y);

	return 0;
}