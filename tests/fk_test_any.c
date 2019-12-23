#include "fk_test_shared.h"
#include "../fk_any.h"

void fk_test_any(void) {

    print_arr();

    printf("%s\n", btoa(FK_ANY(
        arr, 
        FK_ITEM_PTR++, 
        arr + LEN, 
        (FK_ITEM % 2 == 0)
    )));

    printf("%s\n", btoa(FK_ANY_LINEAR(
        arr, 
        2,
        (FK_ITEM % 2 == 0)
    )));

    printf("%s\n", btoa(FK_ANY_STATIC(
        arr, 
        (FK_ITEM % 2 == 0)
    )));
}