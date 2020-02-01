#include "common.h"

void clearln(void) { 
    printf("\n"); 
}

char const* btoa(bool b) {
    return b ? "true" : "false";
}