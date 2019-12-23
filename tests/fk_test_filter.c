#include "fk_test_shared.h"
#include "../fk_filter.h"

void fk_test_filter(void) {
    
    int all  [ LEN ];
    int none [ LEN ];
    int even [ LEN ];
    int odd  [ LEN ];

    size_t len;

    FK_FILTER(arr, FK_ITEM_PTR++, arr + LEN, true, all, &len);
    FK_FOREACH_LINEAR(all, len, printf("%d ", FK_ITEM));
    clearln();

    FK_FILTER(arr, FK_ITEM_PTR++, arr + LEN, false, none, &len);
    FK_FOREACH_LINEAR(none, len, printf("%d ", FK_ITEM));   
    clearln();
    
    FK_FILTER_LINEAR(arr, LEN, FK_ITEM % 2 == 0, even, &len);
    FK_FOREACH_LINEAR(even, len, printf("%d ", FK_ITEM));   
    clearln();
    
    FK_FILTER_STATIC(arr, FK_ITEM % 2 == 1, odd, &len);
    FK_FOREACH_LINEAR(odd, len, printf("%d ", FK_ITEM));   
    clearln();
}