#include "set.h"

#ifndef PROJET_DATASTRUCT_2_CONTACT_H
#define PROJET_DATASTRUCT_2_CONTACT_H

typedef struct{
    char* surname;
    char* name;
}contact;

typedef struct c_cell{
    contact Contact;
    struct c_cell* next;
};
contact* create_contact(char* surname,char* name);
void insert_contactlist(l_list *list,contact Contact);
#endif //PROJET_DATASTRUCT_2_CONTACT_H
