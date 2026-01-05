#include <stdio.h>//标准输入输出头文件
#include <stdlib.h>//标准库头文件
#include <windows.h>
int max(int x, int y)//求较大值函数
{
    return x>y?x:y;//返回较大值
}

int main(void)//主函数
{
    SetConsoleOutputCP(CP_UTF8); 
    int a=0,b=0,c;//定义变量
    char buf[128];//输入缓冲区
    printf("请输入两个整数(两个数字间用空格隔开): ");//提示输入
    fflush(stdout);//确保提示信息立即输出
    if (fgets(buf, sizeof buf, stdin) == NULL)//读取一行输入
    {
        printf("读取输入失败\n");//读取失败
        system("pause");// windows 下保底暂停
        return 1;//退出程序
    }
    if (sscanf(buf, "%d %d", &a, &b) < 1)//解析输入的两个整数
    {
        printf("格式错误\n");//解析失败
        system("pause");// windows 下保底暂停
        return 1;//退出程序
    }
    c = max(a,b);//计算最大值
    printf("max=%d\n", c);//输出最大值
    system("pause"); // windows 下保底暂停
    return 0;//正常退出
}