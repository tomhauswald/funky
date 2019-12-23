#include "fk_test_shared.h"
#include "../fk_all.h"

void fk_test_all(void) {

    print_arr();

    printf("%s\n", btoa(FK_ALL(
        arr, 
        FK_ITEM_PTR++, 
        arr + LEN, 
        (FK_ITEM % 2 == 0)
    )));

    printf("%s\n", btoa(FK_ALL_LINEAR(
        arr, 
        2,
        (FK_ITEM % 2 == 0)
    )));

    printf("%s\n", btoa(FK_ALL_STATIC(
        arr, 
        (FK_ITEM % 2 == 0)
    )));
}