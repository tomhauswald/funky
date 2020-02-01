#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

/*
    foreach
    
    Performs an action on each item inside a collection.

    Starting at 'Begin', it is incremented using 
    'IncrStmt' until it equates to 'End'.
    'End' must thus point at the first element after the
    collection.
    
    'Body' is run once for each value of it.
    
    Inside 'Body', the user may refer to:
        it <=> Pointer to current item,
        i  <=> Number of steps away from 'Begin'. 
*/

#define foreach(Begin, IncrStmt, End, Body) { \
    size_t i = 0; \
    for(__auto_type it = (Begin); it != (End); IncrStmt) { \
        Body; \
        i++; \
    } \
}

/*
    Linear version

    Assumes linear layout of the collection, i.e.
    the increment action consists of incrementing the
    item pointer by one.
*/

#define foreach_linear(Begin, Count, Body) { \
    foreach(Begin, it++, (Begin) + (Count), Body); \
}

/*
    Static array version

    Assumes that 'Array' points to the begin of a 
    static array and that its size can be computed as 
    sizeof('Array') / sizeof('Array'[0]).
*/

#define static_array_len(Array) \
    ( sizeof( Array ) / sizeof( (Array) [0] ) )

#define foreach_static(Array, Body) \
    foreach_linear(Array, static_array_len(Array), Body)
