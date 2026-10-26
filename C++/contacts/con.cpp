#include "con.h"

#include <cstring>

void InitContact(LinkList *L) {
    *L = new LNode;
    (*L)->next = NULL;
}

void Add(LinkList L) {
    LinkList p = L;
    LinkList q;
    while (p->next) {
        p = p->next;
    }
    q = new LNode;
    p->next = q;
    cout << "请输入姓名:";
    cin >> q->data.name;
    cout << "请输入年龄:";
    cin >> q->data.age;
    cout << "请输入性别:";
    cin >> q->data.sex;
    cout << "请输入电话:";
    cin >> q->data.tele;
    cout << "请输入地址:";
    cin >> q->data.addr;
    cout << "已存入通讯录" << endl;
    q->next = NULL;
}
void Del(LinkList L) {
    Show(L);
    cout << "请输入要删除的编号:";
    int input = 0;
    cin >> input;
    LinkList p = L;
    LinkList q;
    if (p->next == NULL) {
        return;
    }
    int count = 0;
    while (L->next) {
        L = L->next;
        count++;
    }
    if (input < 1 || input > count)
        return;
    for (int i = 0; i < input - 1; i++) {
        p = p->next;
    }
    q = p->next;
    p->next = q->next;
    delete q;
}
void Search(LinkList L) {
    cout << "请输入要查找的姓名:";
    char name[20];
    LinkList p = L->next;
    cin >> name;
    while (p) {
        if (strcmp(name, p->data.name) == 0) {
            cout << "姓名: " << p->data.name;
            cout << "年龄: " << p->data.age;
            cout << "性别: " << p->data.sex;
            cout << "电话: " << p->data.tele;
            cout << "地址: " << p->data.addr;
            return;
        }
        p = p->next;
    }
    cout << "查无此人";
}
void Modify(LinkList L) {
    Show(L);
    cout << "请输入要修改的编号:";
    int input = 0;
    cin >> input;
    LinkList p = L;
    if (p->next == NULL) {
        return;
    }
    int count = 0;
    while (L->next) {
        L = L->next;
        count++;
    }
    if (input < 1 || input > count)
        return;
    for (int i = 0; i < input; i++) {
        p = p->next;
    }
    cout << "请输入想要修改的内容:";
    char case1[20];
    cin >> case1;
    if (strcmp(case1, "姓名") == 0) {
        cout << "请输入新的姓名:";
        cin >> p->data.name;
    } else if (strcmp(case1, "年龄") == 0) {
        cout << "请输入新的年龄:";
        cin >> p->data.age;
    } else if (strcmp(case1, "性别") == 0) {
        cout << "请输入新的性别:";
        cin >> p->data.sex;
    } else if (strcmp(case1, "电话") == 0) {
        cout << "请输入新的电话:";
        cin >> p->data.tele;
    } else if (strcmp(case1, "地址") == 0) {
        cout << "请输入新的地址:";
        cin >> p->data.addr;
    } else {
        cout << "输入错误\n";
    }
}
void Show(LinkList L) {
    LinkList p;
    p = L->next;
    int count = 0;
    while (p) {
        count++;
        cout << "编号: " << count;
        cout << "姓名: " << p->data.name;
        cout << "年龄: " << p->data.age;
        cout << "性别: " << p->data.sex;
        cout << "电话: " << p->data.tele;
        cout << "地址: " << p->data.addr;
        p = p->next;
    }
}
void Sort(LinkList L) {
    int count = 0;
    LinkList p = L;
    while (p->next) {
        p = p->next;
        count++;
    }
    for (int i = 0; i < count; i++) {
        p = L->next;
        while (p->next) {
            if (strcmp(p->data.name, p->next->data.name) > 0) {
                PeoInfo temp = p->data;
                p->data = p->next->data;
                p->next->data = temp;
            }
            p = p->next;
        }
    }
}
void Destroy(LinkList *L) {

    LinkList p;
    while (*L) {
        p = *L;
        *L = (*L)->next;
        delete p;
    }
}
