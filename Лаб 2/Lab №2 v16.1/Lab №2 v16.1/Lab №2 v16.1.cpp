#include<iostream>

#include<conio.h>
#include<stdio.h>
#define _CRT_SECURE_NO_WARNINGS

int main(){
	FILE* F1;
	FILE* F2;
	FILE* F3;


	int size1, size2;
	int arr1[100];
	int arr2[100];

	errno_t err1, err2,err3;
	err1 = fopen_s(&F1, "fileA.txt", "r");
	fscanf(F1, "%d", &size1);

	for (int i = 0; i < size1; i++)
	{
		fscanf(F1, "%d", &arr1[i]);
	}
	fclose(F1);

	err2 = fopen_s(&F2, "fileB.txt", "r+");
	fscanf(F2, "%d", &size2);

	for (int i = 0; i < size2; i++)
	{
		fscanf(F1, "%d ", &arr2[i]);
	}
	fclose(F2);
	int sum = 0;
	for (int i = 0; i < size1; i++)
	{
		sum += arr1[i];
	}
	for (int i = 0; i < size2; i++)
	{
		sum += arr2[i];
	}
	err3 = fopen_s(&F3, "fileC.txt", "wb");
	fprintf(F3, "%d", sum);
	fclose(F3);

}
