
#ifndef PROJET_DATASTRUCT_2_CALENDAR_H
#define PROJET_DATASTRUCT_2_CALENDAR_H
#include "contact.h"
#include "appointement.h"
#include "set.h"
typedef struct{
    contact Contact;
    appt_list* listappt;
}calendar;

typedef struct{
    calendar cal;
    int level;
    struct c_cell** next;
}c_cell;

typedef struct c_level_list {
    c_cell** heads;
    int max_level;
} c_l_list;

c_cell * CreateCalendarCell(calendar* c, int level);
c_l_list* createcalendarllist();

calendar* create_calendarentry(contact Contact);
char* GetContactFromCalendar(calendar cal);
void insertcell(c_l_list* list,calendar* cal);
#endif //PROJET_DATASTRUCT_2_CALENDAR_H
