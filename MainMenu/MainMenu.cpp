#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <MmSystem.h>
//#include "MainMenu.h"

using namespace std;
int iDifficulty=1;
HANDLE Console;
void displayInstructions(), BeginGame(), displaySetting(), displayMainMenu(), displayBorder(int);


int main() {
	PlaySound(TEXT("MainMenu.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
	//PlaySound(TEXT("MainMenu.mp3"), NULL, SND_FILENAME | SND_ASYNC);
	displayMainMenu();
	
	return 0;
}

void displayInstructions(){
	int iInput = 0;

	
	system("CLS");
	displayBorder(4);
	SetConsoleTextAttribute(Console, 10);
	cout<< "  _____                 _                           _     _"
		<< "\n |_   _|               | |                         | |   (_)"
		<< "\n   | |    _ __    ___  | |_   _ __   _   _    ___  | |_   _    ___    _ __    ___"
		<< "\n   | |   | '_ \\  / __| | __| | '__| | | | |  / __| | __| | |  / _ \\  | '_ \\  / __|"
		<< "\n   | |_  | | | | \\__ \\ | |_  | |    | |_| | | (__  | |_  | | | (_) | | | | | \\__ \\"
		<< "\n |_____| |_| |_| |___/  \\__| |_|     \\__,_|  \\___|  \\__| |_|  \\___/  |_| |_| |___/";
	displayBorder(4);
	SetConsoleTextAttribute(Console, 2);
	cout << " The game of Mancala is played using a board with 2 rows and 6 holes in each row."
		<< "\n At the beginning of the game, each hole is filled with 4 gems."
		<< "\n Each player has a bank on their right side of the board."
		<< "\n The game starts with the first player choosing a hole on their side of the board."
		<< "\n All the gems are removed from the chosen hole\n and 1 gem is dropped in subsequent holes going counter clockwise around the board."
		<< "\n This process is repeated until all the gems have been placed in either a hole or your mancala.";
	displayBorder(4);
	cout<< " To go back to the main menu, input 1\n\n ";

	while (iInput != 1) {
		cin >> iInput;
		switch (iInput) {
		case 1:
			displayMainMenu();
			break;
		default:
			cout << "\n\n You inputed a wrong value, please input a 1\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void BeginGame() {
}

void displaySettings() {
	int iInput = 0;
	/***
 *       _____          _     _     _
 *      / ____|        | |   | |   (_)
 *     | (___     ___  | |_  | |_   _   _ __     __ _   ___
 *      \___ \   / _ \ | __| | __| | | | '_ \   / _` | / __|
 *      ____) | |  __/ | |_  | |_  | | | | | | | (_| | \__ \
 *     |_____/   \___|  \__|  \__| |_| |_| |_|  \__, | |___/
 *                                               __/ |
 *                                              |___/
 */
	system("CLS");

	displayBorder(3);
	SetConsoleTextAttribute(Console, 13);
	cout << "   _____          _     _     _"
		<< "\n  / ____|        | |   | |   (_)"
		<< "\n | (___     ___  | |_  | |_   _   _ __     __ _   ___"
		<< "\n  \\___ \\   / _ \\ | __| | __| | | | '_ \\   / _` | / __|"
		<< "\n  ____) | |  __/ | |_  | |_  | | | | | | | (_| | \\__ \\"
		<< "\n |_____/   \\___|  \\__|  \\__| |_| |_| |_|  \\__, | |___/"
		<< "\n                                           __/ |"
		<< "\n                                          |___/";
	displayBorder(3);
	SetConsoleTextAttribute(Console, 13);
	cout<< "\n Difficulty Setting:\n"
		<< "\n Currently, the Difficulty is on: ";

	switch (iDifficulty) {
	case 1:
		cout << "Easy";
		break;
	case 2:
		cout << "Medium";
		break;
	case 3:
		cout << "Hard";
		break;
	}

	cout << "\n\n To change the difficulty:\n\n Input 1 for Easy\n\n Input 2 for Medium\n\n Input 3 for Hard"
		 << "\n\n To go back to the Main menu, Input 4\n";

	displayBorder(3);

	while (iInput != 4) {
		cin >> iInput;
		switch (iInput) {
		case 1:
			iDifficulty = 1;
			cout << " ----------------------------------------------------\n The Difficulty is now Easy"
				 << "\n ----------------------------------------------------\n ";
			break;
		case 2:
			iDifficulty = 2;
			cout << " ----------------------------------------------------\n The Difficulty is now Medium"
				 << "\n ----------------------------------------------------\n ";
			break;
		case 3:
			iDifficulty = 3;
			cout << " ----------------------------------------------------\n The Difficulty is now Hard"
				 << "\n ----------------------------------------------------\n ";
			break;
		case 4:
			displayMainMenu();
			break;
		default:
			cout << " ----------------------------------------------------\n You inputed a wrong value, please input a 1,2,3 or 4\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}

void displayBorder(int i) {
	switch (i) {
	case 1:
		SetConsoleTextAttribute(Console, 7);
		cout << "\n\n -----------------------------------------------------\n\n";
		break;
	case 2:
		SetConsoleTextAttribute(Console, 7);
		cout << "\n -----------------------------------------------------\n ";
		break;
	case 3:
		SetConsoleTextAttribute(Console, 7);
		cout << "\n ----------------------------------------------------\n ";
		break;
	case 4:
		SetConsoleTextAttribute(Console, 7);
		cout << "\n\n ---------------------------------------------------------------------------------\n\n";
		break;
	}
}


void displayMainMenu() {
	int iInput=0;

	//defines the standard output device
	Console = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");

	//set the console text colour to 
	displayBorder(1);


	SetConsoleTextAttribute(Console, 11);
	cout << "  __   __                                  _"
		 << "\n |  \\ /  |                                | |"
		 << "\n | \\   / |   __ _   _ __     ___    __ _  | |   __ _"
		 << "\n | |\\ /| |  / _` | | '_ \\   / __|  / _` | | |  / _` |"
		 << "\n | |   | | | (_| | | | | | | (__  | (_| | | | | (_| |"
		 << "\n |_|   |_|  \\__,_| |_| |_|  \\___|  \\__,_| |_|  \\__,_|";
	
	displayBorder(1);
	SetConsoleTextAttribute(Console, 11);
	cout << "\n A two-player turn-based strategy board game"
		 << "\n\n To open the instructions, input 1"
		 << "\n\n To start the game, input 2"
		 << "\n\n To open setting, input 3\n\n";

	displayBorder(2);

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
			displaySettings();
			break;

		default:
			cout << "\n\n You inputed a wrong value, please input a 1,2 or 3\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
}


