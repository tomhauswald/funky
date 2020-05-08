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
#define _fk_nullterm(func, Begin, IncrStmt, Varname, ...) \
    fk_##func(Begin, IncrStmt, NULL, Varname, __VA_ARGS__)

// Uses operator++ to move to the next element.
#define _fk_linear(func, Begin, End, Varname, ...) \
    fk_##func(Begin, _fk_iter++, End, Varname, __VA_ARGS__)

// Uses operator++ to move to the next element and
// stops after 'Count' elements.
#define _fk_ntimes(func, Begin, Count, Varname, ...) \
    fk_##func##_linear(Begin, ((Begin) + (Count)), Varname, __VA_ARGS__)

// Visits all elements of the statically allocated array 'Array'.
// Uses sizeof('Array') / sizeof(('Array')[0]) to compute element count.
#define _fk_static(func, Array, Varname, ...) \
    fk_##func##_ntimes(Array, sizeof(Array) / sizeof((Array)[0]), Varname, __VA_ARGS__)

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


//------------------------------------------------------
// Returns the sum of an expression evaluated for all 
// elements of a collection.
//------------------------------------------------------
// Starting at 'Begin', _fk_iter is advanced using 
// 'IncrStmt' until it equates to 'End', s.t. 'End' 
// shall point to the first element behind the 
// collection. (Think C++ STL std::end)
// 'Expr' is computed for each value of 'Varname',
// which is obtained by dereferencing _fk_iter.
#define fk_sum(Begin, IncrStmt, End, Varname, Expr, AccumType) ({ \
    AccumType _fk_sum = 0; \
    fk_foreach(Begin, IncrStmt, End, Varname, _fk_sum += (AccumType) (Expr)); \
    _fk_sum; \
})

#define fk_sum_nullterm(Begin, IncrStmt, Varname, Expr, AccumType) \
    _fk_nullterm(sum, Begin, IncrStmt, Varname, Expr, AccumType)

#define fk_sum_linear(Begin, End, Varname, Expr, AccumType) \
    _fk_linear(sum, Begin, End, Varname, Expr, AccumType)

#define fk_sum_ntimes(Begin, Count, Varname, Expr, AccumType) \
    _fk_ntimes(sum, Begin, Count, Varname, Expr, AccumType)

#define fk_sum_static(Array, Varname, Expr, AccumType) \
    _fk_static(sum, Array, Varname, Expr, AccumType)

// Signed 64-bit accumulator.
#define fk_ssum64_nullterm(Begin, IncrStmt, Varname, Expr) \
    fk_sum_nullterm(Begin, IncrStmt, Varname, Expr, int64_t)

#define fk_ssum64_linear(Begin, End, Varname, Expr) \
    fk_sum_linear(Begin, End, Varname, Expr, int64_t)

#define fk_ssum64_ntimes(Begin, Count, Varname, Expr) \
    fk_sum_ntimes(Begin, Count, Varname, Expr, int64_t)

#define fk_ssum64_static(Array, Varname, Expr) \
    fk_sum_static(Array, Varname, Expr, int64_t)

// Unsigned 64-bit accumulator.
#define fk_usum64_nullterm(Begin, IncrStmt, Varname, Expr) \
    fk_sum_nullterm(Begin, IncrStmt, Varname, Expr, uint64_t)

#define fk_usum64_linear(Begin, End, Varname, Expr) \
    fk_sum_linear(Begin, End, Varname, Expr, uint64_t)

#define fk_usum64_ntimes(Begin, Count, Varname, Expr) \
    fk_sum_ntimes(Begin, Count, Varname, Expr, uint64_t)

#define fk_usum64_static(Array, Varname, Expr) \
    fk_sum_static(Array, Varname, Expr, uint64_t)

//------------------------------------------------------
// Returns the count of elements of a collection that
// satisfy a given predicate.
//------------------------------------------------------
// Starting at 'Begin', _fk_iter is advanced using 
// 'IncrStmt' until it equates to 'End', s.t. 'End' 
// shall point to the first element behind the 
// collection. (Think C++ STL std::end)
// 'Pred' is checked for each value of 'Varname',
// which is obtained by dereferencing _fk_iter.
#define fk_count(Begin, IncrStmt, End, Varname, Pred) \
    fk_sum(Begin, IncrStmt, End, Varname, !!(Pred), size_t)

#define fk_count_nullterm(Begin, IncrStmt, Varname, Pred) \
    _fk_nullterm(count, Begin, IncrStmt, Varname, Pred)

#define fk_count_linear(Begin, End, Varname, Pred) \
    _fk_linear(count, Begin, End, Varname, Pred)

#define fk_count_ntimes(Begin, Count, Varname, Pred) \
    _fk_ntimes(count, Begin, Count, Varname, Pred)

#define fk_count_static(Array, Varname, Pred) \
    _fk_static(count, Array, Varname, Pred)


//------------------------------------------------------
// Returns the mean of an expression evaluated for all 
// elements of a collection.
//------------------------------------------------------
// Starting at 'Begin', _fk_iter is advanced using 
// 'IncrStmt' until it equates to 'End', s.t. 'End' 
// shall point to the first element behind the 
// collection. (Think C++ STL std::end)
// 'Expr' is computed for each value of 'Varname',
// which is obtained by dereferencing _fk_iter.
#define fk_mean(Begin, IncrStmt, End, Varname, Expr) ({ \
    double _fk_count = 0.0; \
    double _fk_accum = fk_sum(Begin, IncrStmt, End, Varname, (++_fk_count, Expr), double); \
    _fk_accum / _fk_count; \
})

#define fk_mean_nullterm(Begin, IncrStmt, Varname, Expr) \
    _fk_nullterm(mean, Begin, IncrStmt, Varname, Expr)

#define fk_mean_linear(Begin, End, Varname, Expr) \
    _fk_linear(mean, Begin, End, Varname, Expr)

#define fk_mean_ntimes(Begin, Count, Varname, Expr) \
    _fk_ntimes(mean, Begin, Count, Varname, Expr)

#define fk_mean_static(Array, Varname, Expr) \
    _fk_static(mean, Array, Varname, Expr)
