#include "con.h"

void InitContact(Contact *p) {
    p->count = 0;
    memset(p->data, 0, sizeof(p->data));
}

void Add(Contact *p) {
    if (p->count == 100) {
        printf("通讯录已满,无法存入\n");
        return;
    }
    printf("请输入姓名:");
    scanf("%s", p->data[p->count].name);
    printf("请输入年龄:");
    scanf("%d", &(p->data[p->count].age));
    printf("请输入性别:");
    scanf("%s", p->data[p->count].sex);
    printf("请输入电话:");
    scanf("%s", p->data[p->count].tele);
    printf("请输入地址:");
    scanf("%s", p->data[p->count].addr);
    p->count++;
    printf("已存入通讯录\n");
}

void Del(Contact *p) {
    if (p->count == 0) {
        printf("通讯录为空,无法删除\n");
        return;
    }
    Show(p);
    printf("请输入要删除的编号:");
    int input = 0;
    scanf("%d", &input);
    if (input > p->count || input <= 0) {
        printf("请输入正确的编号\n");
        return;
    }
    int pos = input - 1;
    for (int i = pos; i < p->count - 1; i++) {
        p->data[i] = p->data[i + 1];
    }
    p->count--;
    printf("已删除通讯录\n");
}

void Search(Contact *p) {
    if (p->count == 0) {
        printf("通讯录为空,无法查找\n");
        return;
    }
    printf("请输入要查找的姓名:");
    char name[20];
    scanf("%s", name);
    for (int i = 0; i < p->count; i++) {
        if (strcmp(p->data[i].name, name) == 0) {
            printf("查找到姓名为:%s的通讯录\n", name);
            printf("年龄:%d\n", p->data[i].age);
            printf("性别:%s\n", p->data[i].sex);
            printf("电话:%s\n", p->data[i].tele);
            printf("地址:%s\n", p->data[i].addr);
            return;
        }
    }
    printf("查无此人\n");
}

void Modify(Contact *p) {
    if (p->count == 0) {
        printf("通讯录为空,无法修改\n");
        return;
    }
    Show(p);
    printf("请输入要修改的编号:");
    int input = 0;
    scanf("%d", &input);
    if (input > p->count || input <= 0) {
        printf("请输入正确的编号\n");
        return;
    }
    printf("请输入想要修改的内容:");
    char case1[20];
    scanf("%s", case1);
    if (strcmp(case1, "姓名") == 0) {
        printf("请输入新的姓名:");
        scanf("%s", p->data[input - 1].name);
    } else if (strcmp(case1, "年龄") == 0) {
        printf("请输入新的年龄:");
        scanf("%d", &(p->data[input - 1].age));
    } else if (strcmp(case1, "性别") == 0) {
        printf("请输入新的性别:");
        scanf("%s", p->data[input - 1].sex);
    } else if (strcmp(case1, "电话") == 0) {
        printf("请输入新的电话:");
        scanf("%s", p->data[input - 1].tele);
    } else if (strcmp(case1, "地址") == 0) {
        printf("请输入新的地址:");
        scanf("%s", p->data[input - 1].addr);
    } else {
        printf("输入错误\n");
    }
}

void Show(Contact *p) {
    for (int i = 0; i < p->count; i++) {
        printf("编号:%d\n", i + 1);
        printf("姓名:%s\n", p->data[i].name);
        printf("年龄:%d\n", p->data[i].age);
        printf("性别:%s\n", p->data[i].sex);
        printf("电话:%s\n", p->data[i].tele);
        printf("地址:%s\n", p->data[i].addr);
        printf("\n");
    }
}

void Sort(Contact *p) {
    if (p->count < 2) {
        printf("人数不足，无需排序\n");
        return;
    }
    for (int i = 0; i < p->count - 1; i++) {
        for (int j = 0; j < p->count - 1 - i; j++) {
            if (strcmp(p->data[j].name, p->data[j + 1].name) > 0) {
                PeoInfo temp = p->data[j]; // 类型修正为 PeoInfo
                p->data[j] = p->data[j + 1];
                p->data[j + 1] = temp;
            }
        }
    }
    printf("已成功按姓名完成排序！\n");
}
