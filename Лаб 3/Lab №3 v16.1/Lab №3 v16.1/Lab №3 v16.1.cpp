#define _CRT_SECURE_NO_WARNINGS
#include <fstream>
#include <iostream>
using namespace std;

void main()
{
    setlocale(LC_ALL, "rus");
    char buff[50]; char l; int p; int sgl = 0, k = 0;        // буфер для хранения считываемого из файла текста
    ofstream fout("t.txt"), fout2("b.txt");   // создание объекта fout класса ofstream для записи 
    cout << "Введите строки:" << endl;
    while (true)
    {
        cin.getline(buff, 512);


        ;        if (buff[0] == ';') break;
        fout << buff;
        fout << "\n";
    }
    cout << "Количество введённых строк:"; cin >> p;
    // запись строки в файл
    fout.close();
    ifstream fin("t.txt"), fin2("b.txt");    // создание объекта fin класса ifstream для чтения  
    if (!fin.is_open())
        cout << "Файл не может быть открыт!\n";
    else
    {
        for (int i = 0; i < p; i++) {
            char buff[50]; char buff_new[50]; char buff_new2[50];

            fin >> buff_new;
            cout << buff_new << endl;
            fin >> buff_new2;
            cout << buff_new2 << endl;
            fin.getline(buff, 50);
            cout << buff << endl;
            cout << "----------------------------------------------------------------------------------" << endl;
            if (strstr(buff, buff_new2) || strstr(buff_new2,buff_new)) {
                fout2 << buff_new << " " << buff_new2 << buff << "\n";
                k++;
            }

            buff[0] = 0;
            buff_new[0] = 0;
            // печать строки
        } fin.close();
    }fout2.close();

    if (!fin2.is_open())
        cout << "Файл не может быть открыт!\n";
    else {
        for (int y = 0; y <= k; y++) {
            char buff2[50];
            if (y == k - 1) {

                char s[] = ("1234567890");/* { "b","c","d","f","g","h","j","k","l","m","n","p","q","r","s","t","v","w","x","z" };*/

                fin2.getline(buff2, 50);
                cout << buff2 << endl;

                for (int i = 0; i < strlen(buff2); ++i)
                {

                    for (int j = 0; j < strlen(s); ++j)
                    {
                        if (buff2[i] == s[j]) sgl++;
                    }
                }
                cout << "Цифр букв в строке: " << sgl << endl;
                cout << "----------------------------------------------------------------------------------" << endl;

            }
            else {
                fin2.getline(buff2, 50); cout << buff2 << endl;
                buff[0] = 0;
            }

        }
        fin2.close();
    }
}