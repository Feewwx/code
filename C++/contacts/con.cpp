#include "con.h"

void InitContact(LinkList *L) {
    *L = new LNode;
    (*L)->next = NULL;
}
