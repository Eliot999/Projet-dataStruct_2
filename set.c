#include "cell.h"
#include "set.h"
#include <stdlib.h>
#include "list.h"
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
//insert cell in a sorted way using the concept of levels
// Une fonction pour créer une nouvelle cellule avec une valeur et un niveau donnés
s_cell* create_cell(int value, int level) {
    // On alloue de la mémoire pour la cellule
    s_cell* cell = malloc(sizeof(s_cell));
    // On initialise la valeur et le niveau de la cellule
    cell->value = value;
    cell->level = level;
    // On alloue de la mémoire pour le tableau de pointeurs vers les cellules suivantes
    cell->next = (s_cell**)malloc(sizeof(s_cell) * (level + 1));
    // On initialise tous les pointeurs à NULL
    for (int i = 0; i <= level; i++) {
        cell->next[i] = NULL;
    }
    // On retourne la cellule créée
    return cell;
}


void insertSortedCell(l_list * list, int value, int level) {

    if (level > list->max_level || level < 0 ) {
        printf("Cant insert the cell.");
        return;
    }

    s_cell * cell = createCell(value, list->max_level);
    if (list->heads[0] == NULL || list->heads[0]->value > cell->value) {
        for (int i = 0; i <= level; i++) {
            cell->next[i] = list->heads[i];
            list->heads[i] = cell;
        }
    } else {
        for (int i = 0; i <= level; i++) {
            s_cell * ptr = list->heads[i];
            s_cell * previous = NULL;

            while (ptr != NULL && ptr->value < cell->value) {
                previous = ptr;
                ptr = ptr->next[i];
            }
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