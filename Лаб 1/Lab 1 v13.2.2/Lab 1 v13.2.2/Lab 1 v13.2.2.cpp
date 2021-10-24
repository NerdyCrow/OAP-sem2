#include <iostream>
#include <cstdlib>
#define MIN  0
#define MAX   10
using namespace std;

void Func2(int& size)
{
	int  i, j, numofs;

	int** a = new int* [size];
	for (i = 0; i < size; i++)
		a[i] = new int[size];
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{
			a[i][j] = (int)(((double)rand() /
				(double)RAND_MAX) * (MAX - MIN) + MIN);
		}
	}
	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size; j++)
		{

			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	int sum1 = NULL;                        
	for (int i = 1; i < size; i++)
		for (int j = 0; j < size - 1; j++)
			if (i == j + 1)
			{
				sum1 += *(*(a + i) + j);
			}
	int sum2 = 0;
	for (int i = 2; i < size; i++)
		for (int j = 0; j < size - 2; j++)
			if (i == j + 2)
			{
				sum2 += *(*(a + i) + j);
			}
	int sum3 = 0;
	for (int i = 3; i < size; i++)
		for (int j = 0; j < size - 3; j++)
			if (i == j + 3)
			{
				sum3 += *(*(a + i) + j);
			}
	cout << endl;
	cout << "Сумма элементов находщихся под главной диагональю: " << sum1 << " " << sum2 << " " << sum3 << " " << endl;
	cout << endl;
	int massive[3] = { sum1, sum2, sum3 };
	int max = massive[0];
	for (int i = 0; i < 3; ++i)
	{
		if (massive[i] > max)
		{
			max = massive[i];
		}
	}
	cout << "Максимальное значение суммы : " << max << endl;
}
int main(void)
{
	setlocale(LC_CTYPE, "Russian");
	int size;
	cout << "Введите размер квадратной  матрицы: ";
	cin >> size;
	Func2(size);
}