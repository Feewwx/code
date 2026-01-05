#include<stdio.h>//标准输入输出头文件
int main()//主函数
{
    int max(int x, int y);//函数声明
    int a, b, c;//定义变量
    scanf("%d,%d", &a,&b);//输入两个整数
    c = max(a,b);//调用函数求最大值
    printf("max=%d\n", c);//输出最大值
    return 0;//正常退出
}
int max(int x,int y)//求较大值函数
{
    int z;//定义变量
    if (x>y)//比较大小
        z = x;//较大值赋给z
        else//否则
            z = y;//较大值赋给z
        return z;//返回较大值
}