#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void clearln(void);

char const* btoa(bool b);

#define init_static_array(Array) \
    foreach_static(Array, *it = i);

void _print_array(char const* name, int* arr, size_t len);

#define print_array(Array, Len) \
    _print_array(#Array, Array, Len)

#define print_static_array(Array) \
    _print_array(#Array, Array, static_array_len(Array))