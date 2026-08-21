#include <stdio.h>
#include <string.h>

typedef struct PeoInfo {
    char name[20];
    int age;
    char sex[10];
    char tele[12];
    char addr[30];
} PeoInfo;

typedef struct Contact {
    PeoInfo data[100];
    int count;
} Contact;

void InitContact(Contact *p);
void Add(Contact *p);
void Del(Contact *p);
void Search(Contact *p);
void Modify(Contact *p);
void Show(Contact *p);
void Sort(Contact *p);
