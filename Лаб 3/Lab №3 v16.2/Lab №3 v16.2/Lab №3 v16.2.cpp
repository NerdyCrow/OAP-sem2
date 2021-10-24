#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void search(char str[]) {
	


	ofstream fout;
	fout.open("FILE1.txt");
	char st;
	fout << str;
	fout.close();
	ifstream fin;
	fin.open("FILE1.txt");
	char arr[20];
	int i = 0;
	while (!fin.eof())
	{
		fin.get(st);

		if (st=='2'||st=='4'||st=='6'||st=='8')
		{
			cout << st<<" ";
		}
	}
	
	

	fin.close();
	
}


int main() {
	setlocale(LC_ALL, "rus");
	char str[50];
	cout << "¬ведите строку: ";
	gets_s(str);
	cout << str;
	cout << endl;
	search(str);
}