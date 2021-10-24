//#include<iostream>
//using namespace std;
//#include <string>
//#include "stdio.h"
//int main() {
// setlocale(LC_ALL, "Russian");
// cout << "10.1) Скопировать из файла FILE1 в файл FILE2 все строки, в которых нет слов, совпадающих с первым словом. Определить количество согласных букв в первой строке файла FILE2.\n\n";
// int i = 0;
// ifstream in("L101_f1.txt");
// ofstream out("L101_f2.txt");
// string line, firstWord, word;
// while (getline(in, line))
// {
// stringstream ss(line);
// bool h = false;
// ss>> firstWord;
// while (ss » word)
// {
// if (word == firstWord)
// {
// h = true;
// break;
// }
// }
// if (h == 0) out << line << endl;
// }
// in.close();
// out.close();
// ifstream in2("L101_f2.txt");
// getline(in2, line);
// if (i == 0) {
// string consonants("bcdfghjklmnpqrstvwxz");
// int consCount = 0;
// for (auto it = line.begin(); it != line.end(); it++) {
// if (consonants.find(*it) != string::npos)
// consCount++;
// }
// cout << "Количество согласных букв в первой строке файла FILE2: " << consCount << endl;
// }
// i = 1;
// in2.close();
// return 0;
//}
//#include<fstream>
//void main(){
// setlocale(LC_ALL, "rus");
// char buff[100], ruff[100];
// int words = 0, y = 0;
//
// cout << "10.2) Ввести с клавиатуры строку символов, состоящую из слов, разделенных пробелами, и записать ее в файл. Прочитать из файла данные и вывести все слова, которые содержат букву <<р».\n\n";
//
// ofstream fout("L102.txt");
// gets_s(buff);
// fout << buff << endl;
// fout.close();
//
// ifstream fin;
//fin.open("L102.txt");
// if (!fin.is_open())
// cout << "Файл не может быть открыт!\n";
// else {
// for (int k = 0; k < strlen(buff); k++) {
// if (buff[k] == ' ')
// words += 1;
// }
// for (int i = 0; i < words; i++) {
// fin >> ruff;
// for (int k = 0; k < strlen(ruff); k++) {
// if (ruff[k] == 'p') {
// y += 1;
// if (y == 1) {
// cout << ruff << endl;
// ofstream fout("L102.txt", ios_base::app);
// fout << ruff << endl;
// }
// }
// }
// y = 0;
// }
// }
// fout.close();
//}
#include<iostream>
#include <fstream>
#include <string>
#include "stdio.h"
using namespace std;

int main()
{
	setlocale(LC_CTYPE, "rus");
	ofstream fout("file3.txt");
	string str, word;
	cout << "Введите строку символов:\n";
	getline(cin, str);
	fout << str;
	fout.close();
	ifstream fin("file3.txt");
	if (!fin) {
		cout << "fine not open!";
		return -1;
	}
	else {
		fin >> word;
		while (fin) {

			if (word.find("x") != -1) {
				cout << word << " ";
			}
			if (!(fin >> word)) {
				break;
			}
		}
	}
	return 0;
}
