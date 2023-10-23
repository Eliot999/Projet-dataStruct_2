#include "stdlib.h"
#include <list.h>
t_d_list *create_list(void)
{
    t_d_list *list = malloc(sizeof(t_d_list));
    if (list == NULL)
        return NULL;
    list->head_0 = NULL;
    list->head_1 = NULL;
    return list;
};

