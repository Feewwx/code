// #include <iostream>
// using namespace std;
// int main() {
//   int a = 0;                     // 每个月预算
//   int b = 0;                     // 最后剩下的钱
//   int d = 0;                     // 每个月剩下的钱
//   int e = 0;                     // 存到妈妈那里的钱
//   for (int i = 0; i < 12; i++) { // 月份
//     cin >> a;
//     if (a <= 350) {
//       b = 300 - a + d;
//       if (b > 0) {
//         while (b >= 100) {
//           b = b - 100;
//
//           e = e + 100;
//         }
//
//       } else {
//         cout << -(i+1);
//         return 0;
//       }
//
//     } else {
//       cout << "输入错误";
//     }
//     d=b;
//     e = b + e * 1.2;
//     cout << e;
//
//     return 0;
//   }
// #include <iostream>
// using namespace std;
// int main() {
//  int n = 0; // 数组数量
//  int a = 0; // 输入的数
//  int b = 0; // 上一个数（副本）
//  int c;     // 差值
//  cin >> n;
//  for (int i = 0; i <= n; i++) {
//    cin >> a;
//    if (i == 0) {
//      b = a;
//    } else {
//      c = b - a;
//      if (c > 0) {
//        if (c <= n - 1 || c >= 1) {
//         cout << "Jolly";
//          return 0;
//        } else {
//          cout << "Not jolly";
//         return 0;
//        }
//
//      } else if (c < 0) {
//        c = -c;
//        if (c > 0) {
//          if (c <= n - 1 && c >= 1) {
//            cout << "Jolly";
//            return 0;
//          } else {
//            cout << "Not jolly";
//            return 0;
//          }
//
//        } else {
//          cout << "Not jolly";
//          return 0;
//        }
//      }
//    }
//    return 0;
//  }
// #include <iostream>
// using namespace std;
// int main(){
//     int n;//数据的个数
//     int b;//输入的数
//     int c=0;//正确的数
//     cin>>n;
//     for(int a=0;a<n;a++){//计数
//         cin >> b;
//         if(b!=1)
//             c++;}
//         cout<<c;
//     return 0;
// }
// #include <iostream>
// using namespace std;
// int main() {
//   int a = 0;
//   int b = 0;
//   int c = 0;
//   int k = 0;
//
//   int a1 = 0;
//   int b1 = 0;
//   int c1 = 0;
//   while (cin >> a >> b >> c >> k) {
//     for (int i = 0; i < k; i++) {
//       a1 = (b + c) / 2;
//       b1 = (a + c) / 2;
//       c1 = (a + b) / 2;
//       a = a1;
//       b = b1;
//       c = c1;
//     }
//     cout << a << " " << b << " " << c;
//   }
//   return 0;
// }
// #include <algorithm>
// #include <iostream>
// using namespace std;
// int main() {
//   int n = 0; // 需要输入的数
//   int m = 0; // 选画作的数量
//   cin >> n;
//   cin >> m;
//   int arr[10005] = {0};
//   for (int i = 0; i < n; i++)
//     cin >> arr[i];
//
//   sort(arr, arr + n);
//
//   long long ans = 99999999999;
//   for (int j = 0; j <= n - m; j++) {
//     long long L =
//         (long long)arr[j + m - 1] * arr[j + m - 1] - (long long)arr[j] *
//         arr[j];
//     if (L < ans)
//       ans = L;
//   }
//   cout << ans;
//
//   return 0;
// }
// #include <iostream>
// using namespace std;
// int add = 0;
// int a = 0;
// int main() {
//   for (int i = 0; i < 50; i++)
//     add = add + i;
//
//   for (int j = 0; j < 7; j++)
//     a = a + j;
//
//   int c = add - a;
//   cout << c;
//
//   return 0;
// }
#include <iostream>
using namespace std;
int main() {
  int a = 0; // 计数
  int b = 0; // 输入的数
  cin >> b;
  for (int i = 1; i <= b; i++) {
    int temp = i;
    int c = 1; // 位数
    bool isgood = true;
    while (temp > 0) {
      int d = temp % 10; // 取出当前位的数字

      if (c % 2 != 0) {   // 奇数位（个、百、万...）
        if (d % 2 == 0) { // 应该是奇数，如果是偶数就错了
          isgood = false;
          break;
        }
      } else {            // 偶数位（十、千、十万...）
        if (d % 2 != 0) { // 应该是偶数，如果是奇数就错了
          isgood = false;
          break;
        }
      }

      temp /= 10;
      c++;
    }

    if (isgood)
      a++;
  }

  cout << a;

  return 0;
}
// #include <iostream>
// using namespace std;
// int main() {
//   double d = 0; // 输入的浮点数
//   int n = 0;    // 转换参数
//   cin >> n;
//   cin >> d;
//   int a = 0;
//   double e = d * 2;
//   for (int i = 0; i < n - 1; i++) {
//     e = e * 2;
//   }
//
//   a = e * 10;
//   int b = a % 10;
//   int c = a / 10;
//   if (b >= 5) {
//     c += 1;
//   } else {
//     c += 0;
//   }
//   cout << c;
//
//   return 0;
// }
