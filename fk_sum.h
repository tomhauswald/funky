#include "fk_foreach.h"

#define FK_SUM(Begin, IncrementAction, End, Func)    \
    ({                                               \
        int64_t fk_sum_ = 0;                         \
        FK_FOREACH( Begin,                           \
                    IncrementAction,                 \
                    End,                             \
                    {                                \
                        fk_sum_ += (Func);           \
                    } );                             \
        fk_sum_;                                     \
    })

#define FK_SUM_LINEAR(Begin, Count, Func)            \
    ({                                               \
        __auto_type fk_end_ptr_ = (Begin) + (Count); \
        FK_SUM( Begin,                               \
                FK_ITEM_PTR++,                       \
                fk_end_ptr_,                         \
                Func );                              \
    })                                              

#define FK_SUM_STATIC(Array, Func)                   \
    FK_SUM_LINEAR( Array,                            \
                   FK_LENGTH_STATIC(Array),          \
                   Func )
