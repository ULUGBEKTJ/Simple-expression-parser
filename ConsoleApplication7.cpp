// ConsoleApplication7.cpp: определяет точку входа для консольного приложения.
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

class   User//класс хранящий массив  10 на 10
{
private:
	char** matrix;
public:



	////////////////////////////////////////////// объявление массива и заполнение его *
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


	////////////////////////////////////////////// метод ввода кораблей. Пробел для разворота, ENter для установка на позицию. защиту от касания с другими кораблями не стал делать !! и без того кода получилось много. 
	void vvod()
	{
		int type, p;// символы ввода : стрелка вниз вверх, направо и налево
		int x, x1, x2, x3, y, y1, y2, y3;// координаты кораблей ( их 4 пары, так как максимальное судно занимает 4 клетки ) 
		int aaaa = 1, aaa = 2, aa = 3, a = 4;// количество кораблей - 1 штука по 4, 3 штуки по 2 и тд
		do
		{
			system("cls");
			show(matrix);
			cout << "\n введите тип корабля\n";
			cout << " нажмите 4 для установки корабля типа: O-O-O-O " << aaaa << endl;
			cout << " нажмите 3 для установки корабля типа: O-O-O   " << aaa << endl;
			cout << " нажмите 2 для установки корабля типа: O-O     " << aa << endl;
			cout << " нажмите 1 для установки корабля типа: O       " << a << endl;

			type = _getch();// когда вы нажимаем на кнопку, функция GETCH забирает  номер кнопки (символ ). Затем мы проверяем его. если  
			switch (type)//от 1 до 4  то начинаем ставить корабли. иначе, всё возвращается обратно к выбору)
			{
			case '1':// устанавливаем 4 корабля по 1 клеточке
				x = 1; y = 1;
				system("cls");
				while (a != 0)
				{
					system("cls");
					show(matrix, x, y);
					p = _getch();
					if (p == 72 && x > 0)x--;// функции перемещения. 72  80 77 75 - это коды клавиши стрелок (верх, вниз, итд )13 - ENTER
					if (p == 80 && x < 9)x++;
					if (p == 77 && y < 9)y++;
					if (p == 75 && y > 0)y--;
					if (p == 13)// программа распознаёт когда мы нажимаем интер и записывает данные в массив
					{
						matrix[x][y] = 'O'; a -= 1;// O - это корабль
					}
				}
				break;

			case '2':
				x = 1, x1 = 2; y = 1, y1 = 1;// тоже самое для кораблей 2 ранга
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
					if (p == 80 && x < 9 && x1 < 9)// здесь мы проверяем, не выходят ли корабли из поля, если мы их развернёи. РАзворот - пробел
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
					if (p == 32)// 32- клавиша пробела 
					{
						if (x < 9 && y < 9)
						{
							if (y == y1)
							{
								x1 -= 1; y1 += 1;//так мы разворачиваем корабль по горизонтали 
							}
							else if (x == x1)
							{
								y1 -= 1; x1 += 1;//или вертикали
							}
						}
					}
					if (p == 13)
					{
						matrix[x][y] = 'O';  matrix[x1][y1] = 'O';  aa -= 1;// записиь в массив
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

		} while (aaaa + aaa + aa + a != 0);// цикл работает пока мы не разместим все корабли
		system("cls");
		show(matrix);// показ нашего поля
		cout << "\n местоположение кораблей установлено \n";
	}
	//////////////////////////////////////////////
	bool hasShips()// осталось ли на нашем поле корабля? взвращает Истину, если да, и ложь в противном случае
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
	bool atack(int x, int y)// функция аттаки. с помощью неё, наш оппонент нападает на наше поле. мы получаем ккординаты, и если 
	{// наш корабль находится по ним (Х У ) то мы корабль получает урон 
		bool a = false;
		if (matrix[x][y] == 'O')
		{
			matrix[x][y] = '#';
			a = true;
		}
		return a;
	}
	void show_My()// показывает моё  поле
	{
		show(matrix);
	}
	void show_Enemy()// показывает поле врага, с координатами кораблей, которые мы сбили. 
	{// сбитые корабли выводятся в виде # 
		show_SSS(matrix);
	}

};
//////////////////////////////////////////////

// все функции SHOW - показывают поле. только они перегружены. то есть, это одни и те же функции но с разными параметрами 
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



void gameStart()// запускаем игру
{// регистрируем игроков
	int step = 1;
	cout << "\nЗаполните поле игрока 1\n";
	system("Pause");
	User a;
	cout << "\nЗаполните поле игрока 2\n";
	system("Pause");
	User b;
	int x, y;// переменные атаки. для функции атаки

	system("cls");
	do
	{
		system("cls");
		if (step == 1)// если играет первый игрок, то показываем его поле, и поле кораблей соперника, которое он сбил
		{
			cout << endl;

			a.show_My();// функция показа поля
			b.show_Enemy();// показ поля противника
		}
		else// играет второй игрок (STEP == 2 
		{
			cout << endl;

			b.show_My();// то же самое, поле игрока 
			a.show_Enemy();// и поле соперника

		}
		cout << "\n введите координаты X Y для нападения ( играет игрок (" << step << ") )\n";
		cout << " (1-10) = ";
		cin >> x;
		cout << " (a-i) = ";
		cin >> y;
		//y = int(Temp) - 96;

		if (x > 0 && x < 11 && y>0 && y < 11)// проверка координат на правильность
		{
			x -= 1; y -= 1;

			if (step == 1)
			{

				if (b.atack(x, y) == true)// если мы попали по корабля соперника, то ход остаётся за нами.STEP остаётся 1
				{
					cout << "\n вы попали по кораблю второго игрока!!!\n";
					step = 1;
				}
				else// в противном случае ход передаётся противнику
				{
					cout << "\n вы не попали !!!\n";
					step = 2;
				}

				system("Pause");
			}
			else if (step == 2)
			{

				if (a.atack(x, y) == true)// то же самое для второго игрока. если он попал по кораблю первого игрока, то ход за ним
				{
					cout << "\n вы попали по кораблю первого игрока !!!\n";
					step = 2;
				}
				else
				{
					cout << "\n вы не попали !!!\n";
					step = 1;

				}
				system("Pause");
			}

		}
		else
		{
			cout << "Ошибка введённых данных ";
		}
	} while (a.hasShips() == true || b.hasShips() == true);// игра идёт до тех пор, пока у кого то не разрушатся все корабли.
	//
	if (a.hasShips() == false)// функция проверки на наличие живых кораблей
	{
		cout << "\n второй игрок победил  !!!\n";
	}
	else
	{
		cout << "\n первый  игрок победил  !!!\n";// победа игроков
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
