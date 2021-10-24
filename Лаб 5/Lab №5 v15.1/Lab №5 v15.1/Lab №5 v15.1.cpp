/*Справочник абитуриента. Наименование вуза, адрес, перечень специальностей, конкурс прошлого года
по каждой специальности, размер оплаты при договорном обучении. Выбор по минимальному конкурсу.
Кон-курс прошлого года по каждой специальности реализовать через битовые поля, перечень специальностей  через перечисления.*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <strstream>
#include <sstream>

using namespace std;


// идентификация специальностей
enum Specialists
{
	POIT = 1, ISIT, POIBS, DEVI
} specman;

// университет
struct Universaty
{
	string name;
	string adress;
	vector<int>ball;
};

// чтение файла
void readingInfoFromFile(Universaty unik[])
{
	int SIZE = 3;
	ifstream fin("unikInfo.txt");

	if (!fin.is_open()) {
		cout << "Не удаётся открыть файл для чтения " << endl;
		exit(EXIT_FAILURE);
	}

	vector<string> fileinfo;
	string line, word;
	stringstream x;
	for (int i = 0; i < SIZE; ++i) {
		getline(fin, line);
		x << line;
		while (x >> word)
		{
			fileinfo.push_back(word);
		}
		for (int k = 0; k < fileinfo.size(); k++)
		{
			if (k == 0) { unik[i].name = fileinfo[k]; }
			if (k == 1) { unik[i].adress = fileinfo[k]; }
			if (k > 1) {
				istringstream iss(fileinfo[k], istringstream::in);

				int val;
				iss >> val;
				unik[i].ball.push_back(val);
				//unik[i].ball.push_back(fileinfo[k]);
			}
		}
		x.clear();
		line.clear();
		word.clear();
		fileinfo.clear();
	}
}


//байты считаем
struct byte
{
	unsigned a : 1;
	unsigned b : 1;
	unsigned c : 1;
	unsigned d : 1;
	unsigned e : 1;
	unsigned f : 1;
	unsigned g : 1;
	unsigned h : 1;
	unsigned i : 1;
};
union bits
{
	int balls;
	struct byte bit;
} bit_balls;
void disp_bits(bits b)
{
	if (b.bit.h) cout << "1";  else cout << "0";
	if (b.bit.g) cout << "1";  else cout << "0";
	if (b.bit.f) cout << "1";  else cout << "0 ";
	if (b.bit.e) cout << "1";  else cout << "0";
	if (b.bit.d) cout << "1";  else cout << "0";
	if (b.bit.c) cout << "1";  else cout << "0";
	if (b.bit.b) cout << "1";  else cout << "0";
	if (b.bit.a) cout << "1";  else cout << "0";
	cout << "\n";
}


// основа 
int main()
{
	Universaty min;
	min.ball.push_back(999);
	setlocale(LC_ALL, "rus");
	int vvod;
	vector<string> Spesialt = { "POIT","ISIT","POIBS","DEVI" };
	const int SIZE = 3;
	Universaty  Univers[SIZE];
	readingInfoFromFile(Univers);
	cout << endl;
tryAgain:
	cout << "---------------------------------" << endl;
	cout << "Выбирите университет " << endl;
	for (int i = 0; i < SIZE; i++)
	{
		cout << i + 1 << " " << Univers[i].name << endl;
	}
	int unikchoose;
	cin >> unikchoose;
	unikchoose--;
	cout << "---------------------------------" << endl;
	while (true)
	{
		int choosemenu;
		cout << endl;
		cout << "---------------------------------" << endl;
		cout << "1. Хотите узнать какой университет" << endl;
		cout << "2. Хотите узнать какой адрес" << endl;
		cout << "3. Хотите узнать какой Балл на специальность" << endl;
		cout << "4. Хотите поменять университет" << endl;
		cout << "5. Хотите узнать минимальный балл на спец" << endl;
		cout << "6. bits" << endl;
		cin >> choosemenu;
		cout << endl;
		cout << "---------------------------------" << endl;
		switch (choosemenu)
		{

		case 1:
			cout << "Университет " << Univers[unikchoose].name << endl;
			break;
		case 2:
			cout << "Adress " << Univers[unikchoose].adress << endl;
			break;
		case 3:
			int spechoose;
			cout << endl;
			cout << "---------------------------------" << endl;
			cout << "1. POIT" << endl;
			cout << "2. ISIT" << endl;
			cout << "3. POIBS" << endl;
			cout << "4. DEVI" << endl;
			cout << "---------------------------------" << endl;
			cin >> spechoose;
			switch (spechoose)
			{
			case 1:

				cout << "Spec " << "POIT" << " ball ";
				cout << Univers[unikchoose].ball[0];

				break;
			case 2:
				cout << "Spec " << "ISIT" << " ball " << Univers[unikchoose].ball[1];
				break;
			case 3:
				cout << "Spec " << "POIBS" << " ball " << Univers[unikchoose].ball[2];
				break;
			case 4:
				cout << "Spec " << "DEVI" << " ball " << Univers[unikchoose].ball[3];
				break;
			default:
				cout << "Uncorrect" << endl;
				break;
			}
			cout << endl;
			break;
		case 4:
			cin.clear();                               // очистить флаги ошибок потока
			while (cin.get() != '\n');
			goto tryAgain;
			break;
		case 5:
			for (int i = 0; i < SIZE; i++)
			{
				for (int q = 0; q < 4; q++)
				{
					if (min.ball[0] > Univers[i].ball[q])
					{
						min.name = Univers[i].name;
						min.adress = Univers[i].adress;
						min.ball[0] = Univers[i].ball[q];

					}
				}
			}
			cout << endl;
			cout << min.name << " " << min.adress << " " << "POIBS " << min.ball[0] << endl;
			break;
		case 6:

			for (int i = 0; i < 4; i++)
			{
				cout << endl << "-----------------" << endl;
				bit_balls.balls = Univers[unikchoose].ball[i];
				disp_bits(bit_balls);
				cout << endl << "-----------------" << endl;
			}
			break;
		}
	}
	return 0;
}
