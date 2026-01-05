#include<stdio.h>
#include <stdlib.h>//标准库头文件
#include <windows.h>
int main()
    {
        SetConsoleOutputCP(CP_UTF8); 
        int a[10];
        int i, j, t;
        printf("请输入10个整数：\n");
        for(i=0; i<10; i++)
        scanf("%d", &a[i]);
        for (j=0; j<10; j++)
            for (i = 0; i < 9-j; i++)
                if (a[i] > a[i+1])
                {
                    t=a[i];
                    a[i]=a[i+1];
                    a[i+1]=t;
                }
        for (i = 0; i < 10; i++)
            printf("%d ", a[i]);
        return 0;
    }