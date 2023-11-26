#include "cell.h"
#include "list.h"
#include "set.h"
#include <stdlib.h>



int main(){
    l_list * list = createEmptyList(5);
    for(int i = 0; i < 5; i++){
        s_cell *cell = createCell(i,i);
        insertCell(list,cell);
    }
    return 0;
}


void displayList(l_list list){

}

// Add a new element to the level_list
