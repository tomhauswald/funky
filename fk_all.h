#include "fk_any.h"

#define FK_ALL(Begin, IncrementAction, End, Pred) \
    ( !( FK_ANY(                                  \
        Begin,                                    \
        IncrementAction,                          \
        End,                                      \
        ( !(Pred) )                               \
    ) ) )

#define FK_ALL_LINEAR(Begin, Count, Pred)         \
    ( !( FK_ANY_LINEAR(                           \
        Begin,                                    \
        Count,                                    \
        ( !(Pred) )                               \
    ) ) )

#define FK_ALL_STATIC(Array, Pred)                \
    ( !( FK_ANY_STATIC(                           \
        Array,                                    \
        ( !(Pred) )                               \
    ) ) )
