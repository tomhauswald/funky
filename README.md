# funky #
Funky is a single-header C library (read: collection of preprocessor macros)
that provides a functional interface to collection data types.
Being preprocessor-based, funky is able to accept function arguments in a 
lambda-like syntax. This make a lot of boilerplate code unneccessary, which
was previously required in order to pass around pointers to named functions.

---

## Operations ##
In its current state, funky provides the following operations:

### foreach ###
Perform an action on each element.  
Parameters:  
* `Varname`  
The placeholder name to assign to elements.
* `Action`  
The action to perform. (Function of `Varname`)

### any ###
Check whether at least one element satisfies a predicate.
Parameters:  
* `Varname`  
The placeholder name to assign to elements.  
* `Pred`  
The predicate to check. (Function of `Varname`)

### all ### 
Check whether all elements satisfy a predicate.
Parameters:  
* `Varname`  
The placeholder name to assign to elements.
* `Pred`  
The predicate to check. (Function of `Varname`)

### count ###
Compute the number of elements that satisfy a predicate.
Parameters:  
* `Varname`  
The placeholder name to assign to elements.
* `Pred`  
The predicate to check. (Function of `Varname`)

### sum ###
Evaluate an expression for each element and compute the sum thereof.
Parameters:  
* `Varname`  
The placeholder name to assign to elements.
* `Expr`  
The expression the sum of which to compute. (Function of `Varname`)
* `AccumType`  
Datatype of the accumulator.  
Shorthands for (un-)signed 64-bit accumulators: ssum64, usum64.

### mean ###
Evaluate an expression for each element and compute the mean thereof.
Parameters:  
* `Varname`  
The placeholder name to assign to elements.
* `Expr`  
The expression the mean of which to compute. (Function of `Varname`)

---

## Flavors ##
Each operation comes in the following flavors:

### static ### 
Apply an operation on a static array.  
Parameters: 
* `Array`  
The statically sized array.  
Number of elements to be computable as `sizeof(Array) / sizeof(Array[0])`.

### ntimes ### 
Apply an operation on a fixed number of elements that are laid out linearly in memory.  
Parameters:
* `Begin`  
Pointer to the start of the collection.
* `Count`  
Number of elements to visit.

### nullterm ### 
Apply an operation on a NULL-terminated sequence.  
Parameters:
* `Begin`  
Pointer to the start of the collection.
* `IncrStmt`  
Statement that moves _fk_iter to the next element.

### linear ### 
Apply an operation on a collection with linear memory layout.  
Parameters:
* `Begin`  
Pointer to the start of the collection.
* `End`  
Pointer past the end of the collection.

---
## Examples ##
```C
// Print each message from a static array.
char const* messages[] = { "Hello", "World", "Good", "Bye" };
fk_foreach_static(messages, m, puts(m));

// Print the average of age values stored linearly in memory.
extern int const* ages;
extern int num_ages;
printf("%0.2f", fk_mean_ntimes(ages, num_ages));

// Print whether a bitmask is satisfied by all elements of a 
// NULL-terminated, singly-linked list.
extern struct llnode { uint8_t bits; struct llnode* next; } const* list;
if(fk_all_nullterm(list, _fk_iter = _fk_iter->next, node, node.bits & 0xaa)) {
  puts("Hooray!");
}

// Implement the checksum for a substring. 
extern uint64_t _checksum1(char c);
uint64_t checksum(char const* begin, char const* end) {
  return fk_usum64_linear(begin, end, c, _checksum1(c)); 
}
```
