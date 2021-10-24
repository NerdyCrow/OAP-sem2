#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
int main() {   //копирование из файла F1 в файл F2 строк, которые содержат не менее двух одинаковых слов
    ifstream is;
    is.open("FILE1.txt");
    ofstream os;
    os.open("FILE2.txt");
    if (!is || !os) return 1;
    string str, word;
    unordered_set<string> uset;
    while (getline(is, str)) {
        uset.clear();
        stringstream ss(str);

        while (ss >> word) {
            if (!uset.insert(word).second) {
                os << str << '\n';
                break;
            }
        }
    }
    is.close();
    os.close();

    //Определяем номер слова
    is.open("FILE1.txt");
      char letter;

    int kol = 0;
    int number = 0;
    int max = 0;
    int chislo;
    while (is.get(letter))
    {

        if (letter=='l')
        {
            kol++;

        }
        if (letter == ' ' || letter == '\n')
        {
            number++;
            if (kol > max)
            {
                max = kol;
                chislo = number;
            }
            kol = 0;
        }
    }
    cout << chislo;
    is.close();

}