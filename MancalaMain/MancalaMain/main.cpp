/*
Mancala, a text based adaptation 
Made by team 1
Shezwin Carim - #100708604
Alvin Ng - #100754129
Ame Gilham - #100741352
Jonathan Naire - #100741302
Ajieth Varatharajah - #100752537
Omair Ahmad - #100658447

With music by Toby Fox (remastered by Ame Gilham)
*/

/*
This is a text based adaptation of the ancient game Mancala
That uses keyboard based input to simulate the game in a text console envinorment 
It is only comptatible with windows systems 
With "winmm.lib" added in project: properties / configuration properties / linker / Input's additional dependencies section 
*/

//Import all needed librarbies and other files 
#include "aiCode.h"
#include "gameBoard.h"
#include "MainMenu.h"
#include "game.h" 

//Set a variable for the game being run, true means the program is running 
bool gameIsRunning = true; 

//main function, runs the program 
int main() {
	//Play the music ("Once upon a time" By Toby Fox, remastered by Ame Gilham) 
	PlaySound(TEXT("MainMenu.wav"), NULL, SND_FILENAME | SND_LOOP | SND_ASYNC); 

	//While the progrma is running
	while (gameIsRunning)
	{
		//Check which screen they are current on 
		switch (currentScreen)
		{
		//if it's 0, display the mainmenu
		case 0:
			displayMainMenu();
			break;
		//if it's 1, display the instructions 
		case 1:
			displayInstructions();
			break;
		//if it's 2, play the game 
		case 2:
			mancalaGame(); 
			break;
		//if it's 3, display the settings menu
		case 3: 
			displaySettings();
			break;
		//if it's 4, display the credits 
		case 4:
			displayCredits(); 
			break; 
		//otherwise end the program 
		default:
			gameIsRunning = false; 
		}
	}
	
	//return with no errors
	return 0; 
} //End of main 