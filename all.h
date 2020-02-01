#include "any.h"

#define all(Begin, IncrStmt, End, Pred) \
    !any(Begin, IncrStmt, End, !(Pred))

#define all_linear(Begin, Count, Pred) \
    all(Begin, it++, (Begin) + (Count), Pred)

#define all_static(Array, Pred) \
    all_linear(Array, static_array_len(Array), Pred)