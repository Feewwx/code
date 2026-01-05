#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    float score;
    char name[50];
    while (1) {
        printf("请输入学生姓名：");
        scanf("%s", name);
        printf("请输入成绩 (0-100): ");

        if (scanf("%f", &score) != 1) { 
            printf("【系统报错】输入非法！请输入纯数字。\n");

            while (getchar() != '\n'); 
            
            continue; // 重新开始循环
        }

        if (score >= 0 && score <= 100) {
            break; // 输入正确，退出循环
        } else {
            printf("【范围错误】分数必须在 0-100 之间！\n");
        }
    }

    printf("录入成功!学生 %s 的成绩为：%.1f\n", name, score);
    return 0;
}
