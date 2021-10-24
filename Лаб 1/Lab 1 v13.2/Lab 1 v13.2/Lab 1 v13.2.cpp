#include<iostream>
#include <ctime>
using namespace std;
int summa(int& size) {
	srand(time(NULL));
	const int N=100;
	int arr[N][N];
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			arr[i][j] = rand() % 10;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	int sum = 0;
	int summ = 0;
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++) {

			summ += arr[i][j];
		}

	for (int i = 0; i < size; i++)
		for (int j = 0; j < size - i; j++) {

			sum += arr[i][j];
		}
	int pod = summ - sum;
	cout << pod;
	return 0;
}

int main() {
	setlocale(LC_CTYPE, "rus");
	int size;
	cout << "¬ведите размер матрицы: "  ;
	cin >> size;
	summa(size);
}