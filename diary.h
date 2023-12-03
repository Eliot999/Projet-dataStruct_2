#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *surname;
    char *firstname;
} Contact;

typedef struct {
    int day;
    int month;
    int year;
    int start_hour;
    int start_minute;
    int duration_hour;
    int duration_minute;
    char *purpose;
} Appointment;

typedef struct AppointmentNode {
    Appointment appointment;
    struct AppointmentNode *next;
} AppointmentNode;

typedef struct {
    Contact contact;
    AppointmentNode *appointments;
} CalendarNode;


char *scanString(void);
void insertContact(CalendarNode ***diary, Contact contact);
void insertAppointment(CalendarNode ***diary, char *searchKey, Appointment appointment);
//search for a contact in a contact list using the name the list is a list of pointers to contacts
Contact *searchContact(Contact **contactList, char *searchKey);
void viewAppointments(CalendarNode *entry);
void deleteAppointment(CalendarNode **diary, char *searchKey, int appointmentIndex);
void saveAppointmentsToFile(CalendarNode **diary);
void loadAppointmentsFromFile(CalendarNode ***diary);
void calculateInsertionTime(CalendarNode **diary);