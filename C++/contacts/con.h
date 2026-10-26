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
void Add(LinkList L);
void Del(LinkList L);
void Search(LinkList L);
void Modify(LinkList L);
void Show(LinkList L);
void Sort(LinkList L);
void Destroy(LinkList *L);
