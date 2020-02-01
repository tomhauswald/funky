#include "util/linked_list.h"
#include "../any.h"

void test_any(void) {

    const size_t len = 10;
    int arr[len];
    init_static_array(arr);
    print_static_array(arr);

    printf("%s\n", btoa(any(arr, it++, arr + len, *it % 2 == 0)));

    printf("%s\n", btoa(any_linear(arr, 2, *it % 2 == 0)));

    printf("%s\n", btoa(any_static(arr, *it % 2 == 0)));
}