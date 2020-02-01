#pragma once

#include "foreach.h"

#define count(Begin, IncrStmt, End, Pred) ({ \
    size_t count = 0; \
    foreach(Begin, IncrStmt, End, count += (Pred)); \
    count; \
})

#define count_linear(Begin, Count, Pred) \
    count(Begin, it++, (Begin) + (Count), Pred)

#define count_static(Array, Pred) \
    count_linear(Array, static_array_len(Array), Pred)
