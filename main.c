#include "set.h"
#include "diary.h"
#include <stdlib.h>
#include <stdio.h>
#include "calendar.h"
/*
int printMenuAndGetChoice() {
    int choice;

    printf("Diary Management System\n");
    printf("=======================\n");
    printf("1. Search for a contact\n");
    printf("2. View a contact's appointments\n");
    printf("3. Create a new contact\n");
    printf("4. Create a new appointment\n");
    printf("5. Delete an appointment\n");
    printf("6. Save appointments to file\n");
    printf("7. Load appointments from file\n");
    printf("8. Trace complexity of operations\n");
    printf("9. Exit\n");
    printf("Please enter your choice: ");

    //using the scanstin function to get the choice
    char * input = scanString();
    choice = atoi(input);
    free(input);


    return choice; // Return the user's choice for further processing
}




int validateSearchContactInput(char* input) {
    // Validate the search input for contact (e.g., non-empty, valid characters).
     if (input == NULL) {
        printf("Invalid input.\n");
        return 0;
     }


}
int validateViewAppointmentsInput(char* contactName) {
    // Validate the input for viewing appointments (e.g., contact exists).
    if (contactName == NULL) {
        printf("Invalid input.\n");
        return 0;
    }
}
int validateCreateContactInput(char* surname, char* firstname) {
    // Validate inputs for creating a new contact (e.g., non-empty, unique name).
    if (surname == NULL || firstname == NULL) {
        printf("Invalid input.\n");
        return 0;
    }
}
int validateCreateAppointmentInput(Appointment appointment) {
    // Validate the details of the new appointment (e.g., valid date and time).
    if (appointment.day < 1 || appointment.day > 31) {
        printf("Invalid day.\n");
        return 0;
    }
}
int validateDeleteAppointmentInput(char* contactName, Appointment appointment) {
    // Validate input for deleting an appointment (e.g., appointment exists for contact).
    if (contactName == NULL) {
        printf("Invalid input.\n");
        return 0;
    }
}
int validateSaveAppointmentsInput(char* filename) {
    // Validate the filename for saving appointments (e.g., valid file path).
    if (filename == NULL) {
        printf("Invalid input.\n");
        return 0;
    }
}

int validateLoadAppointmentsInput(char* filename) {
    // Validate the filename for loading appointments (e.g., file exists).
    if (filename == NULL) {
        printf("Invalid input.\n");
        return 0;
    }
}


*/
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


    //PART 2

    */
    FILE *log_file = fopen("log.txt", "w");
    if (log_file == NULL) {
        printf("Error opening file!\n");
        return 1;
    }

    char format[] = "%d\t%s\t%s\n";
    int level;
    char *time_lvl0;
    char *time_all_levels;

    for (level = 7; level <= 15; level++) {
        l_list *list2 = createnlvllist(level);
        startTimer();
        for (int i = 0; i <= 100000; i++) {
            int x = generaterandom(1, (pow(2, level) - 1));
            classicsearch(list2, x);
        }
        stopTimer();
        time_lvl0 = getTimeAsString();
        startTimer();
        for (int i = 0; i <= 100000; i++) {
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
    /*
    char* s1=scanString();
    char* s2=scanString();
    contact* ctcte= create_contact(s1,s2);
    calendar* cal= create_calendarentry(*ctcte);

    */
    return 0;
}