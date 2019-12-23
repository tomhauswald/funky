#include "fk_test_shared.h"
#include "../fk_sum.h"

void fk_test_sum(void) {

    print_arr();

    printf("%ld\n", FK_SUM(
        arr,
        FK_ITEM_PTR++,
        arr + LEN,
        FK_ITEM
    ));

    printf("%ld\n", FK_SUM_LINEAR(
        arr,
        LEN,
        ((-FK_ITEM) * (-FK_ITEM)) / 2
    ));

    printf("%ld\n", FK_SUM_STATIC(
        arr,
        5 - FK_ITEM
    ));
}