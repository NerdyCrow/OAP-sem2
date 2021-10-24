#pragma once
#include <iostream>
namespace btree
{
	enum CMP
	{
		LESS = -1, EQUAL = 0, GREAT = 1
	};
	struct Node
	{
		Node* parent;            // óêàçàòåëü íà ðîäèòåëÿ  
		Node* left;              // óêàçàòåëü íà ëåâóþ âåòâü
		Node* right;             // óêàçàòåëü íà ïðàâóþ âåòâü
		void* data;              //  äàííûå    
		Node(Node* p, Node* l, Node* r, void* d) // êîíñòðóêòîð
		{
			parent = p;
			left = l;
			right = r;
			data = d;
		}
		Node* next();              // ñëåäóþùèé ïî êëþ÷ó
		Node* prev();              // ïðåäûäóùèé ïî êëþ÷ó
		Node* min();               // ìèíèìóì â ïîääåðåâå
		Node* max();               // ìàêñèìóì â ïîääåðåâå  
		void scanDown(void(*f)(void* n));    // îáõîä ïîääåðåâà ñâåðõó âíèç Íèñõîäÿùèé (ïðÿìîé) îáõîä Ê Ë Ï
		void scanDown1(void(*f)(void* n)); //Ñìåøàííûé  (îáðàòíûé) îáõîä Ë Ê Ï	
		void scan(int(*f)(void* n));
		void scanLevel(void(*f)(void* n), int);
		int getLevel();
		void scanByLevel(void(*f)(void* n));
		int AVLtree(); //Ïðîâåðêà íà ñáàëàíñèðîâàííîñòü äåðåâà
		int Height(); //Ïðîâåðêà âûñîòû äåðåâà
		int CountTopK(bool(*f)(void* x, int y), int k); //Ïîäñ÷åò êîë-âà âåðøèí ñ çíà÷ k;
		int CountTopKOUT();
	};
	struct Object         // Èíòåðôåéñ áèíàðíîãî äåðåâà 
	{
		Node* Root;                    // óêàçàòåëü íà êîðåíü
		CMP(*compare)(void*, void*);   // ôóíêöèÿ ñðàâíåíèÿ	
		Object(CMP(*f)(void*, void*))
		{
			Root = NULL;
			compare = f;
		};
		bool isLess(void* x1, void* x2)	const
		{
			return compare(x1, x2) == LESS;
		};
		bool isGreat(void* x1, void* x2)const
		{
			return compare(x1, x2) == GREAT;
		};
		bool isEqual(void* x1, void* x2)const
		{
			return compare(x1, x2) == EQUAL;
		};
		bool insert(void* data);           // äîáàâèòü ýëåìåíò
		Node* search(void* d, Node* n);    // íàéòè ýëåìåíò
		Node* search(void* d)
		{
			return search(d, Root);
		};
		bool deleteByNode(Node* e);         // óäàëèòü ïî àäðåñó ýëåìåíòà 
		bool deleteByData(void* data)       // óäàëèòü ïî êëþ÷ó
		{
			return deleteByNode(search(data));
		};
	};
	Object create(CMP(*f)(void*, void*));      // Ñîçäàòü áèíàðíîå äåðåâî    
};