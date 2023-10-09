#ifndef LIB_H_INCLUDED
#define LIB_H_INCLUDED

#define IS_OVERLAPPING(a1,a2,b1,b2)     ( ((a1)>=(b1) && (a1)<=(b2)) || ((a2)>=(b1) && (a2)<=(b2)) )


typedef struct
{
    int starti;
    int endi;
}t_interval;

int compare_intervals_order(const void *i1, const void *i2);
int compare_intervals_overlap(const void *i1, const void *i2);
void merge_intervals(void *i1, const void *i2);
void show_interval(const void *i);

#endif // LIB_H_INCLUDED
