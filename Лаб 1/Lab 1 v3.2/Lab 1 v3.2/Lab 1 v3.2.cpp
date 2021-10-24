#include <iostream>
#include <ctime>
#define MIN  -50
#define MAX   50
using namespace std;
int fmax(int n, ...)
{
	
	int* p = &n;
	int min = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || min < * (p + i)) min = *(p + i);
	}

	return min;
}
double fmax(double n, ...)
{
	double* p = &n;
	double min = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || min < *(p + i)) min = *(p + i);
	}
	return min;
}

int main()
{
	setlocale(LC_ALL, "Rus");

	cout << "(4, -5, 6, 9, -12) = " << fmax(4, -5, 6, 9, -12) << "\n (6.0, -152.45, -316.23, 43.7, -9.345, 4.314, 12.3) = " << fmax(6.0, -152.45, -316.23, 43.7, -9.345, 4.314, 12.3) << ";\n  (7.0, -152.45, 16.23, 58.7, -20.15, 4.314, 12.3, 17.9) = " << fmax(7.0, -152.45, 16.23, 58.7, -20.15, 4.314, 12.3, 17.9) << endl;
	

}