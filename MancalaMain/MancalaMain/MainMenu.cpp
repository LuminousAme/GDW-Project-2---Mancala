/*
Menus code by Johnathan Naire 
With editting by Ame Gilham
*/

//Include the mainmenu's header
#include "MainMenu.h"

//Define namespace 
using namespace std;


//Defines the standard output device
HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);

//Define global variables for current screen, and ai difficulty level
int aiDifficulty = 1; 
int currentScreen = 0; 

// Function to display instruction menu
void displayInstructions(){
	//Set the variable that stores player input 
	int iInput = 0;

	//Clear the console window 
	system("CLS");
	//Display the screen border at the top 
	displayBorder(4);

	//Make the text light green 
	SetConsoleTextAttribute(Console, 10);
	//Display the title
	cout<< "  _____                 _                           _     _"
		<< "\n |_   _|               | |                         | |   (_)"
		<< "\n   | |    _ __    ___  | |_   _ __   _   _    ___  | |_   _    ___    _ __    ___"
		<< "\n   | |   | '_ \\  / __| | __| | '__| | | | |  / __| | __| | |  / _ \\  | '_ \\  / __|"
		<< "\n   | |_  | | | | \\__ \\ | |_  | |    | |_| | | (__  | |_  | | | (_) | | | | | \\__ \\"
		<< "\n |_____| |_| |_| |___/  \\__| |_|     \\__,_|  \\___|  \\__| |_|  \\___/  |_| |_| |___/";
	//Display another screen border 
	displayBorder(4);
	//Make the text green 
	SetConsoleTextAttribute(Console, 2);
	//Display the instructions for how to play the game 
	cout << " The game of Mancala is played using a board with 2 rows and 6 holes in each row."
		<< "\n At the beginning of the game, each hole is filled with 4 gems."
		<< "\n Each player has a bank (or mancala) on their right side of the board."
		<< "\n The game starts with the first player choosing a hole on their side of the board."
		<< "\n All the gems are removed from the chosen hole\n and 1 gem is dropped in subsequent holes going counter clockwise around the board."
		<< "\n This process is repeated until all the gems have been placed in either a hole or your mancala."
		<< "\n If the last gem is placed in your mancala you get a free turn." 
		<< "\n And if the last gem is placed in an empty hole on your side," 
		<< "\n that gem along with all the gems in the pit opposite it immediately go to your manacala."
		<< "\n\n The game ends when all holes on one side are empty," 
		<< "\n all the remaining gems on the other side then go to that player's manacala"
		<< "\n and whoever has more gems is the winner!"
		<< "\n\n And that's all for the basics of Mancala!";
	//Display a screen border again 
	displayBorder(4);
	//Tell the player how to return to the main menu 
	cout<< " To go back to the main menu, input 1\n\n ";

	//While they have said they want to return to the main menu check if they want to
	while (iInput != 1) {
		//Ask for input 
		cin >> iInput;
		//If they input 1 return them to the main menu, otherwise tell them they can only input 1 
		switch (iInput) {
		case 1:
			currentScreen = 0;
			break;
		default:
			cout << "\n\n You inputed an invalid value. Please only input 1 in this menu\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
} // End of displayInstructions 

// Function to display the settings 
void displaySettings() {
	//Set the variable that stores player input 
	int iInput = 0;

	//Clear the console 
	system("CLS");

	//Draw a screen border at the top 
	displayBorder(3);
	//Set the text colour to a light magenta 
	SetConsoleTextAttribute(Console, 13);
	//Display the title 
	cout << "   _____          _     _     _"
		<< "\n  / ____|        | |   | |   (_)"
		<< "\n | (___     ___  | |_  | |_   _   _ __     __ _   ___"
		<< "\n  \\___ \\   / _ \\ | __| | __| | | | '_ \\   / _` | / __|"
		<< "\n  ____) | |  __/ | |_  | |_  | | | | | | | (_| | \\__ \\"
		<< "\n |_____/   \\___|  \\__|  \\__| |_| |_| |_|  \\__, | |___/"
		<< "\n                                           __/ |"
		<< "\n                                          |___/";
	//Draw another screen border 
	displayBorder(3);
	//Set the text colour to a light magenta
	SetConsoleTextAttribute(Console, 13);
	// Display the current difficulty setting 
	cout<< "\n Difficulty Setting:\n"
		<< "\n Currently, the Difficulty is on: ";

	//Shows which difficulty is currently set 
	switch (aiDifficulty) {
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

	//Tell the player how to change various settings 
	cout << "\n\n To change the difficulty:\n\n Input 1 for Easy\n\n Input 2 for Medium\n\n Input 3 for Hard"
		 << "\n\n To go back to the Main menu, Input 4\n";

	//Draw another screen border 
	displayBorder(3);

	// Take user inout 
	while (iInput != 4) {
		//Accept the input 
		cin >> iInput;
		switch (iInput) {
			//If they input one, set the difficulty to easy  
		case 1:
			aiDifficulty = 1;
			cout << " ----------------------------------------------------\n The Difficulty is now Easy"
				 << "\n ----------------------------------------------------\n ";
			break;
			//If they input two, set the difficulty to medium 
		case 2:
			aiDifficulty = 2;
			cout << " ----------------------------------------------------\n The Difficulty is now Medium"
				 << "\n ----------------------------------------------------\n ";
			break;
			//If they input three, set the difficultly to hard 
		case 3:
			aiDifficulty = 3;
			cout << " ----------------------------------------------------\n The Difficulty is now Hard"
				 << "\n ----------------------------------------------------\n ";
			break;
			//If they input 4, return to the main menu 
		case 4:
			currentScreen = 0; 
			break;
			//If they input anything else, ask them to input only a valid input 
		default:
			cout << " ----------------------------------------------------\n You inputed an invalid value, please input only a 1,2,3 or 4\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
} //end of displaySettings 

// Function to display screen borders 
void displayBorder(int i) {
	//display borders of different sizes
	switch (i) {
		//size 1
	case 1:
		//set text colour to light gray and print border 
		SetConsoleTextAttribute(Console, 7);
		cout << "\n\n -----------------------------------------------------\n\n";
		break;
		//size 2
	case 2:
		//set text colour to light gray and print border 
		SetConsoleTextAttribute(Console, 7);
		cout << "\n -----------------------------------------------------\n ";
		break;
		//size 3 
	case 3:
		//set text colour to light gray and print border 
		SetConsoleTextAttribute(Console, 7);
		cout << "\n ----------------------------------------------------\n ";
		break;
		//size 4
	case 4:
		//set text colour to light gray and print border 
		SetConsoleTextAttribute(Console, 7);
		cout << "\n\n ---------------------------------------------------------------------------------\n\n";
		break;
	}
} //end of displayBorder 
		
// Function to display the credits 
void displayCredits() {
	//Set the variable for player input 
	int iInput = 0; 

	//Clear the console 
	system("CLS"); 

	//Display a screen border at the top 
	displayBorder(1); 

	//Set the text colour to yellow 
	SetConsoleTextAttribute(Console, 14); 
	//Display the title
	cout << "   _____              _ _ _       "
		<< "\n  / ____|            | (_) |      "
		<< "\n | |     _ __ ___  __| |_| |_ ___ "
		<< "\n | |    | '__/ _ \\/ _` | | __/ __|"
		<< "\n | |____| | |  __/ (_| | | |_\\__ \\"
		<< "\n  \\_____|_|  \\___|\\__,_|_|\\__|___/"; 
	//Display a screen border 
	displayBorder(1); 

	//Set the text colour to yellow 
	SetConsoleTextAttribute(Console, 14);
	//Display the credits 
	cout << "Mancala, a text based adaptation \n"
		<< "Made by team 1 \n\n"
		<< "Shezwin Carim - #100708604 \n"
		<< "Alvin Ng - #100754129 \n"
		<< "Ame Gilham - #100741352 \n"
		<< "Jonathan Naire - #100741302 \n"
		<< "Ajieth Varatharajah - #100752537 \n"
		<< "and Omair Ahmad - #100658447 \n\n"
		<< "With music by Toby Fox (Remastered by Ame Gilham)\n\n"; 

	//tell the player how to return to the main menu 
	cout << "To return to the main menu input 1\n"; 

	//display another screen border
	displayBorder(2); 

	//Take the user's input 
	while (iInput != 1) {
		//accept the input 
		cin >> iInput; 
		switch (iInput) {
			//If they input 1, bring them back to the main menu 
		case 1:
			currentScreen = 0; 
			break; 
			//otherwise ask  them to only input 1 
		default: 
			cout << "\n\n You inputed an invalid value, please only input 1\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
} //end of displayCredits

// Function to display the main menu
void displayMainMenu() {
	//set the variable for player input 
	int iInput=0;

	//Clear the console 
	system("CLS");

	//Display a screen border at the top 
	displayBorder(1);

	//Set the text colour to a light cyan 
	SetConsoleTextAttribute(Console, 11);
	//Display the title 
	cout << "  __   __                                  _"
		 << "\n |  \\ /  |                                | |"
		 << "\n | \\   / |   __ _   _ __     ___    __ _  | |   __ _"
		 << "\n | |\\ /| |  / _` | | '_ \\   / __|  / _` | | |  / _` |"
		 << "\n | |   | | | (_| | | | | | | (__  | (_| | | | | (_| |"
		 << "\n |_|   |_|  \\__,_| |_| |_|  \\___|  \\__,_| |_|  \\__,_|";
	
	//Display a screen border 
	displayBorder(1);
	//Set the text colour to a light cyan 
	SetConsoleTextAttribute(Console, 11);
	//Give the player some basic information and inform them of how they can access the other menus or the game 
	cout << "\n A two-player turn-based strategy board game"
		 << "\n\n To open the instructions, input 1"
		 << "\n\n To start the game, input 2"
		 << "\n\n To open setting, input 3"
		 << "\n\n To open credits, input 4"
		 << "\n\n To close the game, input 5\n\n";

	//display another screen border
	displayBorder(2);

	// Take the user's input 
	while (iInput != 1 && iInput != 2 && iInput != 3 && iInput !=4 && iInput != 5) {
		//Accept the input
		cin >> iInput;
		switch (iInput) {
			//If they input one display the instructions menu 
		case 1:
			currentScreen = 1;
			break;
			//If they input two, start the game 
		case 2:
			currentScreen = 2;
			break;
			//If they input three, display the settings menu 
		case 3:
			currentScreen = 3;
			break;
			//If they input 4, open the credits menu  
		case 4: 
			currentScreen = 4; 
			break; 
			//If they input 5, exit the game 
		case 5:
			//this exits the game 
			currentScreen = 5; 
			//Otherwise ask them to only input a valid number 
		default:
			cout << "\n\n You inputed an invalid value, please only input a 1,2, 3, 4, or 5\n\n";
			cin.clear();
			cin.ignore(256, '\n');
		}
	}
} //end of displayMainMenu


