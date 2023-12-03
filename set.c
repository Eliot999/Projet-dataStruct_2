#include "set.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
s_cell * createCell(int value, int level){
    s_cell * cell = (s_cell *) malloc(sizeof(s_cell));
    cell->value = value;
    cell->next = malloc(sizeof(s_cell*)*level);
    cell->level=level;
    return cell;
}

l_list * createEmptyList(int max_level){
    l_list *list = malloc(sizeof(l_list));
    list->max_level = max_level;
    list->heads =  malloc(sizeof(s_cell *) * max_level);
    for(int i = 0; i < max_level; i++){
        list->heads[i] = NULL;
    }
    return list;
}


void insertHead(l_list * list, int value, int level) {
    if (level > list->max_level || level < 0) {
        printf("Can't insert the cell: Invalid level.");
        return;

    }
    s_cell *cell = createCell(value,level);
    for(int i=0;i<=level;i++)
    {
        cell->next[i]=list->heads[i];
        list->heads[i]=cell;
    }
}

void insertSortedCell(l_list *list, int value, int level) {
    // Check if the level is within the skip list's range or if it's negative
    if (level > list->max_level || level < 0) {
        printf("Can't insert the cell: Invalid level.");
        return;
    }

    // Create a new cell with the provided value and maximum level of the skip list
    s_cell *cell = createCell(value, level);

    // If the skip list is empty or the value is smaller than the first cell's value
    if (list->heads[0] == NULL || list->heads[0]->value > cell->value) {
        // Insert the new cell at all levels up to the given level
        for (int i = 0; i <= level; i++) {
            cell->next[i] = list->heads[i];
            list->heads[i] = cell;
        }
    } else {
        // Iterate through each level up to the given level
        for (int i = 0; i <= level; i++) {
            s_cell *ptr = list->heads[i];
            s_cell *previous = NULL;

            // Traverse horizontally to find the appropriate position for insertion
            while (ptr != NULL && ptr->value < cell->value) {
                previous = ptr;
                ptr = ptr->next[i];
            }
            // Adjust pointers to insert the new cell at the appropriate position
            if (previous != NULL) {
                cell->next[i] = previous->next[i];
                previous->next[i] = cell;
            } else {
                cell->next[i] = list->heads[i];
                list->heads[i] = cell;
            }
        }
    }
}

void simpledisplayList(l_list list) {
    for (int i = 0; i < list.max_level; i++) {
        printf("list_head_%d @-]-->", i);

        s_cell *cell = list.heads[i];
        while (cell != NULL) {
            printf("[%d|@-]-->", cell->value);
            // Check if the next pointer at this level is NULL or invalid
            if (i >= list.max_level || cell->next[i] == NULL) {
                break;  // Exit the loop if the next pointer is NULL or invalid
            }
            cell = cell->next[i];
        }

        printf("NULL\n");
    }
}

void displayLevel(l_list list, int lvl) {
    if (lvl < 0 || lvl > list.max_level) {
        printf("Invalid level.");
        return;
    }

    printf("list_head_%d @-]-->", lvl);

    s_cell *cell = list.heads[lvl];
    while (cell != NULL) {
        printf("[%d|@-]-->", cell->value);

        // Check if the next pointer at this level is NULL
        if (cell->next[lvl] == NULL) {
            break;  // Exit the loop if the next pointer is NULL
        }

        cell = cell->next[lvl];
    }

    printf("NULL\n");
}
 l_list * createnlvllist(int n)
{
    int size=pow(2,n)-1;
    int* array=(int*) malloc(size * sizeof(int));
    for (int i=0;i<=size;i++)
    {
        array[i]=0;
    }//initialisation
    for (int step=1;step<=n;step++)
    {
        for(int i=0;i<=size;i+=pow(2,step))
        {
            array[i]+=1;
        }
    }
    l_list * nlevellist= createEmptyList(n);
    for (int i=0;i<size;i++)
    {
        insertSortedCell(nlevellist,i+1,i);
    }
    return nlevellist;
}

void classicsearch(l_list* list,int value)
{
    startTimer();
    int i=0;
    int found=0;
    s_cell* ptr=list->heads[0];
    while(found==0 && ptr!=NULL)
    {
        if (ptr->value==value)
        {
            found=1;
            stopTimer();
            displayTime();
        }
        else
        {
            ptr=ptr->next;
        }


    }
}