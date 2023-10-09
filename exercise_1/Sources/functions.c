#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

int* sort_square_vector(int * vec, size_t vec_size)
{
    // validate original vector is not NULL nor empty
    if(!vec || !vec_size)
    {
        printf("ERROR: empty/null vector.\n");
        return NULL;
    }

    // create new vector for results + allocate memory and verify
    int* new_vec = (int*)malloc(sizeof(int)*vec_size);
    if(!new_vec)
    {
        printf("ERROR: memory allocation.\n");
        return NULL;
    }

    // set vars
    int *left = vec;
    int *right = vec + vec_size -1;
    int *aux_new_vec = new_vec + vec_size -1; // to assign values into new_vec from the last position
    int left_sqr, right_sqr;

    // read values and save their squares in new vctor
    while(left <= right)
    {
        // calculate squares
        left_sqr = SQUARE(*left);
        right_sqr = SQUARE(*right);

        // save squares in new_vec in non-decreasing order
        if( left_sqr >= right_sqr)
        {
            // left is bigger than right -> save it last + increase left pointer
            *aux_new_vec = left_sqr;
            left++;
        }
        else
        {
            // right is bigger than left -> save it last + increase right pointer
            *aux_new_vec = right_sqr;
            right--;
        }
        // in any case, an insertion has been made using aux_new_vec, so decrease it
        aux_new_vec--;
    }

    return new_vec;
}

void show_int_vec(int *vec, size_t vec_size)
{
    printf("[");
    while(vec_size-1)
    {
        printf("%d,", *vec);
        vec++;
        vec_size--;
    }
    if(vec_size)
    {
        printf("%d]\n", *vec);
    }
}
