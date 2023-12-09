#include "diary.h"

char *scanString(void) {
    char *string = calloc(100,sizeof(char));
    scanf("%s", string);
    return string;
}


CalendarNode *createCalendarNode(Contact contact) {
    CalendarNode *node = malloc(sizeof(CalendarNode));
    node->contact = contact;
    node->appointments = NULL;
    return node;
}

AppointmentNode *createAppointmentNode(Appointment appointment) {
    AppointmentNode *node = malloc(sizeof(AppointmentNode));
    node->appointment = appointment;
    node->next = NULL;
    return node;
}

Contact *createContact(char *surname, char *firstname) {
    Contact *contact = malloc(sizeof(Contact));
    contact->surname = surname;
    contact->firstname = firstname;
    return contact;
}
//we propose alist of contacts after the third letter of the name
//show the list of contacts after the third letter of the name and ask the user to choose one
Contact *searchContact(Contact **contactList, char *searchKey) {
    int i = 0;
    Contact *contact = NULL;
    while (contactList[i] != NULL) {
        if (strncmp(contactList[i]->firstname, searchKey, 3) == 0) {
            printf("%d. %s %s\n", i + 1, contactList[i]->firstname, contactList[i]->surname);
        }
        i++;
    }
    if (i == 0) {
        printf("No contact found.\n");
        return NULL;
    }
    printf("Choose a contact: ");
    int choice;
    scanf("%d", &choice);
    if (choice > i || choice < 1) {
        printf("Invalid choice.\n");
        return NULL;
    }
    contact = contactList[choice - 1];
    return contact;
}

void insertContact(CalendarNode ***diary, Contact contact) {
    int i = 0;
    while ((*diary)[i] != NULL) {
        i++;
    }
    (*diary)[i] = createCalendarNode(contact);
    (*diary)[i + 1] = NULL;
}