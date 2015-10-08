#define ALLOCSIZE 10000 	/* size of avaliable space */

static char allocbuf[ALLOCSIZE]; 	/* storage for alloc */
static char *allop = allocbuf; 	/* next free position */


/* *alloc : return pointer to n characters */
char *alloc (int n){

	if (allocbuf + ALLOCSIZE - allop >= n){
		allop += n;
		return allop - n;
	}else {
		return 0; 	/* 0 is never a valid address for data */
	}
}

/* afree : point to the previous position */
void afree (char *p){

	if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allop = p;
}