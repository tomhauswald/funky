#include "common.h"
#include "linked_list.h"

linked_list_t* make_list(size_t len) {
    linked_list_t* list = (linked_list_t*) malloc(sizeof(linked_list_t) * len);
    list->value = 0;
    list->next = NULL;
    for(size_t i=1; i<len; ++i) {
        list_append(list, i);
    }
    return list;
}

size_t list_len(linked_list_t const* list) {
    size_t len = 0ul;
    if(list) ++len;
    while(list->next) {
        ++len; 
        list = list->next;
    }
    return len;
}

linked_list_t* list_tail(linked_list_t* list) {
    while(list && list->next) list = list->next;
    return list;    
}

void list_append(linked_list_t* list, int value) {
    linked_list_t* tail = list_tail(list);
    tail->next = malloc(sizeof(linked_list_t));
    tail->next->value = value;
    tail->next->next = NULL;
}

linked_list_t* list_nth_item(linked_list_t* list, size_t n) {
    for(size_t i=0; i<n; ++i) {
        list = (NULL != list) ? (list->next) : NULL;
    }
    return list;
}

void _print_list(char const* name, linked_list_t const* list) {
    printf("Linked List '%s'\n", name);
    printf("  length = %lu\n", list_len(list));
    printf("  values = [");
    if(list) {
        printf("%d", list->value);
        list = list->next;
    }
    while(list) {
        printf(", %d", list->value);
        list = list->next;
    }
    printf("]\n");
}