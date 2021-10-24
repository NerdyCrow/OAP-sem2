#include <stdio.h>
#include <iostream>
#include<ctime>
#define LEN 16
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	int i = 0, j = 0, k, mass[4][4];
	FILE* matrix1;
	FILE* matrix2;
	errno_t err, err2;
	int x = 4;
	int size;
	err = fopen_s(&matrix1, "file1.txt", "wb");
	fprintf(matrix1, "%d", x);
	fclose(matrix1);

	err = fopen_s(&matrix1, "file1.txt", "r");
	fscanf(matrix1, "%d", &size);
	cout << size;
	fclose(matrix1);

	err = fopen_s(&matrix1, "file1.txt", "wb");
	fputs("\n", matrix1);
	for (; i < 4; i++)
	{
		for (; j < size; j++)
		{
			mass[i][j] = rand() % 100 - 30;
			fprintf(matrix1, "%d\t", mass[i][j]);
			if (j == 4 - 1)
			{
				fputs("\n", matrix1);
			}
		}
		j = 0;
	}
	j = 0;
	fclose(matrix1);
	err2 = fopen_s(&matrix2, "file2.txt", "wb");
	cin >> k;

	for (int i = 0; i < 4; ++i) {
		fprintf(matrix2, "%d\n", mass[i][k - 1]);
	}
	cout << endl;
}