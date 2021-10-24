#include "stdafx.h"

void var12() {
	bool work = true;
	CHAR* begin = NULL, * end=NULL;

    char p;
    int choice = 0;

    cout << "\n������� ������ ������� = ";
    cin >> maxSize;

    while (work)
    {
        cout << "\n1. ���������� ������� \n2. ����� ������� � �� �������\n3. �������� ��������\n4. ������� 12\n0. �����\n(������� �����) " << endl;
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "������� ������: ";
            cin >> p;
            create(&begin, &end, p);
            break;
        case 2:
            view(begin);
            break;
        case 3:
            cout << "������� ������: ";
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

void create(CHAR** begin, CHAR** end, char p) //������������ ��������� �������
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
        cout << "������� ���������!" << endl;
    }
}
void view(CHAR* begin) //����� ��������� ������� 
{
    CHAR* t = begin;
    int size = amount(t);

    if (t == NULL)
    {
        cout << "������� �����\n";
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
    cout << "������ �������: " << size<<endl;
}

void Delete(CHAR** begin, CHAR** end, char p) //�������� �� ������������ �������� 
{
    CHAR** prev = begin, ** cur = &(*begin)->next;
    if (prev == NULL)
    {
        cout << "������� �����\n";
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
    cout << endl << "������� ����� ������: ";
    cin >> letter;
    cout << endl;
    CHAR* t = begin;
    CHAR* hz = end;
    int num = amount(t);
    if (t == NULL)
    {
        cout << "��������� �������\n";
    }
    else
    {
       
        t = begin;
        hz = end;
        char max = hz->info;
        if (max==letter)
        {
            cout << endl << "��������� ������ ��������� � ������ " << endl;            
            Delete(&begin, &end, 1);
        }
        else
        {
            cout << endl << "��������� ������ �� ��������� � ������(" << endl;
        }
       /* while (t != NULL)
        {
            if (t->info > max) max = t->info;
            t = t->next;
        }
        cout << "\n������������ ������� �������: " << max << endl;

        t = begin;
        while (t != NULL)
        {
            cout << t->info << " --> ";
            num--;
            if (t->info == 0) break;
            t = t->next;
        }
        cout << "\n������ ���������� �������: " << num << endl;*/
    }
}