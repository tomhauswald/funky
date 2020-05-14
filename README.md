# funky #
Funky is a single-header C library (read: collection of preprocessor macros)
that provides a functional interface to collection data types.
Being preprocessor-based, funky is able to accept function arguments in a 
lambda-like syntax. This make a lot of boilerplate code unneccessary, which
was previously required in order to pass around pointers to named functions.

---

In its current state, funky provides the following operations:
1. ) **foreach** (Apply a function to each element.)
1. ) **any** (Check whether at least one element satisfies a predicate.)
1. ) **all** (Check whether all elements satisfy a predicate.)
1. ) **sum** (Evaluate an expression for each element and compute the sum thereof.)
1. ) **count** (Compute the number of elements that satisfy a predicate.)
1. ) **mean** (Evaluate an expression for each element and compute the mean thereof.)

---

Each operation comes in the following flavors:
1. ) **static** (Apply an operation on a static array.)
1. ) **ntimes** (Apply an operation on a fixed number of elements.)
1. ) **nullterm** (Apply an operation on a NULL-terminated sequence.)
1. ) **linear** (Apply an operation on a collection with linear memory layout.)

---
## Examples ##
```C
int array[] = { 1, 2, 3 };
fk_foreach_static(array, i, printf("%d", i));
```
