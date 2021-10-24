#include <iostream>         
#include <string>
#include <fstream>
using namespace std;

#define sizeS 30  
string A = "A.txt";
char str[512];

struct Students
{
	char name[30];
	int amount_exams;
	int* marks = new int[amount_exams];
};
struct Students LS[sizeS], frS;
int st_size = 0;

void input();
void del_st(int d);
void out_st();
void writeF();
void readF();
void success();



int main()
{
	
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");
	int choice = 1;
	int d;
	while (choice != 0)
	{
		cout << " \n1) Новая запись\n2) Удалить запись\n3) Вывод записи\n4) Запись в файл\n5) Чтение из файла\n6) Успеваемость\n0) Выход\nВыберите: ";
		cin >> choice;
		switch (choice)
		{
		case(1):
			input();
			break;

		case(2):
		
			cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del_st(d);
			break;

		case(3):
			out_st();
			break;

		case(4):
			writeF();
			break;
		case(5):
			readF();
				break;

		case(6):
			success();
			break;

		default:
			break;
		}
	}
	
	
	
}

//
//void extraTask1()
//{
//	int choice = 1;
//
//	while (choice != 0)
//	{
//		cout << " \n1. Новая запись\n2. Удалить запись\n3. Вывести запись в консоль\n4. Запись в файл\n5. Чтение из файла\n6. Успеваемость\n0. Завершить работу\n(Введите выбор) ";
//		cin >> choice;
//		switch (choice)
//		{
//		case(1):
//			input();
//			break;
//
//		case(2):
//			del_st();
//			break;
//
//		case(3):
//			out_st();
//			break;
//
//		case(4):
//			writeF();
//			break;
//
//		/*case(5):
//			read_file();
//			break;*/
//
//		case(6):
//			success();
//			break;
//
//		default:
//			break;
//		}
//	}
//}

void input()
{
	if (st_size < sizeS)
	{
		cout << " Введите данные(ФИО студента, число экзаменов, полученные оценки): \n Запись №" << st_size + 1 << ": ";
		cin >> LS[st_size].name >> LS[st_size].amount_exams;
		for (int i = 0; i < LS[st_size].amount_exams; i++)
		{
			cin >> LS[st_size].marks[i];
		}
		st_size++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
}

void del_st(int d)
{
	
	if (d == -1)
	{
		for (int i = 0; i < sizeS; i++)
		{
			LS[i] = frS;
		}
		st_size = 0;
	}
	else
	{
		for (int i = d - 1; i < st_size; i++)
		{
			LS[i] = LS[i + 1];
		}
		st_size--;
	}
}

void out_st()
{
	string name, num;
	cout << " Введите фамилию для поиска записи(для вывода всех записей введите 1): ";
	cin >> name;
	if (name == "1")
	{
		for (int i = 0; i < st_size; i++)
		{
			cout << " Запись №" << i + 1 << " \n Фамилия - " << LS[i].name << " \n кол-во экзаменов - " << LS[i].amount_exams;
			for (int j = 0; j < LS[i].amount_exams; j++)
			{
				cout << " \n отметка за " << j + 1 << "-й экзамен - " << LS[i].marks[j];
			}
			cout << endl;
		}
	}
	else
	{
		for (int i = 0; i < st_size; i++)
		{
			if (LS[i].name == name)
			{
				cout << " Запись №" << i + 1 << " \n Фамилия - " << LS[i].name << " \n кол-во экзаменов - " << LS[i].amount_exams;
				for (int j = 0; j < LS[i].amount_exams; j++)
				{
					cout << " \n отметка за " << j + 1 << "-й экзамен - " << LS[i].marks[j];
				}
				cout << endl;
			}
		}
	}
}

void writeF()
{

	ofstream fAout(A);
	if (fAout.is_open())
	{
		for (int i = 0; i < st_size; i++)
		{
			fAout << LS[i].name << "\n";
			fAout << LS[i].amount_exams << "\n";
			for (int j = 0; j < LS[i].amount_exams; j++)
			{
				fAout << LS[i].marks[j] << "\n";
			}
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAout.close();
}
void readF() {
	del_st(-1);
	char str2[200], str3[200];
	ifstream fAin(A);
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(LS[st_size].name, sizeof(LS[st_size].name));
			fAin.getline(str2, sizeof(str2));
			if (fAin.eof() != 0) break;
			LS[st_size].amount_exams = atoi(str2);
			for (int i = 0; i < LS[st_size].amount_exams; i++)
			{
				fAin.getline(str2, sizeof(str2));
				LS[st_size].marks[i] = atoi(str2);
			}
			st_size++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();
}

void success()
{
	float num = 0;
	for (int i = 0; i < st_size; i++)
	{
		for (int j = 0; j < LS[i].amount_exams; j++)
		{
			if (LS[i].marks[j] < 4) break;
			if (j == LS[i].amount_exams - 1) num++;
		}
	}
	cout << "Процент студентов = " << num / st_size * 100 << "%" << endl;
}

