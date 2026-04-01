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
#include <iostream>
using namespace std;
int main() {
  int a = 0;
  int b = 0;
  int c = 0;
  int k = 0;

  int a1 = 0;
  int b1 = 0;
  int c1 = 0;
  while (cin >> a >> b >> c >> k) {
    for (int i = 0; i < k; i++) {
      a1 = (b + c) / 2;
      b1 = (a + c) / 2;
      c1 = (a + b) / 2;
      a = a1;
      b = b1;
      c = c1;
    }
    cout << a << " " << b << " " << c;
  }
  return 0;
}
