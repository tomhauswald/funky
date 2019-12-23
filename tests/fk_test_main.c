#include "fk_test_shared.h"

void clearln(void) { 
    printf("\n"); 
}

char const* btoa(bool b) {
    return b ? "true" : "false";
}

int arr[LEN];

void print_arr(void) {
    for(size_t i = 0; i < LEN; ++i) printf("%d ", arr[i]);
    clearln();
}

linked_list_t head;

linked_list_t* list_head(void) {
    return &head;
}

linked_list_t* list_tail(void) {
    linked_list_t* tail = &head;
    while(tail->next) tail = tail->next;
    return tail;    
}

void append_to_list(int value) {
    linked_list_t* tail = list_tail();
    tail->next = malloc(sizeof(linked_list_t));
    tail->next->value = value;
    tail->next->next = NULL;
}

linked_list_t* list_nth_item(size_t n) {
    linked_list_t* item = &head;
    for(size_t i=0; item && i<n; ++i) {
        item = item->next;
    }
    return item;
}

void init_list(void) {
    head.value = 0;
    head.next = NULL;
    for(int i=1; i<LEN; ++i) {
        append_to_list(i);
    }
}

void print_list(void) {
    linked_list_t* node = &head;
    while(node) {
        printf("%d ", node->value);
        node = node->next;
    }
    clearln();
}

extern void fk_test_foreach(void);
extern void fk_test_any(void);

int main(void) {

    init_list();

    printf("Testing 'foreach' functionality...\n\n");

    fk_test_foreach();

    printf("\n\nTesting 'any' functionality...\n\n");

    fk_test_any();

    return 0;
} 