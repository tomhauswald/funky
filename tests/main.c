#include "util/linked_list.h"

extern void test_foreach(void);
extern void test_any(void);
extern void test_all(void);
extern void test_count(void);
extern void test_where(void);
extern void test_sum(void);
extern void test_map(void);

char const* categories[] = { 
    "foreach", 
    "any", 
    "all",
    "count",
    "sum",
    "where",
    "map"
};

void (*funcs[])(void) = {
    &test_foreach,
    &test_any,
    &test_all,
    &test_count,
    &test_sum,
    &test_where,
    &test_map
};

int main(void) {

    for(size_t i = 0; i < sizeof(categories) / sizeof(char*); ++i) {
        printf("\n\nRunning test category '%s'...\n\n", categories[i]);
        (*funcs[i])();
    }

    return 0;
} 