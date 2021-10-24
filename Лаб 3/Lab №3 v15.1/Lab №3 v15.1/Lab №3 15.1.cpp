#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
int main() {   
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

    is.open("FILE1.txt");
    char letter;
    int mas[10]{ '0','1','2','3','4','5','6','7','8','9' };

    int kol = 0;
    int number = 0;
    int max = 0;
    int nomer=0;
    while (is.get(letter))
    {
        for (int i = 0; i < 10; i++)
        {


            if (letter > '0'||letter<'9')
            {
                kol++;

            }
        }
            if (letter == ' ' || letter == '\n')
            {
                number++;
                if (kol > max)
                {
                    max = kol;
                    nomer = number;
                }
                kol = 0;
            }
        
    }
    cout << nomer;
    is.close();


}