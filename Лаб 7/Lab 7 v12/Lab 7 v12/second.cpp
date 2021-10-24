#include "stdafx.h"
string A = "A.txt";
char str[100];
int numOfnumber;
int z = 0, m = 0;
int* arr = new int[0];
int* arr2 = new int[0];
int* arr3 = new int[0];
void fun(int*& arr, int x)
{
	int* temp = new int[_msize(arr) / 4 + 1];
	for (size_t i = 0; i < _msize(arr) / 4; i++)
	{
		temp[i] = arr[i];
	}
	temp[_msize(arr) / 4] = x;
	delete[]arr;
	arr = temp;
}
bool extract(Stack1** s1)
{
	Stack1* st1 = *s1;
	if (st1 != NULL)
	{
		*s1 = st1->next;
		free(st1);
	}
	else return 0;

	return 1;
}
void Add1(Stack1** s1, int D) {
	Stack1* st1 = new Stack1();

	fun(arr, D);
	st1->data = D;

	if (st1==NULL)
	{
		*s1 = st1;
	}
	else
	{
		st1->next = *s1;
		*s1 = st1;
	}
}
void Add2(Stack2** s2, int D) {
	Stack2* st2 = new Stack2();
	st2->data = D;
	if (st2==NULL)
	{
		*s2 = st2;
	}
	else
	{
		st2->next = *s2;
		*s2 = st2;
	}
}
void delete_key(Stack1** s1, int N)
{
	Stack1* st1 = *s1;
	Stack1* prev = NULL;
	while (st1 != NULL)
	{
		if (st1->data == N)
		{
			if (st1 == *s1)
			{

				*s1 = st1->next;
				free(st1);
				st1->data = NULL;
				st1->next = NULL;
			}
			else
			{
				prev->next = st1->next;
				free(st1);
				st1->data = NULL;
				st1->next = NULL;
			}
		}
		prev = st1;
		st1 = st1->next;
	}
}
void Add3(Stack3** s3, int D) {
	Stack3* st3 = new Stack3();
	st3->data = D;
	if (st3 == NULL)
	{
		*s3 = st3;
	}
	else
	{
		st3->next = *s3;
		*s3 = st3;
	}
}
void Show1(Stack1*s1) {
	Stack1* st1 = s1;
	while (st1)
	{
		cout << st1->data << "-->";
		st1 = st1->next;
	}
	cout << "NULL" << endl;
}
void create(Stack1** s1) {
	for (int i = 0; i < _msize(arr)/4; i++)
	{
		if (arr[i]%2==0)
		{
			fun(arr2, arr[i]);
		}
		else
		{
			fun(arr3, arr[i]);
		}
	}
}
void Show2(Stack2*s2) {
	for (size_t i = 0; i < _msize(arr2) / 4; i++)
	{
		Add2(&s2, arr2[i]);
	}
	Stack2* st2 = s2;
	while (st2)
	{
		cout << st2->data << "-->";
		st2 = st2->next;
	}
	cout << "NULL" << endl;
}
void Show3(Stack3* s3) {
	for (size_t i = 0; i < _msize(arr3) / 4; i++)
	{
		Add3(&s3, arr3[i]);
	}
	Stack3* st3 = s3;
	while (st3)
	{
		cout << st3->data << "-->";
		st3 = st3->next;
	}
	cout << "NULL" << endl;
}

void toFile(Stack1* s1)
{
	numOfnumber = 0;
	ofstream fAout(A);
	if (fAout.is_open())
	{
		if (s1 == NULL)
		{
			fAout << "Список пуст" << endl;
		}
		else
		{
			while (s1 != NULL)
			{
				fAout << s1->data << endl;
				numOfnumber++;
				s1 = s1->next;
			}
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}
void clear(Stack1** s1)
{
	while (extract(s1));
}
void fromFile(Stack1** s1)
{
	int* arr = new int[numOfnumber], n;
	ifstream fAin(A);
	if (fAin.is_open())
	{
		clear(s1);
		for (int i = 0; i < numOfnumber; i++)
		{
			fAin.getline(str, sizeof(str));
			arr[i] = atoi(str);
		}
		for (int i = numOfnumber - 1; i >= 0; i--)
		{
			Add1(s1, arr[i]);
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
	delete[] arr;
}

int menu2()
{
	int n;
	cout << "************************************************************" << endl;
	cout << "1 - Добавление в главный стек" << endl;	
	cout << "2 - Удаление числа "<<endl;
	cout << "3 - Вывод главного стека" << endl;
	cout << "4 - Задание" << endl;
	cout << "5 - Вывод Stack1" << endl;
	cout << "6 - Вывод Stack2" << endl;
	cout << "7 - Запись главного стека в файл" << endl;
	cout << "8 - Чтение главного стека из файла" << endl;
	cout << "9 - очистка стека" << endl;
	cout << "10 - Выход" << endl;
	cin >> n;
	cout << endl;
	return n;
}


