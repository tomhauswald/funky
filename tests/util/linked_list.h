#pragma once

#include "common.h"

typedef struct linked_list {
    int value;
    struct linked_list* next;
} linked_list_t;

linked_list_t* list_make_range(size_t len);

size_t list_len(linked_list_t const* list);

linked_list_t* list_tail(linked_list_t* list);

void list_append(linked_list_t* list, int value);

linked_list_t* list_nth_item(linked_list_t* list, size_t n);

void list_delete(linked_list_t* list);

void _print_list(char const* name, linked_list_t const* list);

#define print_list(ListPtr) \
    _print_list(#ListPtr, ListPtr)