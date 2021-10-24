#include <iostream>
using namespace std;

struct  Node
{
    int x;
    Node* Next;
};

struct List
{
    Node* Head, * Tail; 
    int size; 
    List() :Head(NULL), Tail(NULL), size(0) {};
    void Add(int x); 
    bool del(int k);   
    void Show(int size); 
    int Count(); 
};


int List::Count()
{
    return size; 
}

void List::Add(int x)
{
    size++; 
    Node* temp = new Node; 
    temp->Next = Head; 
    temp->x = x; 

    if (Head != NULL) 
    {
        Tail->Next = temp; 
        Tail = temp; 
    }
    else Head = Tail = temp;
}

bool List::del(int k) 
{
    Node* temp = Tail;
    if (Head == NULL) {
        cout << "Список пуст" << endl;
        return false;
    }
    while (Head != Tail)
    {
        for (int i = 1; i < k; i++)
            temp = temp->Next;
        Node* buf = temp->Next;
        cout << buf->x << " ";
        if (buf == Head) Head = buf->Next;
        if (buf == Tail) Tail = temp;
        temp->Next = buf->Next;
        delete buf;
    }
    return true;
}

void List::Show(int temp)
{
    Node* tempHead = Head; 

    temp = size; 
    while (temp != 0) 
    {
        cout << tempHead->x << " "; 
        tempHead = tempHead->Next; 
        temp--; 
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int n, k;
    List lst;
    cout << "Введите кол-во элементов в списке" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        lst.Add(i);
    }
    cout << "Список:" << endl;
    lst.Show(lst.Count());  
    cout << endl;
    cout << "Введите k:" << endl;
    cin >> k;
    lst.del(k);
    cout << endl;
}