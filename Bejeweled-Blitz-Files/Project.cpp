#include<iostream>
#include"help.h"
#include<windows.h>
#include<conio.h>
#include<time.h>
#include <thread>
#include <chrono>
using namespace std;


int key = 0;
bool key_pressed = false;
bool gameover = false;
int time_elapsed = 0;

void timerThread() {
	
	using namespace std::chrono;

		//auto start_time = high_resolution_clock::now();

		while (true) {
			if ((key_pressed) && !gameover) {
				//auto current_time = high_resolution_clock::now();
				//auto elapsed_time = duration_cast<seconds>(current_time - start_time);

				//std::cout << "Time elapsed: " << elapsed_time.count() << " seconds" << std::endl;
				//drawTime(elapsed_time.count());
				drawTime(time_elapsed);
				if (time_elapsed >= 120) {
					gameover = true;
				}

				// Sleep for 1 second before the next update
				std::this_thread::sleep_for(seconds(1));
				time_elapsed++;
			}
			
		}
	
}

//Assigning values to 2-D array
void assigningvalues(int b[][8])
{
	int x;
	srand(time(0));
	int arr[5] = { 1,2,3,4,5 };
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			x = rand() % 5;
			b[i][j] = arr[x];
		}
	}
}
//Printing shapes based on the numbers from 2-D array
void printboard(int b[][8])
{
	myRectangle(20, 20, 475, 475, 255, 255, 255, 0, 0, 0);
	int x = 35, y = 35;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			//for regular gems of each type
			if (b[i][j] == 1) {
				mySquare(x, y, 128, 0, 0);
			}
			else if (b[i][j] == 2) {
				myCircle(x, y, 106, 0, 114);
			}
			else if (b[i][j] == 3) {
				myGemPentagon(x, y, 0, 74, 74);
			}
			else if (b[i][j] == 4) {
				myGemRhombus(x, y, 126, 151, 0);
			}
			else if (b[i][j] == 5) {
				myGemTriangle(x, y, 0, 102, 0);
			}
			//for flame gems of each type
			else if (b[i][j] == 6) {
				mySquare(x, y, 255, 94, 0);
			}
			else if (b[i][j] == 7) {
				myCircle(x, y, 255, 94, 0);
			}
			else if (b[i][j] == 8) {
				myGemPentagon(x, y, 255, 94, 0);
			}
			else if (b[i][j] == 9) {
				myGemRhombus(x, y, 255, 94, 0);
			}
			else if (b[i][j] == 10) {
				myGemTriangle(x, y, 255, 94, 0);
			}
			//for destroyer gems of each type
			else if (b[i][j] == 11) {
				mySquare(x, y, 255, 255, 255);
			}
			else if (b[i][j] == 12) {
				myCircle(x, y, 255, 255, 255);
			}
			else if (b[i][j] == 13) {
				myGemPentagon(x, y, 255, 255, 255);
			}
			else if (b[i][j] == 14) {
				myGemRhombus(x, y, 255, 255, 255);
			}
			else if (b[i][j] == 15) {
				myGemTriangle(x, y, 255, 255, 255);
			}
			x = x + 55;

		}
		x = 35;
		y = y + 55;
		cout << endl;
	}
}

//Set the new position of the row and columns when the gems pops
void uppdown(int b[][8], int i, int j, int found)
{
	int x;
	srand(time(0));
	int arr[5] = { 1,2,3,4,5 };
	if (found == 1)
	{
		while (i != 0)
		{
			b[i][j] = b[i - 1][j];
			b[i][j + 1] = b[i - 1][j + 1];
			b[i][j + 2] = b[i - 1][j + 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j] = arr[x];
			x = rand() % 5;
			b[i][j + 1] = arr[x];
			x = rand() % 5;
			b[i][j + 2] = arr[x];
		}
	}
	else if (found == 2)
	{
		if (((j + 2) - 3) >= 0)
		{
			b[j + 2][i] = b[(j + 2) - 3][i];
		}
		else
		{
			x = rand() % 5;
			b[j + 2][i] = arr[x];
		}
		if ((j + 1) - 3 >= 0)
		{
			b[j + 1][i] = b[(j + 1) - 3][i];
		}
		else
		{
			x = rand() % 5;
			b[j + 1][i] = arr[x];
		}
		if (j - 3 >= 0)
		{
			b[j][i] = b[j - 3][i];
		}
		else
		{
			x = rand() % 5;
			b[j][i] = arr[x];
		}
		j--;
		while (j >= 0)
		{
			if (j - 3 >= 0)
			{
				b[j][i] = b[j - 3][i];
			}
			else
			{
				x = rand() % 5;
				b[j][i] = arr[x];
			}
			j--;
		}
	}
	else if (found == 3)
	{
		if (j == 7)
		{
			if (j - 2 >= 0)
			{
				b[j][i] = b[j - 2][i];
				if (i > 0)
				{
					b[j][i - 1] = b[j - 2][i - 1];
				}
				if (i < 7)
				{
					b[j][i + 1] = b[j - 2][i + 1];
				}
			}
			else
			{
				x = rand() % 5;
				b[j][i] = arr[x];
				if (i > 0)
				{
					x = rand() % 5;
					b[j][i - 1] = arr[x];
				}
				if (i < 7)
				{
					x = rand() % 5;
					b[j][i + 1] = arr[x];
				}
			}
			if (j > 0)
			{
				if ((j - 1) - 2 >= 0)
				{
					b[j - 1][i] = b[(j - 1) - 2][i];
					if (i > 0)
					{
						b[j - 1][i - 1] = b[(j - 1) - 2][i - 1];
					}
					if (i < 7)
					{
						b[j - 1][i + 1] = b[(j - 1) - 2][i + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[j - 1][i] = arr[x];
					if (i > 0)
					{
						x = rand() % 5;
						b[j - 1][i - 1] = arr[x];
					}
					if (i < 7)
					{
						x = rand() % 5;
						b[j - 1][i + 1] = arr[x];
					}
				}
			}
			j = j - 2;
			while (j >= 0)
			{
				if (j - 2 >= 0)
				{
					b[j][i] = b[j - 2][i];
					if (i > 0)
					{
						b[j][i - 1] = b[j - 2][i - 1];
					}
					if (i < 7)
					{
						b[j][i + 1] = b[j - 2][i + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[j][i] = arr[x];
					if (i > 0)
					{
						x = rand() % 5;
						b[j][i - 1] = arr[x];
					}
					if (i < 7)
					{
						x = rand() % 5;
						b[j][i + 1] = arr[x];
					}
				}
				j--;
			}
		}
		else
		{
			if (j < 7)
			{
				if (((j + 1) - 3) >= 0)
				{
					b[j + 1][i] = b[(j + 1) - 3][i];
					if (i > 0)
					{
						b[j + 1][i - 1] = b[(j + 1) - 3][i - 1];
					}
					if (i < 7)
					{
						b[j + 1][i + 1] = b[(j + 1) - 3][i + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[j + 1][i] = arr[x];
					if (i > 0)
					{
						x = rand() % 5;
						b[j + 1][i - 1] = arr[x];
					}
					if (i < 7)
					{
						x = rand() % 5;
						b[j + 1][i + 1] = arr[x];
					}
				}
			}
			if (j - 3 >= 0)
			{
				b[j][i] = b[j - 3][i];
				if (i > 0)
				{
					b[j][i - 1] = b[j - 3][i - 1];
				}
				if (i < 7)
				{
					b[j][i + 1] = b[j - 3][i + 1];
				}
			}
			else
			{
				x = rand() % 5;
				b[j][i] = arr[x];
				if (i > 0)
				{
					x = rand() % 5;
					b[j][i - 1] = arr[x];
				}
				if (i < 7)
				{
					x = rand() % 5;
					b[j][i + 1] = arr[x];
				}
			}
			if (j > 0)
			{
				if ((j - 1) - 3 >= 0)
				{
					b[j - 1][i] = b[(j - 1) - 3][i];
					if (i > 0)
					{
						b[j - 1][i - 1] = b[(j - 1) - 3][i - 1];
					}
					if (i < 7)
					{
						b[j - 1][i + 1] = b[(j - 1) - 3][i + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[j - 1][i] = arr[x];
					if (i > 0)
					{
						x = rand() % 5;
						b[j - 1][i - 1] = arr[x];
					}
					if (i < 7)
					{
						x = rand() % 5;
						b[j - 1][i + 1] = arr[x];
					}
				}
			}
			j = j - 2;
			while (j >= 0)
			{
				if (j - 3 >= 0)
				{
					b[j][i] = b[j - 3][i];
					if (i > 0)
					{
						b[j][i - 1] = b[j - 3][i - 1];
					}
					if (i < 7)
					{
						b[j][i + 1] = b[j - 3][i + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[j][i] = arr[x];
					if (i > 0)
					{
						x = rand() % 5;
						b[j][i - 1] = arr[x];
					}
					if (i < 7)
					{
						x = rand() % 5;
						b[j][i + 1] = arr[x];
					}
				}
				j--;
			}
		}
	}
	else if (found == 4)
	{
		if (i == 7)
		{
			if (i - 2 >= 0)
			{
				b[i][j] = b[i - 2][j];
				if (j > 0)
				{
					b[i][j - 1] = b[i - 2][j - 1];
				}
				if (j < 7)
				{
					b[i][j + 1] = b[i - 2][j + 1];
				}
			}
			else
			{
				x = rand() % 5;
				b[i][j] = arr[x];
				if (j > 0)
				{
					x = rand() % 5;
					b[i][j - 1] = arr[x];
				}
				if (j < 7)
				{
					x = rand() % 5;
					b[i][j + 1] = arr[x];
				}
			}
			if (i > 0)
			{
				if ((i - 1) - 2 >= 0)
				{
					b[i - 1][j] = b[(i - 1) - 2][j];
					if (j > 0)
					{
						b[i - 1][j - 1] = b[(i - 1) - 2][j - 1];
					}
					if (j < 7)
					{
						b[i - 1][j + 1] = b[(i - 1) - 2][j + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[i - 1][j] = arr[x];
					if (j > 0)
					{
						x = rand() % 5;
						b[i - 1][j - 1] = arr[x];
					}
					if (j < 7)
					{
						x = rand() % 5;
						b[i - 1][j + 1] = arr[x];
					}
				}
			}
			i = i - 2;
			while (i >= 0)
			{
				if (i - 2 >= 0)
				{
					b[i][j] = b[i - 2][j];
					if (j > 0)
					{
						b[i][j - 1] = b[i - 2][j - 1];
					}
					if (j < 7)
					{
						b[i][j + 1] = b[i - 2][j + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[i][j] = arr[x];
					if (j > 0)
					{
						x = rand() % 5;
						b[i][j - 1] = arr[x];
					}
					if (j < 7)
					{
						x = rand() % 5;
						b[i][j + 1] = arr[x];
					}
				}
				i--;
			}
		}
		else
		{
			if (i < 7)
			{
				if (((i + 1) - 3) >= 0)
				{
					b[i + 1][j] = b[(i + 1) - 3][j];
					if (j > 0)
					{
						b[i + 1][j - 1] = b[(i + 1) - 3][j - 1];
					}
					if (j < 7)
					{
						b[i + 1][j + 1] = b[(i + 1) - 3][j + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[i + 1][j] = arr[x];
					if (j > 0)
					{
						x = rand() % 5;
						b[i + 1][j - 1] = arr[x];
					}
					if (j < 7)
					{
						x = rand() % 5;
						b[i + 1][j + 1] = arr[x];
					}
				}
			}
			if (i - 3 >= 0)
			{
				b[i][j] = b[i - 3][j];
				if (j > 0)
				{
					b[i][j - 1] = b[i - 3][j - 1];
				}
				if (j < 7)
				{
					b[i][j + 1] = b[i - 3][j + 1];
				}
			}
			else
			{
				x = rand() % 5;
				b[i][j] = arr[x];
				if (j > 0)
				{
					x = rand() % 5;
					b[i][j - 1] = arr[x];
				}
				if (j < 7)
				{
					x = rand() % 5;
					b[i][j + 1] = arr[x];
				}
			}
			if (i > 0)
			{
				if ((i - 1) - 3 >= 0)
				{
					b[i - 1][j] = b[(i - 1) - 3][j];
					if (j > 0)
					{
						b[i - 1][j - 1] = b[(i - 1) - 3][j - 1];
					}
					if (j < 7)
					{
						b[i - 1][j + 1] = b[(i - 1) - 3][j + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[i - 1][j] = arr[x];
					if (j > 0)
					{
						x = rand() % 5;
						b[i - 1][j - 1] = arr[x];
					}
					if (j < 7)
					{
						x = rand() % 5;
						b[i - 1][j + 1] = arr[x];
					}
				}
			}
			i = i - 2;
			while (i >= 0)
			{
				if (i - 3 >= 0)
				{
					b[i][j] = b[i - 3][j];
					if (j > 0)
					{
						b[i][j - 1] = b[i - 3][j - 1];
					}
					if (j < 7)
					{
						b[i][j + 1] = b[i - 3][j + 1];
					}
				}
				else
				{
					x = rand() % 5;
					b[i][j] = arr[x];
					if (j > 0)
					{
						x = rand() % 5;
						b[i][j - 1] = arr[x];
					}
					if (j < 7)
					{
						x = rand() % 5;
						b[i][j + 1] = arr[x];
					}
				}
				i--;
			}

		}

	}
	else if (found == 5 || found == 6)
	{
		while (i != 0)
		{
			for (int k = 0; k < 8; k++)
			{
				b[i][k] = b[i - 1][k];
			}
			i--;
		}
		if (i == 0)
		{
			for (int k = 0; k < 8; k++)
			{
				x = rand() % 5;
				b[i][k] = arr[x];
			}
		}
		for (int k = 0; k < 8; k++)
		{
			x = rand() % 5;
			b[k][j] = arr[x];
		}
	}
}
//Adjust the position of rows anad columns when any special gem is created and place it in right position
void specialupdown(int b[][8], int i, int j, int found)
{
	int x;
	srand(time(0));
	int arr[5] = { 1,2,3,4,5 };

	if (found == 1)
	{
		b[i][j] = b[i][j] + 5;
		while (i != 0)
		{
			b[i][j - 1] = b[i - 1][j - 1];
			b[i][j + 1] = b[i - 1][j + 1];
			b[i][j + 2] = b[i - 1][j + 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j - 1] = arr[x];
			x = rand() % 5;
			b[i][j + 1] = arr[x];
			x = rand() % 5;
			b[i][j + 2] = arr[x];
		}
	}
	if (found == 2)
	{
		b[i][j] = b[i][j] + 5;
		while (i != 0)
		{
			b[i][j - 1] = b[i - 1][j - 1];
			b[i][j - 2] = b[i - 1][j - 2];
			b[i][j + 1] = b[i - 1][j + 1];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j - 1] = arr[x];
			x = rand() % 5;
			b[i][j - 2] = arr[x];
			x = rand() % 5;
			b[i][j + 1] = arr[x];
		}
	}

	if (found == 3)
	{
		b[i + 3][j] = b[i + 3][j] + 5;
		if (((i + 2) - 3) >= 0)
		{
			b[i + 2][j] = b[(i + 2) - 3][j];
		}
		else
		{
			x = rand() % 5;
			b[i + 2][j] = arr[x];
		}
		if (((i + 1) - 3) >= 0)
		{
			b[i + 1][j] = b[(i + 1) - 3][j];
		}
		else
		{
			x = rand() % 5;
			b[i + 1][j] = arr[x];
		}
		if ((i - 3) >= 0)
		{
			b[i][j] = b[i - 3][j];
		}
		else
		{
			x = rand() % 5;
			b[i][j] = arr[x];
		}
		i--;
		while (i >= 0)
		{
			if (i - 3 >= 0)
			{
				b[i][j] = b[i - 3][j];
			}
			else
			{
				x = rand() % 5;
				b[i][j] = arr[x];
			}
			i--;
		}
	}
	if (found == 4)
	{
		b[i + 4][j] = b[i + 4][j] + 5;
		if (((i + 3) - 4) >= 0)
		{
			b[i + 3][j] = b[(i + 3) - 4][j];
		}
		else
		{
			x = rand() % 5;
			b[i + 3][j] = arr[x];
		}
		if (((i + 2) - 4) >= 0)
		{
			b[i + 2][j] = b[(i + 2) - 4][j];
		}
		else
		{
			x = rand() % 5;
			b[i + 2][j] = arr[x];
		}
		if (((i + 1) - 4) >= 0)
		{
			b[i + 1][j] = b[(i + 1) - 4][j];
		}
		else
		{
			x = rand() % 5;
			b[i + 1][j] = arr[x];
		}
		if ((i - 4) >= 0)
		{
			b[i][j] = b[i - 4][j];
		}
		else
		{
			x = rand() % 5;
			b[i][j] = arr[x];
		}
		i--;
		while (i >= 0)
		{
			if (i - 4 >= 0)
			{
				b[i][j] = b[i - 4][j];
			}
			else
			{
				x = rand() % 5;
				b[i][j] = arr[x];
			}
			i--;
		}
	}
	if (found == 5)
	{
		b[i][j] = b[i][j] + 5;
		while (i != 0)
		{
			b[i][j - 1] = b[i - 1][j - 1];
			b[i][j - 2] = b[i - 1][j - 2];
			b[i][j + 1] = b[i - 1][j + 1];
			b[i][j + 2] = b[i - 1][j + 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j - 1] = arr[x];
			x = rand() % 5;
			b[i][j - 2] = arr[x];
			x = rand() % 5;
			b[i][j + 1] = arr[x];
			x = rand() % 5;
			b[i][j + 2] = arr[x];
		}
	}
	if (found == 6)
	{
		int k = i, l = j;
		b[i - 2][j] = b[i][j] + 10;
		while (i != 0)
		{
			b[i][j + 1] = b[i - 1][j + 1];
			b[i][j + 2] = b[i - 1][j + 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j + 1] = arr[x];
			x = rand() % 5;
			b[i][j + 2] = arr[x];
		}

		if (((k + 1) - 2) >= 0)
		{
			b[k + 1][l] = b[(k + 1) - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k + 1][l] = arr[x];
		}
		if ((k - 2) >= 0)
		{
			b[k][l] = b[k - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k][l] = arr[x];
		}
		k--;
		while (k >= 0)
		{
			if (k - 2 >= 0)
			{
				b[k][l] = b[k - 2][l];
			}
			else
			{
				x = rand() % 5;
				b[k][l] = arr[x];
			}
			k--;
		}
	}
	if (found == 7)
	{
		int k = i, l = j;
		b[i - 2][j] = b[i][j] + 10;
		while (i != 0)
		{
			b[i][j - 1] = b[i - 1][j - 1];
			b[i][j - 2] = b[i - 1][j - 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j - 1] = arr[x];
			x = rand() % 5;
			b[i][j - 2] = arr[x];
		}

		if (((k + 1) - 2) >= 0)
		{
			b[k + 1][l] = b[(k + 1) - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k + 1][l] = arr[x];
		}
		if ((k - 2) >= 0)
		{
			b[k][l] = b[k - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k][l] = arr[x];
		}
		k--;
		while (k >= 0)
		{
			if (k - 2 >= 0)
			{
				b[k][l] = b[k - 2][l];
			}
			else
			{
				x = rand() % 5;
				b[k][l] = arr[x];
			}
			k--;
		}
	}
	if (found == 8)
	{
		int k = i, l = j;
		b[i][j] = b[i][j] + 10;
		while (i != 0)
		{
			b[i][j + 1] = b[i - 1][j + 1];
			b[i][j + 2] = b[i - 1][j + 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j + 1] = arr[x];
			x = rand() % 5;
			b[i][j + 2] = arr[x];
		}

		if (((k - 1) - 2) >= 0)
		{
			b[k - 1][l] = b[(k - 1) - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k - 1][l] = arr[x];
		}
		if (((k - 2) - 2) >= 0)
		{
			b[k][l] = b[(k - 2) - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k - 2][l] = arr[x];
		}
		k = k - 3;
		while (k >= 0)
		{
			if (k - 2 >= 0)
			{
				b[k][l] = b[k - 2][l];
			}
			else
			{
				x = rand() % 5;
				b[k][l] = arr[x];
			}
			k--;
		}
	}
	if (found == 9)
	{
		int k = i, l = j;
		b[i][j] = b[i][j] + 10;
		while (i != 0)
		{
			b[i][j - 1] = b[i - 1][j - 1];
			b[i][j - 2] = b[i - 1][j - 2];
			i--;
		}
		if (i == 0)
		{
			x = rand() % 5;
			b[i][j - 1] = arr[x];
			x = rand() % 5;
			b[i][j - 2] = arr[x];
		}

		if (((k - 1) - 2) >= 0)
		{
			b[k - 1][l] = b[(k - 1) - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k - 1][l] = arr[x];
		}
		if (((k - 2) - 2) >= 0)
		{
			b[k][l] = b[(k - 2) - 2][l];
		}
		else
		{
			x = rand() % 5;
			b[k - 2][l] = arr[x];
		}
		k = k - 3;
		while (k >= 0)
		{
			if (k - 2 >= 0)
			{
				b[k][l] = b[k - 2][l];
			}
			else
			{
				x = rand() % 5;
				b[k][l] = arr[x];
			}
			k--;
		}
	}
}

//Checks the condition for the creation of any special gem and pass its coordinates to special updown function
void specialupdate(int b[][8], int i, int j, int& score)
{
	if (j < 6 && i < 6)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i - 1][j] && b[i][j] == b[i - 2][j])
			{
				Sleep(2000);
				specialupdown(b, i, j, 6);
				score = score + 20;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
	if (j > 1 && i < 6)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i - 1][j] && b[i][j] == b[i - 2][j])
			{
				Sleep(2000);
				specialupdown(b, i, j, 7);
				score = score + 20;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
	if (j < 6 && i>1)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j])
			{
				Sleep(2000);
				specialupdown(b, i, j, 8);
				score = score + 20;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
	if (j > 1 && i > 1)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j])
			{
				Sleep(2000);
				specialupdown(b, i, j, 9);
				score = score + 20;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
	for (int k = 0; k < 4; k++)
	{
		if (b[k][j] <= 5)
		{
			if (b[k][j] == b[k + 1][j] && b[k][j] == b[k + 2][j] && b[k][j] == b[k + 3][j] && b[k][j] == b[k + 4][j])
			{
				Sleep(2000);
				specialupdown(b, k, j, 4);
				score = score + 15;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);
			}
		}
	}
	if (j < 6 && j>1)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
			{
				Sleep(2000);
				specialupdown(b, i, j, 5);
				score = score + 15;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
	if (j < 6 && j>0)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
			{
				Sleep(2000);
				specialupdown(b, i, j, 1);
				score = score + 15;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
	if (j < 7 && j>1)
	{
		if (b[i][j] <= 5)
		{
			if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i][j + 1])
			{
				Sleep(2000);
				specialupdown(b, i, j, 2);
				score = score + 15;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);
			}
		}
	}
	for (int k = 0; k < 5; k++)
	{
		if (b[k][j] <= 5)
		{
			if (b[k][j] == b[k + 1][j] && b[k][j] == b[k + 2][j] && b[k][j] == b[k + 3][j])
			{
				Sleep(2000);
				specialupdown(b, k, j, 3);
				score = score + 15;
				drawScore(score);
				printboard(b);
				gotoxy(0, 0);

			}
		}
	}
}
//Check the creation of special gems throughout the table after swapping 
int checkspecial(int b[][8], int& c1, int& c2)
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if (j < 6 && i < 6)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i - 1][j] && b[i][j] == b[i - 2][j])
					{
						c1 = i, c2 = j;
						return 1;

					}
				}
			}
			if (j > 1 && i < 6)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i - 1][j] && b[i][j] == b[i - 2][j])
					{

						c1 = i, c2 = j;
						return 1;
					}
				}
			}
			if (j < 6 && i>1)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2] && b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j])
					{
						c1 = i, c2 = j;
						return 1;
					}
				}
			}
			if (j > 1 && i > 1)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i + 1][j] && b[i][j] == b[i + 2][j])
					{
						c1 = i, c2 = j;
						return 1;
					}
				}
			}
			if (j < 6 && j>1)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
					{

						c1 = i, c2 = j;
						return 1;
					}
				}
			}
			for (int k = 0; k < 4; k++)
			{
				if (b[k][j] <= 5)
				{
					if (b[k][j] == b[k + 1][j] && b[k][j] == b[k + 2][j] && b[k][j] == b[k + 3][j] && b[k][j] == b[k + 4][j])
					{
						c1 = k, c2 = j;
						return 1;
					}
				}
			}
			if (j < 6 && j>0)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
					{
						c1 = i, c2 = j;
						return 1;

					}
				}
			}
			if (j < 7 && j>1)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j - 1] && b[i][j] == b[i][j - 2] && b[i][j] == b[i][j + 1])
					{
						c1 = i, c2 = j;
						return 1;
					}
				}
			}
			for (int k = 0; k < 5; k++)
			{
				if (b[k][j] <= 5)
				{
					if (b[k][j] == b[k + 1][j] && b[k][j] == b[k + 2][j] && b[k][j] == b[k + 3][j])
					{
						c1 = k, c2 = j;
						return 1;

					}
				}
			}
		}
	}
	return 0;
}
//Check the condition for the creation of trio and other respective cases and passes its coordinates to other functions like updown 
void updateboard(int b[][8], int& score)
{
	int found = 0, x = 0, c1, c2;
	while (x == 0)
	{
		x = 1;
		for (int i = 0; i < 8 && x == 1; i++)
		{
			for (int j = 0; j < 8 && x == 1; j++)
			{
				if ((b[i][j] == (b[i][j + 1] + 10) && b[i][j] == (b[i][j + 2] + 10)) || (b[i][j] == (b[i][j + 1] + 10) && b[i][j] == (b[i][j - 1] + 10)) || (b[i][j] == (b[i][j - 1] + 10) && b[i][j] == (b[i][j - 2] + 10)))
				{
					x = 0;
					for (int k = 0; k < 8; k++)
					{
						if (b[i][k] > 10 && b[i][k] < 16)
						{
							found = 5;
							uppdown(b, i, k, found);
						}
					}
					for (int k = 0; k < 8; k++)
					{
						if (b[k][j] > 10 && b[k][j] < 16)
						{
							found = 5;
							uppdown(b, k, j, found);
						}
					}
					for (int k = 0; k < 8; k++)
					{
						if (b[i][k] > 5 && b[i][k] < 11)
						{
							found = 4;
							uppdown(b, i, k, found);
						}
					}
					for (int k = 0; k < 8; k++)
					{
						if (b[k][j] > 5 && b[k][j] < 11)
						{
							found = 4;
							uppdown(b, k, j, found);
						}
					}
					Sleep(2000);
					found = 5;
					uppdown(b, i, j, found);
					score = score + 30;//POPPING DESTROYER GEM
					drawScore(score);
					printboard(b);
					gotoxy(0, 0);
				}
				if ((b[j][i] == (b[j + 1][i] + 10) && b[j][i] == (b[j + 2][i] + 10)) || (b[j][i] == (b[j + 1][i] + 10) && b[j][i] == (b[j - 1][i] + 10)) || (b[j][i] == (b[j - 1][i] + 10) && b[j][i] == (b[j - 2][i] + 10)))
				{
					x = 0;
					for (int k = 0; k < 8; k++)
					{
						if (b[i][k] > 10 && b[i][k] < 16)
						{
							found = 5;
							uppdown(b, i, k, found);
						}
					}
					for (int k = 0; k < 8; k++)
					{
						if (b[k][j] > 10 && b[k][j] < 16)
						{
							found = 5;
							uppdown(b, k, j, found);
						}
					}
					for (int k = 0; k < 8; k++)
					{
						if (b[i][k] > 5 && b[i][k] < 11)
						{
							found = 4;
							uppdown(b, i, k, found);
						}
					}
					for (int k = 0; k < 8; k++)
					{
						if (b[k][j] > 5 && b[k][j] < 11)
						{
							found = 4;
							uppdown(b, k, j, found);
						}
					}
					Sleep(2000);
					found = 6;
					uppdown(b, j, i, found);
					score = score + 30;//POPPING DESTROYER GEM
					drawScore(score);
					printboard(b);
					gotoxy(0, 0);

				}

			}
		}
		for (int i = 0; i < 8 && x == 1; i++)
		{
			for (int k = 0; k < 8 && x == 1; k++)
			{
				if ((b[k][i] == (b[k + 1][i] + 5) && b[k][i] == (b[k + 2][i] + 5)) || (b[k][i] == (b[k + 1][i] + 5) && b[k][i] == (b[k - 1][i] + 5)) || (b[k][i] == (b[k - 1][i] + 5) && b[k][i] == (b[k - 2][i] + 5)))
				{
					x = 0;
					Sleep(2000);
					found = 3;
					uppdown(b, i, k, found);
					score = score + 25;//Popping flame gem
					drawScore(score);
					printboard(b);
					gotoxy(0, 0);
				}
			}
			for (int j = 0; j < 8 && x == 1; j++)
			{
				if ((b[i][j] == (b[i][j + 1] + 5) && b[i][j] == (b[i][j + 2] + 5)) || (b[i][j] == (b[i][j + 1] + 5) && b[i][j] == (b[i][j - 1] + 5)) || (b[i][j] == (b[i][j - 1] + 5) && b[i][j] == (b[i][j - 2] + 5)))
				{
					x = 0;
					Sleep(2000);
					found = 4;
					uppdown(b, i, j, found);
					score = score + 25;//Popping flame gem
					drawScore(score);
					printboard(b);
					gotoxy(0, 0);
				}
			}
		}
		while (checkspecial(b, c1, c2) == 1)
		{
			specialupdate(b, c1, c2, score);
		}
		for (int i = 0; i < 8 && x == 1; i++)
		{
			for (int j = 0; j < 6 && x == 1; j++)
			{
				if (b[i][j] <= 5)
				{
					if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
					{
						x = 0;
						Sleep(2000);
						found = 1;
						uppdown(b, i, j, found);
						score = score + 10;//Popping 3 gems
						drawScore(score);
						printboard(b);
						gotoxy(0, 0);
					}
				}
			}
			for (int k = 0; k < 6 && x == 1; k++)
			{
				if (b[k][i] <= 5)
				{
					if (b[k][i] == b[k + 1][i] && b[k][i] == b[k + 2][i])
					{
						x = 0;
						Sleep(2000);
						found = 2;
						uppdown(b, i, k, found);
						score = score + 10;//Popping 3 gems
						drawScore(score);
						printboard(b);
						gotoxy(0, 0);
					}
				}
			}
		}
	}
}
//Make sure that there is no comination when game starts
void initialization_updateboard(int b[][8])
{
	int found = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (b[i][j] <= 5)
			{
				if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
				{
					found = 1;
					uppdown(b, i, j, found);

				}
			}
		}
		for (int k = 0; k < 6; k++)
		{
			if (b[k][i] <= 5)
			{
				if (b[k][i] == b[k + 1][i] && b[k][i] == b[k + 2][i])
				{
					found = 2;
					uppdown(b, i, k, found);
				}
			}
		}
	}


}
//Checks that if after swapping there is any combination left behind to be popped
int checkupdate(int b[][8])
{
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if ((b[i][j] == (b[i][j + 1] + 10) && b[i][j] == (b[i][j + 2] + 10)) || (b[i][j] == (b[i][j + 1] + 10) && b[i][j] == (b[i][j - 1] + 10)) || (b[i][j] == (b[i][j - 1] + 10) && b[i][j] == (b[i][j - 2] + 10)))
			{
				return 1;
			}
			if ((b[j][i] == (b[j + 1][i] + 10) && b[j][i] == (b[j + 2][i] + 10)) || (b[j][i] == (b[j + 1][i] + 10) && b[j][i] == (b[j - 1][i] + 10)) || (b[j][i] == (b[j - 1][i] + 10) && b[j][i] == (b[j - 2][i] + 10)))
			{
				return 1;
			}

		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int k = 0; k < 8; k++)
		{
			if ((b[k][i] == (b[k + 1][i] + 5) && b[k][i] == (b[k + 2][i] + 5)) || (b[k][i] == (b[k + 1][i] + 5) && b[k][i] == (b[k - 1][i] + 5)) || (b[k][i] == (b[k - 1][i] + 5) && b[k][i] == (b[k - 2][i] + 5)))
			{
				return 1;
			}
		}
		for (int j = 0; j < 8; j++)
		{
			if ((b[i][j] == (b[i][j + 1] + 5) && b[i][j] == (b[i][j + 2] + 5)) || (b[i][j] == (b[i][j + 1] + 5) && b[i][j] == (b[i][j - 1] + 5)) || (b[i][j] == (b[i][j - 1] + 5) && b[i][j] == (b[i][j - 2] + 5)))
			{
				return 1;
			}
		}
	}
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			if (b[i][j] == b[i][j + 1] && b[i][j] == b[i][j + 2])
			{
				return 1;
			}
		}
		for (int k = 0; k < 6; k++)
		{
			if (b[k][i] == b[k + 1][i] && b[k][i] == b[k + 2][i])
			{
				return 1;
			}
		}
	}


	return 0;
}







//Takes cursor row and column and shift the cursor to that position
void updateCursor(int cursor_row, int cursor_col, int R, int G, int B) {//prints the cursor on the given row column intersection
	float cursorX = (cursor_col * 55) + 27.5, cursorY = (cursor_row * 55) + 27.5;
	myCursor(cursorX, cursorY, R, G, B);


}




//Detects key presses and uses them to move the cursor if valid swap and calls rest of functions to update board accordingly
void moveCursor(int& cursor_row, int& cursor_col, bool& enter_pressed, int board[][8], int& score) {
	bool key_pressed = false;
	int key;
	while (key_pressed != true) {
		key_pressed = isCursorKeyPressed(key);
	}
	if (key == 1) {//left
		if (enter_pressed == true) {
			//CODE TO SWAP VALUE AND PRINT BOARD
			gotoxy(0, 0);
			if (cursor_col > 0) {
				swap(board[cursor_row][cursor_col], board[cursor_row][cursor_col - 1]);
				if (checkupdate(board) == true) {
					printboard(board);
					specialupdate(board, cursor_row, cursor_col - 1, score);
					printboard(board);
					while (checkupdate(board) == true) {
						gotoxy(0, 0);
						updateboard(board, score);
						printboard(board);
					}
				}
				else {
					swap(board[cursor_row][cursor_col], board[cursor_row][cursor_col - 1]);
				}
			}
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
			enter_pressed = false;
		}
		else if (cursor_col > 0) {
			updateCursor(cursor_row, cursor_col, 0, 0, 0);
			cursor_col--;
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
		}
	}
	else if (key == 2) {//up
		if (enter_pressed == true) {
			//CODE TO SWAP VALUE AND PRINT BOARD
			gotoxy(0, 0);
			if (cursor_row > 0) {
				swap(board[cursor_row][cursor_col], board[cursor_row - 1][cursor_col]);//DOESNT CHECK FOR BOUNDARIES
				if (checkupdate(board) == true) {
					printboard(board);
					specialupdate(board, cursor_row - 1, cursor_col, score);
					while (checkupdate(board) == true) {
						gotoxy(0, 0);
						updateboard(board, score);
						printboard(board);
					}
				}
				else {
					swap(board[cursor_row][cursor_col], board[cursor_row - 1][cursor_col]);
				}
			}
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
			enter_pressed = false;
		}
		else if (cursor_row > 0) {
			updateCursor(cursor_row, cursor_col, 0, 0, 0);
			cursor_row--;
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
		}

	}
	else if (key == 3) {//right
		if (enter_pressed == true) {
			//CODE TO SWAP VALUE AND PRINT BOARD
			gotoxy(0, 0);
			if (cursor_col < 7) {
				swap(board[cursor_row][cursor_col], board[cursor_row][cursor_col + 1]);//DOESNT CHECK FOR BOUNDARIES
				if (checkupdate(board) == true) {
					printboard(board);
					specialupdate(board, cursor_row, cursor_col + 1, score);
					while (checkupdate(board) == true) {
						gotoxy(0, 0);
						updateboard(board, score);
						printboard(board);
					}
				}
				else {
					swap(board[cursor_row][cursor_col], board[cursor_row][cursor_col + 1]);
				}
			}
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
			enter_pressed = false;
		}
		else if (cursor_col < 7) {
			updateCursor(cursor_row, cursor_col, 0, 0, 0);
			cursor_col++;
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
		}

	}
	else if (key == 4) {//down
		if (enter_pressed == true) {
			//CODE TO SWAP VALUE AND PRINT BOARD
			gotoxy(0, 0);
			if (cursor_row < 7) {
				swap(board[cursor_row][cursor_col], board[cursor_row + 1][cursor_col]);//DOESNT CHECK FOR BOUNDARIES
				if (checkupdate(board) == true) {
					printboard(board);
					specialupdate(board, cursor_row + 1, cursor_col, score);
					while (checkupdate(board) == true) {
						gotoxy(0, 0);
						updateboard(board, score);
						printboard(board);
					}
				}
				else {
					swap(board[cursor_row][cursor_col], board[cursor_row + 1][cursor_col]);
				}
			}
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
			enter_pressed = false;
		}
		else if (cursor_row < 7) {
			updateCursor(cursor_row, cursor_col, 0, 0, 0);
			cursor_row++;
			updateCursor(cursor_row, cursor_col, 255, 0, 0);
		}

	}
	else if (key == 5) {//enter
		updateCursor(cursor_row, cursor_col, 28, 0, 141);
		enter_pressed = true;


	}


}

int getCoordX(int col) {
	int X = (col * 55) + 35;
	return X;
}
int getCoordY(int row) {
	int Y = (row * 55) + 35;
	return Y;
}










int main() {
	std::thread timer(timerThread);


	//Increases the console text size
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = 36;
	fontex.dwFontSize.Y = 36;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
	cout << "\nYou have 120 seconds to play the game\n\n\t\tPress ENTER to start the game.\n\t\tPress ESC to exit.";
	gotoxy(0, 0);
	//Maximizes the console window
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_SHOWMAXIMIZED);


	//Detcts key presses
	
	while (key_pressed == false || (key < 5)) {
		key_pressed = isCursorKeyPressed(key);
	}
	if (key == 6) {
		return 0;
	}
	system("CLS");
	gotoxy(0, 0);
	int cursor_row = 0, cursor_col = 0;
	bool enter_pressed = false;
	int board[8][8];
	int score = 0;
	assigningvalues(board);
	//Initializing the board
	while (checkupdate(board)) {
		initialization_updateboard(board);
	}
	score = 0;
	printboard(board);
	draw_the_word_score();
	draw_the_word_time();
	updateCursor(cursor_row, cursor_col, 255, 0, 0);
	drawScore(score);



	while (!gameover) {

		gotoxy(0, 0);
		moveCursor(cursor_row, cursor_col, enter_pressed, board, score);
		//drawScore(score);
		//drawScore(time_in_seconds);

	}
	using namespace std::chrono;
	system("CLS");
	draw_the_word_score();
	drawScore(score);
	std::this_thread::sleep_for(seconds(5));
	

	_getch();
	timer.detach();
}