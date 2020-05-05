#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#define _FK_VARARG0(_0, ...) _0
#define _FK_VARARG1(_0, _1, ...) _1
#define _FK_VARARG2(_0, _1, _2, ...) _2
#define _FK_VARARG3(_0, _1, _2, _3, ...) _3
#define _FK_VARARG4(_0, _1, _2, _3, _4, ...) _4
#define _FK_VARARG5(_0, _1, _2, _3, _4, _5, ...) _5
#define _FK_VARARG6(_0, _1, _2, _3, _4, _5, _6, ...) _6
#define _FK_VARARG7(_0, _1, _2, _3, _4, _5, _6, _7, ...) _7
#define _FK_VARARG8(_0, _1, _2, _3, _4, _5, _6, _7, _8, ...) _8
#define _FK_VARARG9(_0, _1, _2, _3, _4, _5, _6, _7, _8, _9, ...) _9

// Stops at null terminator.
#define _fk_nullterm(func, Begin, IncrStmt, Varname, Body) \
    fk_##func(Begin, IncrStmt, NULL, Varname, Body)

// Uses operator++ to move to the next element.
#define _fk_linear(func, Begin, End, Varname, Body) \
    fk_##func(Begin, _fk_iter++, End, Varname, Body)

// Uses operator++ to move to the next element and
// stops after 'Count' elements.
#define _fk_ntimes(func, Begin, Count, Varname, Body) \
    fk_##func##_linear(Begin, ((Begin) + (Count)), Varname, Body)

// Visits all elements of the statically allocated array 'Array'.
// Uses sizeof('Array') / sizeof(('Array')[0]) to compute element count.
#define _fk_static(func, Array, Varname, Body) \
    fk_##func##_ntimes(Array, sizeof(Array) / sizeof((Array)[0]), Varname, Body)

//------------------------------------------------------
// Performs an action on each element of a collection.
//------------------------------------------------------
// Starting at 'Begin', _fk_iter is advanced using 
// 'IncrStmt' until it equates to 'End', s.t. 'End' 
// shall point to the first element behind the 
// collection. (Think C++ STL std::end)
// 'Body' is run once for each value of 'Varname',
// which is obtained by dereferencing _fk_iter.
#define fk_foreach(Begin, IncrStmt, End, Varname, Body) { \
    for(__auto_type _fk_iter = (Begin); _fk_iter != (End); IncrStmt) { \
        __auto_type Varname = *_fk_iter; \
        Body; \
    } \
}

#define fk_foreach_nullterm(Begin, IncrStmt, Varname, Body) \
    _fk_nullterm(foreach, Begin, IncrStmt, Varname, Body)

#define fk_foreach_linear(Begin, End, Varname, Body) \
    _fk_linear(foreach, Begin, End, Varname, Body)

#define fk_foreach_ntimes(Begin, Count, Varname, Body) \
    _fk_ntimes(foreach, Begin, Count, Varname, Body)

#define fk_foreach_static(Array, Varname, Body) \
    _fk_static(foreach, Array, Varname, Body)


//------------------------------------------------------
// Returns whether a predicate is true for at least one
// element of a collection.
//------------------------------------------------------
// Starting at 'Begin', _fk_iter is advanced using 
// 'IncrStmt' until it equates to 'End', s.t. 'End' 
// shall point to the first element behind the 
// collection. (Think C++ STL std::end)
// 'Pred' is checked for each value of 'Varname',
// which is obtained by dereferencing _fk_iter.
#define fk_any(Begin, IncrStmt, End, Varname, Pred) ({ \
    bool _fk_result = false; \
    fk_foreach(Begin, IncrStmt, End, Varname, if(Pred) { _fk_result = true; break; }); \
    _fk_result; \
})

#define fk_any_nullterm(Begin, IncrStmt, Varname, Pred) \
    _fk_nullterm(any, Begin, IncrStmt, Varname, Pred)

#define fk_any_linear(Begin, End, Varname, Pred) \
    _fk_linear(any, Begin, End, Varname, Pred)

#define fk_any_ntimes(Begin, Count, Varname, Pred) \
    _fk_ntimes(any, Begin, Count, Varname, Pred)

#define fk_any_static(Array, Varname, Pred) \
    _fk_static(any, Array, Varname, Pred)


//------------------------------------------------------
// Returns whether a predicate is true for all elements 
// of a collection.
//------------------------------------------------------
// Starting at 'Begin', _fk_iter is advanced using 
// 'IncrStmt' until it equates to 'End', s.t. 'End' 
// shall point to the first element behind the 
// collection. (Think C++ STL std::end)
// 'Pred' is checked for each value of 'Varname',
// which is obtained by dereferencing _fk_iter.
#define fk_all(Begin, IncrStmt, End, Varname, Pred) \
    !fk_any(Begin, IncrStmt, End, Varname, !(Pred))

#define fk_all_nullterm(Begin, IncrStmt, Varname, Pred) \
    _fk_nullterm(all, Begin, IncrStmt, Varname, Pred)

#define fk_all_linear(Begin, End, Varname, Pred) \
    _fk_linear(all, Begin, End, Varname, Pred)

#define fk_all_ntimes(Begin, Count, Varname, Pred) \
    _fk_ntimes(all, Begin, Count, Varname, Pred)

#define fk_all_static(Array, Varname, Pred) \
    _fk_static(all, Array, Varname, Pred)


// TODO: Add descriptions and variant macros.

#define fk_sum(Begin, IncrStmt, End, Expr) ({ \
    int64_t _fk_sum = 0; \
    fk_foreach(Begin, IncrStmt, End, _fk_sum += (Expr)); \
    _fk_sum; \
})

#define fk_count(Begin, IncrStmt, End, Pred) \
    fk_sum(Begin, IncrStmt, End, !!(Pred))


// TODO: Port old macros.