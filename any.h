#pragma once

#include "foreach.h"

#define any(Begin, IncrStmt, End, Pred) ({ \
    bool result = false; \
    foreach( \
        Begin, \
        IncrStmt, \
        End, \
        if(Pred) { \
            result = true; \
            break; \
        } \
    ); \
    result; \
})

#define any_linear(Begin, Count, Pred) ({ \
    any(Begin, it++, (Begin) + (Count), Pred); \
})

#define any_static(Array, Pred) \
    any_linear(Array, static_array_len(Array), Pred)                               
