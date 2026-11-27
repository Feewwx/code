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

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int n = 0; // 小人的数量  0内1外
//     int m = 0; // 指令的条数字
//
//     int c = 0; // 编号
//
//     cin >> n >> m;
//
//     typedef struct s { // 小人
//         int b = 0;     // 朝向
//         char arr[20] = {0};
//     } peoinfo;
//
//     typedef struct w { // 命令
//         int a = 0;     // 0左1右
//         int s = 0;     // 步数
//     } pro;
//
//     peoinfo data[100008];
//     pro pg[100008];
//
//     // 输入
//
//     for (int i = 0; i < n; i++) {
//         cin >> data[i].b >> data[i].arr;
//     }
//     for (int i = 0; i < m; i++) {
//         cin >> pg[i].a >> pg[i].s;
//     }
//
//     // 执行命令
//
//     for (int i = 0; i < m; i++) {
//         if (pg[i].a == data[c].b) {
//             if (pg[i].s < n) {
//                 c = (c + n - pg[i].s) % n;
//             }
//         } else {
//             if (pg[i].s < n) {
//                 c = (c + pg[i].s) % n;
//             }
//         }
//     }
//
//     cout << data[c].arr;
// }

// P1601 高精度加法

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int a[505] = {0};
//     int b[505] = {0};
//     int f[505] = {0};
//     int carry = 0;
//     string c;
//     string d;
//     cin >> c >> d;
//     int clen = c.size();
//     int dlen = d.size();
//     for (int i = 0; i < clen; i++)
//         a[clen - 1 - i] = c[i] - '0';
//     for (int i = 0; i < dlen; i++)
//         b[dlen - 1 - i] = d[i] - '0';
//     int maxlen = clen > dlen ? clen : dlen;
//     for (int p = 0; p < maxlen; p++) {
//         int g1 = 0;
//         int g2 = 0;
//         int g = a[p] + b[p] + carry;
//         g1 = g / 10;
//         g2 = g % 10;
//         f[p] = f[p] + g2;
//         carry = g1;
//     }
//     f[maxlen] = carry;
//     bool s = false;
//     for (int i = maxlen; i >= 0; i--) {
//         if (f[i] == 0 && s == false)
//             continue;
//         s = true;
//         cout << f[i];
//     }
//     if (s == false)
//         cout << 0;
// }

// P1303 A*B Problem

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int a[2005] = {0};
//     int b[2005] = {0};
//     int f[4005] = {0};
//     int h = 0;
//     int carry = 0;
//     string c;
//     string d;
//     cin >> c >> d;
//     int clen = c.size();
//     int dlen = d.size();
//     for (int i = 0; i < clen; i++)
//         a[clen - 1 - i] = c[i] - '0';
//     for (int i = 0; i < dlen; i++)
//         b[dlen - 1 - i] = d[i] - '0';
//     for (int i = 0; i < clen + 1; i++) {
//         for (int j = 0; j < dlen + 1; j++) {
//             int g1 = 0;
//             int g2 = 0;
//             int g3 = 0;
//             int g = a[i] * b[j] + carry;
//             g1 = g / 10;
//             g2 = g % 10;
//             if (f[j + i] + g2 >= 10) {
//                 g = f[j + i] + g2;
//                 g3 = g / 10;
//                 g2 = g % 10;
//                 f[j + i] = g2;
//             } else
//                 f[j + i] = f[j + i] + g2;
//             carry = g1 + g3;
//         }
//     }
//     bool s = false;
//     for (int i = 4004; i >= 0; i--) {
//         if (f[i] == 0 && s == false)
//             continue;
//         s = true;
//         cout << f[i];
//     }
//     if (s == false)
//         cout << 0;
// }

// P1009 [NOIP 1998 普及组] 阶乘之和

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int input = 0;
//     cin >> input;
//
//     int fact[100] = {0}; // 当前 i!, 个位在 fact[0]
//     int sum[100] = {0};  // 累加和, 个位在 sum[0]
//     fact[0] = 1;
//
//     for (int i = 1; i <= input; i++) {
//         // fact = fact * i: 逐位乘, 进位往高位走
//         int carry = 0;
//         for (int d = 0; d < 100; d++) {
//             int t = fact[d] * i + carry;
//             fact[d] = t % 10;
//             carry = t / 10;
//         }
//
//         // sum = sum + fact: 逐位加, 进位往高位走
//         carry = 0;
//         for (int d = 0; d < 100; d++) {
//             int t = sum[d] + fact[d] + carry;
//             sum[d] = t % 10;
//             carry = t / 10;
//         }
//     }
//
//     // 从最高非零位倒着输出
//     int start = 99;
//     while (start > 0 && sum[start] == 0)
//         start--;
//     for (int d = start; d >= 0; d--)
//         cout << sum[d];
//     cout << endl;
//
//     return 0;
// }

// P4924 [1007] 魔法少女小Scarlet

// #include <iostream>
//
// // 定义
//
// using namespace std;
//
// typedef struct PeoInfo {
//     int x = 0;
//     int y = 0;
//     int r = 0;
//     int z = 0;
// } PeoInfo;
//
// PeoInfo sd[505];
//
// int main() {
//     // 初始化
//     int n = 0;
//     int m = 0;
//     int arr[505][505] = {0};
//     int temp[505][505] = {0};
//     int z = 1;
//     // 输入
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         cin >> sd[i].x >> sd[i].y >> sd[i].r >> sd[i].z;
//     }
//     // 初始化
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             arr[i][j] = z;
//             z++;
//         }
//     }
//     // 运行
//     for (int i = 0; i < m; i++) {
//         // 搬运
//         for (int j = sd[i].y - sd[i].r - 1; j < sd[i].y + (sd[i].r); j++) {
//             for (int t = sd[i].x - sd[i].r - 1; t < sd[i].x + (sd[i].r); t++) {
//                 temp[t][j] = arr[t][j];
//             }
//         }
//         // 运算
//         if (sd[i].z == 0) {
//             for (int z = 0; z < sd[i].r; z++) {
//                 int L = 2 * (sd[i].r - z) + 1;
//                 // 这一圈的边长
//                 int gx = sd[i].x - sd[i].r - 1 + z;
//                 // 这一圈的左上角
//                 int gy = sd[i].y - sd[i].r - 1 + z;
//                 for (int j = 0; j < L - 1; j++) {
//                     int tempp = temp[gx][gy + j];
//                     // 上
//                     temp[gx][gy + j] = temp[gx + L - 1 - j][gy];                 // 上 <- 左
//                     temp[gx + L - 1 - j][gy] = temp[gx + L - 1][gy + L - 1 - j]; // 左 <- 下
//                     temp[gx + L - 1][gy + L - 1 - j] = temp[gx + j][gy + L - 1]; // 下 <- 右
//                     temp[gx + j][gy + L - 1] = tempp;
//                     // 右 <- 上
//                 }
//             }
//         } else {
//             for (int z = 0; z < sd[i].r; z++) {
//                 int L = 2 * (sd[i].r - z) + 1;
//                 int gx = sd[i].x - sd[i].r - 1 + z;
//                 int gy = sd[i].y - sd[i].r - 1 + z;
//                 for (int j = 0; j < L - 1; j++) {
//                     int tempp = temp[gx][gy + j];
//                     // 上
//                     temp[gx][gy + j] = temp[gx + j][gy + L - 1];                 // 上 <- 右
//                     temp[gx + j][gy + L - 1] = temp[gx + L - 1][gy + L - 1 - j]; // 右 <- 下
//                     temp[gx + L - 1][gy + L - 1 - j] = temp[gx + L - 1 - j][gy]; // 下 <- 左
//                     temp[gx + L - 1 - j][gy] = tempp;
//                     // 左 <- 上
//                 }
//             }
//         }
//         // 回家
//         for (int j = sd[i].y - sd[i].r - 1; j < sd[i].y + (sd[i].r); j++) {
//             for (int t = sd[i].x - sd[i].r - 1; t < sd[i].x + (sd[i].r); t++) {
//                 arr[t][j] = temp[t][j];
//             }
//         }
//     }
//     // 输出
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// P4924 不按环的写法: 每格自己算新位置

// #include <iostream>
//
// // 定义
//
// using namespace std;
//
// typedef struct PeoInfo {
//     int x = 0;
//     int y = 0;
//     int r = 0;
//     int z = 0;
// } PeoInfo;
//
// PeoInfo sd[505];
//
// int main() {
//     // 初始化
//     int n = 0;
//     int m = 0;
//     int arr[505][505] = {0};
//     int temp[505][505] = {0};
//     int z = 1;
//     // 输入
//     cin >> n >> m;
//     for (int i = 0; i < m; i++) {
//         cin >> sd[i].x >> sd[i].y >> sd[i].r >> sd[i].z;
//     }
//     // 初始化
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             arr[i][j] = z;
//             z++;
//         }
//     }
//     // 运行
//     for (int i = 0; i < m; i++) {
//         int cx = sd[i].x - 1; // 中心行, 换成 0 起始
//         int cy = sd[i].y - 1; // 中心列
//         // 运算: 每格按相对坐标算新位置, 写进 temp
//         for (int dr = -sd[i].r; dr <= sd[i].r; dr++) {
//             for (int dc = -sd[i].r; dc <= sd[i].r; dc++) {
//                 if (sd[i].z == 0)
//                     temp[cx + dc][cy - dr] = arr[cx + dr][cy + dc]; // 顺时针 (dr,dc) -> (dc,-dr)
//                 else
//                     temp[cx - dc][cy + dr] = arr[cx + dr][cy + dc]; // 逆时针 (dr,dc) -> (-dc,dr)
//             }
//         }
//         // 回家
//         for (int j = cx - sd[i].r; j <= cx + sd[i].r; j++) {
//             for (int t = cy - sd[i].r; t <= cy + sd[i].r; t++) {
//                 arr[j][t] = temp[j][t];
//             }
//         }
//     }
//     // 输出
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < n; j++) {
//             cout << arr[i][j] << " ";
//         }
//         cout << endl;
//     }
// }

// P1328 [NOIP 2014 提高组] 生活大爆炸版石头剪刀布

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int a = 0; // a的分数
//     int b = 0; // b的分数
//     int arr[210] = {0};
//     int brr[210] = {0};
//     int c;  // 猜拳数量
//     int an; // a的一次性周期数量
//     int bn; // b的一次性周期数量
//     cin >> c >> an >> bn;
//     for (int i = 1; i <= an; i++) {
//         cin >> arr[i];
//         // int count = c / an;
//         // for (int j = 1; j <= count; j++) {
//         // if (i + an * j > c) break;
//         //     arr[i + an * j] = arr[i];
//         // }
//     }
//     for (int i = 1; i <= bn; i++) {
//         cin >> brr[i];
//         // int count = c / bn;
//         // for (int j = 1; j <= count; j++) {
//         // if (i + bn * j > c) break;
//         //     brr[i + bn * j] = brr[i];
//         // }
//     }
//     int t[5][5] = {{0, -1, 1, 1, -1},
//                    {1, 0, -1, 1, -1},
//                    {-1, 1, 0, -1, 1},
//                    {-1, -1, 1, 0, 1},
//                    {1, 1, -1, 1, 0}};
//     for (int i = 1; i <= c; i++) {
//         int d = 0;
//         // d = t[arr[i]][brr[i]];
//         d = t[arr[(i - 1) % an + 1]][brr[(i - 1) % bn + 1]];
//         if (d == 1)
//             a++;
//         if (d == -1)
//             b++;
//     }
//     cout << a << " " << b;
//     return 0;
// }

// P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two

// #include <iostream>
//
// using namespace std;
//
// void move(int *x, int *y, char (&input)[12][12], int *r) {
//     switch (*r) {
//     case 0:
//         if (input[*x - 1][*y] == '*') {
//             *r = *r + 1;
//         } else {
//             char temp = 0;
//             temp = input[*x - 1][*y];
//             input[*x - 1][*y] = input[*x][*y];
//             input[*x][*y] = temp;
//             *x = *x - 1;
//         }
//         break;
//     case 1:
//         if (input[*x][*y + 1] == '*') {
//             *r = *r + 1;
//         } else {
//             char temp = 0;
//             temp = input[*x][*y + 1];
//             input[*x][*y + 1] = input[*x][*y];
//             input[*x][*y] = temp;
//             *y = *y + 1;
//         }
//         break;
//     case 2:
//         if (input[*x + 1][*y] == '*') {
//             *r = *r + 1;
//         } else {
//             char temp = 0;
//             temp = input[*x + 1][*y];
//             input[*x + 1][*y] = input[*x][*y];
//             input[*x][*y] = temp;
//             *x = *x + 1;
//         }
//         break;
//     case 3:
//         if (input[*x][*y - 1] == '*') {
//             *r = 0;
//         } else {
//             char temp = 0;
//             temp = input[*x][*y - 1];
//             input[*x][*y - 1] = input[*x][*y];
//             input[*x][*y] = temp;
//             *y = *y - 1;
//         }
//         break;
//     }
// }
//
// int main() {
//     char input[12][12];
//     int f = 0; // john的方向,0上1右2下3左
//     int c = 0; // cow的方向,0上1右2下3左
//     int fx = 0, fy = 0;
//     int cx = 0, cy = 0;
//     int count = 0;
//     bool vis[12][12][4][12][12][4] = {};
//     // 初始化
//     for (int i = 0; i < 12; i++) {
//         for (int j = 0; j < 12; j++) {
//             input[i][j] = '*';
//         }
//     }
//     for (int i = 1; i < 11; i++) {
//         for (int j = 1; j < 11; j++) {
//             cin >> input[i][j];
//         }
//     }
//     // char input[12][12] = {{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
//     //                       {'*', '*', '.', '.', '.', '*', '.', '.', '.', '.', '.', '*'},
//     //                       {'*', '.', '.', '.', '.', '.', '.', '*', '.', '.', '.', '*'},
//     //                       {'*', '.', '.', '.', '*', '.', '.', '.', '*', '.', '.', '*'},
//     //                       {'*', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '*'},
//     //                       {'*', '.', '.', '.', '*', '.', 'F', '.', '.', '.', '.', '*'},
//     //                       {'*', '*', '.', '.', '.', '.', '.', '*', '.', '.', '.', '*'},
//     //                       {'*', '.', '.', '.', '*', '.', '.', '.', '.', '.', '.', '*'},
//     //                       {'*', '.', '.', 'C', '.', '.', '.', '.', '.', '.', '*', '*'},
//     //                       {'*', '.', '.', '.', '*', '.', '*', '.', '.', '.', '.', '*'},
//     //                       {'*', '.', '*', '.', '*', '.', '.', '.', '.', '.', '.', '*'},
//     //                       {'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'}};
//     // 找到cow和john
//     for (int i = 1; i < 11; i++) {
//         for (int j = 1; j < 11; j++) {
//             if (input[i][j] == 'F') {
//                 fx = i;
//                 fy = j;
//             }
//             if (input[i][j] == 'C') {
//                 cx = i;
//                 cy = j;
//             }
//         }
//     }
//     do {
//         if (vis[fx][fy][f][cx][cy][c]) {
//             cout << 0;
//             return 0;
//         }
//         vis[fx][fy][f][cx][cy][c] = true;
//         move(&fx, &fy, input, &f);
//         move(&cx, &cy, input, &c);
//         count++;
//     } while (!(fx == cx && fy == cy));
//     cout << count;
//     return 0;
// }

// P1067 [NOIP 2009 普及组] 多项式输出

// #include <iostream>
//
// using namespace std;
//
// int main() {
//     int n = 0;
//     cin >> n;
//     int arr[105];
//     for (int i = 0; i <= n; i++) {
//         cin >> arr[i];
//     }
//     int cn = n;
//     for (int i = 0; i < n; i++) {
//         if (cn == 1) {
//             if (arr[i] < 0) {
//                 if (arr[i] == 1 || arr[i] == -1)
//                     cout << '-' << "x";
//                 else
//                     cout << arr[i] << "x";
//             }
//             if (arr[i] > 0) {
//                 if (i == 0) {
//                     if (arr[i] != 1)
//                         cout << arr[i] << "x";
//                     else
//                         cout << "x";
//                 } else {
//                     cout << '+';
//                     if (arr[i] != 1)
//                         cout << arr[i] << "x";
//                     else
//                         cout << "x";
//                 }
//             }
//         } else {
//             if (arr[i] < 0) {
//                 if (arr[i] == 1 || arr[i] == -1)
//                     cout << '-' << "x^" << cn;
//                 else
//                     cout << arr[i] << "x^" << cn;
//             }
//             if (arr[i] > 0) {
//                 if (i == 0) {
//                     if (arr[i] != 1)
//                         cout << arr[i] << "x^" << cn;
//                     else
//                         cout << "x^" << cn;
//                 } else {
//                     cout << '+';
//                     if (arr[i] != 1)
//                         cout << arr[i] << "x^" << cn;
//                     else
//                         cout << "x^" << cn;
//                 }
//             }
//         }
//         cn--;
//     }
//     if (n == 0) {
//         cout << arr[n];
//     } else {
//         if (arr[n] > 0)
//             cout << '+' << arr[n];
//         if (arr[n] < 0)
//             cout << arr[n];
//     }
//     return 0;
// }

// P1098 [NOIP 2007 提高组] 字符串的展开

// #include <cstring>
// #include <iostream>
//
// using namespace std;
//
// int main() {
//     char input[105] = {0};
//     int p1 = 0;
//     int p2 = 0;
//     int p3 = 0;
//     int x = 'a' - 'A';
//     cin >> p1 >> p2 >> p3 >> input;
//     int len = strlen(input);
//     for (int i = 0; i < len; i++) {
//         if (input[i] == '-') {
//             if (i > 0) {
//                 int y = input[i + 1] - input[i - 1] - 1;
//                 if (input[i - 1] < input[i + 1] && input[i - 1] >= 'a' && input[i + 1] <= 'z') {
//                     if (input[i + 1] - input[i - 1] == 1) {
//                         continue;
//                     } else {
//                         if (p3 == 1) {
//                             for (int j = 0; j < y; j++) {
//                                 if (p1 == 1) {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << char(input[i - 1] + j + 1);
//                                     }
//                                 } else if (p1 == 2) {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << char(input[i - 1] + j - x + 1);
//                                     }
//                                 } else {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << '*';
//                                     }
//                                 }
//                             }
//                         } else {
//                             for (int j = y; j > 0; j--) {
//                                 if (p1 == 1) {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << char(input[i - 1] + j);
//                                     }
//                                 } else if (p1 == 2) {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << char(input[i - 1] + j - x);
//                                     }
//                                 } else {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << '*';
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 } else if (input[i - 1] < input[i + 1] && input[i - 1] >= '0' &&
//                            input[i + 1] <= '9') {
//                     if (input[i + 1] - input[i - 1] == 1) {
//                         continue;
//                     } else {
//                         if (p3 == 1) {
//                             for (int j = 0; j < y; j++) {
//                                 if (p1 == 3) {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << '*';
//                                     }
//                                 } else {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << char(input[i - 1] + j + 1);
//                                     }
//                                 }
//                             }
//                         } else {
//                             for (int j = y; j > 0; j--) {
//                                 if (p1 == 3) {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << '*';
//                                     }
//                                 } else {
//                                     for (int z = 0; z < p2; z++) {
//                                         cout << char(input[i - 1] + j);
//                                     }
//                                 }
//                             }
//                         }
//                     }
//                 } else {
//                     cout << input[i];
//                 }
//             } else {
//                 cout << input[i];
//             }
//         } else
//             cout << input[i];
//     }
//     return 0;
// }

// P1065 [NOIP 2006 提高组] 作业调度方案

#include <iostream>

using namespace std;

int main() {
    // 输入
    int m = 0;
    int n = 0;
    cin >> m >> n;
    int step[400] = {0};
    for (int i = 0; i < (m * n); i++) {
        cin >> step[i];
    }
}
