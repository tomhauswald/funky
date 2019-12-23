#include "fk_test_shared.h"
#include "../fk_foreach.h"

void fk_test_foreach(void) {
    
    print_arr();

    FK_FOREACH_LINEAR(
        arr, 
        2,
        { 
            FK_ITEM = 1;
        }
    );

    print_arr();

    FK_FOREACH_LINEAR(
        arr + 2, 
        LEN - 2, 
        {
            FK_ITEM = arr[FK_INDEX] + arr[FK_INDEX + 1];
        }
    );
    
    print_arr();

    FK_FOREACH_LINEAR(
        arr, 
        LEN / 2, 
        {
            printf("%d ", FK_ITEM); 
        }
    ); 
    
    clearln();

    FK_FOREACH_LINEAR(
        arr + LEN / 2, 
        LEN - LEN / 2, 
        {
            printf("%d ", FK_ITEM); 
        }
    );
    
    clearln();

    FK_FOREACH_STATIC(
        arr, 
        {
            printf("%d ", FK_ITEM); 
        }
    ); 
    
    clearln();

    FK_FOREACH_STATIC(
        arr, 
        {
            printf("%lu: %d \t", FK_INDEX, FK_ITEM);
        
            FK_FOREACH_LINEAR(
                arr, 
                FK_INDEX, 
                {
                    printf("%lu: %d ", FK_INDEX, FK_ITEM);
                }
            ); 
        
            clearln();
        }
    );
    
    print_list();

    FK_FOREACH(
        list_head(), 
        FK_ITEM_PTR = FK_ITEM_PTR->next,
        NULL,
        {
            printf("%d ", FK_ITEM.value);
        }
    );
    
    clearln();

    FK_FOREACH(
        list_head(),
        FK_ITEM_PTR = FK_ITEM_PTR->next,
        NULL,
        {
            FK_ITEM.value = FK_INDEX * FK_INDEX;
        }
    );

    FK_FOREACH(
        list_nth_item(LEN / 2),
        FK_ITEM_PTR = FK_ITEM_PTR->next,
        NULL,
        {
            FK_ITEM.value = FK_INDEX * FK_INDEX;
        }
    );

    print_list();
}