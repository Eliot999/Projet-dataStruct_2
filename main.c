#include "set.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
    //l_list * list = createEmptyList(5);
    //insertHead(list,5,4);
    //insertHead(list,2,3);
    //insertSortedCell(list,1,2);
    //insertSortedCell(list,2,4);
    //insertSortedCell(list,6,3);
    //simpledisplayList(*list);
    //displayLevel(*list,0);
    //classicsearch(list,6);
    int n=14;
    l_list * list2 = createnlvllist(n);
    startTimer();
    for (int i=0;i<=10000;i++) {
        int x = generaterandom(1,(pow(2,n)-1));
        //classicsearch(list2, x);
        advancedsearch(list2, x);
    }
    stopTimer();
    displayTime();
    //simpledisplayList(*list2);

    //for(int i=0;i<64;i++){advancedsearch(list2,i);}
    return 0;
}