#include "common.h"

void clearln(void) { 
    printf("\n"); 
}

char const* btoa(bool b) {
    return b ? "true" : "false";
}

void _print_array(char const* name, int* arr, size_t len) {
    printf("Array '%s'\n", name);
    printf("  length = %lu\n", len);
    printf("  values = [");
    printf("%d", arr[0]);
    for(size_t i=1; i<len; ++i) {
        printf(", %d", arr[i]);
    }
    printf("]\n");
}
