#include "util/linked_list.h"
#include "../foreach.h"

void test_foreach(void) {
    
    const size_t len = 10;
    int arr[len];
    init_static_array(arr);
    print_static_array(arr);



    foreach_linear(arr, 2, *it = 1);

    print_static_array(arr);



    foreach_linear(arr + 2, len - 2, *it = arr[i] + arr[i + 1]);
    
    print_static_array(arr);



    foreach_linear(arr, len / 2, printf("%d ", *it));
    
    clearln();



    foreach_linear(arr + len / 2, len - len / 2, printf("%d ", *it));
    
    clearln();



    foreach_static(arr, printf("%d ", *it));
    
    clearln();



    foreach_static(arr, {
        size_t outer = i;
        printf("%lu: %d \t", outer, *it);
        foreach_linear(arr, outer, {
            size_t inner = i;
            printf("%lu: %d ", inner, *it);
        }); 
        clearln();
    });



    linked_list_t* list = list_make_range(len);
    print_list(list);



    foreach(
        list, 
        it = it->next,
        NULL,
        printf("%d ", it->value)
    );
    
    clearln();



    foreach(
        list,
        it = it->next,
        NULL,
        it->value = i * i
    );



    foreach(
        list_nth_item(list, len / 2),
        it = it->next,
        NULL,
        it->value = i * i
    );

    print_list(list);

    list_delete(list);
}