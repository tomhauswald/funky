#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void clearln(void);

char const* btoa(bool b);

#define init_static_array(Array) \
    foreach_static(Array, *it = i);

#define print_static_array(Array) { \
    if(NULL != (Array)) printf("%d", (Array)[0]); \
    foreach_linear((Array) + 1, static_array_len(Array) - 1, printf(", %d", *it)); \
    clearln(); \
}