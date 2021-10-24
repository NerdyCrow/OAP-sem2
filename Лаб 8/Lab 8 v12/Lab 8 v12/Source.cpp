#include "stdafx.h"

void var12() {
	bool work = true;
	CHAR* begin = NULL, * end=NULL;

    char p;
    int choice = 0;

    cout << "\nВведите размер очереди = ";
    cin >> maxSize;

    while (work)
    {
        cout << "\n1. Заполнение очереди \n2. Вывод очереди и ее размера\n3. Удаление элемента\n4. Вариант 12\n0. Вызод\n(Введите выбор) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Введите символ: ";
            cin >> p;
            create(&begin, &end, p);
            break;
        case 2:
            view(begin);
            break;
        case 3:
            cout << "Введите символ: ";
            cin >> p;
            Delete(&begin, &end, p);
            break;
        case 4:
            task(begin,end);
            break;
        case 0:
            work = false;
            break;
        default:
            break;
        }
    }
}

void create(CHAR** begin, CHAR** end, char p) //Формирование элементов очереди
{
    if (curSize != maxSize)
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
        curSize++;
    }
    else
    {
        cout << "Очередь заполнена!" << endl;
    }
}
void view(CHAR* begin) //Вывод элементов очереди 
{
    CHAR* t = begin;
    int size = amount(t);

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
        cout << "NULL"<<endl;
    }
    cout << "Размер очереди: " << size<<endl;
}

void Delete(CHAR** begin, CHAR** end, char p) //Удаление до минимального элемента 
{
    CHAR** prev = begin, ** cur = &(*begin)->next;
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

int amount(CHAR* begin)
{
    int x = 0;
    CHAR* t = begin;
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

void task(CHAR* begin,CHAR* end)
{
    char letter;
    cout << endl << "Введите любой символ: ";
    cin >> letter;
    cout << endl;
    CHAR* t = begin;
    CHAR* hz = end;
    int num = amount(t);
    if (t == NULL)
    {
        cout << "Заполните очередь\n";
    }
    else
    {
       
        t = begin;
        hz = end;
        char max = hz->info;
        if (max==letter)
        {
            cout << endl << "Введенный символ совпадает с первым " << endl;            
            Delete(&begin, &end, 1);
        }
        else
        {
            cout << endl << "Введенный символ не совпадает с первым(" << endl;
        }
       /* while (t != NULL)
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
        cout << "\nРазмер оставшейся очереди: " << num << endl;*/
    }
}