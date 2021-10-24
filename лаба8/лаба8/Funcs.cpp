#include "stdafx.h"

void var6()
{
    bool work = true;
    Number* begin = NULL, * end;
    int p, choice = 0;

    cout << "\nВведите размер очереди = ";
    cin >> maxSize;

    while (work)
    {
        cout << "\n1. Ввод числа\n2. Вывод очереди\n3. Удаление элемента\n4. Задание\n0. Закончить\n(Введите выбор) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите число: ";
            cin >> p;
            create(&begin, &end, p);
            break;
        case 2:
            view(begin);
            break;
        case 3:
            cout << "Введите число: ";
            cin >> p;
            Delete(&begin, &end, p);
            break;
        case 4:
            task(begin);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create(Number** begin, Number** end, int p) //Формирование элементов очереди
{
    if (curSize != maxSize)
    {
        Number* t = new Number;
        t->next = NULL;
        if (*begin == NULL)
        {
            *begin = *end = t;
            t->info = p;
        }
        else
        {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        curSize++;
    }
    else
    {
        cout << "Очередь заполнена!" << endl;
    }
}

void view(Number* begin) //Вывод элементов очереди 
{
    Number* t = begin;
    if (t == NULL)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL";
    }
}

void Delete(Number** begin, Number** end, int p) //Удаление до минимального элемента 
{
    Number** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        if ((*prev)->info == p)
        {
            *begin = (*prev)->next;
            curSize--;
        }
        else
        {
            while (cur != NULL)
            {
                if ((*cur)->info == p)
                {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }
    }
}

int amount(Number* begin)
{
    int x = 0;
    Number* t = begin;
    if (t == NULL)
    {
        return 0;
    }
    else
    {
        while (t != NULL)
        {
            t = t->next;
            x++;
        }
    }
    return x;
}

void task(Number* begin)
{
    Number* t = begin;
    int num = amount(t);
    if (t == NULL)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        view(t);
        t = begin;
        int max = t->info;
        while (t != NULL)
        {
            if (t->info > max) max = t->info;
            t = t->next;
        }
        cout << "\nМаксимальный элемент очереди: " << max << endl;

        t = begin;
        while (t != NULL)
        {
            cout << t->info << " --> ";
            num--;
            if (t->info == 0) break;
            t = t->next;
        }
        cout << "\nРазмер оставшейся очереди: " << num << endl;
    }
}

void dop1()
{
    int n;
    bool work = true;
    while (work)
    {
        cout << "\n1. Первое задание\n2. Второе задание\n3. Третье задание\n4. Пятое задание\n0. Выйти" << endl;
        cin >> n;
        switch (n)
        {
        case 1:
            dop1_1();
            break;
        case 2:
            dop1_2();
            break;
        case 3:
            dop1_3();
            break;
        case 4:
            dop1_5();
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void dop1_1()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. добавить элемент" << endl;
        cout << "2. получить элемент с начала" << endl;
        cout << "3. извлечь элемент с начала" << endl;
        cout << "4. вывести элементы" << endl;
        cout << "5. очистить очередь" << endl;
        cout << "0. выход" << endl;
        cout << "Выберите действие  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "Введите элемент:  "; cin >> z;
            insertToQueue(z); printQueue();  break;
        case 2: getFromHead(); break;
        case 3: deletFirst();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

void dop1_2()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. добавить элемент" << endl;
        cout << "2. получить элемент с начала" << endl;
        cout << "3. извлечь элемент с начала" << endl;
        cout << "4. вывести элементы" << endl;
        cout << "5. очистить очередь" << endl;
        cout << "0. выход" << endl;
        cout << "Выберите действие  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "Введите элемент:  "; cin >> z;
            insertToQueue2(z); printQueue();  break;
        case 2: getFromHead(); break;
        case 3: deletFirst();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

void dop1_3()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. добавить элемент" << endl;
        cout << "2. получить элемент с конца" << endl;
        cout << "3. извлечь элемент с конца" << endl;
        cout << "4. вывести элементы" << endl;
        cout << "5. очистить очередь" << endl;
        cout << "0. выход" << endl;
        cout << "Выберите действие  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "Введите элемент:  "; cin >> z;
            insertToQueue(z); printQueue();  break;
        case 2: getFromEnd(); break;
        case 3: deletLast();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

void dop1_5()
{
    int i = 1, choice = 1, z; head = NULL;  tail = NULL;
    while (choice != 0)
    {
        cout << "1. добавить элемент" << endl;
        cout << "2. получить элемент с конца" << endl;
        cout << "3. извлечь элемент с конца" << endl;
        cout << "4. вывести элементы" << endl;
        cout << "5. очистить очередь" << endl;
        cout << "0. выход" << endl;
        cout << "Выберите действие  ";  cin >> choice;
        switch (choice)
        {
        case 1: cout << "Введите элемент:  "; cin >> z;
            insertToQueue2(z); printQueue();  break;
        case 2: getFromEnd(); break;
        case 3: deletLast();  break;
        case 4: printQueue();  break;
        case 5: clrQueue();    break;
        }
    }
}

bool isNull(void)    //Проверка на пустоту
{
    return (head == NULL);
}

void deletFirst()   //Извлечение элемента из начала
{
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
    {
        Item* p = head;
        head = head->next;
        delete p;
    }
}

void getFromHead()  //Получение элемента из начала
{
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
        cout << "Начало = " << head->data << endl;
}

void deletLast()   //Извлечение элемента из начала
{
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
    {
        Item* h = head, * t = tail;
        while (true)
        {
            if (h->next == t)
            {
                delete tail;
                tail = h;
                tail->next = NULL;
                break;
            }
            h = h->next;
        }
    }
}

void getFromEnd()  //Получение элемента из начала
{
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
        cout << "Начало = " << tail->data << endl;
}

void insertToQueue(int x)  //Добавление элемента в очередь 
{
    Item* p = new Item;      //новый указатель 
    p->data = x;
    p->next = NULL;
    Item* v = new Item;      //указатель для нового числа
    Item* p1 = new Item;
    Item* p2 = new Item;
    int i = 0;               //флажок
    if (isNull())
        head = tail = p;
    else
    {
        p2 = head; p1 = head;
        while (p1 != NULL)  //пока очередь не закончится
        {
            if (i == 1)
            {
                if (x <= p1->data)  //число меньше, чем в очереди
                {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;      // следующее число
            }
            else
            {
                if (x <= p1->data)
                {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL)
        {
            tail->next = p;
            tail = p;
        }
    }
}

void insertToQueue2(int x)  //Добавление элемента в очередь 
{
    Item* p = new Item;      //новый указатель 
    p->data = x;
    p->next = NULL;
    Item* v = new Item;      //указатель для нового числа
    Item* p1 = new Item;
    Item* p2 = new Item;
    int i = 0;               //флажок
    if (isNull())
        head = tail = p;
    else
    {
        p2 = head; p1 = head;
        while (p1 != NULL)  //пока очередь не закончится
        {
            if (i == 1)
            {
                if (x >= p1->data)  //число меньше, чем в очереди
                {
                    v->data = x;
                    v->next = p1;
                    p2->next = v;
                    return;
                }
                p2 = p2->next;      // следующее число
            }
            else
            {
                if (x >= p1->data)
                {
                    v->data = x;
                    v->next = p1;
                    head = v;
                    return;
                }
            }
            p1 = p1->next;
            i = 1;
        }
        if (p1 == NULL)
        {
            tail->next = p;
            tail = p;
        }
    }
}

void printQueue()             //Вывод очереди
{
    Item* p = new Item;
    if (isNull())
        cout << "Очередь пуста" << endl;
    else
    {
        cout << "Очередь = ";
        p = head;
        while (!isNull())
        {
            if (p != NULL)
            {
                cout << p->data << " "; cout << "->";
                p = p->next;
            }
            else
            {
                cout << "NULL" << endl;
                return;
            }
        }
    }
}

void clrQueue()           //Очистка очереди
{
    while (!isNull()) deletFirst();
}

void dop2()
{
    bool work = true;
    Number2* begin = NULL, * end;
    int choice = 0;
    float p;

    cout << "\nВведите размер очереди = ";
    cin >> maxSize2;

    while (work)
    {
        cout << "\n1. Ввод числа\n2. Вывод очереди\n3. Удаление элемента\n4. Сделать циклический сдвиг\n0. Закончить\n(Введите выбор) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите число: ";
            cin >> p;
            create2(&begin, &end, p);
            break;
        case 2:
            view2(begin);
            break;
        case 3:
            cout << "Введите число: ";
            cin >> p;
            Delete2(&begin, &end, p);
            break;
        case 4:
            task2(&begin, &end);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create2(Number2** begin, Number2** end, float p) //Формирование элементов очереди
{
    if (curSize2 != maxSize2)
    {
        Number2* t = new Number2;
        t->next = NULL;
        if (*begin == NULL)
        {
            *begin = *end = t;
            t->info = p;
        }
        else
        {
            t->info = p;
            (*end)->next = t;
            *end = t;
        }
        curSize2++;
    }
    else
    {
        cout << "Очередь заполнена!" << endl;
    }
}

void view2(Number2* begin) //Вывод элементов очереди 
{
    Number2* t = begin;
    if (t == NULL)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        while (t != NULL)
        {
            cout << t->info << " --> ";
            t = t->next;
        }
        cout << "NULL";
    }
}

void Delete2(Number2** begin, Number2** end, float p) //Удаление до минимального элемента 
{
    Number2** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        if ((*prev)->info == p)
        {
            *begin = (*prev)->next;
            curSize2--;
        }
        else
        {
            while (cur != NULL)
            {
                if ((*cur)->info == p)
                {
                    (*prev)->next = (*cur)->next;
                    if ((*prev)->next == NULL) *end = *prev;
                    curSize2--;
                    break;
                }
                prev = cur;
                cur = &(*cur)->next;
            }
        }
    }
}

void task2(Number2** begin, Number2** end)
{
    cout << "Выполнить циклический сдвиг элементов в очереди так, чтобы в ее начале был расположен наибольший элемент" << endl;
    Number2** h = begin, ** t = end, * newH = NULL, * newT = NULL;
    float n;
    int count = 0;
    if (h == NULL)
    {
        cout << "Очередь пуста\n";
    }
    else
    {
        n = (*h)->info;
        while (h != NULL)
        {
            count++;
            if ((*h)->info > n) n = (*h)->info;
            if ((*h)->next == NULL) h = NULL;
            else h = &(*h)->next;
        }

        bool work = false;
        curSize2 = 0;
        h = begin;
        if ((*h)->info == n) return;
        while (h != NULL)
        {
            if ((*h)->info == n || work)
            {
                work = true;
                count--;
                create2(&newH, &newT, (*h)->info);
            }
            if ((*h)->next == NULL) h = NULL;
            else h = &(*h)->next;
        }

        h = begin;
        for (int i = 0; i < count; i++)
        {
            create2(&newH, &newT, (*h)->info);
            h = &(*h)->next;
        }
        *begin = newH;
        *end = newT;
    }
}



void createCH(CHAR** begin, CHAR** end, char p) //Формирование элементов очереди
{
    CHAR* t = new CHAR;
    t->next = NULL;
    if (*begin == NULL)
    {
        *begin = *end = t;
        t->info = p;
    }
    else
    {
        t->info = p;
        (*end)->next = t;
        *end = t;
    }
}

void task3()
{
    cout << "Содержимое текстового файла f, разделенное на строки, переписать в текстовый файл g, перенося при этом в конец каждой строки все входящие в нее цифры (с сохранением исходного взаимного порядка, как среди цифр, так и среди остальных ли-тер строки). Использовать очереди" << endl;
    char str[200];
    string A = "A.txt", B = "B.txt";
    ifstream fAin(A), fBin(B);
    ofstream fAout(A), fBout(B);
    string arr[] = { "ab12cd3e4fghi56jk", "12a34bc567de8", "123abc456" };
    CHAR* begin = NULL, * end = NULL;

    cout << size(arr) << endl;
    if (fAout.is_open())
    {
        for (int i = 0; i < size(arr); i++)
        {
            fAout << arr[i] << "\n";
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAout.close();
    CHAR* t = begin;
    if (fAin.is_open() && fBout.is_open())
    {
        while (!fAin.eof())
        {
            begin = NULL;
            end = NULL;
            fAin.getline(str, sizeof(str));
            if (fAin.eof() != 0) break;
            for (int i = 0; i < strlen(str); i++)
            {
                createCH(&begin, &end, str[i]);
            }

            t = begin;
            while (t != NULL)
            {
                if (t->info < '0' || t->info > '9') fBout << t->info;
                t = t->next;
            }

            t = begin;
            while (t != NULL)
            {
                if (t->info >= '0' && t->info <= '9') fBout << t->info;
                t = t->next;
            }
            fBout << "\n";
        }
    }
    else
    {
        cout << " Невозможно открыть файл!" << endl;
    }
    fAin.close();
    fBout.close();
}