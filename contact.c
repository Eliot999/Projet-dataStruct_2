#include "contact.h"
#include <stdlib.h>
contact* create_contact(char* surname,char* name)
{
    contact* Contact=malloc(sizeof(contact));
    Contact->surname=surname;
    Contact->name=name;
    return Contact;
}