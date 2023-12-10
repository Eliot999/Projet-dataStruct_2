#include "timer.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
typedef struct d_cell{
    int value;
    int level;
    struct d_cell** next;
} s_cell;

typedef struct d_list{
    int max_level;
    struct d_cell** heads;
} l_list;

s_cell * createCell(int, int);
l_list * createEmptyList(int);
void insertHead(l_list * list, int value, int level);
void insertSortedCell(l_list * list, int value, int level);
void simpledisplayList(l_list list);
void displayLevel(l_list list, int lvl);
s_cell* classicsearch(l_list* list,int value);
l_list * createnlvllist(int n);
s_cell* advancedsearch(l_list list, int value);
int generaterandom(int min,int max);

