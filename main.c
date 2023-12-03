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

    //simpledisplayList(*list2);
    FILE *log_file = fopen("log.txt", "w");
    char format[] = "%d\t%s\t%s\n" ;
    int level;
    char *time_lvl0;
    char *time_all_levels;
    for (level=7;level<=16;level++){
        l_list * list2 = createnlvllist(level);
        startTimer();
        for (int i=0;i<=10000;i++) {
            int x = generaterandom(1,(pow(2,level)-1));
            classicsearch(list2, x);
        }
        stopTimer();
        time_lvl0=getTimeAsString();
        startTimer();
        for (int i=0;i<=10000;i++) {
            int x = generaterandom(1,(pow(2,level)-1));

            advancedsearch(*list2, x);
        }
        stopTimer();
        time_all_levels=getTimeAsString();
        printf("classic linked list search: %s\nlevel search: %s",time_lvl0,time_all_levels);
        fprintf(log_file,format,level,time_lvl0, time_all_levels);
        fclose(log_file);}
    return 0;
}