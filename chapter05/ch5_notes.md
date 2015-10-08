#CH5 Pointers and Arrays

*Pointers have been lumped with the goto statement as a marvelous way to create impossible to-understand programs*

###5.1 Pointers and Address

* a typical machine has `an array of consecutively numbered / addressed` memory cells
* unary operator `&` gives the address of an object
* `&` operator can only applied to objects in memory : `vars and array elements` ; cannot applied to `constants` or `register`
* unary operator `*` is `dereferencing` operator, applied to pointer 
* The `asterisk` means that ip, the variable we're declaring, is not `of type int`, but rather `of type pointer-to-int`. (Another way of looking at it is that *ip, which as we'll see is `the value pointed to by ip, will be an int`.

**Example of * and &**

	int x=1, y=2, z[10];
	int *ip; // ip is a pointer to int
	
	ip = &x; // ip now points to x
	y = *ip; // y is now 1
	*ip = 0; // x is now 0
	ip = &z[0] // ip is now points to z[0]
	
* pointer points to a specific data type
* a `pointer to void` is used to hold any type of pointer, but cannot be `dereferenced` 
* the unary operators `*` and `&` bind more tightly than `arithmetic operators`
* `++*ip` and `(*ip++)` where parentheses is necessary
* `iq = ip` makes `iq` points to whatever `ip` points to


###5.2 Pointers and Function Arguments

* C passes arguments to function by value
* `swap (int *px, int *py)`

###5.3 Pointers and Arrays

* operations with `array subscripting` can be done with `pointers`; a pointer version will in general be faster
* the value of a `variable` or `expression of type array` is the address of element zero of the array
* `pa = &a[0]` is the same as `pa = a`
* in evaluating a[i], c convert it to `*(a+i)` immediately, (ith element beyond a)
* `&a[i]` and `a+i` are identical
* if `pa` is a pointer, `pa[i]` is identical to `(pa+i)`
* an `array-and-index` expression is equivalent to one written as a `pointer and offset`
* `difference`: 
	* `pointer` is variable => `pa=a` and `pa++` is legal; 
	* `array` is not variable => cannot perform `a=pa` or `a++`
* it is illegal to refer to objects that are not within the array bounds 

**example of array address**

	// within caller :
	f (&a[2])
	f (a+2)
	
	// within function :
	f (int arr[]) {...}
	f (int *arr) {...}
	
###5.4 Address Arithmetic

* `0` is never a valid address for data, thus return 0 to signal an `abnormal event` when `returning pointer`
* `pointers` and `integers` are not interchangeable; `zero` is an exception
	* `constant zero` can be assigned to pointer
	* `pointer` can be compared with constant `zero`
* `NULL` is used in place of `zero` to indicate that this is a special value for a `pointer`
* the behavior is undefined for arithmetic or comparisons with pointers that do not point to members of the same array
* Valid pointer operations :
	* `pointer` and `integer` can be added or subtracted
	* `comparing` two pointers being members of same array
	* assignment of pointers of the same type (except for `void *`)
	* assigning or comparing to `zero`
	
* `void pointer`:
	* general purpose pointer
	* does not have any data type associated with it
	* it can store address of any type of vars
	* is a C convention for raw address
	* use `*((int*)vp)` to dereference a void pointer currently pointing to a integer

###5.5 Character Pointers and Functions

**example of printf()**

	printf ("hello world\n");
	
* printf() receives a `pointer` to the beginning of the character array

**example of msg_pointer**

	char *pmsg;
	msg = "this is a string.";
	
	char amsg[] = "this is a string.";
	
* pmsg is not a string copy; it can point to elsewhere 
* amsg will always refer to the same storage

**standard idiom of stack op**

	*--p;
	
	// push val to the stack
	*p++ = val;
	
	// pop top of the stack into val
	val = *--p;
	
	while (s++)
	// is equivalent to :
	while (s){
		...
		...
		s++;
	}
	
###5.6 Pointer Arrays: Pointers to Pointers

**Example of text-line sorter**

###5.7 Multi-dimensional Arrays

* `daytab[i][j]` // [row][col]
* if two dimensional array is passed to a function, the parameter declared in the function must include the number of `columns`
* `int *daytab[13]` is an array of 13 pointers to integers

**example of function declaration** 

	f (int daytab[2][13]) { ... }
	f (int daytab[][13]) { ... }
	f (int (*daytab)[13]) { ... }
	
###5.8 Initialization of Pointer Arrays

* use `char *name[]` to init a array of strings
* the compiler counts the initializers and fills in the correct number of characters

###5.9 Pointers VS Multidimensional Array

**example of pointers and 2-d array**

	int a[10][20]
	int *b[10]

* for `a`, 200 int-sized locations have been set aside; conventionally `20*row + col` is used to find element
* for `b`, this line only allocate 10 pointers without initialization; 
* assuming b is inited, there are 200 int-sized locations plus 10 cells for pointers
* the `advantage of pointers` is that the row of arrays can be different length

###5.10 Command-line Arguments

**example of main command args**

	main (int argc, char *argv[])
	
* `argc` for arguments count
* `argv` for arguments vector
* by convention, `argv[0]` is the name invoked (i.e., `./a.out`); use `++argv` to access the meaningful arguments
* `argv[argc]` is a null pointer
* 
	