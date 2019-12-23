#include "fk_foreach.h"

#define FK_FILTER(Begin, IncrementAction, End, Pred, OutBuf, OutLen)  \
    {                                                                 \
        size_t fk_count_ = 0;                                         \
        FK_FOREACH( Begin,                                            \
                    IncrementAction,                                  \
                    End,                                              \
                    {                                                 \
                        if(Pred) {                                    \
                            (OutBuf)[fk_count_++] = FK_ITEM;          \
                        }                                             \
                    } );                                              \
        if(NULL != (OutLen)) *(OutLen) = fk_count_;                   \
    }

#define FK_FILTER_LINEAR(Begin, Count, Pred, OutBuf, OutLen) \
    {                                                        \
        __auto_type fk_end_ptr_ = (Begin) + (Count);         \
        FK_FILTER( Begin,                                    \
                   FK_ITEM_PTR++,                            \
                   fk_end_ptr_,                              \
                   Pred,                                     \
                   OutBuf,                                   \
                   OutLen );                                 \
    }

#define FK_FILTER_STATIC(Array, Pred, OutBuf, OutLen)        \
    FK_FILTER_LINEAR( Array,                                 \
                      FK_LENGTH_STATIC(Array),               \
                      Pred,                                  \
                      OutBuf,                                \
                      OutLen );
