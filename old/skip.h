#pragma once

#include "foreach.h"
#include "count.h"

#define skip(Begin, ReadValStmt, IncrStmt, End, SkipNum, OptOutBuf, OptOutLen) ({ \
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
        size_t num_elems = count(Begin, IncrStmt, End, true) - (SkipNum); \
        outbuf = malloc( num_elems * sizeof(value) ); \
    } \
    \
    foreach( \
        Begin, \
        IncrStmt, \
        End, \
        { if(i >= SkipNum) { outbuf[written++] = *it; } } \
    ); \
    \
    if(NULL != (OptOutLen)) *(size_t *)(OptOutLen) = written; \
    \
    outbuf; \
})

#define skip_linear(Begin, Count, SkipNum, OptOutBuf, OptOutLen) \
    skip(Begin, *it, it++, (Begin) + (Count), SkipNum, OptOutBuf, OptOutLen);

#define skip_static(Array, SkipNum, OptOutBuf, OptOutLen) \
    skip_linear(Array, static_array_len(Array), SkipNum, OptOutBuf, OptOutLen);
