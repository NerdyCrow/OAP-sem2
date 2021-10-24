#include <stdio.h>
#include <iostream>
#include<ctime>
#include <conio.h>
using namespace std;
int main()
{
	setlocale(LC_ALL, "rus");
	FILE* first;
	FILE* second;

	char c[1000];

	errno_t err;
	errno_t err2;
	int k;
	cin >> k;
	err = fopen_s(&first, "F1.txt", "r");
	/*for (int i = 0; i < 10; i++)
	{
		if (i==k && i<(k+3))
		{
			fgetc(c, 1000, f);
		}
		
	}*/
	int count = 0;
	while (!feof(first))
	{
		count++;
		
		if (count >= k)
		{
			if (fgets(c, 1000, first)!=0)
			{
				printf("%s", c);
			}
			
		}
		else
		{
			fgets(c, 1000, first);
		}
		
		if (count==k+4)
		{
			break;
		}
		
		
		
	}
	
	
	fclose(first);
	/*err2 = fopen_s(&second, "F2.txt", "w");
	fclose(second);*/
}