#ifndef CELL_H
#define CELL_H
typedef struct d_cell{
    int value;
    int level;
    struct d_cell** next;
} s_cell;


#endif