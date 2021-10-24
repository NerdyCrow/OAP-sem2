#pragma once
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

extern int maxSize, curSize;
struct CHAR
{
    char info;
    CHAR* next;
};

void var12();
void create(CHAR** begin, CHAR** end, char p);
void view(CHAR* begin);
void Delete(CHAR** begin, CHAR** end, char p);
int amount(CHAR* begin);
void task(CHAR* begin,CHAR* end);
void tsk();
