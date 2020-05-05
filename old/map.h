#pragma once

#include "foreach.h"
#include "count.h"

#define map(Begin, ReadValStmt, IncrStmt, End, Expr, OptOutBuf, OptOutLen) ({ \
    __auto_type it     =  (Begin); \
    __auto_type outbuf = &(ReadValStmt); \
    __auto_type value  =  (ReadValStmt); \
    it = NULL; \
    \
    size_t written = 0ul; \
    \
    if(NULL != (OptOutBuf)) { /* Use the given buffer. */ \
        outbuf = (OptOutBuf); \
    } \
    else { /* Heap-allocate new output buffer. */ \
        size_t num_elems = count(Begin, IncrStmt, End, true); \
        outbuf = malloc( num_elems * sizeof(value) ); \
    } \
    \
    _fk_foreach_base( \
        Begin, \
        IncrStmt, \
        End, \
        { outbuf[written++] = (Expr); } \
    ); \
    \
    if(NULL != (OptOutLen)) *(size_t *)(OptOutLen) = written; \
    \
    outbuf; \
})

#define map_linear(Begin, Count, Expr, OptOutBuf, OptOutLen) \
    map(Begin, *it, it++, (Begin) + (Count), Expr, OptOutBuf, OptOutLen);

#define map_static(Array, Expr, OptOutBuf, OptOutLen) \
    map_linear(Array, static_array_len(Array), Expr, OptOutBuf, OptOutLen);
