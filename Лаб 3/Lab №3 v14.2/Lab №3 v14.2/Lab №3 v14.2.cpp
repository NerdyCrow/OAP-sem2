#include<iostream>
#include<fstream>
#include<string>
//#include "conio.h"
//#include "stdio.h"
using namespace std;


int main()
{
    setlocale(LC_ALL, "rus");
    string str;
    cout << "¬ведите строку: ";
    getline(cin, str);
    cout << endl;
    ofstream file;
    file.open("FILE1.txt");
   
    file << str;
    file.close();
    ifstream fout;
    fout.open("FILE1.txt");
    while (!fout.eof())
    {
        getline(fout, str);
        
    }
    fout.close();
    int k = 0;
    cout << "¬ведите K: ";
    cin >> k;

    int pos = k;
    if (k < str.length() && str[k - 1] != ' ')
    {
        for (int i = k - 1; i >= 0; i--)
        {
            if (str[i] == ' ')
            {
                break;
            }
            else
            {
                pos--;
            }
        }
    }
    string sub1, sub2;
    if (pos < str.length())
    {
        sub1 = str.substr(0, pos);
        sub2 = str.substr(pos, str.length());
    }
    else
    {
        sub1 = str;
    }
    ofstream fin;
    fin.open("FILE2.txt");
    fin << sub1 << "\n";
    fin << sub2 << "\n";
    fin.close();
    system("pause");
    return 0;
}