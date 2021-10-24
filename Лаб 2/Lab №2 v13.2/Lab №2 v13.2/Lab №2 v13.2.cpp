#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "");
	int size;
	FILE* fileA;
	FILE* fileB;
	fileA = fopen("f.txt", "r");  //Открытие для чте-ния

	fscanf_s(fileA, "%d", &size);
	int arr[100];
	for (int i = 0; i < size; i++) {
		fscanf_s(fileA, "%d", &arr[i]);
		printf("%d   ", arr[i]);
	}
	fclose(fileA);
	fileB = fopen("g.txt", "w");
	cout << endl;
	
	
	
	for (int i = 0; i < size; i++)
	{
		
		for (int j = i + 1; j < size; j++)
		{
			
			if (arr[i] == arr[j])
			{
				
				int wasBefore = 0;
				for (int k = 0; k < i; k++) {
					if (arr[k] == arr[i]) {
						wasBefore = 1; break;
					}
				}
				if (wasBefore == 0) {
					fprintf(fileB, "%d ", arr[i]);
					cout << arr[i] << " ";
					
				}
				break;
			}
			
			
		}
		
		
		

	}
	int arr2[100];
	int numb;
	int size2 = 0;
	for (int i = 0; i < size; i++)
	{
		numb = 1;
		for (int j = 0; j < size; j++)
		{
			if ((j != i) && (arr[i] == arr[j]))
			{
				numb = 0;
			}

		}
		if (numb)
		{
			size2++;
			arr2[size2 - 1] = arr[i];
		}
	}
	for (int i = 0; i < size2; i++)
	{
		fprintf(fileB, "%d ", arr2[i]);
	}
	fclose(fileB);
	return 0;
}