#pragma once
#include <iostream> 
#include <fstream>
#include <string>
using namespace std;

struct Number
{
    int info;
    Number* next;
};

extern int maxSize, curSize;

struct Number2
{
    float info;
    Number2* next;
};

extern int maxSize2, curSize2;

struct CHAR
{
    char info;
    CHAR* next;
};

struct Item
{
    int data;
    Item* next;
};

extern Item* head, * tail;

void create(Number** begin, Number** end, int p);
void view(Number* begin);
void Delete(Number** begin, Number** end, int p);
int amount(Number* begin);
void task(Number* begin);
void var6();
void dop1();
void dop1_1();
void dop1_2();
void dop1_3();
void dop1_5();
void insertToQueue(int z);
void insertToQueue2(int x);
void printQueue();
void getFromHead();
void getFromEnd();
void deletFirst();
void deletLast();
void printQueue();
void clrQueue();
void dop2();
void create2(Number2** begin, Number2** end, float p);
void view2(Number2* begin);
void Delete2(Number2** begin, Number2** end, float p);
void task2(Number2** begin, Number2** end);
void createCH(CHAR** begin, CHAR** end, char p);
void task3();