#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define MAX 100
#define NUM_COURSES 3

struct Student {
    char id[20];
    char name[50];
    char gender[10];
    int age;
    char className[20];
    float scores[NUM_COURSES];
};

struct Student students[MAX];
int count = 0;

void addStudent() {
    if (count >= MAX) {
        printf("学生数量已满！\n");
        return;
    }
    printf("请输入学号、姓名、性别、年龄、班级、3门课成绩：\n");
    scanf("%s %s %s %d %s %f %f %f", 
          students[count].id, students[count].name, students[count].gender,
          &students[count].age, students[count].className,
          &students[count].scores[0], &students[count].scores[1], &students[count].scores[2]);
    count++;
    printf("录入成功！\n");
}

void queryStudent() {
    char id[20];
    printf("请输入学号：");
    scanf("%s", id);
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("学号：%s 姓名：%s 性别：%s 年龄：%d 班级：%s 成绩：%.1f %.1f %.1f\n",
                   students[i].id, students[i].name, students[i].gender, students[i].age,
                   students[i].className, students[i].scores[0], students[i].scores[1], students[i].scores[2]);
            return;
        }
    }
    printf("未找到该学生！\n");
}

void modifyStudent() {
    char id[20];
    printf("请输入要修改的学号：");
    scanf("%s", id);
    int i;
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("请输入新的姓名、性别、年龄、班级、3门课成绩：\n");
            scanf("%s %s %d %s %f %f %f", 
                  students[i].name, students[i].gender, &students[i].age,
                  students[i].className, &students[i].scores[0], 
                  &students[i].scores[1], &students[i].scores[2]);
            printf("确认修改？(y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y') {
                printf("修改成功！\n");
            }
            return;
        }
    }
    printf("未找到该学生！\n");
}

void deleteStudent() {
    char id[20];
    printf("请输入要删除的学号：");
    scanf("%s", id);
    int i, j;
    for (i = 0; i < count; i++) {
        if (strcmp(students[i].id, id) == 0) {
            printf("确认删除？(y/n): ");
            char confirm;
            scanf(" %c", &confirm);
            if (confirm == 'y') {
                for (j = i; j < count - 1; j++) {
                    students[j] = students[j + 1];
                }
                count--;
                printf("删除成功！\n");
            }
            return;
        }
    }
    printf("未找到该学生！\n");
}

void statistics() {
    char className[20];
    printf("请输入班级（输入all表示全年级）：");
    scanf("%s", className);
    int i, j, n = 0;
    float sum[NUM_COURSES] = {0}, max[NUM_COURSES] = {0}, min[NUM_COURSES] = {100, 100, 100};
    for (i = 0; i < count; i++) {
        if (strcmp(className, "all") == 0 || strcmp(students[i].className, className) == 0) {
            n++;
            for (j = 0; j < NUM_COURSES; j++) {
                sum[j] += students[i].scores[j];
                if (students[i].scores[j] > max[j]) max[j] = students[i].scores[j];
                if (students[i].scores[j] < min[j]) min[j] = students[i].scores[j];
            }
        }
    }
    if (n == 0) {
        printf("没有找到学生！\n");
        return;
    }
    printf("统计结果（共%d人）：\n", n);
    for (j = 0; j < NUM_COURSES; j++) {
        printf("第%d门课 - 平均分：%.1f 最高分：%.1f 最低分：%.1f\n",
               j + 1, sum[j] / n, max[j], min[j]);
    }
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    int choice;
    while (1) {
        printf("\n=== 学生成绩管理系统 ===\n");
        printf("1. 信息录入  2. 查询  3. 修改  4. 删除  5. 统计分析  0. 退出\n");
        printf("请选择：");
        scanf("%d", &choice);
        if (choice == 0) break;
        if (choice == 1) addStudent();
        else if (choice == 2) queryStudent();
        else if (choice == 3) modifyStudent();
        else if (choice == 4) deleteStudent();
        else if (choice == 5) statistics();
        else printf("无效选择！\n");
    }
    return 0;
}
