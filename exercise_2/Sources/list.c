#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "list.h"

void create_list(t_list *p)
{
    *p = NULL;
}

void empty_list(t_list *p)
{
    t_node *aux;

    while(*p)
    {
        aux = *p;
        *p = aux->next;

        free(aux->info);
        free(aux);
    }
}

int is_empty_list(const t_list *p)
{
    return *p == NULL;
}


int insert_order_list(t_list *p, const void *elem, unsigned elem_size,
                      int(*compare_info)(const void *, const void *))
{
    t_node *new_node;

    // search insertion position
    while(*p && compare_info(elem,(*p)->info)>0)
    {
        p = &(*p)->next;
    }

    // allocate memory for the element-to-insert node and its node
    if( (new_node=(t_node*)malloc(sizeof(t_node))) == NULL ||
            (new_node->info = malloc(elem_size)) == NULL )
    {
        free(new_node);
        return NO_MEMORY;
    }

    // set new node
    memcpy(new_node->info, elem, elem_size);
    new_node->info_size = elem_size;

    // insert new node in list
    new_node->next = *p;
    *p = new_node;

    return OK;
}

int merge_list(t_list *p, int(*compare_info)(const void *, const void *),
               void(*merge_info)(void *, const void *))
{
    t_node *aux_node;
    int deleted_nodes = 0;

    // iterate through list
    while(*p && (*p)->next)
    {
        // if current interval and the next overlap: merge
        if(compare_info((*p)->info, (*p)->next->info) == 0)
        {
            aux_node = (*p)->next;
            merge_info((*p)->info, aux_node->info);

            (*p)->next = aux_node->next;

            free(aux_node->info);
            free(aux_node);

            deleted_nodes++;
        }

        // while current interval and the next do not overlap, advance in list
        if((*p)->next && compare_info((*p)->info, (*p)->next->info) != 0)
        {
            p = &(*p)->next;
        }
    }

    return deleted_nodes;
}


void show_list(const t_list *p, void(*show)(const void *))
{
    while(*p)
    {
        show((*p)->info);
        p = &(*p)->next;
    }
}

void show_list_intervals(const t_list *p, void(*show)(const void *))
{
    printf("[");
    while(*p && (*p)->next)
    {
        show((*p)->info);
        printf(",");
        p = &(*p)->next;
    }

    if(*p)
    {
        show((*p)->info);
    }
    printf("]");
}
