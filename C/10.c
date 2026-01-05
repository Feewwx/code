#include <stdio.h>//标准输入输出头文件
#include <stdlib.h>//标准库头文件
#include <windows.h>//Windows API 头文件，用于设置控制台编码

int main() // 主函数
    {
        SetConsoleOutputCP(CP_UTF8); // 设置控制台输出为 UTF-8 编码
        int score;// 定义变量存储分数
        printf("请输入分数 (0-100): ");// 提示用户输入分数
        if (scanf("%d", &score) != 1)// 输入验证 
            {
                printf("请输入有效的数字！\n");// 提示无效输入
                return 1;
            }

        if (score < 0 || score > 100) // 检查分数范围
            {
                printf("分数范围无效！\n");// 提示分数无效
                return 1;
            }

        // 核心技巧：除以 10，把 90-100 变成 9 和 10，把 80-89 变成 8
        switch (score / 10) // 使用 switch 语句根据分数段分类
            {
                case 10: // 100分
                case 9:  // 90-99分
                    printf("等级: A (根据题目逻辑, 85及以上为A)\n");
                    // 注意：如果题目严格要求85分界，switch 这里的逻辑会变复杂
                    // 通常教学中 90+ 为 A，但按照你图上的 85 为界，switch 并不是最佳工具
                    break;
                case 8:// 80-89分
                    if (score >= 85) printf("等级: A\n");// 85分及以上为A
                    else printf("等级: B\n");// 80-84分为B
                    break;
                case 7:// 70-79分
                    printf("等级: B\n");// 70-79分为B
                    break;
                case 6:// 60-69分
                    printf("等级: C\n");// 60-69分为C
                    break;
                default:// 0-59分
                    printf("等级: D\n");// 0-59分为D
                    break;
            }

    return 0;
}