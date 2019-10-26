#include "aiCode.h"
#include "gameBoard.h"
#include "MainMenu.h"

bool gameIsRunning = true; 

int main() {
	
	while (gameIsRunning)
	{
		switch (currentScreen)
		{
		case 0:
			displayMainMenu();
			break;
		case 1:
			displayInstructions();
			break;
		case 2:
			displaySettings();
			break;
		default:
			gameIsRunning = false; 
		}
	}
	

	return 0; 
}