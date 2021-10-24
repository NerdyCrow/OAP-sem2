#include<iostream>
#include<cstring>
#include<string.h>
#include<string>
#include<stdio.h>
#include<fstream>

using namespace std;

//int main() {
//	char line[] = "abc def ghi";
//	char* arr[3];
//	char* p;
//
//	p = line;
//	for (int i = 0; i < 3; i++)
//	{
//		p = strtok(p, " ,");
//		if (p)
//		{
//			arr[i] = p;
//			p = NULL;
//		}
//		else
//		{
//			break;
//		}
//	}
//	for (int i = 0; i < 3; i++)
//	{
//		cout << arr[i] << endl;
//	}
//
//
//}

int main() {

	bool flag = false;
	ifstream fin;
	fin.open("file.txt");


	int k;
	char a[1000];
	char* arr[100];
	
	char* str;
	while (!fin.eof())
	{
		fin.getline(a, 1000);


		str = strtok(a, " ");
		k = 0;
		cout << endl;
		while (str != NULL)
		{
			arr[k] = str;
			k++;
			str = strtok(NULL, " ");

		}
		for (int i = 0; i < k; i++)
		{
			
			for (int j = i+1;  j < k; j++)
			{
				if (arr[j]==arr[i])
				{
					flag = true;
					break;
				}
			}
		}
		if (flag)
		{
			cout << a << endl;
			flag = false;
		}
	}
	fin.close();
}
