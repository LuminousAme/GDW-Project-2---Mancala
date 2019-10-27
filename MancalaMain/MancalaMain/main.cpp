#include "aiCode.h"
#include "gameBoard.h"
#include "MainMenu.h"
#include "game.h" 

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
		case 3: 
			mancalaGame(); 
			break; 
		default:
			gameIsRunning = false; 
		}
	}
	

	return 0; 
}