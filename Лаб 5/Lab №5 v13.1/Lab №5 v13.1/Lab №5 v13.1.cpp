#include<iostream>
#include<fstream>
#include<string>
#include<cstring>

using namespace std;
enum Efacult { ХТИТ = 1, ЛИД, ТОВ, ФИТ }facult;

struct byte {
	unsigned date: 11;

};

struct stud{
	string  fio;
	char sredball[80];
	byte bits;
	string spec;
	string gruppa;
	string facult;
	string switchend;

};



int main()
{
	setlocale(0, "rus");
	byte bits;
	int type;
	const int size = 2;
	string s;
	string str;
	stud num[size];
	do
	{
		cout << " || 1 || Ввод данных в структуру " << endl;
		cout << " || 2 || Вывод элементов в консольное окно " << endl;
		cout << " || 3 || Удаление заданой структурированной переменной " << endl;
		cout << " || 4 || Поиск информации " << endl;
		cout << " || 5 || Запись в файл " << endl;
		cout << " || 6 || Чтение из файла " << endl;
		cout << " || 7 || Выход " << endl;
		cout << endl;
		cin >> type;
		switch (type)
		{
			/////////////////////////////
		case 1:
		{
			int d;
			for (int i = 0; i < size; i++)
			{
				cout << endl << " || FIO: " << i + 1 << ' ';
				cin >> num[i].fio;
				cout << endl << " || Дата поступления: ";
				cin >> d;
					num[i].bits.date=d;
				cout << endl << " || Специальность: ";
				cin >> num[i].spec;
				cout << endl << " || Группа: ";
				cin >> num[i].gruppa;
				cout << endl << " || Факультет: ";
				cin >> num[i].facult;
				cout << endl << " || Средний балл: ";
				cin >> num[i].sredball;
				cout << endl;

			}
			cout << endl;
			break;
		}
		/////////////////////////////
		case 2:
		{
			for (int i = 0; i < size; i++)
			{
				cout << " FIO: " << num[i].fio << endl;
				cout << " Дата поступления: " << num[i].bits.date << endl;
				cout << " Специальность: " << num[i].spec << endl;
				cout << " Группа : " << num[i].gruppa << endl;
				cout << " Факультет: " << num[i].facult << endl;
				cout << " Средний балл:: " << num[i].sredball << endl;
				cout << endl;
			}
			cout << endl;
			break;
		}
		////////////////////////////
		case 3:
		{
			char namedel[50];
			cout << " Введите FIO для удаления: ";
			getchar();
			cin.getline(namedel, 40);
			for (int i = 0; i < size; i++)
			{
				if (*num[i].sredball == *namedel)
				{
					*num[i].sredball = '\0';
					i++;
				}
				else break;
			}
			cout << endl;
			break;
		}
		////////////////////////////
		case 4:
		{
			char name[80];
			cout << " Введите средний балл "; cin >> name;
			for (int i = 0; i < size; i++)
			{
				if (strcmp(num[i].sredball, name) == 0)
				{
					cout << " FIO: " << num[i].fio << endl;
					cout << " Дата поступления: " << num[i].bits.date << endl;
					cout << " Специальность: " << num[i].spec << endl;
					cout << " Группа : " << num[i].gruppa << endl;
					cout << " Факультет: " << num[i].facult << endl;
					cout << " Средний балл:: " << num[i].sredball << endl;
					cout << endl;
				}
			}
			cout << endl;
			break;
		}
		////////////////////////////
		case 5:
		{
			ofstream file("file.txt");
			for (int i = 0; i < size; i++)
			{
				file << num[i].fio << ' ' << num[i].bits.date << ' ' << num[i].spec << ' ' << num[i].gruppa << ' ' << num[i].facult << num[i].sredball << ' ' << endl;
			}
			file.close();
			cout << endl;
			break;
		}
		///////////////////////////
		case 6:
		{
			ifstream fileA("file.txt");
			while (!fileA.eof())
			{
				getline(fileA, str);
				cout << str << endl;
			}
			fileA.close();
			cout << endl;
			break;
		}
		case 7: { break; };
		}
	} while (type != 7);
}


