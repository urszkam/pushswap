#include "push_swap.h"


int main(int argc, char **argv)
{
    double  disorder;
    int     algorithm;
    stack_t stack_a;
    meta_t  sort_metdata;

    if argc > 1 
    {
        if (!validate_list(++argv))
        {
            print_err();
            return 1;
        }
        populate_stack(argv, stack_a);
        disorder = calc_disorder(stack_a);
        algorithm = choose_algorithm(argv, disorder);
        sort_stack(stack_a, sort_metadata, disorder, algorithm);
        print_operations(sort_metadata->ops);
        if (is_bench_flag(argv))
            print_bench(sort_metadata);
    }
}