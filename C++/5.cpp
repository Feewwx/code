#include <stdio.h>//标准输入输出头文件
#include <math.h>//数学函数头文件
int main()//主函数
{
    int d, p;//定义变量
    float r, m;//定义变量
    d = 324500;//赋值
    p = 3245;//赋值
    r = 0.008;//赋值
    m = (log10(p) - log10(p - d * r)) / (log10(1 + r));//计算月数
    printf("month=%f\n", m);//输出月数
    printf("total=%f\n", m * p);//输出总还款额
    return 0;//正常退出
}