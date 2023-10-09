#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#define OK          1
#define NO_MEMORY   0
#define DUPLICATE   2

typedef struct s_node
{
    void *          info;
    unsigned        info_size;
    struct s_node * next;
}t_node;

typedef t_node *t_list;

void create_list(t_list *p);
void empty_list(t_list *p);
int is_empty_list(const t_list *p);

int insert_order_list(t_list *p, const void *elem, unsigned elem_size,
                      int(*compare_info)(const void *, const void *));

int merge_list(t_list *p, int(*compare_info)(const void *, const void *),
               void(*merge_info)(void *, const void *));

void show_list(const t_list *p, void(*show)(const void *));

void show_list_intervals(const t_list *p, void(*show)(const void *));

#endif // LIST_H_INCLUDED
