#include <iostream>
using namespace std;
bool vys(int year)
{
    bool res = false;
    if (year % 4 == 0)
        res = true;
    if (year % 100 == 0)
        res = false;
    if (year % 400 == 0)
        res = true;
    return res;
}
int date(int d, int m, int y)
{
    int k = d;
    if (vys(y) && (m > 2))
        k += y * 366;
    else k += y * 365;
    switch (m - 1)
    {
    case 12: k += 31;
    case 11: k += 30;
    case 10: k += 31;
    case  9: k += 30;
    case  8: k += 31;
    case  7: k += 31;
    case  6: k += 30;
    case  5: k += 31;
    case  4: k += 30;
    case  3: k += 31;
    case  2: k += 28;
    case  1: k += 31;
    }
    return k;
}
int difference(int n, ...)
{
    int day1, day2, mon1, mon2, year1, year2;
    int* p = &n;
    p++;
  

    day1 = *p / 1000000;
    mon1 = (*p - day1 * 1000000) / 10000;
    year1 = (*p - day1 * 1000000 - mon1 * 10000) / 1;
    p++;
    day2= *p / 1000000;
    mon2 = (*p - day2 * 1000000) / 10000;
    year2 = (*p - day2 * 1000000 - mon2 * 10000) / 1;


    int k = date(day2, mon2, year2) - date(day1, mon1, year1) + 1;
    return k;
}
void main()
{
    setlocale(LC_CTYPE, "rus");
    /*int d1, d2, m1, m2, y1, y2;
    cout << "Input first day: ";
    cin >> d1;
    cout << "Input first month: ";
    cin >> m1;
    cout << "Input first year: ";
    cin >> y1;
    cout << "Input second day: ";
    cin >> d2;
    cout << "Input second month: ";
    cin >> m2;
    cout << "Input second year: ";
    cin >> y2;*/
    cout << "Между двумя датами:  " << difference(2,12122006,24062019) << " дней\n";
    cout << "Между двумя датами: " << difference(2, 13022002, 21042021) << " дней\n";
    cout << "Между двумя датами: " << difference(2,31012003,24062019) << " дней\n";

}