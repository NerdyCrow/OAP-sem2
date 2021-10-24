#include <stdio.h>
#include <iostream>
#include<ctime>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	FILE* spisok1;
	FILE* spisok2;
	errno_t err;
	errno_t err2;
	char str1[50] = "1 строки\n";
	char str2[50] = "вторая строка\n";
	char str3[50] = "3 строка\n";
	char str4[50] = "четвертая строка\n";
	char str5[50] = "5 строка\n";
	err = fopen_s(&spisok1, "F1.txt", "w");
	fputs(str1, spisok1);
	fputs(str2, spisok1);
	fputs(str3, spisok1);
	fputs(str4, spisok1);
	fputs(str5, spisok1);
	fclose(spisok1);
	err2 = fopen_s(&spisok2, "F2.txt", "w");
	if (str1[0] >= 0)
	{
		fputs(str1, spisok2);
	}
	if (str2[0] >= 0)
	{
		fputs(str2, spisok2);
	}
	if (str3[0] >= 0)
	{
		fputs(str3, spisok2);
	}
	if (str4[0] >= 0)
	{
		fputs(str4, spisok2);
	}
	if (str5[0] >= 0)
	{
		fputs(str5, spisok2);
	}
	fclose(spisok2);
}