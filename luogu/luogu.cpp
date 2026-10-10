#include <iostream>

using namespace std;

void output11(int b, int c, int count, char arr[]) {
    int d = 0;
    do {
        if (arr[d] == 'W')
            b++;
        if (arr[d] == 'L')
            c++;
        if ((b >= 11 || c >= 11) && (b - c >= 2 || c - b >= 2)) {
            cout << b << ":" << c << endl;
            b = 0;
            c = 0;
        }
        d++;
    } while (d < count);
    // 收尾:所有字符走完了,手里这局不管打到几比几(哪怕 0:0)都要打一次。
    // 这里不需要判断 —— 要判断的是"一局结束没",那是循环里那行的事。
    cout << b << ":" << c << endl;
}

void output21(int b, int c, int count, char arr[]) {
    int d = 0;
    do {
        if (arr[d] == 'W')
            b++;
        if (arr[d] == 'L')
            c++;
        if ((b >= 21 || c >= 21) && (b - c >= 2 || c - b >= 2)) {
            cout << b << ":" << c << endl;
            b = 0;
            c = 0;
        }
        d++;
    } while (d < count);
    cout << b << ":" << c << endl;
}

int main() {
    char a = 0; // 输入
    char arr[70000] = {0};
    int count = 0;
    int b = 0; // W的数量
    int c = 0; // L的数量

    // 输入
    do {
        cin >> a;
        arr[count] = a;
        count++;
    } while (a != 'E');

    output11(b, c, count, arr);
    cout << endl; // 两段之间的空行
    output21(b, c, count, arr);
    return 0;
}
