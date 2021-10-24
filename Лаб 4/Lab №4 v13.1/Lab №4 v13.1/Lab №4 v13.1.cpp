#include <iostream>
#include<Windows.h>
#include<fstream>
#include<string>
using namespace std;
const int size = 10;

int N = 0;
struct country
{
	char name[20];
	char capital[30];
	char pop[20];
	char square[20];
	char secName[20];
}cou[20];
struct country bad;
void input() {
	if (N < 20)
	{
		cout << "Название Гос-ва: "; 	cin >> cou[N].name;
		cout << "Столица: "; 	cin >> cou[N].capital;
		cout << "Население: "; 	cin >> cou[N].pop;
		cout << "Площадь: "; 	cin >> cou[N].square;
		cout << "Фамилия президента: ";	cin >> cou[N].secName;
		cout << "\................................................................/" << endl;
		N++;
	}
	else
	{
		cout << " Введено максимальное кол-во строк" << endl;
	}
	
}
void output() {
	string search;
	cout << "Выберите название гос-ва(для вывода всех записей введите -1): "; cin >> search;
	if (search == "-1") {
		for (int s = 0; s < N; s++)
		{
			cout << "Название Гос-ва: " << cou[s].name << endl;
			cout << "Столица: " << cou[s].capital << endl;
			cout << "Население: " << cou[s].pop << endl;
			cout << "Площадь: " << cou[s].square << endl;
			cout << "Фамилия президента: " << cou[s].secName << endl;
			cout << "\................................................................/" << endl;
		}
	}
	else
	{
		for (int i = 0; i < N; i++)
		{
			if (cou[i].name==search)
			{
				cout << "Название Гос-ва: " << cou[i].name << endl;
				cout << "Столица: " << cou[i].capital << endl;
				cout << "Население: " << cou[i].pop << endl;
				cout << "Площадь: " << cou[i].square << endl;
				cout << "Фамилия президента: " << cou[i].secName << endl;
				cout << "\................................................................/" << endl;

			}
		}
	}


}
void del(int d)
{

	if (d == -1)
	{
		for (int i = 0; i < N; i++)
		{
			cou[i] = bad;
		}
		N = 0;
	}
	else
	{
		for (int i = d - 1; i < N; i++)
		{
			cou[i] = cou[i + 1];
		}
		N--;
	}

}

void write_file() {
	ofstream out;
	out.open("FILE.txt");
	for (int i = 0; i < N; i++)
	{
		out << cou[i].name << endl;
		out << cou[i].capital << endl;
		out << cou[i].pop << endl;
		out << cou[i].square << endl;
		out << cou[i].secName << endl;
		
	}
	out.close();
}
void read_file() {
	del(-1);
	char str2[200], str3[200], str4[200],str5[200];
	ifstream fAin("FILE.txt");
	if (fAin.is_open())
	{
		while (true)
		{
			fAin.getline(cou[N].name, sizeof(cou[N].name));
			fAin.getline(cou[N].capital, sizeof(cou[N].capital));
			fAin.getline(cou[N].pop, sizeof(cou[N].pop));
			fAin.getline(cou[N].square, sizeof(cou[N].square));
			fAin.getline(cou[N].secName, sizeof(cou[N].secName));
			if (fAin.eof() != 0) break;
		
			N++;
		}
	}
	else
	{
		cout << " Невозможно открыть файл!" << endl;
	}
	fAin.close();



	}

int main()
{
	setlocale(LC_ALL, "Russian");


	
	int choice;
	int d;

	do
	{
		cout << "Введите:" << endl;
		cout << "1-Для ввода структуры с клавиатуры" << endl;
		cout << "2-для вывода элеметв структуры в консольное окно" << endl;
		cout << "3-для удаления заданной структурированной переменной" << endl;
		cout << "4-для записи в файл" << endl;
		cout << "5-для чтения из файла" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:  input();	break;
		case 2:  output();  break;
		case 3:  cout << " Номер строки, которую надо удалить(для удаления всех строк введите -1): ";
			cin >> d;
			del(d);;  break;
		case 4:  write_file();	break;
		case 5:  read_file();	break;
		}
	} while (choice != 0);




}

