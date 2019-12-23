#include "fk_foreach.h"

#define FK_COUNT(Begin, IncrementAction, End, Pred)  \
    ({                                               \
        size_t fk_count_ = 0;                        \
        FK_FOREACH( Begin,                           \
                    IncrementAction,                 \
                    End,                             \
                    {                                \
                        if(Pred) {                   \
                            fk_count_++;             \
                        }                            \
                    } );                             \
        fk_count_;                                   \
    })

#define FK_COUNT_LINEAR(Begin, Count, Pred)          \
    ({                                               \
        __auto_type fk_end_ptr_ = (Begin) + (Count); \
        FK_COUNT( Begin,                             \
                  FK_ITEM_PTR++,                     \
                  fk_end_ptr_,                       \
                  Pred );                            \
    })                                              

#define FK_COUNT_STATIC(Array, Pred)                 \
    FK_COUNT_LINEAR( Array,                          \
                     FK_LENGTH_STATIC(Array),        \
                     Pred )
