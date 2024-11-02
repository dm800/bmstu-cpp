#include <Windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

class MenuClass
{
	void SetPos(COORD dwCursorPosition) {
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), dwCursorPosition);
	}

	void SetPos(int x, int y) {
		COORD cd;
		cd.X = x;
		cd.Y = y;
		SetPos(cd);
	}
	void getKeyDown()
	{
		while (true)
		{
			while (!_kbhit());
		
			int key = _getch();
			if (key == 80)
				index++;
			if (key == 72)
				index--;

			if (key == 13)
			{
				system("cls");
				switch (index)
				{
				case 0:
					break;
				case 1:break;
				case 2:
					cout << "Какуую цифру добавить?" << endl;
					int c;
					cin >> c;
					break;
				default:
					break;
				}
				system("pause");
				ShowMenu();
			}
			for (int i = 0; i < count;i++)
			{
				SetPos(0, i);
				cout << " ";
			}
			index %= count;
			SetPos(0, index);
			cout << ">";
		}
	}
	int index = 0;
	int count = 5;

public :
	void ShowMenu()
	{
		cout << " Создать" << endl;
		cout << " Concat" << endl;
		cout << " Append" << endl;
		cout << " q2eqweqwe" << endl;
		cout << " q2eqweqwe" << endl;
		getKeyDown();
	}

	
};