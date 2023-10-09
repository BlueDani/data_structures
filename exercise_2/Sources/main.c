#include <stdio.h>
#include <stdlib.h>

#include "lib.h"
#include "list.h"

int main()
{
    int i;

    t_interval intervals[] = {{1,3},{2,6},{8,10},{15,18},{13,16}};
    //t_interval intervals[] = {{1,4},{4,5},{0,15}};
    //t_interval intervals[] = {{1,2}};
    //t_interval intervals[] = {}; // this case does not respect constraints

    t_interval *aux_intervals = intervals;
    t_list intervals_list;

    create_list(&intervals_list);

    // load vector in list, in non-decreasing order
    for(i=0 ; i<(sizeof(intervals)/sizeof(t_interval)) ; i++)
    {
        if(!insert_order_list(&intervals_list, aux_intervals, sizeof(t_interval), compare_intervals_order))
        {
            exit(1);
        }
        aux_intervals++;
    }
    // show list of intervals pre-merge
    printf("PRE-MERGE:\t");
    show_list_intervals(&intervals_list, show_interval);
    merge_list(&intervals_list, compare_intervals_overlap, merge_intervals);
    printf("\n");

    // show list of intervals post-merge
    printf("POST-MERGE:\t");
    show_list_intervals(&intervals_list, show_interval);
    printf("\n");

    // free allocated memory for list
    empty_list(&intervals_list);

    return 0;
}
