#pragma once

#include "foreach.h"
#include "count.h"

#define where(Begin, ReadValStmt, IncrStmt, End, Pred, OptOutBuf, OptOutLen) ({ \
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
        size_t num_matches = count(Begin, IncrStmt, End, Pred); \
        outbuf = malloc( num_matches * sizeof(value) ); \
    } \
    \
    foreach( \
        Begin, \
        IncrStmt, \
        End, \
        if(Pred) { \
            outbuf[written++] = (ReadValStmt); \
        } \
    ); \
    \
    if(NULL != (OptOutLen)) *(OptOutLen) = written; \
    \
    outbuf; \
})

#define where_linear(Begin, Count, Pred, OptOutBuf, OptOutLen) \
    where(Begin, *it, it++, (Begin) + (Count), Pred, OptOutBuf, OptOutLen);

#define where_static(Array, Pred, OptOutBuf, OptOutLen) \
    where_linear(Array, static_array_len(Array), Pred, OptOutBuf, OptOutLen);
