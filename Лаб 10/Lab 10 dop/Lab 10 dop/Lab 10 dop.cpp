#include <iostream>
#include <stdio.h>
#include <cmath>
#include <math.h>
#include <fstream>
using namespace std;
int find(char* a, int i, int n)
{
	i++;
	if (i == 26)
	{
		i += n;
		cout << "Искомый элемент массива: " << a[i - 1] << endl;
		return a[i - 1];
	}
	else
		find(a, i, n);
	return a[i - 1];
}
void main()
{
	setlocale(LC_CTYPE, "RU");
	int i = 0;
	char a[] = "qwertyuiopasdfghjklzxcvbnm,./1234567890";
	int n;
	cout << "Введите n:";
	cin >> n;//не больше 13)))
	find(a, i, n);
}