#include <iostream>
#include <iomanip>

using namespace std;

int arr[5]{1,2,3,4,5};
int  n = 5, x,c;
int (*fun1)();

int fan1() {
	for (int i = 0; i < n; i++) {
		if (arr[i] % x == 0)
			cout << arr[i] << " ";
	}
	return 0;
}

int main() {
	cin >> x;
	(*fan1)();
}