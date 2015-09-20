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