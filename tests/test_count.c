#include "util/linked_list.h"
#include "../count.h"

void test_count(void) {

    const size_t len = 10;
    int arr[len];
    init_static_array(arr);
    print_static_array(arr);
    
    printf("%lu\n", count(arr, it++, arr + len, *it == 1));

    printf("%lu\n", count_linear(arr + len / 2, len - len / 2, *it < 10));

    printf("%lu\n", count_static(arr, *it % 2 == 0));

    printf("%lu\n", count_static(arr, *it % 2 == 1));
}