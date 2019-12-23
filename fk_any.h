#include "fk_foreach.h"



#define FK_ANY_RESBUF fk_result_

#define FK_ANY_BODY(Pred)                         \
    {                                             \
        if(Pred) {                                \
            FK_ANY_RESBUF = true;                 \
            break;                                \
        }                                         \
    }



#define FK_ANY(Begin, IncrementAction, End, Pred) \
    ({                                            \
        bool FK_ANY_RESBUF = false;               \
        FK_FOREACH( Begin,                        \
                    IncrementAction,              \
                    End,                          \
                    FK_ANY_BODY(Pred) );          \
        FK_ANY_RESBUF;                            \
    })

#define FK_ANY_LINEAR(Begin, Count, Pred)         \
    ({                                            \
        bool FK_ANY_RESBUF = false;               \
        FK_FOREACH_LINEAR( Begin,                 \
                           Count,                 \
                           FK_ANY_BODY(Pred) );   \
        FK_ANY_RESBUF;                            \
    })

#define FK_ANY_STATIC(Array, Pred)                \
    ({                                            \
        bool FK_ANY_RESBUF = false;               \
        FK_FOREACH_STATIC( Array,                 \
                           FK_ANY_BODY(Pred) );   \
        FK_ANY_RESBUF;                            \
    })


