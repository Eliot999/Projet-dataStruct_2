#include "cell.h"
#include <stdlib.h>
t_d_cell *create_cell(int value)
{
    t_d_cell *cell = malloc(sizeof(t_d_cell));
    if (cell == NULL)
        return NULL;
    cell->value = value;
    cell->next_0 = NULL;
    cell->next_1 = NULL;
    return cell;
}

t_level_cell *createCell(int value, int level){
    t_level_cell * new = (t_level_cell*) malloc(sizeof(t_level_cell));
    new->value = value;
    new->level= level;
}

