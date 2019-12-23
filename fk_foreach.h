#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
    FK_FOREACH
    
    Performs an action on each item inside a collection.

    Starting at 'Begin', FK_ITEM_PTR is incremented using 
    'IncrementAction' until it equates to 'End'.
    'End' must thus point at the first element after the
    collection.
    
    'Body' is run once for each value of FK_ITEM_PTR.
    
    Inside 'Body', the user may refer to:
        FK_ITEM     <=> Current item (lvalue),
        FK_ITEM_PTR <=> Address of FK_ITEM,
        FK_INDEX    <=> Number of steps away from 'Begin'. 
*/

#define FK_INDEX fk_loop_idx_

#define FK_ITEM_PTR fk_item_ptr_

#define FK_ITEM (*(FK_ITEM_PTR))

#define FK_FOREACH(Begin, IncrementAction, End, Body) \
    {                                                 \
        size_t FK_INDEX = 0;                          \
        for ( __auto_type FK_ITEM_PTR = (Begin);      \
              FK_ITEM_PTR != (End);                   \
              IncrementAction                         \
        ) {                                           \
            Body;                                     \
            FK_INDEX++;                               \
        }                                             \
    }

/*
    Linear version

    Assumes linear layout of the collection, i.e.
    the increment action consists of incrementing the
    item pointer by one.
*/

#define FK_FOREACH_LINEAR(Begin, Count, Body)         \
    {                                                 \
        __auto_type fk_end_ptr_ = (Begin) + (Count);  \
        FK_FOREACH(                                   \
            Begin,                                    \
            FK_ITEM_PTR++,                            \
            fk_end_ptr_,                              \
            Body                                      \
        );                                            \
    }

/*
    Static array version

    Assumes that 'Array' points to the begin of a 
    static array and that its size can be computed as 
    sizeof('Array') / sizeof('Array'[0]).
*/

#define FK_LENGTH_STATIC(Array)                       \
    ( sizeof( Array ) / sizeof( (Array) [0] ) )

#define FK_FOREACH_STATIC(Array, Body)                \
    FK_FOREACH_LINEAR(                                \
        Array,                                        \
        FK_LENGTH_STATIC(Array),                      \
        Body                                          \
    )
