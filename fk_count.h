#include "fk_foreach.h"

#define FK_COUNT_VAR fk_count_

#define FK_COUNT_BODY(Pred)                         \
    {                                               \
        if(Pred) {                                  \
            FK_COUNT_VAR++;                         \
        }                                           \
    }

#define FK_COUNT(Begin, IncrementAction, End, Pred) \
    ({                                              \
        size_t FK_COUNT_VAR = 0;                    \
        FK_FOREACH( Begin,                          \
                    IncrementAction,                \
                    End,                            \
                    FK_COUNT_BODY(Pred) );          \
        FK_COUNT_VAR;                               \
    })

#define FK_COUNT_LINEAR(Begin, Count, Pred)         \
    ({                                              \
        size_t FK_COUNT_VAR = 0;                    \
        FK_FOREACH_LINEAR( Begin,                   \
                           Count,                   \
                           FK_COUNT_BODY(Pred) );   \
        FK_COUNT_VAR;                               \
    })

#define FK_COUNT_STATIC(Array, Pred)                \
    ({                                              \
        size_t FK_COUNT_VAR = 0;                    \
        FK_FOREACH_STATIC( Array,                   \
                           FK_COUNT_BODY(Pred) );   \
        FK_COUNT_VAR;                               \
    })
