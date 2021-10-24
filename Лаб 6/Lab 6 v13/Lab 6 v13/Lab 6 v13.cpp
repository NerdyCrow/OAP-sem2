#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct list
{
    int number;
    list* next;
};

void insert(list*&, int); //функция добавления элемента, передается адрес списка и символ, который добавляется 
int del(list*&, int);   //функция удаления, передается адрес списка и символ, который удаляется 
int IsEmpty(list*);         //функция, которая проверяет, пуст ли список
void printList(list*);      //функция вывода
void menu(void);     //функция, показывающая меню
void sum(list*);  //функция подсчета суммы чисел, больших 7  
void toFile(list*& p); // Запись в файл
void fromFile(list*& p); //Считывание из файла
void search(list*& p, int value); //Поиск по индексу 


int main()
{
    setlocale(LC_CTYPE, "Rus");

    list* first = NULL;
    int choice;
    int value;
    int local_num;


    menu();    // вывести меню 
    cout << " ? ";
    cin >> choice;

    while (choice)
    {

        switch (choice)
        {
        case 1:  	cout << "Введите число "; // добавить число в список
            cin >> value;
            insert(first, value);
            break;

        case 2:   if (!IsEmpty(first)) // удалить число из списка
        {
            cout << "Введите удаляемое число ";
            cin >> value;
            if (del(first, value))
            {
                cout << "Удалено число " << value << endl;
            }
            else
                cout << "Число не найдено" << endl;
        }
              else
            cout << "Список пуст" << endl;
            break;

        case 3:   sum(first);	// вычисление суммы	
            break;
        case 4:
            cout << "число для индекса = ";
            cin >> local_num;
            cout << endl;
            search(first, local_num);
            break;
        case 5:
            printList(first);
            break;
        case 6:
            toFile(first);
            break;
        case 7:
            fromFile(first);
            break;
        case 8:
            cout << "Exit" << endl;
            return 0;
            break;
        default:  cout << "Неправильный выбор" << endl;
            menu();
            break;
        }
        menu();    // вывести меню 
        cout << " ? ";
        cin >> choice;
    }
    cout << "Конец" << endl;
    return 0;
}

void menu(void)  //Вывод меню 
{
    cout << "Сделайте выбор:" << endl;
    cout << " 1 - Ввод числа" << endl;
    cout << " 2 - Удаление числа" << endl;
    cout << " 3 - Вычисление суммы отрицательных двухзначных элементов " << endl;
    cout << " 4 - Поиск индекса" << endl;
    cout << " 5 - Вывод списка" << endl;
    cout << " 6 - Запись списка" << endl;
    cout << " 7 - Чтение списка" << endl;
    cout << " 8 - Выход" << endl;
}

void insert(list*& p, int value) //Добавление числа value в список 
{
    list* newP = new list;
    if (newP != NULL)     //есть ли место?  
    {
        newP->number = value;
        newP->next = p;
        p = newP;
    }
    else
        cout << "Операция добавления не выполнена" << endl;
}

int del(list*& p, int value)  // Удаление числа 
{
    list* previous, * current, * temp;
    if (value == p->number)
    {
        temp = p;
        p = p->next;    // отсоединить узел 
        delete temp;      //освободить отсоединенный узел 
        return value;
    }
    else
    {
        previous = p;
        current = p->next;
        while (current != NULL && current->number != value)
        {
            previous = current;
            current = current->next; // перейти к следующему 
        }
        if (current != NULL)
        {
            temp = current;
            previous->next = current->next;
            free(temp);
            return value;
        }
    }
    return 0;
}

int IsEmpty(list* p) //Список  пустой? (1-да, 0-нет) 
{
    return p == NULL;
}

void printList(list* p)  //Вывод списка 
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

void sum(list* p)  
{
    int sm = 0;
    if (p == NULL)
        cout << "Список пуст" << endl;
    else
    {
        while (p != NULL)
        {
            if (p->number < -9 && p->number > -100)
                sm = sm + (p->number);
            p = p->next;
        }
        if (sm == 0) {
            cout << "Подходящих элементов нет!" << endl;
        }
        else {
            cout << "Сумма = " << sm << endl;
        }
    }
}

void toFile(list*& p) // запись в файл
{
    list* temp = p;
    int buf;
    ofstream frm("mList.txt");
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (temp)
    {
        buf = *(&temp->number);
        frm << buf << " ";
        temp = temp->next;
    }
    frm.close();
    cout << "Список записан в файл mList.txt\n";
}

void fromFile(list*& p)          //Считывание из файла
{
    int buf;
    list* first = nullptr;
    ifstream frm("mList.txt");
    vector <int> intbuff;
    if (frm.fail())
    {
        cout << "\n Ошибка открытия файла";
        exit(1);
    }
    while (!frm.eof())
    {
        char buff[50];
        frm >> buff;
        int x;
        x = atoi(buff);
        intbuff.push_back(x);
    }
    reverse(intbuff.begin(), intbuff.end());
    for (int i = 0; i < intbuff.size(); i++)
    {
        insert(first, intbuff[i]);
    }
    del(first, 0);
    cout << "-->NULL" << endl;
    frm.close();
    p = first;
    cout << "\nСписок считан из файла mList.txt\n";
}

void search(list*& p, int value) // поиск по индексу
{
    list* temp = p;
    int x = 1;
    if (p == NULL)
    {
        cout << "Список пуст" << endl;
    }
    else
    {
        while (p != NULL)
        {
            if (p->number == value)
            {

                break;
            }
            x++;
            p = p->next;
        }
        cout << "Индекс = " << x << endl;
    }

}



