#include <stdio.h>
#include <iostream>
#include<ctime>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	FILE* F1;
	FILE* F2;
	errno_t err1, err2;
	err1 = fopen_s(&F1, "file1.txt", "r");
	int arr[100];
	int size;

	err2 = fopen_s(&F2, "file2.txt", "wb");
	fscanf(F1, "%d", &size);


	for (int i = 0; i < size; i++)
	{
		fscanf(F1, "%d", &arr[i]);
		cout << arr[i] << " ";
	}
	cout << endl;

	fclose(F1);
	int count = 0;


	for (int i = 0; i < size - 1; i++)
	{
		if (arr[i] > 0)
		{
			count++;
			fprintf(F2, "%d ", arr[i]);
			
			if (count == 10)
			{
				break;
			}
		}
	}
	

	for (int i = 0; i < size; i++)
	{
		if (arr[i] < 0)
		{
			count++;
			fprintf(F2, "%d ", arr[i]);
			if (count == 10)
			{
				break;
			}
		}
	}


}

