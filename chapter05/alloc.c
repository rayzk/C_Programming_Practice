
/* alloc : allocate array of given size and return a pointer to the beginning of the array */

#define ALLOCSIZE 10000 	/* size of available space */

static char allocbuf[ALLOCSIZE]; 	/* storage for alloc */
static char *allocp = allocbuf; 	/* next free position */

/* alloc : return pointer to n characters */
char *alloc (int n){

	if (allocbuf + ALLOCSIZE - allocp >= n){
		allocp += n;
		return allocp - n;
	}else {
		return 0; 	/* 0 is never a valid address for data */
	}
}

/* afree : point to the previous position */
void afree (char *p){

	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}