#ifndef LIST_H
#define LIST_H
#include "cell.h"

typedef struct d_list{
    int max_level;
    struct d_cell** heads;
} l_list;

#endif

