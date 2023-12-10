#include "appointement.h"
#include "stdio.h"
#include "stdlib.h"

appt_list* create_apptlist()
{
    appt_list* list= malloc(sizeof(appt_list));
    list->head=NULL;
    return list;
}

int DateTest(int year, int month, int day){
    if (year<0)
    {
        return 0;
    }
    if (month<1 || month>12)
    {
        return 0;
    }
    if (day<1){
        return 0;
    }
    if (month==2)
    {
        //bisextile years in february
        if (year % 4 == 0)
        {
            if (day>29)
            {
                return 0;
            }
        } else
        {
            if (day > 28)
            {
                return 0;
            }
        }
    } else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        if (day > 30)
        {
            return 0;
        }
    } else {
        if (day > 31)
        {
            return 0;
        }
    }
    return 1;
}

int LenghtTest(int lhour, int lminute){
    if (lhour>23 || lhour<0){
        return 0;
    }
    if (lminute >59 || lminute <0){
        return 0;
    }
    return 1;
}

appointement * createAppointment(int day, int month, int year, int hour, int minute, char* purpose)
{
    if (DateTest(year, month, day) == 0 || LenghtTest(hour, minute) == 0)printf("impossible parameters");
    appointement *appt = malloc(sizeof(appointement));
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
