#include  <windows.h>
#include <iostream>
#include<fstream>
#include <string>
using namespace std;
enum room
{
	ONE_PERSON = 1,
	TWO_PERSON,
	THREE_PERSON,
	APARTAMENTS,
	LUKS
};
union Utypes
{
	int passport;
	char nomer[50];
	
		 int day;
		 int month;
		 int year;
	

}mun;
struct hotel
{
	int passport;
	string nomer;
	struct hot {
		int day;
		 int month;
		 int year;
	}zacelen, pribitye;
}a[2];
void input()
{
	int b;
	int d;
	int m;
	int y;
	for (int i = 0; i < 2; i++)
	{
		cout << "Гость номер:" << i + 1 << endl;
		cout << "Паспортные данные: ";
		cin >> mun.passport;
		a[i].passport = mun.passport;
		cout << "Введите день:" << endl;
		cin >> mun.day;

		a[i].zacelen.day = mun.day;
		cout << "Введите месяц:" << endl;
		cin>>mun.month;
		
		a[i].zacelen.month = mun.month;
		cout << "Введите год:" << endl;

		cin >> mun.year;
		a[i].zacelen.year = mun.year;
		cout << "Дата приезда: ";
		cout << a[i].zacelen.day;
		cout << ".";
		cout << a[i].zacelen.month;
		cout << ".";
		cout << a[i].zacelen.year << endl;
		cout << "Введите день:" << endl;
		cin >> mun.day;

		a[i].pribitye.day = mun.day;
		cout << "Введите месяц:" << endl;
		cin >> mun.month;

		a[i].pribitye.month = mun.month;
		cout << "Введите год:" << endl;
		cin >> mun.year;
		a[i].pribitye.year = mun.year;
		cout << "Дата отъезда: ";
		cout << a[i].pribitye.day;
		cout << ".";
		cout << a[i].pribitye.month;
		cout << ".";
		cout << a[i].pribitye.year << endl;
		cout << "Введите значения(1-ONE_PERSON,2-TWO_PERSON,3-THREE_PERSON,4-APARTAMENTS,5-LUKS):" << endl;
		cin >> b;
		cout << "Тип номера: ";
		switch (b)
		{
		case 1:a[i].nomer = "ONE_PERSON"; cout << "ONE_PERSON" << endl; break;
		case 2:a[i].nomer = "TWO_PERSON"; cout << "TWO_PERSON" << endl; break;
		case 3:a[i].nomer = "THREE_PERSON"; cout << "THREE_PERSON" << endl; break;
		case 4:a[i].nomer = "APARTAMENTS"; cout << "APARTAMENTS" << endl; break;
		case 5:a[i].nomer = "LUKS"; cout << "LUKS" << endl; break;
		}
		cout << "  " << endl;
		cout << "  " << endl;
	}
}
void del()
{
	int i;
	cin >> i;
	int c;
	cin >> c;
	switch (c)
	{
	case 1:a[i].passport = 0; break;
	case 2:a[i].zacelen.day = 0;
		a[i].zacelen.month = 0;
		a[i].zacelen.year = 0;
		break;
	case 3:a[i].pribitye.day = 0;
		a[i].pribitye.month = 0;
		a[i].pribitye.year = 0;
		break;
	}
}
void search()
{
	int y;
	int r;
	int z;
	cin >> y;
	cin >> r;
	cin >> z;
	for (int i = 0; i < 2; i++)
	{
		if (a[i].zacelen.day == y and a[i].zacelen.month == r and a[i].zacelen.year == z)
		{
			cout << "Гость номер:" << i + 1 << endl;
			cout << "Паспортные данные: ";
			cout << a[i].passport << endl;
			cout << "Дата приезда: ";
			cout << a[i].zacelen.day;
			cout << ".";
			cout << a[i].zacelen.month;
			cout << ".";
			cout << a[i].zacelen.year << endl;
			cout << "Дата отъезда: ";
			cout << a[i].pribitye.day;
			cout << ".";
			cout << a[i].pribitye.month;
			cout << ".";
			cout << a[i].pribitye.year << endl;
			cout << "Тип номера: ";
			cout << a[i].nomer << endl;
			cout << "  " << endl;
			cout << "  " << endl;
		}
	}
}
void vivod()
{
	int i;
	cin >> i;
	int q;
	cin >> q;
	for (; i < q; i++)
	{
		cout << "Гость номер:" << i + 1 << endl;
		cout << "Паспортные данные: ";
		cout << a[i].passport << endl;
		cout << "Дата приезда: ";
		cout << a[i].zacelen.day;
		cout << ".";
		cout << a[i].zacelen.month;
		cout << ".";
		cout << a[i].zacelen.year << endl;
		cout << "Дата отъезда: ";
		cout << a[i].pribitye.day;
		cout << ".";
		cout << a[i].pribitye.month;
		cout << ".";
		cout << a[i].pribitye.year << endl;
		cout << "Тип номера: ";
		cout << a[i].nomer << endl;
		cout << "  " << endl;
		cout << "  " << endl;
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int x;
	do
	{
		cout << "1. Ввести данные" << endl;
		cout << "2. Удалить данные" << endl;
		cout << "3. Поиск информации" << endl;
		cout << "4. Вывести что-нибудь" << endl;
		cout << "5. Выход" << endl;
		cout << "Выберите команду: ";
		cin >> x;
		switch (x)
		{
		case 1: input(); break;
		case 2: del(); break;
		case 3: search(); break;
		case 4: vivod(); break;
		case 5:return 0; break;
		}
	} while (x > 0);
}