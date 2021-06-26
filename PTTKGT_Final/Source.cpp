#include <iostream>
#include <iomanip>
#include <conio.h>
#include <Windows.h>
using namespace std;
void SetColor(int backgound_color, int text_color)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	int color_code = backgound_color * 16 + text_color;
	SetConsoleTextAttribute(hStdout, color_code);
}
#include "Share.h"
int main() {
	char chooseMM = 0;
	int kMM = 1;
	showMainMenu(kMM);
	while (chooseMM != 27)
	{
		chooseMM = _getch();
		if (chooseMM != -32) {
			showMainMenu(kMM);
			//Start Switch Main Menu
			switch (chooseMM) {
				//Key Down
				case 80:
					kMM++;
					if (kMM == 4) {
						kMM = 1;
					}
					showMainMenu(kMM);
					break;
				//Key Up
				case 72:
					kMM--;
					if (kMM == 0) {
						kMM = 3;
					}
					showMainMenu(kMM);
					break;
				//Key Enter
				case 13:
				switch (kMM) {
					//Backtracking
					case 1:
					{
						backtracking();
						exit();
						showMainMenu(kMM);
						break;
					}
					//Dynamic programing
					case 2:
					{
						dynamicPrograming();
						exit();
						showMainMenu(kMM);
						break;
					}
					//Exit
					default:
						exit(0);
						break;
				}
			}
			//End Switch Main Menu
		}
	}
}