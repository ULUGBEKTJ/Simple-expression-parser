// ConsoleApplication7.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"


#include <conio.h>
#include <iostream>
#include  <string>
#include <iomanip>
using namespace std;


///////////////////////////////////////////////
void show(char** m, int x, int y, int x1, int y1, int x2, int y2, int x3, int y3);
void show(char** m, int x, int y, int x1, int y1, int x2, int y2);
void show(char** m, int x, int y, int x1, int y1);
void show(char** m, int x, int y);
void show(char** m);
void show_SSS(char** m);
//////////////////////////////////////////////

class   User//����� �������� ������  10 �� 10
{
private:
	char** matrix;
public:



	////////////////////////////////////////////// ���������� ������� � ���������� ��� *
	User()
	{
		matrix = new char*[10];
		for (int i = 0; i < 10; i++)
		{
			matrix[i] = new char[10];
		}
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				matrix[i][j] = '*';
			}
		}
		vvod();
	}
	//////////////////////////////////////////////


	////////////////////////////////////////////// ����� ����� ��������. ������ ��� ���������, ENter ��� ��������� �� �������. ������ �� ������� � ������� ��������� �� ���� ������ !! � ��� ���� ���� ���������� �����. 
	void vvod()
	{
		int type, p;// ������� ����� : ������� ���� �����, ������� � ������
		int x, x1, x2, x3, y, y1, y2, y3;// ���������� �������� ( �� 4 ����, ��� ��� ������������ ����� �������� 4 ������ ) 
		int aaaa = 1, aaa = 2, aa = 3, a = 4;// ���������� �������� - 1 ����� �� 4, 3 ����� �� 2 � ��
		do
		{
			system("cls");
			show(matrix);
			cout << "\n ������� ��� �������\n";
			cout << " ������� 4 ��� ��������� ������� ����: O-O-O-O " << aaaa << endl;
			cout << " ������� 3 ��� ��������� ������� ����: O-O-O   " << aaa << endl;
			cout << " ������� 2 ��� ��������� ������� ����: O-O     " << aa << endl;
			cout << " ������� 1 ��� ��������� ������� ����: O       " << a << endl;

			type = _getch();// ����� �� �������� �� ������, ������� GETCH ��������  ����� ������ (������ ). ����� �� ��������� ���. ����  
			switch (type)//�� 1 �� 4  �� �������� ������� �������. �����, �� ������������ ������� � ������)
			{
			case '1':// ������������� 4 ������� �� 1 ��������
				x = 1; y = 1;
				system("cls");
				while (a != 0)
				{
					system("cls");
					show(matrix, x, y);
					p = _getch();
					if (p == 72 && x > 0)x--;// ������� �����������. 72  80 77 75 - ��� ���� ������� ������� (����, ����, ��� )13 - ENTER
					if (p == 80 && x < 9)x++;
					if (p == 77 && y < 9)y++;
					if (p == 75 && y > 0)y--;
					if (p == 13)// ��������� ��������� ����� �� �������� ����� � ���������� ������ � ������
					{
						matrix[x][y] = 'O'; a -= 1;// O - ��� �������
					}
				}
				break;

			case '2':
				x = 1, x1 = 2; y = 1, y1 = 1;// ���� ����� ��� �������� 2 �����
				system("cls");
				while (aa != 0)
				{
					system("cls");
					show(matrix, x, y, x1, y1);
					p = _getch();
					if (p == 72 && x > 0 && x1 > 0)
					{
						x--; x1--;
					}
					if (p == 80 && x < 9 && x1 < 9)// ����� �� ���������, �� ������� �� ������� �� ����, ���� �� �� ��������. �������� - ������
					{
						x++; x1++;
					}
					if (p == 77 && y < 9 && y1 < 9)
					{
						y++; y1++;
					}
					if (p == 75 && y > 0 && y1 > 0)
					{
						y--; y1--;
					}
					if (p == 32)// 32- ������� ������� 
					{
						if (x < 9 && y < 9)
						{
							if (y == y1)
							{
								x1 -= 1; y1 += 1;//��� �� ������������� ������� �� ����������� 
							}
							else if (x == x1)
							{
								y1 -= 1; x1 += 1;//��� ���������
							}
						}
					}
					if (p == 13)
					{
						matrix[x][y] = 'O';  matrix[x1][y1] = 'O';  aa -= 1;// ������� � ������
					}
				}
				break;
			case '3':

				x = 1, x1 = 2; y = 1, y1 = 1, x2 = 3, y2 = 1;
				system("cls");
				while (aaa != 0)
				{
					system("cls");
					show(matrix, x, y, x1, y1, x2, y2);
					p = _getch();
					if (p == 72 && x > 0 && x2 > 0)
					{
						x--; x1--; x2--;
					}
					if (p == 80 && x < 9 && x2 < 9)
					{
						x++; x1++; x2++;
					}
					if (p == 77 && y < 9 && y2 < 9)
					{
						y++; y1++; y2++;
					}
					if (p == 75 && y > 0 && y2 > 0)
					{
						y--; y1--; y2--;
					}
					if (p == 32)
					{
						if (x < 8 && y < 8)
						{
							if (y == y2)
							{
								x1 -= 1; y1 += 1;
								x2 -= 2; y2 += 2;
							}
							else if (x == x2)
							{
								y1 -= 1; x1 += 1;
								y2 -= 2; x2 += 2;
							}
						}
					}
					if (p == 13)
					{
						matrix[x][y] = 'O';  matrix[x1][y1] = 'O'; matrix[x2][y2] = 'O'; aaa -= 1;
					}
				}
				break;

			case '4':
				x = 1, x1 = 2; x2 = 3, x3 = 4, y = 1, y1 = 1, y2 = 1, y3 = 1;
				system("cls");
				while (aaaa != 0)
				{
					system("cls");
					show(matrix, x, y, x1, y1, x2, y2, x3, y3);
					p = _getch();
					if (p == 72 && x > 0 && x3 > 0)
					{
						x--; x1--; x2--; x3--;
					}
					if (p == 80 && x < 9 && x3 < 9)
					{
						x++; x1++; x2++; x3++;
					}
					if (p == 77 && y < 9 && y3 < 9)
					{
						y++; y1++; y2++, y3++;
					}
					if (p == 75 && y > 0 && y3 > 0)
					{
						y--; y1--; y2--; y3--;
					}
					if (p == 32)
					{
						if (x < 7 && y < 7)
						{
							if (y == y2)
							{
								x1 -= 1; y1 += 1;
								x2 -= 2; y2 += 2;
								x3 -= 3; y3 += 3;
							}
							else if (x == x2)
							{
								y1 -= 1; x1 += 1;
								y2 -= 2; x2 += 2;
								y3 -= 3; x3 += 3;
							}
						}
					}
					if (p == 13)
					{
						matrix[x][y] = 'O';  matrix[x1][y1] = 'O'; matrix[x2][y2] = 'O'; matrix[x3][y3] = 'O'; aaaa -= 1;
					}
				}
				break;
			default:
				break;
			}

		} while (aaaa + aaa + aa + a != 0);// ���� �������� ���� �� �� ��������� ��� �������
		system("cls");
		show(matrix);// ����� ������ ����
		cout << "\n �������������� �������� ����������� \n";
	}
	//////////////////////////////////////////////
	bool hasShips()// �������� �� �� ����� ���� �������? ��������� ������, ���� ��, � ���� � ��������� ������
	{
		bool yeas = false;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (matrix[i][j] == 'O')
				{
					yeas = true;
				}
			}
		}
		return yeas;
	}
	//////////////////////////////////////////////
	bool atack(int x, int y)// ������� ������. � ������� ��, ��� �������� �������� �� ���� ����. �� �������� ����������, � ���� 
	{// ��� ������� ��������� �� ��� (� � ) �� �� ������� �������� ���� 
		bool a = false;
		if (matrix[x][y] == 'O')
		{
			matrix[x][y] = '#';
			a = true;
		}
		return a;
	}
	void show_My()// ���������� ��  ����
	{
		show(matrix);
	}
	void show_Enemy()// ���������� ���� �����, � ������������ ��������, ������� �� �����. 
	{// ������ ������� ��������� � ���� # 
		show_SSS(matrix);
	}

};
//////////////////////////////////////////////

// ��� ������� SHOW - ���������� ����. ������ ��� �����������. �� ����, ��� ���� � �� �� ������� �� � ������� ����������� 
void show_SSS(char** m)
{
	cout << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << "  " << char('a' + i);
	}

	cout << endl << "    -------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << i + 1 << '|';

		for (int j = 0; j < 10; j++)
		{
			if (m[i][j] == '#') cout << "  #";
			if (m[i][j] == '*') cout << "   ";
		}
		cout << endl;
	}
}
//////////////////////////////////////////////
void show(char** m)
{
	cout << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << "  " << char('a' + i);
	}

	cout << endl << "    -------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << i + 1 << '|';

		for (int j = 0; j < 10; j++)
		{
			cout << "  " << m[i][j];
		}
		cout << endl;
	}
}
//////////////////////////////////////////////
void show(char** m, int x, int y)
{
	cout << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << "  " << char('a' + i);
	}

	cout << endl << "    -------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << i + 1 << '|';

		for (int j = 0; j < 10; j++)
		{
			if (i == x && j == y) cout << "  O";
			else { cout << "  " << m[i][j]; }
		}
		cout << endl;
	}
}
//////////////////////////////////////////////
void show(char** m, int x, int y, int x1, int y1)
{
	cout << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << "  " << char('a' + i);
	}

	cout << endl << "    -------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << i + 1 << '|';

		for (int j = 0; j < 10; j++)
		{
			if (i == x && j == y || i == x1 && j == y1) cout << "  O";
			else { cout << "  " << m[i][j]; }
		}
		cout << endl;
	}
}
//////////////////////////////////////////////
void show(char** m, int x, int y, int x1, int y1, int x2, int y2)
{
	cout << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << "  " << char('a' + i);
	}

	cout << endl << "    -------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << i + 1 << '|';

		for (int j = 0; j < 10; j++)
		{
			if (i == x && j == y || i == x1 && j == y1 || i == x2 && j == y2) cout << "  O";
			else { cout << "  " << m[i][j]; }
		}
		cout << endl;
	}
}
//////////////////////////////////////////////
void show(char** m, int x, int y, int x1, int y1, int x2, int y2, int x3, int y3)
{
	cout << "   ";
	for (int i = 0; i < 10; i++)
	{
		cout << "  " << char('a' + i);
	}

	cout << endl << "    -------------------------------" << endl;

	for (int i = 0; i < 10; i++)
	{
		cout << setw(2) << i + 1 << '|';

		for (int j = 0; j < 10; j++)
		{
			if (i == x && j == y || i == x1 && j == y1 || i == x2 && j == y2 || i == x3 && j == y3) cout << "  O";
			else { cout << "  " << m[i][j]; }
		}
		cout << endl;
	}
}
//////////////////////////////////////////////



void gameStart()// ��������� ����
{// ������������ �������
	int step = 1;
	cout << "\n��������� ���� ������ 1\n";
	system("Pause");
	User a;
	cout << "\n��������� ���� ������ 2\n";
	system("Pause");
	User b;
	int x, y;// ���������� �����. ��� ������� �����

	system("cls");
	do
	{
		system("cls");
		if (step == 1)// ���� ������ ������ �����, �� ���������� ��� ����, � ���� �������� ���������, ������� �� ����
		{
			cout << endl;

			a.show_My();// ������� ������ ����
			b.show_Enemy();// ����� ���� ����������
		}
		else// ������ ������ ����� (STEP == 2 
		{
			cout << endl;

			b.show_My();// �� �� �����, ���� ������ 
			a.show_Enemy();// � ���� ���������

		}
		cout << "\n ������� ���������� X Y ��� ��������� ( ������ ����� (" << step << ") )\n";
		cout << " (1-10) = ";
		cin >> x;
		cout << " (a-i) = ";
		cin >> y;
		//y = int(Temp) - 96;

		if (x > 0 && x < 11 && y>0 && y < 11)// �������� ��������� �� ������������
		{
			x -= 1; y -= 1;

			if (step == 1)
			{

				if (b.atack(x, y) == true)// ���� �� ������ �� ������� ���������, �� ��� ������� �� ����.STEP ������� 1
				{
					cout << "\n �� ������ �� ������� ������� ������!!!\n";
					step = 1;
				}
				else// � ��������� ������ ��� ��������� ����������
				{
					cout << "\n �� �� ������ !!!\n";
					step = 2;
				}

				system("Pause");
			}
			else if (step == 2)
			{

				if (a.atack(x, y) == true)// �� �� ����� ��� ������� ������. ���� �� ����� �� ������� ������� ������, �� ��� �� ���
				{
					cout << "\n �� ������ �� ������� ������� ������ !!!\n";
					step = 2;
				}
				else
				{
					cout << "\n �� �� ������ !!!\n";
					step = 1;

				}
				system("Pause");
			}

		}
		else
		{
			cout << "������ �������� ������ ";
		}
	} while (a.hasShips() == true || b.hasShips() == true);// ���� ��� �� ��� ���, ���� � ���� �� �� ���������� ��� �������.
	//
	if (a.hasShips() == false)// ������� �������� �� ������� ����� ��������
	{
		cout << "\n ������ ����� �������  !!!\n";
	}
	else
	{
		cout << "\n ������  ����� �������  !!!\n";// ������ �������
	}
	system("PAUSE");
}




///////////////////////////////////////////
int main()
{
	setlocale(LC_ALL, "RUS");
	gameStart();
	system("pause");
	return 0;
}
///////////////////////////////////////////
