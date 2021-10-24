﻿#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

string A = "A.txt";
char str[200];
int amountOfStr = 0;



struct list2
{
    int number;
    list2* next;
};


list2* v9;

int menu();


void insert1(list2*&, int);
int del1(list2*&, int);
void find1(list2*, int);
void printList1(list2*);
void toFile(list2*);
void fromFile(list2*&);


void mainTask1(list2*&);
void kratn(list2*);

int main()
{
    setlocale(LC_ALL, "Russian");

    mainTask1(v9);

    return 0;
}



void mainTask1(list2*& first)
{
    first = NULL;
    int a = 1;
    int n;
    while (a != 0)
    {
        switch (menu())
        {
        case 1:
            cout << "Введите число: ";
            cin >> n;
            insert1(first, n);
            break;

        case 2:
            cout << "Введите число: ";
            cin >> n;
            del1(first, n);
            break;

        case 3:
            cout << "Введите число: ";
            cin >> n;
            find1(first, n);
            break;

        case 4:
            printList1(first);
            break;

        case 5:
            toFile(first);
            break;

        case 6:
            fromFile(first);
            break;

        case 7:
            kratn(first);
            break;

        case 0:
            a = 0;
            break;

        default:
            break;
        }
    }
}

int menu()
{
    int n;
    cout << endl;
    cout << " 1. Ввод числа" << endl;
    cout << " 2. Удаление числа" << endl;
    cout << " 3. Поиск числа" << endl;
    cout << " 4. Вывод списка в консольное окно" << endl;
    cout << " 5. Запись списка в файл" << endl;
    cout << " 6. Считывание списка из файла" << endl;
    cout << " 7. Сумма отриц. кратных 5" << endl;
    cout << " 0. Выход" << endl;
    cout << "(Введите выбор) ";
    cin >> n;
    cout << endl;
    return n;
}



void insert1(list2*& p, int value) //Добавление числа value в список 
{
    list2* newP = new list2;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else cout << "Операция добавления не выполнена" << endl;
}

int del1(list2*& p, int value)  // Удаление числа 
{
    list2* previous, * current;

    previous = p;
    current = p->next;
    if (p->number == value)
    {
        free(p);
        p = current;
    }
    else
    {
        while (current != NULL)
        {
            if (current->number == value)
            {
                previous->next = current->next;
                free(current);
                break;
            }
            previous = current;
            current = current->next;
        }
    }
    return 0;
}

void find1(list2* p, int value)
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Переменные: " << value << endl;
        while (p != NULL)
        {
            if (p->number == value) cout << p->number << endl;
            p = p->next;
        }
    }
}

void printList1(list2* p)  //Вывод списка 
{
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        cout << "Список:" << endl;
        while (p != NULL)
        {
            cout << "-->" << p->number;
            p = p->next;
        }
        cout << "-->NULL" << endl;
    }
}

void toFile(list2* p)
{
    amountOfStr = 0;
    ofstream fAout(A);
    if (fAout.is_open())
    {
        if (p == NULL)
        {
            fAout << "Список пуст" << endl;
        }
        else
        {
            while (p != NULL)
            {
                fAout << p->number << endl;
                p = p->next;
                amountOfStr++;
            }
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
}

void fromFile(list2*& p)
{
    list2* previous, * current;
    previous = p;
    current = p->next;
    while (current != NULL)
    {
        free(previous);
        previous = current;
        current = previous->next;
    }
    p = NULL;

    ifstream fAin(A);
    int* arr = new int[amountOfStr];
    if (fAin.is_open())
    {
        for (size_t i = 0; i < amountOfStr; i++)
        {
            fAin.getline(str, sizeof(str));

            arr[i] = atof(str);
        }
        for (int i = amountOfStr - 1; i >= 0; i--)
        {
            insert1(p, arr[i]);
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
}


void kratn(list2* p)
{
    cout << "Найти сумму отрицательных элементов, кратных 5" << endl;
    int sum = 0, num = 0;
    if (p == NULL) cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < 0 && p->number % 5==0)
            {
                sum += p->number;
                num++;
            }
            p = p->next;
        }
        if (sum == 0) cout << "Таких элементов нет";
        else cout << "Среднее значение = " << sum << endl;
    }
}