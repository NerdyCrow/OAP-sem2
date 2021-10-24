#include <iostream>
#include <cstdlib>
using namespace std;

char* compr(char* a, char* z) {
	for (int i = 0; i < strlen(a); i++) {

		if (a[i] == ' ') {

		}
		else
			z[strlen(z)] = a[i];

	}
	cout << z;
	return 0;

}
int main() {
	setlocale(LC_CTYPE, "rus");
	const int size = 100;
	char z[100] = "";
	char a[size];
	cout << "¬ведите строку";
	cin.getline(a, 100);
	compr(a, z);
}