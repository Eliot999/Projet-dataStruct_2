#include "set.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
    l_list * list = createEmptyList(5);
    //insertHead(list,5,4);
    //insertHead(list,2,3);
    insertSortedCell(list,1,2);
    insertSortedCell(list,2,4);
    insertSortedCell(list,6,3);
    //simpledisplayList(*list);
    //displayLevel(*list,0);
    classicsearch(list,6);
    l_list * list2 = createnlvllist(3);
    simpledisplayList(*list2);
    return 0;
}

