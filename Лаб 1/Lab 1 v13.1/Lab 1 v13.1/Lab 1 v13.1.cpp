#include <iostream>
using namespace std;

float func1(float x)
{
	return 5 * x - 1 + pow(x, 3);
}
float func2(float x) {
	return pow(x,2)+1/x;
}


float dichotomy_method(float a, float b, float(*func)(float)) {
																  
																  
	float x = a, e = 0.001;
	

	while (abs(a - b) > 2 * e)
	{
		x = (a + b) / 2;
		if (func(x) * func(a) <= 0)
			b = x;
		else
			a = x;
	}
	return x;
}

int main() {
	setlocale(0, "rus");
	float a, b;
	cout << "¬ведите a: " << endl;
	cin >> a;
	cout << "¬ведите b: " << endl;
	cin >> b;

	cout << dichotomy_method(a, b, func1) << endl;
	cout << dichotomy_method(a, b, func2);

	return 0;
}
