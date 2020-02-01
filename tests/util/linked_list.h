#pragma once

#include "common.h"

typedef struct linked_list {
    int value;
    struct linked_list* next;
} linked_list_t;

linked_list_t* make_list(size_t len);

size_t list_len(linked_list_t const* list);

linked_list_t* list_tail(linked_list_t* list);

void list_append(linked_list_t* list, int value);

linked_list_t* list_nth_item(linked_list_t* list, size_t n);

void print_list(linked_list_t const* list);