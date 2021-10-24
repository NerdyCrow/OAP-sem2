#pragma once
#include <iostream>;
#include <fstream>
#include <string>
#include <malloc.h>
using namespace std;

struct Stack1 {
	int data;
	Stack1* next;
};

struct Stack2 {			//Стуктура элемента стека
	int data;
	//Указатель на вершину стека
	Stack2* next;		//Указатель на следующий элемент
};

struct Stack3 {			//Стуктура элемента стека
	int data;
	//Указатель на вершину стека
	Stack3* next;		//Указатель на следующий элемент
};


void Add1(Stack1** s1, int D);
void Add1(Stack2** s2, int D);
void create(Stack1**s1);
void Show1(Stack1* s1);
void Show2(Stack2* s2);
void Show3(Stack3* s3);
void create(Stack1** s1);
void delete_key(Stack1** s1, int N);
void toFile(Stack1* s1);
void fromFile(Stack1** s1);
void clear(Stack1** s1);



int menu2();