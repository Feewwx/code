#include <stdio.h>
#include <stdlib.h>//标准库头文件
#include <windows.h>
int main()
{
    SetConsoleOutputCP(CP_UTF8); 
    char dengji;
    scanf("%c", &dengji);
    switch (dengji)
    {
        case 'A':
            printf("该生分数为85~100\n");
            break;
        case 'B':
            printf("该生分数为70~84\n");
            break;
        case 'C':
            printf("该生分数为60~69\n");
            break;
        case 'D':
            printf("该生分数为0~59\n");
            break;
        case 'F':
            printf("不及格\n");
            break;
        default:
            printf("输入有误\n");
            break;
    }
    return 0;
}