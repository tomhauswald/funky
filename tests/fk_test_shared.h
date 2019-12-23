#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void clearln(void);

char const* btoa(bool b);

#define LEN 10
extern int arr[LEN];

void print_arr();

typedef struct linked_list {
    int value;
    struct linked_list* next;
} linked_list_t;

linked_list_t* list_head(void);

linked_list_t* list_tail(void);

void append_to_list(int value);

linked_list_t* list_nth_item(size_t n);

void init_list(void);

void print_list(void);