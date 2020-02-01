#pragma once

#include "foreach.h"

#define sum(Begin, IncrStmt, End, Func) ({ \
    int64_t result = 0; \
    foreach(Begin, IncrStmt, End, result += (Func)); \
    result; \
})

#define sum_linear(Begin, Count, Func) ({ \
    __auto_type end = (Begin) + (Count); \
    sum(Begin, it++, end, Func); \
})                                              

#define sum_static(Array, Func) \
    sum_linear(Array, static_array_len(Array), Func)
