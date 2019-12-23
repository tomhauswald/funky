#include "fk_test_shared.h"
#include "../fk_filter.h"

void fk_test_filter(void) {
    
    size_t len;

    linked_list_t all_list_elems [ LEN ];

    FK_FILTER(
        list_head(), 
        FK_ITEM_PTR = FK_ITEM_PTR->next, 
        NULL, 
        true, 
        all_list_elems, 
        &len
    );
    
    FK_FOREACH_LINEAR(
        all_list_elems, 
        len, 
        printf("%d ", FK_ITEM.value)
    );
    
    clearln();

    int none [ LEN ];
    FK_FILTER(arr, FK_ITEM_PTR++, arr + LEN, false, none, &len);
    FK_FOREACH_LINEAR(none, len, printf("%d ", FK_ITEM));   
    clearln();
    
    int even [ LEN ];
    FK_FILTER_LINEAR(arr, LEN, FK_ITEM % 2 == 0, even, &len);
    FK_FOREACH_LINEAR(even, len, printf("%d ", FK_ITEM));   
    clearln();
    
    int odd [ LEN ];
    FK_FILTER_STATIC(arr, FK_ITEM % 2 == 1, odd, &len);
    FK_FOREACH_LINEAR(odd, len, printf("%d ", FK_ITEM));   
    clearln();

    int interleaved [ LEN ];
    FK_FILTER_STATIC(arr, FK_INDEX % 2 == 0, interleaved, &len);
    FK_FOREACH_LINEAR(interleaved, len, printf("%d ", FK_ITEM));   
    clearln();
}