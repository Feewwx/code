// P1042 [NOIP 2003 普及组] 乒乓球

// #include <iostream>
//
// using namespace std;
//
// void output11(int b, int c, int count, char arr[]) {
//     int d = 0;
//     do {
//         if (arr[d] == 'W')
//             b++;
//         if (arr[d] == 'L')
//             c++;
//         if ((b >= 11 || c >= 11) && (b - c >= 2 || c - b >= 2)) {
//             cout << b << ":" << c << endl;
//             b = 0;
//             c = 0;
//         }
//         d++;
//     } while (d < count);
//     // 收尾:所有字符走完了,手里这局不管打到几比几(哪怕 0:0)都要打一次。
//     // 这里不需要判断 —— 要判断的是"一局结束没",那是循环里那行的事。
//     cout << b << ":" << c << endl;
// }
//
// void output21(int b, int c, int count, char arr[]) {
//     int d = 0;
//     do {
//         if (arr[d] == 'W')
//             b++;
//         if (arr[d] == 'L')
//             c++;
//         if ((b >= 21 || c >= 21) && (b - c >= 2 || c - b >= 2)) {
//             cout << b << ":" << c << endl;
//             b = 0;
//             c = 0;
//         }
//         d++;
//     } while (d < count);
//     cout << b << ":" << c << endl;
// }
//
// int main() {
//     char a = 0; // 输入
//     char arr[70000] = {0};
//     int count = 0;
//     int b = 0; // W的数量
//     int c = 0; // L的数量
//
//     // 输入
//     do {
//         cin >> a;
//         arr[count] = a;
//         count++;
//     } while (a != 'E');
//
//     output11(b, c, count, arr);
//     cout << endl; // 两段之间的空行
//     output21(b, c, count, arr);
//     return 0;
// }

// P2670 [NOIP 2015 普及组] 扫雷游戏

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int x = 0; // 行数
//     int y = 0; // 列数
//     cin >> x >> y;
//     char arr[102][102] = {0};  // 输入的雷区
//     char arr2[102][102] = {0}; // 输出的雷区
//
//     for (int i = 1; i <= x; i++) {
//         for (int j = 1; j <= y; j++) {
//             arr2[i][j] = 48;
//         }
//     }
//
//     for (int i = 1; i <= x; i++) {
//         for (int j = 1; j <= y; j++) {
//             cin >> arr[i][j];
//         }
//     }
//
//     for (int i = 1; i <= x; i++) {
//         for (int j = 1; j <= y; j++) {
//             if (arr[i][j] == '*') {
//                 arr2[i][j] = '*';
//                 if (arr2[i - 1][j - 1] != '*')
//                     arr2[i - 1][j - 1]++;
//                 if (arr2[i - 1][j] != '*')
//                     arr2[i - 1][j]++;
//                 if (arr2[i - 1][j + 1] != '*')
//                     arr2[i][j - 1]++;
//                 if (arr2[i][j + 1] != '*')
//                     arr2[i][j + 1]++;
//                 if (arr2[i + 1][j - 1] != '*')
//                     arr2[i + 1][j - 1]++;
//                 if (arr2[i + 1][j] != '*')
//                     arr2[i + 1][j]++;
//                 if (arr2[i + 1][j + 1] != '*')
//                     arr2[i + 1][j + 1]++;
//             }
//         }
//     }
//
//     for (int i = 1; i <= x; i++) {
//         for (int j = 1; j <= y; j++) {
//             cout << arr2[i][j];
//         }
//         cout << endl;
//     }
//     return 0;
// }

// P1563 [NOIP 2016 提高组] 玩具谜题

#include <iostream>

using namespace std;

int main() {
    int n = 0; // 小人的数量  0内1外
    int m = 0; // 指令的条数字

    int c = 0; // 编号

    cin >> n >> m;

    typedef struct s { // 小人
        int b = 0;     // 朝向
        char arr[20] = {0};
    } peoinfo;

    typedef struct w { // 命令
        int a = 0;     // 0左1右
        int s = 0;     // 步数
    } pro;

    peoinfo data[100008];
    pro pg[100008];

    // 输入

    for (int i = 0; i < n; i++) {
        cin >> data[i].b >> data[i].arr;
    }
    for (int i = 0; i < m; i++) {
        cin >> pg[i].a >> pg[i].s;
    }

    // 执行命令

    for (int i = 0; i < m; i++) {
        if (pg[i].a == data[c].b) {
            if (pg[i].s < n) {
                c = (c + n - pg[i].s) % n;
            }
        } else {
            if (pg[i].s < n) {
                c = (c + pg[i].s) % n;
            }
        }
    }

    cout << data[c].arr;
}
