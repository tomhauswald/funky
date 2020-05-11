# funky #
Funky is a single-header library (read: collection of preprocessor macros)
that provides a functional interface to generic collections.
The primary benefit of being preprocessor-based is that funky is able to
accept function arguments in a lambda-like syntax, as opposed to requiring
them to be passed as pointers to named functions.

---

In its current state, funky provides the following basic operations:
1. ) **foreach** (Apply a function to each element.)
1. ) **any** (Check whether at least one element satisfies a predicate.)
1. ) **all** (Check whether all elements satisfy a predicate.)
1. ) **sum** (Evaluate an expression for each element and compute the sum of the results.)
1. ) **count** (Compute the number of elements that satisfy a predicate.)
1. ) **mean** (Evaluate an expression for each element and compute the mean of the results.)

---

Each operation comes in the following four flavors:
1. ) **static** (Apply an operation on a static array.)
1. ) **ntimes** (Apply an operation on a fixed number of elements.)
1. ) **nullterm** (Apply an operation on a NULL-terminated sequence.)
1. ) **linear** (Apply an operation on a collection with linear memory layout.)
