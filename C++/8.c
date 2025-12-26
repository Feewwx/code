#include <stdio.h>

int main() {
    char name[20];
    int score;

    printf("请输入学生姓名：");
    scanf("%s", name);

    printf("请输入学生成绩：");
    scanf("%d", &score);

    printf("\n--- 学生成绩信息 ---\n");
    printf("学生姓名：%s\n", name);
    printf("学生成绩：%d\n", score);

    if (score >= 60) {
        printf("成绩评价：及格\n");
    } else {
        printf("成绩评价：不及格\n");
    }

    return 0;
}
