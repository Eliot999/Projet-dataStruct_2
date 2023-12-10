#include "calendar.h"
calendar* create_calendarentry(contact Contact)
{
    calendar* calentry= malloc(sizeof(calendar));
    calentry->Contact=Contact;
    calentry->listappt=create_apptlist();
    return calentry;
}

char* GetContactFromCalendar(calendar cal){
    //return the name and surname of the contact of the calendar in the form name_surname
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
    //create a cell with the calendar
    c_cell * ccell =malloc(sizeof(s_cell));
    ccell->cal = *c;
    ccell->next = malloc(sizeof(s_cell));
    for (int i = 0; i < level; i++) {
        ccell->next[i] = NULL;
    }
    return ccell;
}

c_l_list* CreateCalendarllist()
{
    {
        //create a list of calendar cells
        c_l_list *list = malloc(sizeof(l_list));
        list->max_level = 4;
        list->heads =  calloc(4,sizeof(s_cell));
        for(int i = 0; i < list->max_level; i++){
            list->heads[i] = NULL;
        }
        return list;

    }
}
/*
void insertcell(c_l_list* list, calendar* cal) {
    char* s1 = GetContactFromCalendar(*cal);

    if (list->heads[0] == NULL) {
        c_cell* cell = CreateCalendarCell(cal, 3);
        for (int i = 0; i <= 3; i++) {
            list->heads[i] = cell;
        }
        return;
    }

    c_cell* current = list->heads[3];
    c_cell* prev = NULL;
    char* sh = GetContactFromCalendar(current->cal);

    if (strcmp(s1, sh) < 0) {
        c_cell* cell = CreateCalendarCell(cal, 3);
        for (int i = 3; i >= 0; i--) {
            cell->next = list->heads[i];
            list->heads[i] = cell;
        }
        return;
    }
    while (current != NULL) {
        char* s2 = GetContactFromCalendar(prev->cal);
        char* s3 = GetContactFromCalendar(current->cal);

        if (strcmp(s1, s2) > 0 && strcmp(s1, s3) < 0) {
            //if there are a previous contact with a first letter before in the alphabet and a one with a letter after then we can insert it
            c_cell* cell = CreateCalendarCell(cal, 3);
            prev->next = cell;
            cell->next = current;

            for (int i = 0; i <= 2; i++) {
                current = list->heads[i];
                prev = NULL;

                while (current != NULL) {
                    char* s2 = GetContactFromCalendar(prev->cal);
                    char* s3 = GetContactFromCalendar(current->cal);

                    if (strcmp(s1, s2) > 0 && strcmp(s1, s3) < 0) {
                        c_cell* cell = CreateCalendarCell(cal, 3);
                        prev->next = cell;
                        cell->next = current;
                    } else if (current->next == NULL && strcmp(s1, s3) > 0) {
                        c_cell* cell = CreateCalendarCell(cal, 3);
                        current->next = cell;
                    } else {
                        prev = current;
                        current = current->next;
                    }
                }
            }
        } else if (current->next == NULL && strcmp(s1, s3) > 0) {
            //case 2  if it's after every other cells and there isn't the letter
            c_cell* cell = CreateCalendarCell(cal, 3);
            current->next = cell;

            for (int i = 0; i <= 2; i++) {
                current = list->heads[i];
                prev = NULL;

                while (current != NULL) {
                    char* s2 = GetContactFromCalendar(prev->cal);
                    char* s3 = GetContactFromCalendar(current->cal);

                    if (strcmp(s1, s2) > 0 && strcmp(s1, s3) < 0) {
                        c_cell* cell = CreateCalendarCell(cal, 3);
                        prev->next = cell;
                        cell->next = current;
                    } else if (current->next == NULL && strcmp(s1, s3) > 0) {
                        c_cell* cell = CreateCalendarCell(cal, 3);
                        current->next = cell;
                    } else {
                        prev = current;
                        current = current->next;
                    }
                }
            }
        } else {
            prev = current;
            current = current->next;
        }
        prev=NULL;
        current=list->heads[0];
        while(current!=NULL)
        {
            // check if there are words with the same first letter and update the word with the same value as the input, inserting the other calendar at the level2 if not yet
            char* s3= GetContactFromCalendar(current->cal);
            if((strcmp(&s1[0],&s3[0])==0)&&(strcmp(&s1[1],&s3[1])!=0))
            {
                current=list->heads[2];
                prev=NULL;

            }
        }
    }
}

void displayCalendarList(c_l_list list)
{
    for (int i = 0; i < 4; i++) {
        printf("list_head_%d @-]-->", i);

        c_cell *cell = list.heads[i];
        while (cell != NULL) {
            printf("[%s_%s|@-]-->", cell->cal.Contact.name,cell->cal.Contact.surname);
            cell = cell->next[i];
        }

        printf("NULL\n");
    }
}

//first check if there is already the first letter in the level 3 linked list if not insert level 0 1 2 3
//second insert sorted level 0 1 2 all the contacts that have the same 1st letters but a different second
//third step insert sorted level 0 1 all of those having the first 2 letters in common but 3rd different
//fourth insert sorted level 0 all the cells*/


