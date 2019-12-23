#include "fk_foreach.h"

#define FK_ANY(Begin, IncrementAction, End, Pred)     \
    ({                                                \
        bool fk_result_ = false;                      \
        FK_FOREACH( Begin,                            \
                    IncrementAction,                  \
                    End,                              \
                    {                                 \
                        if(Pred) {                    \
                            fk_result_ = true;        \
                            break;                    \
                        }                             \
                    } );                              \
        fk_result_;                                   \
    })

#define FK_ANY_LINEAR(Begin, Count, Pred)             \
    ({                                                \
        __auto_type fk_end_ptr_ = (Begin) + (Count);  \
        FK_ANY( Begin,                                \
                FK_ITEM_PTR++,                        \
                fk_end_ptr_,                          \
                Pred );                               \
    })

#define FK_ANY_STATIC(Array, Pred)                    \
    FK_ANY_LINEAR( Array,                             \
                   FK_LENGTH_STATIC(Array),           \
                   Pred )                               
