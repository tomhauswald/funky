#pragma once

#include "foreach.h"
#include "count.h"

#define take(Begin, ReadValStmt, IncrStmt, End, TakeNum, OptOutBuf, OptOutLen) ({ \
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
        outbuf = malloc( (TakeNum) * sizeof(value) ); \
    } \
    \
    foreach( \
        Begin, \
        IncrStmt, \
        End, \
        { if(i < TakeNum) { outbuf[written++] = *it; } else { break; } } \
    ); \
    \
    if(NULL != (OptOutLen)) *(size_t *)(OptOutLen) = written; \
    \
    outbuf; \
})

#define take_linear(Begin, Count, TakeNum, OptOutBuf, OptOutLen) \
    take(Begin, *it, it++, (Begin) + (Count), TakeNum, OptOutBuf, OptOutLen);

#define take_static(Array, TakeNum, OptOutBuf, OptOutLen) \
    take_linear(Array, static_array_len(Array), TakeNum, OptOutBuf, OptOutLen);
