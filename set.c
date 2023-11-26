#include "cell.h"
#include "set.h"
#include <stdlib.h>
#include "list.h"

s_cell * createCell(int value, int level){
    s_cell * cell = (s_cell *) malloc(sizeof(s_cell));
    cell->value = value;
    cell->next = NULL;
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
//insert cell in a sorted way using the concept of levels
void insertCell(l_list * list, s_cell * cel){
    int level = cel->level;
    int value = cel->value;
    if (list->heads[level] == NULL){
        list->heads[level] = cel;
        return;
    }
    if (list->heads[level] == NULL){
        list->heads[level] = cel;
        return;
    }
    if (list->heads[level]->value > value){
        cel->next = list->heads[level];
        list->heads[level] = cel;
        return;
    }


}
void insertCell2(l_list* LList, s_cell *Cell){

        for(unsigned int i=0; i<Cell->level; i++){
            Cell->next[i] = LList->heads[i];
            LList->heads[i] = Cell;
        }
}