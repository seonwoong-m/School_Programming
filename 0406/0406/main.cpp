#include <iostream>
#include <conio.h>
#include <string.h>

using namespace std;

struct tag_Munje
{
	string Question;
	string Answer;
	int wordCount;
};

tag_Munje Munje[] = {
	{"********", "alphabet", 8}

};

int main()
{
	cout << " ------------------------------ " << endl;
	cout << "|    alphabet 맞히기 게임      |" << endl;
	cout << " ------------------------------ " << endl;
	cout << "|   설명 : 알파벳을 누르세요   |" << endl;
	cout << " ------------------------------ " << endl;

	string tempQuestion = Munje[0].Question;
	char ch;

	cout << tempQuestion;

	while(tempQuestion != Munje[0].Answer)
	{
		ch = _getch();
		cout << " " << ch << endl;

		for (int j = 0; j < Munje[0].wordCount; j++)
		{
			if (ch == Munje[0].Answer[j])
			{
				tempQuestion[j] = ch;
			}
		}

		cout << tempQuestion;
	}
	


	return 0;
}