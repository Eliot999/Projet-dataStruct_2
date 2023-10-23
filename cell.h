#ifndef CELL_H
#define CELL_H


typedef struct s_d_cell
{
    int value;
    struct s_d_cell *next_0;
    struct s_d_cell *next_1;
} t_d_cell;

typedef struct t_level_cell
{
    int value;
    int level;
    struct t_level_cell *next;
} t_level_cell;

t_d_cell *create_cell(int value);
t_level_cell *createCell(int value, int level);

#endif