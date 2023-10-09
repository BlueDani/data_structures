#include <stdio.h>
#include <stdlib.h>

#include "functions.h"


int main()
{
    // SHORT INT: 2 bytes: (-32768; 32767)
    // CHAR: 1 byte: (-128; 127)

    int nums[] = {-4, -1, 0, 3, 10};
    //int nums[] = {-7, -3, 2, 3, 11};
    //int nums[] = {-20, -13, -12, -3, 0};
    //int nums[] = {0, 2, 2, 4, 8};
    //int nums[] = {4, 4, 4, 4, 4};
    //int nums[] = {-4, -4, -4, -4, -4};
    //int nums[] = {0, 0, 0, 0, 0};

    size_t nums_size = sizeof(nums)/sizeof(int);
    int *res_nums = sort_square_vector(nums, nums_size);

    if(res_nums)
    {
        show_int_vec(nums, nums_size);
        show_int_vec(res_nums, nums_size);
    }

    free(res_nums);

    return 0;
}
