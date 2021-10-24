#include<iostream>
#include<fstream>
#include<string>

using namespace std;

#define size21 20


struct book {
	char f[50];
	char i[50];
	char o[50];
	char address[20];
	int phone;
	char work[20];
	char rank[20];

	struct Date {
		unsigned int day : 5;
		unsigned int mon : 5;
		unsigned int year : 12;
		}DT;
};
struct book b[20],dost;
int size2 = 0;



void input();
void del();
void out();
void writeF();
void readF();
void sort();

int main() {
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int choice = 1;
	
	while (choice != 0)
	{
		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n0. Завершить работу\nВвОд ";
		cin >> choice;
		
		switch (choice)
		{
		case(1):
			input();
			break;

		case(2):
			del();
			break;

		case(3):
			out();
			break;

		

		
		default:
			break;
		}
	}


}
void input()
{ 
	int d;
	int m;
	int y;


	if (size2 < 20)
	{
		cout << " Введите данные(Фамилия,Имя,Отчество,адрес,номер тлф,место работы, должность,день,месяц,год): \n Запись №" << size2 + 1 << ": ";
		cin >> b[size2].f;
		cin >> b[size2].i;
		cin >> b[size2].o;
		cin >> b[size2].address;
		cin >> b[size2].phone;
		cin >> b[size2].work;
		cin >> b[size2].rank;
		cin>> d >> m >> y;
		b[size2].DT.day = d;
		b[size2].DT.mon =m;
		b[size2].DT.year = y;		
		size2++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del() {
	int d;
	cout << "Номер строки, которую  хотите удалить(1 для удаления всех): ";
	cin >> d;
	d--;
	if (d == -2)
	{
		for (int i = 0; i < 20; i++)
		{
			b[i] = dost;
		}
		size2 = 0;
	}
	else
	{
		for (int i = d - 1; i < size2; i++)
		{
			b[i] = b[i + 1];
		}
		size2--;
	}
}

void out()
{
	string name, num;
	cout << " Введите фамилию для поиска записи(для вывода всех записей введите 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < size2; i++)
		{
			cout << " Запись №" << i + 1 << " \n Фамилия - " << b[i].f << " \n имя - " << b[i].i << " \n отчество - " << b[i].o << " \n ДР - " << b[i].DT.day << "." << b[i].DT.mon << "." << b[i].DT.year << " \n Адрес - " << b[i].address << " \n ТЛФ - " << b[i].phone << " \n Место работы - " << b[i].work << " \n Должность - " << b[i].rank << endl<<endl;
		}
	}
	else
	{
		for (int i = 0; i < size2; i++)
		{
			if (b[i].f == name)
			{
				cout << " Запись №" << i + 1 << " \n Фамилия - " << b[i].f << " \n имя - " << b[i].i << " \n отчество - " << b[i].o << " \n ДР - " << b[i].DT.day << "." << b[i].DT.mon << "." << b[i].DT.year << " \n Адрес - " << b[i].address << " \n ТЛФ - " << b[i].phone << " \n Место работы - " << b[i].work << " \n Должность - " << b[i].rank << endl<<endl;
			}
		}
	}
}
