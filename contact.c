#include "contact.h"

contact* create_contact(char* surname,char* name)
{
    contact* Contact=malloc(sizeof(contact));
    Contact->surname=surname;
    Contact->name=name;
    return Contact;
}


void insert_contactlist(l_list*list,contact Contact)
{
    if (list->heads[0]==NULL)
    {
        list->heads[0]==Contact.name;
    }
    else
    {
        // first insert at level 0 ordering and then if 2 or more = inserting at the number of same letter
    }
}