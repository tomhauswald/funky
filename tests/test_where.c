#include "util/linked_list.h"
#include "../where.h"

void test_where(void) {
    
    const int input_len = 10;
    linked_list_t* input = list_make_range(input_len);
    
    {
        size_t num_all;
        int all_[input_len];
        (void) where(input, it->value, it = it->next, NULL, true, all_, &num_all);
        print_static_array(all_);
    }


    {
        size_t num_all;
        int* all_;
        all_ = where(input, it->value, it = it->next, NULL, true, NULL, &num_all);
        print_array(all_, num_all);
        free(all_);
    }


    {
        size_t num_even;
        int* even;
        even = where(input, it->value, it = it->next, NULL, it->value % 2 == 0, NULL, &num_even);
        print_array(even, num_even);
        free(even);
    }

    {
        size_t num_odd;
        int* odd;
        odd = where(input, it->value, it = it->next, NULL, it->value % 2 == 1, NULL, &num_odd);
        print_array(odd, num_odd);
        free(odd);
    }

    {
        size_t num_leq_7;
        int* leq_7;
        leq_7 = where(input, it->value, it = it->next, NULL, it->value <= 7, NULL, &num_leq_7);
        print_array(leq_7, num_leq_7);
        free(leq_7);
    }

    {
        size_t len;
        int* leq_7; 
        int* even_leq_7;
        leq_7 = where(input, it->value, it = it->next, NULL, it->value <= 7, NULL, &len);
        even_leq_7 = where_linear(leq_7, len, *it % 2 == 0, NULL, &len);
        print_array(even_leq_7, len);
        free(leq_7);
        free(even_leq_7);
    }

    list_delete(input);
}