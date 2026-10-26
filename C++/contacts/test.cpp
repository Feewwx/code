#include "con.h"

void menu() {
    cout << ("******************************************\n");
    cout << ("****   1.add               2.del      ****\n");
    cout << ("****   3.search            4.modify   ****\n");
    cout << ("****   5.show              6.sort     ****\n");
    cout << ("****   0.exit                         ****\n");
    cout << ("******************************************\n");
}

int main() {
    int input = 0;
    LinkList L = NULL;
    InitContact(&L);
    do {
        menu();
        cout << "请选择:";
        cin >> input;
        switch (input) {
        case 1:
            Add(&L);
            break;
        case 2:
            Del(&L);
            break;
        case 3:
            Search(&L);
            break;
        case 4:
            Modify(&L);
            break;
        case 5:
            Show(&L);
            break;
        case 6:
            Sort(&L);
            break;
        case 0:
            printf("再见\n");
            Destroy(&L);
            break;
        default:
            printf("输入错误\n");
            break;
        }
    } while (input);
}
