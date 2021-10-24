#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>
#include <strstream>
#include <sstream>

using namespace std;

union MyUnion
{
	string name;
	string adress;
	vector<string> spec;
	vector<int> marks;
	int cashflow;
};

struct Mystruct
{
	string name;
	string adress;
	vector<string> spec;
	vector<int> marks;
	int cashflow;
};
Mystruct Unik[2];

#define LEN 20;


int main()
{
	setlocale(LC_ALL, "rus");

	union MyUnion
	{
		//	string name;
		char name[20];

		//string adress;
		char adress[20];
		//vector<string> spec;
		char spec[4][20];
		//vector<int> marks;
		int marks[4];
		int cashflow;
	};
	MyUnion uUnik[2];

	int spec1;
	int spec2;
	cout << "Заполнить информацию университетов" << endl;
	for (int i = 0; i < 2; i++)
	{
		cout << "Name " << endl;
		string name_1;
		getline(cin, name_1);
		char buf1[255];
		strcpy_s(buf1, name_1.c_str());
		for (int q = 0; q < name_1.size() + 1; q++)
		{
			uUnik[i].name[q] = buf1[q];
			cout << uUnik[i].name[q];
			Unik[i].name += uUnik[i].name[q];
		}
		cout << endl;
		cout << "Adress";
		cout << endl;
		name_1.clear();
		string name_2;
		getline(cin, name_2);
		char buf2[255];
		strcpy_s(buf2, name_2.c_str());
		for (int q = 0; q < name_2.size() + 1; q++)
		{
			uUnik[i].adress[q] = buf2[q];
			cout << uUnik[i].adress[q];
			Unik[i].adress += uUnik[i].adress[q];
		}
		cout << endl;
		cout << "Amount of spec";
		cout << endl;
		int sizespec;
		cin >> sizespec;
		if (i == 0)
		{
			spec1 = sizespec;
		}
		if (i == 1)
		{
			spec2 = sizespec;
		}
		cout << endl;
		for (int k = 0; k < sizespec; k++)
		{
			cout << "name spec" << endl;
			cin.clear();                               // очистить флаги ошибок потока
			while (cin.get() != '\n');
			string spec_1;
			getline(cin, spec_1);
			char buf3[255];
			strcpy_s(buf3, spec_1.c_str());
			for (int q = 0; q < spec_1.size(); q++)
			{
				uUnik[i].spec[k][q] = buf3[q];
				cout << uUnik[i].spec[k][q];
			}
			Unik[i].spec.push_back(uUnik[i].spec[k]);
			cout << endl;

			cout << "mark of spec" << endl;
			int mark_1;
			cin >> mark_1;
			uUnik[i].marks[k] = mark_1;
			cout << uUnik[i].marks[k];
			Unik[i].marks.push_back(uUnik[i].marks[k]);
			cout << endl;

		}
		cout << endl;
		cout << "Pay for education";
		cout << endl;
		int cash_1;
		cin >> cash_1;
		uUnik[i].cashflow = cash_1;
		cout << uUnik[i].cashflow;
		Unik[i].cashflow += uUnik[i].cashflow;
		cin.clear();                               // очистить флаги ошибок потока
		while (cin.get() != '\n');
	}

	while (true)
	{
		cout << "=============================" << endl;
		int userchooice_1;
		cout << "Info of Unik" << endl;
		cout << "0." << Unik[0].name;
		cout << endl;
		cout << "1." << Unik[1].name;
		cout << endl;
		cout << "2. Min mark of spec" << endl;
		cin >> userchooice_1;
		cout << endl;
		int userchooice_2;
		int userchooice_3;
		int userchooice_4;
		cout << "=============================" << endl;

		switch (userchooice_1)
		{
		case 0:
			cout << "1. Info of Unik" << endl;
			cout << "2. Research" << endl;
			cin >> userchooice_2;
			cout << endl;
			switch (userchooice_2)
			{
			case 1:
				cout << "=============================" << endl;
				cout << Unik[userchooice_1].name << endl;
				cout << Unik[userchooice_1].adress << endl;
				cout << Unik[userchooice_1].cashflow << "$" << endl;
				for (int i = 0; i < Unik[userchooice_1].spec.size(); i++)
				{
					cout << "///////////////////////" << endl;
					cout << Unik[userchooice_1].spec[i] << endl;
					cout << "mark " << Unik[userchooice_1].marks[i] << endl;
				}
				cout << "=============================" << endl;
				break;
			case 2:
				cout << "=============================" << endl;
				cout << "1. name" << endl;
				cout << "2. adress" << endl;
				cout << "3. cash" << endl;
				cout << "4.spec" << endl;
				cin >> userchooice_3;
				switch (userchooice_3)
				{
				case 1:
					cout << "name " << Unik[userchooice_1].name << endl;
					break;
				case 2:
					cout << "adress " << Unik[userchooice_1].adress << endl;
					break;
				case 3:
					cout << "cost " << Unik[userchooice_1].cashflow << endl;
					break;
				case 4:
					for (int i = 0; i < Unik[userchooice_1].spec.size(); i++)
					{
						cout << "///////////////////////" << endl;
						cout << Unik[userchooice_1].spec[i] << endl;
						cout << "mark " << Unik[userchooice_1].marks[i] << endl;
					}
					cout << "=============================" << endl;
					break;
				default:
					cout << "Uncorrect" << endl;
					break;
				}
				cout << "=============================" << endl;
				break;
			default:
				cout << "Uncorrect" << endl;
				break;
			}
			break;
		case 1:
			cout << "1. Info of Unik" << endl;
			cout << "2. Research" << endl;
			cin >> userchooice_2;
			cout << endl;
			switch (userchooice_2)
			{
			case 1:
				cout << "=============================" << endl;
				cout << Unik[userchooice_1].name << endl;
				cout << Unik[userchooice_1].adress << endl;
				cout << Unik[userchooice_1].cashflow << "$" << endl;
				for (int i = 0; i < Unik[userchooice_1].spec.size(); i++)
				{
					cout << "///////////////////////" << endl;
					cout << Unik[userchooice_1].spec[i] << endl;
					cout << "mark " << Unik[userchooice_1].marks[i] << endl;
				}
				cout << "=============================" << endl;
				break;
			case 2:
				cout << "=============================" << endl;
				cout << "1. name" << endl;
				cout << "2. adress" << endl;
				cout << "3. cash" << endl;
				cout << "4.spec" << endl;
				cin >> userchooice_3;
				switch (userchooice_3)
				{
				case 1:
					cout << "name " << Unik[userchooice_1].name << endl;
					break;
				case 2:
					cout << "adress " << Unik[userchooice_1].adress << endl;
					break;
				case 3:
					cout << "cost " << Unik[userchooice_1].cashflow << endl;
					break;
				case 4:
					for (int i = 0; i < Unik[userchooice_1].spec.size(); i++)
					{
						cout << "///////////////////////" << endl;
						cout << Unik[userchooice_1].spec[i] << endl;
						cout << "mark " << Unik[userchooice_1].marks[i] << endl;
					}
					cout << "=============================" << endl;
					break;
				default:
					cout << "Uncorrect" << endl;
					break;
				}
				cout << "=============================" << endl;
				break;
			default:
				cout << "Uncorrect" << endl;
				break;
			}
			break;
			break;
		case 2:
			cout << "choice spec" << endl;
			for (int q1 = 0; q1 < 2; q1++)
			{
				cout << q1 << Unik[0].spec[q1] << endl;
			}
			cin >> userchooice_4;
			switch (userchooice_4)
			{
			case 0:
				if (Unik[0].marks[0] > Unik[1].marks[0])
				{
					cout << Unik[1].name << endl;
					cout << Unik[1].spec[0] << endl;
					cout << Unik[1].marks[0] << endl;
				}
				else
				{
					cout << Unik[0].name << endl;
					cout << Unik[0].spec[0] << endl;
					cout << Unik[0].marks[0] << endl;
				}
				break;
			case 1:
				if (Unik[0].marks[1] > Unik[1].marks[1])
				{
					cout << Unik[1].name << endl;
					cout << Unik[1].spec[1] << endl;
					cout << Unik[1].marks[1] << endl;
				}
				else
				{
					cout << Unik[0].name << endl;
					cout << Unik[0].spec[1] << endl;
					cout << Unik[0].marks[1] << endl;
				}
				break;
			default:
				cout << "Uncorrect" << endl;
				break;
			}
			break;

		default:
			cout << "Uncorrect" << endl;
			break;
		}
		cout << "=============================" << endl;

	}
	return 0;
}