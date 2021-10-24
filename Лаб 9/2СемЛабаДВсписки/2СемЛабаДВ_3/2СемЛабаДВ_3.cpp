#include "1.h"
using namespace std;

struct Warehouse
{
	char name[20];
	char ex[20];
	int date;
	Warehouse* next;
};
Warehouse items[10];

void deleteLinkedList(Element** node)
{
	Element* tmpNode;
	while (*node) {
		tmpNode = *node;
		*node = tmpNode->Next;
		delete tmpNode;
	}
}

void print(void* b)  //Функция используется при выводе 
{
	Warehouse* a = (Warehouse*)b;
	cout << a->name << " " << a->ex <<" " <<  a->date << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	items[0] = { "Жиляк", "ОИТ", 12122020};
	items[1] = { "Гринюк", "АЛОЦВМ", 15122020};
	items[2] = { "Белодед","ОАиП", 18122020 };
	items[3] = { "Мисевич","Физика", 9122020 };
	bool rc;
	Object L1 = Create();  // создание списка с именем L1

	cout << "Выберите опцию:" << endl;
	cout << "1. Вставка в начало" << endl;
	cout << "2. Найти заданный элемент" << endl;
	cout << "3. Вывод" << endl;
	cout << "4. Удалить по ссылке" << endl;
	cout << "5. Удалить по значению" << endl;
	cout << "6. Очистить список" << endl;
	cout << "7. Подсчет элементов списка" << endl;
	cout << "0. Выход" << endl;

	int choice = 1;
	for (; choice != 0;)
	{
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			for (int i = 0; i < 4; i++)
			{
				L1.Insert(&items[i]);
			}
			cout << "Элементы добавлены в список" << endl;
			break;
		}
		case 2: {
			Element* e = L1.Search(&items[1]);
			Warehouse* aa = (Warehouse*)e->Data;
			cout << "Найден элемент: " << aa->name << endl;
			break;
		}
		case 3: {
			cout << "Список:" << endl;
			L1.PrintList(print);
			break;
		}
		case 4: {
			if (L1.Delete(&items[0])) cout << "Удален элемент" << endl;
			else cout << "Что-то пошло не так..." << endl;
			break;
		}
		case 5: {
			int i;
			cout << "Введите номер элемента для удаления" << endl; cin >> i;
			if (L1.Delete(&items[i])) cout << "Удален элемент" << endl;
			else cout << "Что-то пошло не так..." << endl;
			break;
		}
		case 6: {
			int ln = L1.CountList(print);
			for (int i = 0; i < ln; i++)
			{
				L1.Delete(&items[i]);
			}
			cout << "Список очищен!" << endl;
			break;
		}
		case 7: {
			if (L1.CountList(print)) cout << "Количество элментов в списке:" << L1.CountList(print) << endl;
			else cout << "Что-то пошло не так..." << endl;
			break;
		}
		case 0: break;
		}
	}

	return 0;
}