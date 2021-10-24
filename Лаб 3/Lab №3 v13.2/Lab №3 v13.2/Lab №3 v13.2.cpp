#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int search(char str[]) {
	cout << endl << str;

	
	ofstream fout;
	fout.open("FILE1.txt");
	char st;
	fout << str;
	fout.close();
	ifstream fin;
	fin.open("FILE1.txt");
	int num = 0;
	while (!fin.eof())
	{
		fin.get(st);

		if (st == '{' || st == '}' || st == '(' || st == ')' || st == '[' || st == ']' || st == '<' || st == '>')
		{
			num++;
		}
	}
	num = num - 1;
	
	fin.close();
	return num;
}

int main() {

	setlocale(LC_ALL, "rus");
	char str[50];
	cout << "Введите строку: ";
	cin >> str;
	cout << endl;
	cout<< "Количество скобок: "<<search(str);
	


}