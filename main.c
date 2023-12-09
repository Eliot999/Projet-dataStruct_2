#include "set.h"
#include "diary.h"
#include <stdlib.h>
#include <stdio.h>
int main(){
    /*
    l_list * list = createEmptyList(5);
    l_list *list2= createEmptyList(5);
    insertSortedCell(list2,5,3);
    insertSortedCell(list2,5,3);
    insertSortedCell(list2,4,3);
    insertSortedCell(list2,6,3);
    //insertHead(list,5,4);
    //insertHead(list,2,3);
    //insertSortedCell(list,1,2);
    //insertSortedCell(list,2,4);
    //insertSortedCell(list,6,3);
    simpledisplayList(*list2);

    //displayLevel(*list,0);
    //classicsearch(list,6);
    //simpledisplayList(*list2);
    */

    //PART 2


    FILE *log_file = fopen("log.txt", "w");
    if (log_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char format[] = "%d\t%s\t%s\n";
    int level;
    char *time_lvl0;
    char *time_all_levels;

    for (level = 7; level <= 16; level++) {
        l_list *list2 = createnlvllist(level);
        startTimer();
        for (int i = 0; i <= 10000; i++) {
            int x = generaterandom(1, (pow(2, level) - 1));
            classicsearch(list2, x);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        startTimer();
        for (int i = 0; i <= 10000; i++) {
            int x = generaterandom(1, (pow(2, level) - 1));
            advancedsearch(*list2, x);
        }
        stopTimer();
        time_all_levels = getTimeAsString();

        printf("\n%d level level list:\n-classic linked list search: %s s\n-optimised level search: %s s",
               level, time_lvl0, time_all_levels);

        fprintf(log_file, format, level, time_lvl0, time_all_levels);
        fflush(log_file); // Flush the buffer after writing to the file
    }

    fclose(log_file);
    return 0;
}