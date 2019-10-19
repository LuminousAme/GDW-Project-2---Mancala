//#include "MainMenu.h"
#include <iostream>

using namespace std;
int iDifficulty=1;


void displayInstructions(){
	/***
 *      _____                 _                           _     _
 *     |_   _|               | |                         | |   (_)
 *       | |    _ __    ___  | |_   _ __   _   _    ___  | |_   _    ___    _ __    ___
 *       | |   | '_ \  / __| | __| | '__| | | | |  / __| | __| | |  / _ \  | '_ \  / __|
 *      _| |_  | | | | \__ \ | |_  | |    | |_| | | (__  | |_  | | | (_) | | | | | \__ \
 *     |_____| |_| |_| |___/  \__| |_|     \__,_|  \___|  \__| |_|  \___/  |_| |_| |___/
 *
 *
 *
 *
 *
 *
 *
 *
 *
 *
 */
}
void BeginGame() {
}
void displayDifficulty() {
}
void displayTitle() {
	int iInput=0;


	/*
	Mancala
	  __  __                                  _
	 |  \/  |                                | |
	 | \  / |   __ _   _ __     ___    __ _  | |   __ _
	 | |\/| |  / _` | | '_ \   / __|  / _` | | |  / _` |
	 | |  | | | (_| | | | | | | (__  | (_| | | | | (_| |
	 |_|  |_|  \__,_| |_| |_|  \___|  \__,_| |_|  \__,_|

	*/
	cout << "\n\n------------------------------------------------------\n"
		<< "  __   __                                  _"
		<< "\n |  \\ /  |                                | |"
		<< "\n | \\   / |   __ _   _ __     ___    __ _  | |   __ _"
		<< "\n | |\\ /| |  / _` | | '_ \\   / __|  / _` | | |  / _` |"
		<< "\n | |   | | | (_| | | | | | | (__  | (_| | | | | (_| |"
		<< "\n |_|   |_|  \\__,_| |_| |_|  \\___|  \\__,_| |_|  \\__,_|"
		<< "\n\n-----------------------------------------------------\n"
		<< "\n    A two-player turn-based strategy board game"
		<< "\n\n    To open the instructions, input 1"
		<< "\n\n    To start the game, input 2"
		<< "\n\n    To choose difficulty, input 3\n\n"
		<< "-----------------------------------------------------\n\n";

	while (iInput!=1 && iInput != 2 && iInput != 3) {
		cin >> iInput;
		switch (iInput) {
		case 1:
			displayInstructions();
			break;
		case 2:
			BeginGame();
			break;
		case 3:
			displayDifficulty();
			break;

		default:
			cout << "\n\n You inputed a wrong value, please input a 1,2 or 3\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}
int main() {
	displayTitle();
	return 0;
}

