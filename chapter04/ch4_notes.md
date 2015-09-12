#CH4 Functions and Program Structure

* when arguments are properly declared, appropriate type coercions are performed automatically
* more readings for `C Preprocessor`

###4.1 Basic of Functions

* `strstr()`
* if the return type of a function is omitted, `int` is assumed
* `cc main.c getline.c` will result object code in files `main.o` and `get line.o`, then loads them into executable file `a.out`

###4.2 Functions Returning Non-integer

* calling routine must know the return type of the function, `declaration` of the function explicitly in the calling routine can ensure this
* otherwise, if calling routine and function are compiled separately, the error will not be detected
* first appearance of a function `sum += atof(line)` is declared by context to be a function name, and assumed to return int, nothing is assumed about its arguments
* if a `function declaration` does not include arguments, nothing is assumed

**proper declaration**

	int atoi (char s[]){
		double atof(char s[]);
		return (int) atof(s);
	}
	
###4.3 External Variables

* `internal` arguments and vars defined inside functions
* `external var` are defined outside of any functions, and potentially available to many functions
* `function` are always external (C does not allow function defined inside function)
* `external linkage` external vars and functions are referenced by the same name
* `external var` are more convenient and efficient than long argument lists
* `internal var` is created when entering function and destroyed when leaving function
* 