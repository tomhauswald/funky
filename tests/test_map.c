#include "../map.h"
#include "util/linked_list.h"

void test_map(void) {

    int arr[100];
    foreach_static(arr, *it = 0);
    print_static_array(arr);

    map_static(arr, i, arr, NULL);
    print_static_array(arr);

    map_static(arr, (*it) * (*it), arr, NULL);
    print_static_array(arr);
}