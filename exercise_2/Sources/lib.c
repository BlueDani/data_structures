#include <stdio.h>
#include "lib.h"


int compare_intervals_order(const void *i1, const void *i2)
{
    t_interval *aux_i1 = (t_interval*)i1;
    t_interval *aux_i2 = (t_interval*)i2;

    return aux_i1->starti - aux_i2->starti; // 0 when equal
}

int compare_intervals_overlap(const void *i1, const void *i2)
{
    t_interval *aux_i1 = (t_interval*)i1;
    t_interval *aux_i2 = (t_interval*)i2;

    // validate if current interval and next one are overlapping
    if(IS_OVERLAPPING(aux_i1->starti, aux_i1->endi, aux_i2->starti, aux_i2->endi))
        return 0; // true

    if(IS_OVERLAPPING(aux_i2->starti, aux_i2->endi, aux_i1->starti, aux_i1->endi))
        return 0; // true


    return 1; // false
}

void merge_intervals(void *i1, const void *i2)
{
    t_interval *aux_i1 = (t_interval*)i1;
    t_interval *aux_i2 = (t_interval*)i2;

    // save min between the starts of both intervals
    if(aux_i2->starti < aux_i1->starti)
        aux_i1->starti = aux_i2->starti;

    // save the max between the ends of both intervals
    if(aux_i2->endi > aux_i1->endi)
        aux_i1->endi = aux_i2->endi;
}

void show_interval(const void *i)
{
    t_interval *aux_i = (t_interval*)i;

    printf("[%d,%d]", aux_i->starti, aux_i->endi);
}

