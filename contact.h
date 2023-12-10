
#include "string.h"
#include "ctype.h"

#ifndef PROJET_DATASTRUCT_2_CONTACT_H
#define PROJET_DATASTRUCT_2_CONTACT_H

typedef struct{
    char* surname;
    char* name;
}contact;

contact* create_contact(char* surname,char* name);
#endif //PROJET_DATASTRUCT_2_CONTACT_H
