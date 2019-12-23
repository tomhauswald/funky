#include "fk_test_shared.h"
#include "../fk_count.h"

void fk_test_count(void) {

    print_arr();

    printf("%lu\n", FK_COUNT(
        arr,
        FK_ITEM_PTR++,
        arr + LEN,
        (FK_ITEM == 1)
    ));

    printf("%lu\n", FK_COUNT_LINEAR(
        arr + LEN / 2,
        LEN - LEN / 2,
        (FK_ITEM < 10)
    ));

    printf("%lu\n", FK_COUNT_STATIC(
        arr, 
        (FK_ITEM % 2 == 0)
    ));

    printf("%lu\n", FK_COUNT_STATIC(
        arr, 
        (FK_ITEM % 2 == 1)
    ));
}