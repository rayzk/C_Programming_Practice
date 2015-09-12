#CH3 Control Flow

###3.1 Statements and Blocks

* `;` is the statement terminator 
* `compound statement` is statements grouped inside `{}`
* Variables can be declared inside any block

###3.2 If-Else

pernicious false:

	if (...)
		if (...)
			...
	else 
		...
		
###3.3 Else-If

* Ex3_1 binary search

###3.4 Switch

	switch (expression) {
		case const-expr: statements;
		case const-expr: statements;
		default: statements
	}

* each statement is labeled by one or more `integer-valued` constants or constants expression
* default case can occur in any order
* falling through from one case to another is not robust


###3.5 Loops While and For

* Shell sort use nest loop

###3.6 Loops Do-While

###3.7 Break and Continue

* `continue` is not applicable to `switch` 
* a `continue` inside a `switch` inside a `loop` causes the next loop iteration

###3.8 Goto and Labels

* useful when abandon processing in nested loops


 