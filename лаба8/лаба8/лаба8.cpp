#include "stdafx.h"

int maxSize, curSize = 0;
int maxSize2, curSize2 = 0;
Item* head, * tail;

int main()
{
    setlocale(LC_ALL, "rus");
    bool work = true;
    int choice;
    while (work)
    {
        cout << "\n1. Варинт 6\n2. Доп 1\n3. Доп 2\n4. Доп 3\n(Введите выбор) ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            var6();
            break;
        case 2:
            dop1();
            break;
        case 3:
            dop2();
            break;
        case 4:
            task3();
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
    return 0;
}