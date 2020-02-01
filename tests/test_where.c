#include "util/linked_list.h"
#include "../where.h"

void test_where(void) {
    
    const int input_len = 10;
    linked_list_t* input = make_list(input_len);
    
    {
        size_t num_all;
        int all_[input_len];
        (void) where(input, it->value, it = it->next, NULL, true, all_, &num_all);
        printf("[%lu] ", num_all);
        print_static_array(all_);
    }


    {
        size_t num_all;
        int* all_;
        all_ = where(input, it->value, it = it->next, NULL, true, NULL, &num_all);
        printf("[%lu] ", num_all);
        foreach_linear(all_, num_all, printf("%d ", *it));
        clearln();
    }


    {
        size_t num_even;
        int* even;
        even = where(input, it->value, it = it->next, NULL, it->value % 2 == 0, NULL, &num_even);
        printf("[%lu] ", num_even);
        foreach_linear(even, num_even, printf("%d ", *it));
        clearln();
    }
}