#include "cell.h"
#include "list.h"
#include "set.h"
#include <stdlib.h>
#include <stdio.h>
void simpledisplayList(l_list list) {


    for (int i = 0; i <= list.max_level; i++) {
        printf("list_head_%d @-]-->", i);
        s_cell *cell = list.heads[i];
        while (cell!= NULL) {
            printf("[%d|@-]-->", cell->value);
            cell = cell->next[i];
        }
        printf("NULL\n");
    }
}

int main(){
    l_list * list = createEmptyList(5);
    for(int i = 0; i < 5; i++){
        insertSortedCell(list, i, i);
    }
    simpledisplayList(*list);
    return 0;
}



// Add a new element to the level_list
