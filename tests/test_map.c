#include "../map.h"
#include "../skip.h"
#include "../take.h"

#include "util/linked_list.h"

void test_map(void) {

    int arr[100];
    foreach_static(arr, *it = 0);
    print_static_array(arr);

    int range[100];
    map_static(arr, i, range, NULL);
    print_static_array(range);
    
    int squares[100];
    map_static(range, (*it) * (*it), squares, NULL);
    print_static_array(squares);
}