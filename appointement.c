#include "appointement.h"


appt_list* create_apptlist()
{
    appt_list* list= malloc(sizeof(appt_list));
    list->head=NULL;
    return list;
}

appointement * createAppointment(int day, int month, int year, int hour, int minute, char* purpose) {
    appointement* appt = malloc(sizeof(appointement));
    appt->day = day;
    appt->month = month;
    appt->year = year;
    appt->lhour = hour;
    appt->lminute = minute;
    appt->purpose = malloc(sizeof(char) * (strlen(purpose) + 1));
    strcpy(appt->purpose, purpose);
    return appt;
}
void print_appointement(appointement* appt)
{
    printf("date:%d/%d/%d\nlenght of the appointement:%d:%d\npurpose:/s",appt->day, appt->month,appt->lhour,appt->lminute,appt->purpose);
}