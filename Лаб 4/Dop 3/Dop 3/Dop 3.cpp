#include <iostream>         
#include <string>
#include <fstream>
using namespace std;

#define str_len 30                               
#define sizeS 30  
#define trains_len 8
string A = "FILE.txt";
char str[512];





struct Sanatorium
{
	char name[str_len];
	char location[str_len];
	char profile[str_len];
	int amount;
};



struct Sanatorium LS_SN[sizeS], dost, HSN;
int SIZE_SN = 0;



void input();
void del(int d);
void out();
void writeF();
void readF();
void sort();

int main()
{
	int d;
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	bool work = true;
	int n;
	int choice = 1;

	while (choice != 0)
	{
		cout << " \n1) Новая запись\n2. Удалить запись\n3) Вывести запись в консоль\n4) Запись в файл\n5. Чтение из файла\n6) Сортировка\n0) Выход\nВвОд ";
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
	if (SIZE_SN < sizeS)
	{
		cout << " Введите данные(Название санатория, Место расположения, Лечебный профиль, Количество путевок): \n Запись №" << SIZE_SN + 1 << ": ";
		cin >> LS_SN[SIZE_SN].name >> LS_SN[SIZE_SN].location >> LS_SN[SIZE_SN].profile >> LS_SN[SIZE_SN].amount;
		SIZE_SN++;
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
		for (int i = 0; i < sizeS; i++)
		{
			LS_SN[i] = dost;
		}
		SIZE_SN = 0;
	}
	else
	{
		for (int i = d - 1; i < SIZE_SN; i++)
		{
			LS_SN[i] = LS_SN[i + 1];
		}
		SIZE_SN--;
	}
}

void out()
{
	string name, num;
	cout << " Введите название санатория для поиска записи(для вывода всех записей введите 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < SIZE_SN; i++)
		{
			cout << " Запись №" << i + 1 << " \n название санатория - " << LS_SN[i].name << " \n место расположения - " << LS_SN[i].location << " \n лечебный профиль - " << LS_SN[i].profile << " \n кол-во путёвок - " << LS_SN[i].amount << endl;
		}
	}
	else
	{
		for (int i = 0; i < SIZE_SN; i++)
		{
			if (LS_SN[i].name == name)
			{
				cout << " Запись №" << i + 1 << " \n название санатория - " << LS_SN[i].name << " \n место расположения - " << LS_SN[i].location << " \n лечебный профиль - " << LS_SN[i].profile << " \n кол-во путёвок - " << LS_SN[i].amount << endl;
			}
		}
	}
}

void writeF()
{
	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < SIZE_SN; i++)
		{
			fAout << LS_SN[i].name << endl;
			fAout << LS_SN[i].location << endl;
			fAout << LS_SN[i].profile << endl;
			fAout << LS_SN[i].amount << endl;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}
void readF() {
	del(-1);
	char str4[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(LS_SN[SIZE_SN].name, sizeof(LS_SN[SIZE_SN].name));
			fAin.getline(LS_SN[SIZE_SN].location, sizeof(LS_SN[SIZE_SN].location));
			fAin.getline(LS_SN[SIZE_SN].profile, sizeof(LS_SN[SIZE_SN].profile));
			fAin.getline(str4, sizeof(str4));
			if (fAin.eof() != 0) break;
			LS_SN[SIZE_SN].amount = atoi(str4);
			SIZE_SN++;
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
	int q, n;
	for (int i = 0; i < SIZE_SN - 1; i++)
	{
		q = (strlen(LS_SN[i].profile) > strlen(LS_SN[i + 1].profile)) ? strlen(LS_SN[i + 1].profile) : strlen(LS_SN[i].profile);
		for (int j = 0; j < q; j++)
		{
			if (LS_SN[i].profile[j] < LS_SN[i + 1].profile[j]) break;
			if (LS_SN[i].profile[j] > LS_SN[i + 1].profile[j])
			{
				HSN = LS_SN[i + 1];
				LS_SN[i + 1] = LS_SN[i];
				LS_SN[i] = HSN;
				i = -1;
				break;
			}
		}
	}

	n = 0;
	for (int k = 0; k < SIZE_SN; k++)
	{
		if (LS_SN[k].profile != LS_SN[k + 1].profile)
		{
			for (int i = n; i < k; i++)
			{
				q = (strlen(LS_SN[i].name) > strlen(LS_SN[i + 1].name)) ? strlen(LS_SN[i + 1].name) : strlen(LS_SN[i].name);
				for (int j = 0; j < q; j++)
				{
					if (LS_SN[i].name[j] < LS_SN[i + 1].name[j]) break;
					if (LS_SN[i].name[j] > LS_SN[i + 1].name[j])
					{
						HSN = LS_SN[i + 1];
						LS_SN[i + 1] = LS_SN[i];
						LS_SN[i] = HSN;
						i = -1;
						break;
					}
				}
			}
			n = k;
		}
	}
}