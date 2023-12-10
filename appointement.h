
#ifndef PROJET_DATASTRUCT_2_APPOINTEMENT_H
#define PROJET_DATASTRUCT_2_APPOINTEMENT_H
#include "set.h"
#include"string.h"
typedef struct{
    //date and time
    int day;
    int month;
    int year;
    int hour;
    int minute;
    //lenght of appointement
    int lhour;
    int lminute;
    char* purpose;


}appointement;

typedef struct a_cell {
    appointement appt;
    struct s_cell* next;
}a_cell;

typedef struct appt_list {
    a_cell* head;
} appt_list;

appt_list* create_apptlist();
appointement * createAppointment(int day, int month, int year, int hour, int minute, char* purpose);
void print_appointement(appointement* appt);

#endif //PROJET_DATASTRUCT_2_APPOINTEMENT_H
