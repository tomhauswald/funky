#include "util/linked_list.h"
#include "../sum.h"

void test_sum(void) {

    const size_t len = 10;
    int arr[len];
    init_static_array(arr);
    print_static_array(arr);

    printf("%ld\n", sum(arr, it++, arr + len, *it));

    printf("%ld\n", sum_linear(arr, len, *it));

    printf("%ld\n", sum_static(arr, *it));
}