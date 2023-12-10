#include "calendar.h"
#include "string.h"
#include "ctype.h"
calendar* create_calendarentry(contact Contact)
{
    calendar* calentry= malloc(sizeof(calendar));
    calentry->Contact=Contact;
    calentry->listappt=create_apptlist();
    return calentry;
}

char* GetContactFromCalendar(calendar cal){
    char* name_surname = malloc((strlen(cal.Contact.name)+ strlen(cal.Contact.surname)+2) * sizeof(char));
    for (int i = 0; i < strlen(cal.Contact.surname); i++)
    {
        name_surname[i] = tolower(cal.Contact.surname[i]);
    }
    // uses ctype to lower to avoid confusion between UPPERCASE and lowercase letters.
    strcat(name_surname,"_");
    for (int i=0;i< strlen(cal.Contact.name);i++)
    {
        name_surname[i] = tolower(cal.Contact.name[i]);
    }
    return name_surname;
}

c_cell * CreateCalendarCell(calendar* c, int level){
    c_cell * ccell = (s_cell *) malloc(sizeof(s_cell));
    ccell->cal = c;
    ccell->next = (s_cell **) calloc(level,sizeof(s_cell));
    for (int i = 0; i < level; i++) {
        ccell->next[i] = NULL;
    }
    return ccell;
}

c_l_list* CreateCalendarllist()
{
    {
        c_l_list *list = malloc(sizeof(l_list));
        list->max_level = 4;
        list->heads =  calloc(4,sizeof(s_cell));
        for(int i = 0; i < list->max_level; i++){
            list->heads[i] = NULL;
        }
        return list;

    }
}

void insertcell(c_l_list* list,calendar* cal)
{
    c_cell* current=list->heads[0];
    c_cell* prev=NULL;
    char* s1= GetContactFromCalendar(*cal);
    if (list->heads[0]==NULL)
    {
        c_cell* cell=CreateCalendarCell(cal,3);
        for(int i=0;i<=3;i++)
        {
            list->heads[i]=cell;
        }
    }
    else
    {
        current=list->heads[3];

        //first check if there is already the first letter in the level 3 if not insert level 0 1 2 3
        //second insert sorted level 0 1 2 all the contacts that have the same 1st letters but a different second
        //third step insert sorted level 0 1 all of those having the first 2 letters in common but 3rd different
        //fourth insert sorted level 0 all the cells



    }
}
