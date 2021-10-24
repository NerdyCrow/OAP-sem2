


#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#define str_len 20
#define size 30
void inputdata();
void searchdate();
void output(int i);
void outputdata();
void deleted();
using namespace std;
union gosud
{
	char fio1[str_len];
	char stol[str_len];
	int ch;
	int pl;
	char fam[str_len];
}un;
union gosud gos[str_len];

struct country
{
	string fio1;
	string stol;
	int ch;
	int pl;
	string fam;
}cou[str_len];
struct country clearstroke;
int choise;
int current_sized = 0;
char c = '-', space = ' ';
int main() //основная функция меню
{
	do
	{
		setlocale(LC_CTYPE, "Russian");
		cout << setw(120) << setfill(c) << c << endl;
		cout << "|" << setw(11) << setfill(space) << space;
		cout << "|| 1 ||Ввод данных ." << endl;
		cout << "|" << setw(11) << setfill(space) << space;
		cout << "|| 2 ||Выбор по государству." << endl;
		cout << "|" << setw(11) << setfill(space) << space;
		cout << "|| 3 ||Вывод всех данных на экран." << endl;
		cout << "|" << setw(11) << setfill(space) << space;
		cout << "|| 4 ||Удаление записи по номеру." << endl;
		cout << "|" << setw(11) << setfill(space) << space;
		cout << "|| 0 ||Выход из программы." << endl;
		cout << "|" << setw(11) << setfill(space) << space;
		cout << "Выберите функцию:"; cin >> choise;
		cout << setw(120) << setfill(c) << c << endl;
		switch (choise)
		{
		case 1: inputdata();
			break;
		case 2: searchdate();
			break;
		case 3: outputdata();
			break;
		case 4: deleted();
			break;
		case 0:
			break;
		}
	} while (choise != 0);
}
void inputdata()
{
	cout << "Введите иформацию о человеке:" << endl;
	if (current_sized < size)
	{
		cout << "|| Номер записи: " << current_sized + 1 << endl;
		cout << "|| Название государтсва: "; cin >> un.fio1;
		cou[current_sized].fio1 = un.fio1;

	
		cout << "|| Столица: "; cin >>un.stol;
		cou[current_sized].stol = un.stol;
		cout << "|| Численность населения: "; cin >>un.ch;
		cou[current_sized].ch = un.ch;
		cout << "|| Площадь: "; cin >> un.pl;
		cou[current_sized].pl = un.pl;
		cout << "|| Фамилия президента: "; cin >> un.fam;
		cou[current_sized].fam = un.fam;
		current_sized++;
	}
	else
	{
		cout << "Введено максимальное число строк.";
		main();
	}
}
void outputdata()
{
	int sw, i;
	cout << "|| 1 ||Вывод 1-ой записи." << endl;
	cout << "|| 2 ||Вывод высех записей." << endl;
	cin >> sw;
	if (sw == 1)
	{
		cout << setw(120) << setfill(c) << c << endl;
		cout << "|| Введите номер записи: ";
		cin >> i;
		cout << setw(120) << setfill(c) << c << endl;
		cout << "|| Запись: " << i << endl;
		cout << "|| Название государтсва: " << cou[i - 1].fio1 << ' ' <<  endl;
		cout << "|| Столица: " << cou[i - 1].stol<< endl;
		cout << "|| Численность населения: " << cou[i - 1].ch<< endl;
		cout << "|| Фамилия президента: " << cou[i - 1].fam << endl;
	}
	if (sw == 2)
	{
		for (int i = 0; i < current_sized; i++)
		{
			cout << "\n|| Номер записи: " << i + 1 << endl;
			cout << "|| Название государства: " << cou[i].fio1 << ' '<< endl;
			cout << "|| Столица: " << cou[i].stol << endl;
			cout << "|| Численность населения " << cou[i].ch <<' ' << endl;
			cout << "|| Фамилия президента: " << cou[i].fam << endl;
		}
	}
}

void searchdate()
{
	char a[20];
	cout << "|| Введите название государтсва" << endl;
	cin >> a;
	for (int i = 0; i < size; i++)
	{
		if ( cou[i].fio1==a)
		{

			cout << "|| Номер записи: " << i + 1 << endl;
			cout << "|| Название государства: " << cou[i].fio1 << endl;
			cout << "|| Столица: " << cou[i].stol << endl;
			cout << "|| Численность населения: " << cou[i].ch << endl;
			cout << "|| Фамилия президента: " << cou[i].fam << endl;
		}
	}
}
void deleted()
{
	int d;
	cout << "\n|| Укажите номер строки для удаления:" << endl;
	cin >> d;
	if (d != 99)
	{
		for (int delet1 = (d - 1); delet1 < current_sized; delet1++)
		{
			cou[delet1] = cou[delet1 + 1];
			current_sized = current_sized - 1;
		}
	}
	if (d == 99)
	{
		for (int i = 0; i < size; i++)
		{
			cou[i] = clearstroke;
			current_sized = 0;
		}
	}
}

