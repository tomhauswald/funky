#include "util/linked_list.h"
#include "../all.h"

void test_all(void) {

    const size_t len = 10;
    int arr[len];
    init_static_array(arr);
    print_static_array(arr);

    printf("%s\n", btoa(all(arr, it++, arr + len, *it % 2 == 0)));

    printf("%s\n", btoa(all_linear(arr, 2, *it % 2 == 0)));

    printf("%s\n", btoa(all_static(arr, *it % 2 == 0)));
}