#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void clearln(void);

char const* btoa(bool b);

#define init_static_array(Array) \
    foreach_static(Array, *it = i);

void print_array(int* arr, size_t len);

#define print_static_array(Array) \
    print_array(Array, static_array_len(Array))