#include <iostream>
#include <string>
using namespace std;

int hashF(int length, int maxlength, int size) { //универсальная
	int a = maxlength / 3;
	int b = maxlength / 2;

	return ((a * length + b) % maxlength) % size;
}

bool checkSize(string a[], int size) {
	int count = 0;

	for (int i = 0; i < size; i++)
		if (a[i] != "")
			count++;

	if (count >= size * 0.5)
		return true;
	else
		return false;
}

int main()
{
	setlocale(LC_ALL, "");
	/*Реализовать хеш - таблицу с открытой адресацией для хранения строк.Таблица должна увеличивать свой размер втрое при достижении 50 % заполнения.*/

	string a[1000];

	int size = 10;
	int maxlength = 40;

	int tmp;
	int number;
	string fam;
	do {
		if (checkSize(a, size)) {
			string b[1000];
			for (int i = 0; i < size; i++) {
				if (a[i] != "") {
					tmp = hashF(a[i].length(), maxlength, size);
					if (b[tmp] == "")
						b[tmp] = a[i];
					else {
						int end = tmp;
						bool z = false;
						tmp = tmp + 1;

						while (tmp != end) {
							if (tmp == size)
								tmp = 0;
							if (b[tmp] == "") {
								b[tmp] = a[i];
								z = true;
								break;
							}
							tmp++;
						}
						if (!z)
							cout << "Элемент не может попасть в хэш-карту\n";
					}
				}
			}
			size *= 3;

			for (int i = 0; i < size; i++)
				a[i] = b[i];
		}

		int key;
		cin >> key;
		system("cls");
		for (int i = 0; i < size; i++) {
			cout << a[i] << " | ";
		}
		cout << endl;
		switch (key)
		{
		case 1:
			cin >> fam;
			tmp = hashF(fam.length(), maxlength, size);
			cout << tmp << endl;
			if (a[tmp] == "")
				a[tmp] = fam;
			else {
				int end = tmp;
				bool b = false;
				tmp = tmp + 1;

				while (tmp != end) {
					if (tmp == size)
						tmp = 0;
					if (a[tmp] == "") {
						a[tmp] = fam;
						b = true;
						break;
					}
					tmp++;
				}
				if (!b)
					cout << "Элемент не может попасть в хэш-карту\n";
			}
			break;
		case 2:
			cin >> fam;
			tmp = hashF(fam.length(), maxlength, size);
			if (a[tmp] == fam)
				cout << "Строка номер " << tmp;
			else {
				int end = tmp;
				bool b = false;
				tmp = tmp + 1;

				while (tmp != end) {
					if (tmp == size)
						tmp = 0;
					if (a[tmp] == fam) {
						cout << "Строка номер " << tmp;
						b = true;
						break;
					}
					tmp++;
				}
				if (!b)
					cout << "Элемент не может попасть в хэш-карту\n";
			}
			break;
		case 3:
			cin >> fam;
			tmp = hashF(fam.length(), maxlength, size);
			if (a[tmp] == fam)
				a[tmp] = "";
			else {
				int end = tmp;
				bool b = false;
				tmp = tmp + 1;

				while (tmp != end) {
					if (tmp == size)
						tmp = 0;
					if (a[tmp] == fam) {
						a[tmp] = "";
						b = true;
						break;
					}
					tmp++;
				}
				if (!b)
					cout << "Элемент не может попасть в хэш-карту\n";
			}
			break;
		default:
			break;
		}
	} while (1);
}