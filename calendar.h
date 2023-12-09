
#ifndef PROJET_DATASTRUCT_2_CALENDAR_H
#define PROJET_DATASTRUCT_2_CALENDAR_H
#include "contact.h"
#include "appointement.h"
#include "set.h"
typedef struct{
    contact Contact;
    appt_list* listappt;
}calendar;

calendar* create_calendarentry(contact Contact);
#endif //PROJET_DATASTRUCT_2_CALENDAR_H
