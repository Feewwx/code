#include <iostream>

using namespace std;

typedef struct PeoInfo {
    char name[20];
    int age;
    char sex[10];
    char tele[12];
    char addr[30];
} PeoInfo;

typedef struct LNode {
    PeoInfo data;
    LNode *next;
} LNode, *LinkList;

void InitContact(LinkList *L);
void Add(LNode *L);
void Del(LNode *p);
void Search(LNode *p);
void Modify(LNode *p);
void Show(LNode *p);
void Sort(LNode *p);
void Destroy(LNode *p);
