//1.初识C语言
    //1.认识C语言
    //C语言代码中一定要有main函数
    //主函数

    //printf是一个库函数
    //专门用来打印输出的

    //std-标准
    //i-input
    //o-output
    //2.第一个C语言项目
    #include <stdio.h>
    #include <string.h>//包含字符串操作相关的函数的头文件

    //标准的主函数的写法
        //void main()-古老的写法
    int main()
    //C语言规定
        //main函数是程序的入口
        //main函数有且只有一个

    {
        /* printf("Hello, World!\n"); */

    //3.数据类型
        //char-字符数据类型-1个字节              计算机中的单位：
        //short-短整型-2个字节                   bit-比特位
        //int-整形-4个字节                       byte-字节-8个比特位
        //long-长整型-4个字节                    kb-千字节-1024字节
        //long long-更长的整型-8个字节            mb-兆字节-1024千字节
        //float-单精度浮点型-4个字节              gb-吉字节-1024兆字节
        //double-双精度浮点型-8个字节             tb-太字节-1024吉字节
        //例如：66.6-小数-浮点型  666-整数-整型   pb-拍字节-1024太字节
        //sizeof(long)>=sizeof(int)
    
        /* 
        int age = 20;
        double price = 66.6;
        printf("age = %d, price = %.1f\n", age, price); */

        //输出格式控制符:
            //%d-十进制整数
            //%c-字符
            //%f-浮点数-float
            //%lf-双精度浮点数-double
            //%s-字符串
            //%.1f-表示小数点后保留1位
            //%zu-size_t类型的无符号整数

    //4.变量和常量:局部变量和全局变量
        //变量分为两种：局部变量和全局变量
            //局部变量-{}内部定义的变量
            //全局变量-{}外部定义的变量
    
        /* 
        short age = 20;//年龄
        int height = 180;//身高
        float weight = 88.5;//体重 */

        /* 
        int a = 10;
        {
            int a = 20;
            printf("a = %d\n", a);//当全局变量和局部变量重名时，优先使用局部变量
        } */
        //但是建议不要将全局变量和局部变量的名字写成一样的，避免混淆
    
        //写一个代码，计算两个整数的和
            //scanf  是一个输入函数
            //printf 是一个输出函数
            /* 
            int num1 = 0;
            int num2 = 0;//初始化
            scanf("%d %d", &num1, &num2);//输入2个整数//取地址符&
            int sum = num1 + num2;//求和
            printf("%d\n", sum);//输出 */

    //5.变量的作用域和生命周期
        //作用域：局部变量的作用域是变量所在的局部范围
            //全局变量的作用域是整个源文件
        //生命周期：局部变量：进入作用域生命周期开始，出作用域生命周期结束
            //全局变量：整个程序的生命周期    

    //6.常量
        //1.字面常量
            //整数常量：10、20、-30
            //浮点数常量：3.14、66.6、-0.88
            //字符常量：'a'、'b'、'1'、'*'
            //字符串常量："hello"、"bit"
        //2.const修饰的常变量
            /* 
            const int a=10;
            a=20;//错误，常量不可修改*/
            //在C语言中，const修饰的a，本质上是变量，但是不能直接修改，有常量的属性
        //3.define定义的标识符常量
            //预处理指令#define
            //格式：#define 标识符 常量值
            /* 
            #define MAX 100
            #define STR "hello"
            printf("%d\n", MAX);
            int a = MAX;
            printf("%d\n", a);
            printf("%s\n", STR);
            MAX = 200;//错误，标识符常量不可修改 */
        //4.枚举常量
            /* 
            enum Color {RED, GREEN, BLUE};
            int num = 10;//定义整型变量num，并初始化为10
            enum Color c = RED;//定义枚举变量c，并初始化为RED
            printf("num = %d, c = %d\n", num, c);//枚举常量本质上是整型常量，RED的值为0，GREEN的值为1，BLUE的值为2
            RED = 100;//错误，枚举常量不可修改 */

    //7.字符串
        //'a'是字符
            /* char ch = 'a'; */
        //"abc"是字符串
            /* 
            char arr1[4] = "abc";//字符串以'\0'结尾但默认隐藏所以【n+1】
            char arr2[] = "abc";//自动计算数组大小为4
            char arr3[3] = {'a', 'b', 'c'};//没有'\0'结尾
            printf("%s\n", arr1);
            printf("%s\n", arr2);
            printf("%s\n", arr3);//未以'\0'结尾，可能打印出乱码
            char arr4[4] = {'a', 'b', 'c', '\0'};//手动添加'\0'结尾
            printf("%s\n", arr4);//正确打印abc
            //字符串结束的标志是'\0'
            printf("%d\n", strlen(arr1));//strlen计算字符串长度，不包括'\0' */
         
    //8.转义字符  
        /* 
        printf("Hello, World!\n");//\n换行
        printf("Hello, World!\t\n");//\t水平制表符（tab键）
        printf("Hello, \"World\"!\n");//\"打印双引号
        printf("Hello, \\World\\!\n");//\\打印反斜杠
        printf("Hello\0,World");//\0字符串结束标志，后面的内容不打印 */
        // 所有的转义字符：\? \' \" \\ \a \b \f \n \r \t \v \0 \ddd \xdd

    //9.注释
        //单行注释
        /* 
        多行注释
        */

    //10.选择语句和循环语句
        //选择语句:if语句、switch语句

            /* int input=0;
            printf("进入大学\n");
            printf("要好好学习吗？(1-是 0-否)：");
            scanf("%d", &input);
            if (input ==1)
            {
                printf("好offer\n");
            }
            else
            {
                printf("卖红薯\n");
            } */
    
            // 循环语句:while语句、do-while语句、for语句

            /*  int line = 0;
            printf("进入大学\n");
            while (line<20)
            {
                printf("写代码:%d\n", line);
                line++;
            }
            if (line >=20)
            {
                printf("好offer\n");
            }
            else
            {
                printf("继续加油\n");
            } */
    
    //11.函数       

        return 0;
}