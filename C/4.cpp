#include <stdio.h>//标准输入输出头文件
int main()//主函数
{
    int h, f, x, y;//定义变量
    h = 16;//赋值
    f = 40;//赋值
    y = (f - 2 * h) / 2;// 计算y
    x = h - y;// 计算x
    printf("%d %d\n", x, y);//输出结果
    return 0;
}