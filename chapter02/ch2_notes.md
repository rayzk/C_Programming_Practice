#Chapter 2 
#Types, Operators and Expressions

###2.1 Variables Names
* lower case for var names
* upper case for constants
* first 31 characters for internal variables are significant
* first 6 characters for internal variables are significant


###2.2 Data Types and Sizes
__Basic data types in C__

* `char` single byte; printable chars are always positive
* `int` 
* `float` single precision floating point
* `double` double precision floating point 

__Qualifiers applied to basic types__

* `short`
* `long`
* `signed`
* `unsigned`


###2.3 Constants
__Integer constant__

* `L` : long constant
* unsigned constants with terminal `u` or `U`
* unsigned long with suffix `ul` or `UL`
* `0` : octal
* `0x` : hex

__Floating-point constants__

* `f` : float constant
* `l` : long double

__Character constants__

* `'x'` is a integer -- numerical value of char `x` in ASCII table

__Constant expression__

* evaluated at compilation time 
* `#define MAXLINE 1000`

__String constants__

* string constants can be concatenated at compile time 
* string constant is an array of chars
* internal representation has a null char `'\0'` at the end
* `strlen()` exclude the `\0` at the end of array

__Enumeration constants__

* an enumeration is a list of constant integer value
* `enum boolean {NO, YES}` NO has value `0` and YES has value `1`
* `enum month {JAN = 1, FEB, MAR, ...}` JAN has the specified value 1, unspecified (FEB ...) continue the value, (FEB=2)
* values need not be distinct in same enum
* names in different enums must be distinct


###2.4 Declarations

* external and static var are initialized to be zero by default
* automatic var have undefined value
* `const` qualifier specify value cannot be changed

###2.6 Relation and Logical Operators

* `||` and `&&` is evaluated from left to right, stops as soon as the truth/false is known
* precedence of `&&` is higher then `||`

###2.7 Type Conversions

* convert from a narrower operand to wider operand 
* specify `signed` or `unsigned` if non-char data is to be stored in `char` var
* longer int converted to shorter int by dropping excess high-order bit
* float to int cause truncation of any fraction part
* absence of function prototype, `char` and `short` becomes `int`, `float` becomes `double`
* 



  
