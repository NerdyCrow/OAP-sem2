#include<iostream>
#include <stdio.h>       
using namespace std;

int main() {
	setlocale(LC_CTYPE, "rus");

	FILE* F1;
	FILE* F2;
	errno_t err1,err2;
	err2 = fopen_s(&F2, "fileB.txt", "wb");
	err1 = fopen_s(&F1, "fileA.txt", "wb");
	fprintf(F1, "%d ", 10);
	fclose(F1);

	int x;
	err1 = fopen_s(&F1, "fileA.txt", "r");
	fscanf_s(F1, "%d", &x);

	fprintf(F2,"%d", x);
	fclose(F1);
	fclose(F2);


}