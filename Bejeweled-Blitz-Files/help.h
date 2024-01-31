#pragma once
#include <windows.h>
#include<iostream>
using namespace std;

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

void myLine(int x1, int y1, int x2, int y2, int R, int G, int B) //use three 3 integers if you want colored lines.
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255) to get shades of gray. For other colors use 3 integers for colors.
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B)); //2 is the width of the pen
	SelectObject(device_context, pen);
	MoveToEx(device_context, x1, y1, NULL);
	LineTo(device_context, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);

}

void myCursor(int x, int y, int R, int G, int B) {
	myLine(x, y, x, y + 55, R, G, B);
	myLine(x, y, x + 55, y, R, G, B);
	myLine(x, y + 55, x + 55, y + 55, R, G, B);
	myLine(x + 55, y, x + 55, y + 55, R, G, B);
}


// This function checks if any of the 4 cursor keys are pressed. 
// If any cursor key is pressed, then the function returns true, and whichKey identifies which of the 4 cursor keys is pressed.
// whichkey is assigned following values if any cursor key is pressed. 1 for left, 2 for up, 3 for right and 4 for left.
bool isCursorKeyPressed(int& whichKey)   //whichKey passed as reference.... 
{
	char key;
	key = GetAsyncKeyState(37);
	if (key == 1)
	{
		whichKey = 1;		// 1 if left key is pressed 
		return true;
	}
	key = GetAsyncKeyState(38);
	if (key == 1)
	{

		whichKey = 2;		// 2 if up key is pressed
		return true;
	}

	key = GetAsyncKeyState(39);
	if (key == 1)
	{

		whichKey = 3; // 3 if right key is pressed
		return true;
	}
	key = GetAsyncKeyState(40);
	if (key == 1)
	{

		whichKey = 4;   // 4 if down key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_RETURN);
	if (key == 1)
	{

		whichKey = 5;   // 5 if enter key is pressed
		return true;
	}
	key = GetAsyncKeyState(VK_ESCAPE);
	if (key == 1) {

		whichKey = 6; // 6 if escape key is pressed
		return true;
	}
	return false;
}

void myRectangle(int x1, int y1, int x2, int y2, int R, int G, int B, int R1, int G1, int B1)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R1, G1, B1)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
}



void myEllipse(int x1, int y1, int x2, int y2, int R, int G, int B, int R1, int G1, int B1)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R1, G1, B1));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x2, y2);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}
void mySmallerTriangle(int x, int y, int R, int G, int B)
{
	POINT coord[3] = { {x + 20,y + 5},{x + 5,y + 35},{x + 35,y + 35} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 3);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}

void mySmallerPentagon(int x, int y, int R, int G, int B) {
	POINT coord[5] = { {x + 5,y + 20},{x + 15,y + 35},{x + 25,y + 35},{x + 35,y + 20},{x + 20,y + 5} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 5);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

}

void mySmallerRhombus(int x, int y, int R, int G, int B) {
	POINT coord[4] = { {x + 5,y + 20},{x + 20,y + 35},{x + 35,y + 20},{x + 20,y + 5} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 4);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);


}


void mySquare(int x1, int y1, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B)); //Fill color can also be passed as parameter to the function!!!

	SelectObject(device_context, brush);

	Rectangle(device_context, x1, y1, x1 + 40, y1 + 40);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	myRectangle(x1 + 5, y1 + 5, x1 + 35, y1 + 35, 191, 11, 11, 191, 11, 11);
}



void myCircle(int x1, int y1, int R, int G, int B)
{
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Ellipse(device_context, x1, y1, x1 + 40, y1 + 40);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	myEllipse(x1 + 5, y1 + 5, x1 + 35, y1 + 35, 155, 0, 166, 155, 0, 166);

}

void myGemTriangle(int x, int y, int R, int G, int B)
{
	POINT coord[3] = { {x + 20,y},{x,y + 40},{x + 40,y + 40} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 3);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);
	mySmallerTriangle(x, y, 2, 172, 1);
}


void myGemPentagon(int x, int y, int R, int G, int B) {
	POINT coord[5] = { {x,y + 20},{x + 10,y + 40},{x + 30,y + 40},{x + 40,y + 20},{x + 20,y} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 5);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	mySmallerPentagon(x, y, 0, 162, 162);

}

void myGemRhombus(int x, int y, int R, int G, int B) {
	POINT coord[4] = { {x,y + 20},{x + 20,y + 40},{x + 40,y + 20},{x + 20,y} };
	HWND console_handle = GetConsoleWindow();
	HDC device_context = GetDC(console_handle);

	//change the color by changing the values in RGB (from 0-255)
	HPEN pen = CreatePen(PS_SOLID, 2, RGB(R, G, B));
	SelectObject(device_context, pen);
	HBRUSH brush = ::CreateSolidBrush(RGB(R, G, B));  //Fill color is black
	SelectObject(device_context, brush);
	Polygon(device_context, coord, 4);
	ReleaseDC(console_handle, device_context);
	DeleteObject(pen);
	DeleteObject(brush);

	mySmallerRhombus(x, y, 182, 218, 5);


}
void drawDigit(int digit, int x, int y) {
	if (digit == 1) {
		myLine(x + 7.5, y, x + 7.5, y + 30, 255, 255, 255);
		myLine(x + 7.5, y, x, y + 7.5, 255, 255, 255);
		myLine(x, y + 30, x + 12, y + 30, 255, 255, 255);

	}
	else if (digit == 2) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 15, 255, 255, 255);
		myLine(x + 15, y + 15, x, y + 15, 255, 255, 255);
		myLine(x, y + 15, x, y + 30, 255, 255, 255);
		myLine(x, y + 30, x + 15, y + 30, 255, 255, 255);
	}
	else if (digit == 3) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 30, 255, 255, 255);
		myLine(x + 15, y + 15, x, y + 15, 255, 255, 255);
		myLine(x + 15, y + 30, x, y + 30, 255, 255, 255);
	}
	else if (digit == 4) {
		myLine(x, y, x, y + 15, 255, 255, 255);
		myLine(x, y + 15, x + 15, y + 15, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 30, 255, 255, 255);

	}
	else if (digit == 5) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x, y, x, y + 15, 255, 255, 255);
		myLine(x, y + 15, x + 15, y + 15, 255, 255, 255);
		myLine(x + 15, y + 15, x + 15, y + 30, 255, 255, 255);
		myLine(x + 15, y + 30, x, y + 30, 255, 255, 255);
	}
	else if (digit == 6) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x, y, x, y + 30, 255, 255, 255);
		myLine(x, y + 15, x + 15, y + 15, 255, 255, 255);
		myLine(x + 15, y + 15, x + 15, y + 30, 255, 255, 255);
		myLine(x + 15, y + 30, x, y + 30, 255, 255, 255);

	}
	else if (digit == 7) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 30, 255, 255, 255);

	}
	else if (digit == 8) {
		myLine(x, y, x, y + 30, 255, 255, 255);
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 30, 255, 255, 255);
		myLine(x, y + 30, x + 15, y + 30, 255, 255, 255);
		myLine(x, y + 15, x + 15, y + 15, 255, 255, 255);

	}
	else if (digit == 9) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x, y, x, y + 15, 255, 255, 255);
		myLine(x, y + 15, x + 15, y + 15, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 30, 255, 255, 255);
		myLine(x, y + 30, x + 15, y + 30, 255, 255, 255);
	}
	else if (digit == 0) {
		myLine(x, y, x + 15, y, 255, 255, 255);
		myLine(x, y, x, y + 30, 255, 255, 255);
		myLine(x, y + 30, x + 15, y + 30, 255, 255, 255);
		myLine(x + 15, y, x + 15, y + 30, 255, 255, 255);

	}
}

void drawScore(int score) {
	//draw rectangle over previous score
	myRectangle(630, 90, 744, 140, 255, 255, 255, 0, 0, 0);
	int changing_score = score;
	int digit;
	int reversed = 0, factor = 10;
	int x = 640, y = 100;
	if (score % 10 == 0) {
		changing_score = changing_score + 1;
	}
	while (changing_score != 0) {
		digit = changing_score % 10;
		changing_score = changing_score / 10;
		reversed = (reversed * factor) + digit;



	}
	while (reversed != 0) {
		digit = reversed % 10;
		reversed = reversed / 10;
		if (score % 10 == 0) {
			if (reversed == 0) {
				drawDigit(0, x, y);
			}
			else {
				drawDigit(digit, x, y);
			}
		}
		else {
			drawDigit(digit, x, y);
		}
		x = x + 23;
	}

}

void drawTime(int time) {
	//draw rectangle over previous time
	myRectangle(630, 290, 744, 340, 255, 255, 255, 0, 0, 0);
	int changing_time = time;
	int digit;
	int reversed = 0, factor = 10;
	int x = 640, y = 300;
	if (time % 10 == 0) {
		changing_time = changing_time + 1;
	}
	while (changing_time != 0) {
		digit = changing_time % 10;
		changing_time = changing_time / 10;
		reversed = (reversed * factor) + digit;



	}
	while (reversed != 0) {
		digit = reversed % 10;
		reversed = reversed / 10;
		if (time % 10 == 0) {
			if (reversed == 0) {
				drawDigit(0, x, y);
			}
			else {
				drawDigit(digit, x, y);
			}
		}
		else {
			drawDigit(digit, x, y);
		}
		x = x + 23;
	}

}

void draw_the_word_score() {
	int R = 255, G = 255, B = 255;
	int x = 600, y = 20;
	//letter S
	myLine(x, y, x + 25, y, R, G, B);
	myLine(x, y, x, y + 25, R, G, B);
	myLine(x, y + 25, x + 25, y + 25, R, G, B);
	myLine(x + 25, y + 25, x + 25, y + 50, R, G, B);
	myLine(x + 25, y + 50, x, y + 50, R, G, B);

	x = x + 37;

	//letter C
	myLine(x, y, x + 25, y, R, G, B);
	myLine(x, y, x, y + 50, R, G, B);
	myLine(x, y + 50, x + 25, y + 50, R, G, B);

	x = x + 37;

	//letter O
	myLine(x, y, x + 25, y, R, G, B);
	myLine(x, y, x, y + 50, R, G, B);
	myLine(x, y + 50, x + 25, y + 50, R, G, B);
	myLine(x + 25, y, x + 25, y + 50, R, G, B);

	x = x + 37;

	//letter R
	myLine(x, y, x + 25, y, R, G, B);
	myLine(x, y, x, y + 50, R, G, B);
	myLine(x + 25, y, x + 25, y + 25, R, G, B);
	myLine(x, y + 25, x + 25, y + 25, R, G, B);
	myLine(x, y + 25, x + 25, y + 50, R, G, B);

	x = x + 37;

	//letter E
	myLine(x, y, x, y + 50, R, G, B);
	myLine(x, y, x + 25, y, R, G, B);
	myLine(x, y + 50, x + 25, y + 50, R, G, B);
	myLine(x, y + 25, x + 25, y + 25, R, G, B);
}

void draw_the_word_time() {
	int R = 255, G = 255, B = 255;
	int x = 600, y = 220;
	//letter T
	myLine(x, y, x + 30, y, R, G, B);
	myLine(x+15, y, x+15, y + 50, R, G, B);
	

	x = x + 37;

	//letter I
	myLine(x, y, x + 30, y, R, G, B);
	myLine(x + 15, y, x + 15, y + 50, R, G, B);
	myLine(x, y+50, x + 30, y+50, R, G, B);

	x = x + 37;

	//letter M
	myLine(x, y, x, y + 50, R, G, B);
	myLine(x + 30, y, x + 30, y + 50, R, G, B);
	myLine(x, y, x + 15, y + 25, R, G, B);
	myLine(x + 30, y, x + 15, y + 25, R, G, B);

	x = x + 37;

	//letter E
	myLine(x, y, x, y + 50, R, G, B);
	myLine(x, y, x + 25, y, R, G, B);
	myLine(x, y + 50, x + 25, y + 50, R, G, B);
	myLine(x, y + 25, x + 25, y + 25, R, G, B);
}