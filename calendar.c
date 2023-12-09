#include "calendar.h"
calendar* create_calendarentry(contact Contact)
{
    calendar* calentry= malloc(sizeof(calendar));
    calentry->Contact=Contact;
    calentry->listappt=create_apptlist();
}

