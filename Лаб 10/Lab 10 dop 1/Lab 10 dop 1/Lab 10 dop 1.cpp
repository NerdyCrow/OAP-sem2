#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
void far(unsigned long i, int n, ofstream* f)
{
	i++;
	if (i >= pow(10, n))
		return;
	unsigned long a = i; bool tf = true;
	while (a != 0)
	{
		if (a % 10 > n)
		{
			tf = false;
			break;
		}
		a /= 10;
	}
	if (tf)
	{
		*f << i << ' ';
		far(i, n, f);
	}
	else
	{
		far(i, n, f);
	}
	return;
}
void fing_and_write(int n)
{
	ofstream fout;
	fout.open("fileLAB10.3.txt");
	unsigned long i = pow(10, n - 1) - 1;
	far(i, n, &fout);
	fout.close();
}

void  main()
{
	setlocale(LC_CTYPE, "RU");
	int nmb;
	cout << "Введите число: "; cin >> nmb;
	fing_and_write(nmb);
}