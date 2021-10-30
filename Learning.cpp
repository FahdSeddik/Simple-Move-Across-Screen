// Learning.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>
#include <windows.h>
using namespace std;


const int SCREENX = 30;
const int SCREENY = 10;

void setcursor(bool, DWORD);
HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
void show(COORD, string,string="");
void hide(COORD, string,string="");
void move(COORD &, char);
int main()
{
	COORD c;
	c.X = 0;
	c.Y = 0;
	COORD center;
	center.X = SCREENX / 2;
	center.Y = SCREENY / 2;
	string ch =  "\\(O_O)/";
	string ch1 = "  | |";
	string che = "        ";
	int speed;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), center);
	cout << "Enter latency(10-30): ";
	cin >> speed;
	system("CLS");
	char dirx = 'R';
	char diry = 'D';
	while (true) {
		setcursor(0, 0);
		show(c, ch,ch1);
		Sleep(speed);
		hide(c, che,che);
		move(c, dirx);
		if (c.Y == SCREENY)
			diry = 'U';
		if (c.Y == 0)
			diry = 'D';
		if (c.X == SCREENX) {
			dirx = 'L';
			move(c, diry);
		}
		if (c.X == 0) {
			dirx = 'R';
			move(c, diry);
		}
		
	}

}

void move(COORD &o, char dir) {
	switch (dir) {
	case 'L':
		o.X--;
		break;
	case 'R':
		o.X++;
		break;
	case 'U':
		o.Y--;
		break;
	case'D':
		o.Y++;
		break;
	}

}

void hide(COORD o,string c,string che1) {
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), o);
	cout << c;
	o.Y++;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), o);
	cout << che1;
}

void show(COORD o, string ch,string ch1) {
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), o);
	cout << ch;
	o.Y++;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), o);
	cout << ch1;
}

void setcursor(bool visible, DWORD size) // set bool visible = 0 - invisible, bool visible = 1 - visible
{
	if (size == 0)
	{
		size = 20;	// default cursor size Changing to numbers from 1 to 20, decreases cursor width
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(console, &lpCursor);
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files    
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
