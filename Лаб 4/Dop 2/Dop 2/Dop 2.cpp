#include <iostream>         
#include <string>
#include <fstream>
using namespace std;

#define str_len 30                               
#define sizeS 30  
#define trLen 8
string A = "FILE.txt";
char str[512];



struct Trains
{
	char name[str_len];
	int num;
	int time;
};





struct Trains LS_tr[trLen], train2, train1;
int csize = 0;






void extraTask2();
void input();
void del(int d);
void out();
void writeF();
void readF();
void sort();



int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	bool work = true;
	int n;
	int d;
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1) Создать запись\n2) Удалить запись\n3) Вывод записи\n4) Запись в файл\n5) Чтение из файла\n) Сортировка\n0) Выход\n(Выберите:) ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			input();
			break;

		case(2):
			cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del(d);
			break;

		case(3):
			out();
			break;

		case(4):
			writeF();
			break;

		case(5):
			readF();
			break;

		case(6):
			sort();
			break;

		default:
			break;
		}
	}
}

void input()
{
	if (csize < trLen)
	{
		cout << " Введите данные(названия пункта назначения, номер поезда, время отправления): \n Запись №" << csize + 1 << ": ";
		cin >> LS_tr[csize].name >> LS_tr[csize].num >> LS_tr[csize].time;
		csize++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del(int d)
{
	if (d == -1)
	{
		for (int i = 0; i < 8; i++)
		{
			LS_tr[i] = train2;
		}
		csize = 0;
	}
	else
	{
		for (int i = d - 1; i < csize; i++)
		{
			LS_tr[i] = LS_tr[i + 1];
		}
		csize--;
	}
}

void out()
{
	int t, q = 0;
	cout << "Введите время(-1 для вывода всех записей): ";
	cin >> t;
	for (int i = 0; i < csize; i++)
	{
		if (LS_tr[i].time >= t)
		{
			cout << " Запись №" << i + 1 << " \n названия пункта назначения - " << LS_tr[i].name << " \nномер поезда - " << LS_tr[i].num << " \n время отправления - " << LS_tr[i].time << endl;
			q++;
		}
	}
	if (q == 0) cout << "Поездов нет" << endl;
}


	

void writeF()
{
	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < csize; i++)
		{
			fAout << LS_tr[i].name << endl;;
			fAout << LS_tr[i].num << endl;;
			fAout << LS_tr[i].time << endl;;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}
void readF(){
	del(-1);
	char str2[200], str3[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(LS_tr[csize].name, sizeof(LS_tr[csize].name));
			fAin.getline(str2, sizeof(str2));
			fAin.getline(str3, sizeof(str3));
			if (fAin.eof() != 0) break;
			LS_tr[csize].num = atoi(str2);
			LS_tr[csize].time = atoi(str3);
			csize++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}

void sort()
{
	int q, i;
	for (i = 0; i < csize - 1; i++)
	{
		q = (strlen(LS_tr[i].name) > strlen(LS_tr[i + 1].name)) ? strlen(LS_tr[i + 1].name) : strlen(LS_tr[i].name);
		for (int j = 0; j < q; j++)
		{
			if (LS_tr[i].name[j] < LS_tr[i + 1].name[j]) break;
			if (LS_tr[i].name[j] > LS_tr[i + 1].name[j])
			{
				train1 = LS_tr[i + 1];
				LS_tr[i + 1] = LS_tr[i];
				LS_tr[i] = train1;
				i = -1;
				break;
			}
		}
	}
}

