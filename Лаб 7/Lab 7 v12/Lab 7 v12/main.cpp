#include "stdafx.h"

int main() {
	setlocale(LC_ALL, "rus");
	Stack1* s1 = NULL;
	Stack2* s2 = NULL;			//указатель на вершину стека - NULL
	int N = 3;
	Stack3* s3 = NULL;
	int* temp = new int[N];
	

	bool work = true;
	float n;

	while (work)
	{


		switch (menu2()) {
		case 1: cout << "¬ведите число: ";
			cin >> n;
			Add1(&s1, n);
			break;
		case 2:
			cout << "¬ведите число, которое нужно удалить: ";
			cin >> n;
			delete_key(&s1, n);
			break;
		case 3:Show1(s1);
			break;
		case 4:create(&s1);
			break;
		case 5:
			Show2(s2);
			break;
		case 6:
			Show3(s3);
			break;
		case 7:
			toFile(s1);
			break;
		case 8:
			fromFile(&s1);
			break;
		case 9:
			clear(&s1);
			break;
		case 10:
			work = false;
			break;
		};
	}				
}