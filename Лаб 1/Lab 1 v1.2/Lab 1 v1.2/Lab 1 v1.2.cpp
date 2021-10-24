#include <iostream>
#include <ctime>

using namespace std;

int fmin(int n, ...)
{
	int* p = &n;
	int min = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i == 1 || min > * (p + i)) min = *(p + i);
	}
	return min;
}
int main(){

setlocale(LC_ALL, "Rus");
srand(time(NULL));
	
	cout << "(4, -5, 6, 9, -12) = " << fmin(4, -5, 6, 9, -12) << "; \n (6, -52, 16, 4, -90, 45, 12) = " << fmin(6, -52, 16, 4, -90, 45, 12) << ";\n (7, -78, 34, 15, -99, 4, 18, -37) = " << fmin(7, -78, 34, 15, -99, 4, 18, -37) << endl;
}