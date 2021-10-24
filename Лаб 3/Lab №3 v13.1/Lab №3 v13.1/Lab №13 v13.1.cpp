#include<iostream>
#include<string>
#include<fstream>

using namespace std;

int main() {
	setlocale(LC_ALL, "rus");

	//Write.............................................

	

	ofstream fout2;
	fout2.open("FILE2.txt");


	char str[100];
	char letter;

	int kol=0;
	int number=0;
	int max = 0;
	int num;

	ifstream fin;
	fin.open("FILE1.txt");
	int count = 0;
	while (fin.get(letter))
	{
		
		if (letter=='a'|| letter == 'e'|| letter == 'i'|| letter == 'o' || letter == 'u')
		{
			kol++;
			
		}
		if (letter==' ' || letter=='\n')
		{
			number++;
			if (kol>max)
			{
				max = kol;
				num = number;
			}
			kol = 0;
		}
	}
	cout << num;
	fin.close();
	fin.open("FILE1.txt");
	while (!fin.eof())
	{
		fin.getline(str, 100);
		cout<<str<<endl;
		count = 0;
		int size = strlen(str);
		int i = 0;
		while (i < size)
		{
			if (str[i] != ' ' && (str[i + 1] == ' ' || str[i + 1] == '\0'))
				count++;
			i++;
		}
		if (count >= 2)
		{
			
			fout2 << str;
			fout2 << "\n";
		}
		
	}
	

	fout2.close();
	fin.close();




}