/*
Gameplay code by Ajieth Varatharajah and Alvin Ng 
With editing by Ame Gilham 
*/

//Include header file 
#include "game.h"

//Define namespace 
using namespace std;

//Global Variables
bool inGame = true;
int startPieceCount = 4;
int board[14], pitCaptured, gemsStolen;
bool turn = true, extraTurn = false, captured = false, gotPoint = false, inRound = true;

//variable used to check if the player would like to play again after the game ends 
string cont = "nope";

//Function to fill the board 
void populate(int piece) {
	//Fill the board array
	for (int i = 0; i < 14; i++) {
		board[i] = piece;
		//Exclude the mancalas
		if (i == 6 || i == 13) {
			board[i] = 0;
		}
	}
} //End of populate 

// Function to get player input
int getChoice() {
	//Variable that stores if the input is valid 
	bool validIn = false;
	//Variable that stores what the player has input 
	int playerPick = 0;
	//Prompt the user
	std::cout << "\nSelect your hole (1-6): \n";
	std::cin >> playerPick;
	playerPick--;
	//Check if the input is valid
	while (!validIn) {
		//If it's not then ask them to input a valid choice
		if (std::cin.fail() || playerPick < 0 || playerPick > 5 || board[playerPick] == 0) {
			std::cout << "Please enter a valid choice: \n";
			std::cin.clear();
			std::cin.ignore();
			std::cin >> playerPick;
			playerPick--;
		}
		//Otherwise set that it is valid and return it 
		else {
			validIn = true;
		}
	}
	//return the player's input
	return playerPick;
}//End of getChoice

//Function to check if a pits gems have been captured 
bool isCapture(int choice) {
	//If it's the player's turn 
	if (turn) {
		//see if hole is empty and on player side
		if (board[choice] == 0 && choice >= 0 && choice < 6 && board[12 - choice] > 0) {
			//If yes return true
			return true;
		}
	}
	//If it's the ai's turn 
	else {
		//see if hole is empty and on ai side
		if (board[choice] == 0 && choice >= 7 && choice < 13 && board[12 - choice] > 0) {
			//If yes return true 
			return true;
		}
	}
	//Otherwise return false
	return false;
} //end of isCapture

//Function to capture all the gems in an opposite side pit
void capture(int choice) {
	//find the opposite hole
	int clearedHole = 12 - choice;
	//If it's the player's turn 
	if (turn) {
		//Put the gems in the player's manacala
		board[6] += board[clearedHole] + 1;
		//Store how many points they got for the capture 
		gemsStolen = board[clearedHole] + 1;
		//And remove them from the other two 
		board[clearedHole] = 0;
		board[choice] = -1;

	}
	//If it's the ai's turn 
	else {
		//Put the gems in the ai's mancala
		board[13] += board[clearedHole] + 1;
		//Store how many points they got for the capture 
		gemsStolen = board[clearedHole] + 1;
		//and remove them from the other 2
		board[clearedHole] = 0;
		board[choice] = -1;
	}
	//Let the player know 
	captured = true;
	pitCaptured = clearedHole;
} //end of capture 

// Function to check if the gem is being placed in a mancala
bool inBank(int choice) {
	//If it's the players turn 
	if (turn) {
		//and the selected pit is the player's mancala
		if (choice == 6) {
			//Let the player know they got a point 
			gotPoint = true; 
			//return true
			return true;
		}
	}
	//If it's the ai's turn 
	else {
		//and the selected pit is the ai's mancala
		if (choice == 13) {
			//Let the player know the ai got a point 
			gotPoint = true; 
			//then return true
			return true;
		}
	}
	//otherwise return false
	return false;
} //end of inBank

//Function to draw the gameboard
void drawBoard(bool end) {
	//Clear the console 
	system("CLS");

	//If it's the player's turn 
	if (turn && !end) {
		//Set the text colour to green
		SetConsoleTextAttribute(Console, 2);
	}
	//If it's the ai's turn 
	else if (!turn && !end) {
		//Set the text colour to red 
		SetConsoleTextAttribute(Console, 4);
	}
	//Otherwise the game has ended
	else {
		//So set the text colour to white
		SetConsoleTextAttribute(Console, 15);
	}

	//Display the gameboard
	displayBoard(board); 
} //end of drawBoard

// Function to check to see if the game is done 
bool isDone() {
	//Variable for if the game is done 
	bool doneCheck = true;
	//If it's the player's turn 
	if (turn) {
		//Check all their pits 
		for (int i = 0; i < 6; i++) {
			//If any aren't empty 
			if (board[i] != 0) {
				//Return false (the game is still going)
				doneCheck = false;
			}
		}
	}
	//If it's the ai's turn
	else {
		//Check all their pits
		for (int j = 12; j > 6; j--) {
			//If any aren't empty
			if (board[j] != 0) {
				//Return false (the game is still going)
				doneCheck = false;
			}
		}
	}
	//Return the result
	return doneCheck;
} //end of isDone

// Function to drop gems into their new pits
void dropIn(int choice) {
	//Count the number of gems to move 
	int pieceCount = board[choice];
	//Set the pit the player choose to be empty 
	board[choice] = 0;
	choice++;
	// going through each piece
	for (int i = 0; i < pieceCount; i++) {
		//If it's the player's turn and you're at the ai's mancala, skip it 
		if (turn && choice == 13) {
			i--;
		}
		//If it's the ai's turn and you're at the players's mancala, skip it 
		else if (!turn && choice == 6) {
			i--;
		}
		//Otherwise
		else {
			//Check if it's the last gem 
			if (i == pieceCount - 1) {
				//If it is, check if it's capturing a pit 
				if (isCapture(choice)) {
					//If yes capture that pit 
					capture(choice);
				}
				//Or if it's getting a free turn 
				if (inBank(choice)) {
					//If yes give them a free turn
					extraTurn = true;
				}
			}
			//Place the piece in that pit 
			board[choice]++;
		}
		//move to the next pit 
		choice++;
		//If you reach the end of the board 
		if (choice >= 14) {
			//Restart at the beginning 
			choice = 0;
		}
	}
} //end of dropIn

// Function to clear the board at the end of the game
void cleanBoard() {
	//Cycling through the player's pits
	for (int i = 0; i < 6; i++) {
		//place all gems into their mancala
		board[6] += board[i];
		//and empty those pits 
		board[i] = 0;
	}
	//Cycling through the ai's pits
	for (int j = 12; j > 6; j--) {
		//place all gems into their mancala
		board[13] += board[j];
		//and empty those pits
		board[j] = 0;
	}
} //end of cleanBoard

// Function to check if the player won
int isWin() {
	//If the player's mancala has more gems than the ai's 
	if (board[6] > board[13]) {
		//return 1 (player win) 
		return 1;
	}
	//If they have an equal ammount of gems 
	else if (board[6] == board[13]){
		//return 0 (draw) 
		return 0;
	}
	//Otherwise the ai must have more 
	else {
		//and so return -1 (player lose, ai win) 
		return -1;
	}
} //end of isWin 

//Function to display a you win title card
void gameWin() {
	//set the colour to green
	SetConsoleTextAttribute(Console, 2);
	//print out the text 
	cout<< " __     __                    _       \n"
		<< " \\ \\   / /                   (_)      \n"
		<< "  \\ \\_/ /__  _   _  __      ___ _ __  \n"
		<< "   \\   / _ \\| | | | \\ \\ /\\ / / | '_ \\ \n"
		<< "    | | (_) | |_| |  \\ V  V /| | | | |\n"
		<< "    |_|\\___/ \\__,_|   \\_/\\_/ |_|_| |_|\n";
} //end of gameWin 

//Function to display a you lose title card 
void gameLose() {
	//set the colour to red
	SetConsoleTextAttribute(Console, 4);
	//print out the text 
	cout << " __     __           _                "
		<< "\n \\ \\   / /          | |               "
		<< "\n  \\ \\_/ /__  _   _  | | ___  ___  ___ "
		<< "\n   \\   / _ \\| | | | | |/ _ \\/ __|/ _ \\ "
		<< "\n    | | (_) | |_| | | | (_) \\__ \\  __/"
		<< "\n    |_|\\___/ \\__,_| |_|\\___/|___/\\___| \n";
} //end of gameLose

// Function to let user read while waiting for their next turn 
void nextTurn() {
	//create an variable to take whatever junk input 
	int nextTurnInput; 
	//Wait for the user to input that they are ready 
	cin >> nextTurnInput; 
	//Regardless of what they input just throw it away and reset cin so we can continue with the next turn 
	cin.clear(); 
	cin.ignore(INT_MAX, '\n'); 
} //end of nextTurn 

// Function to take input for when the game ends 
void gameContinue() {
	//Take input 
	cin >> cont; 
	//While the input is not 'y' or 'n'
	while (cin.fail() && (cont.at(0) != 'n' || cont.at(0) != 'y')) {
		//ask the user to only enter 'y' or 'n' 
		cout << "Please only enter 'y' or 'n' \n"; 
		//reset cin 
		cin.clear(); 
		cin.ignore(INT_MAX, '\n'); 
		//allow them to input again 
		cin >> cont; 
	}
} //end of gameContinue 

//Function to execute the gameplay code
void mancalaGame() {
	// set the random seed 
	srand(time(0));
	
	//While the player is playing 
	while (inGame) {
		//initialize board and variables
		//give the player and bot choice default values 
		int playerChoice = 0, botChoice = 7;
		//fill out the gameboard 
		populate(startPieceCount);
		//Set that a game is currently being played to true 
		inRound = true;
		//While a game is being played 
		while (inRound) {
			//If it's the player turn, draw the current board state 
			if(turn) drawBoard(false);
			//If it's the player's turn
			if (turn) {
				//ask the player for input 
				playerChoice = getChoice();
				//Apply their choice 
				dropIn(playerChoice);
			}
			//Otherwise it's the bot's turn 
			else {
				//If the difficutly is set to easy run the easy ai's code 
				if(aiDifficulty == 1)  botChoice = easyAi(board);
				//If the difficutly is set to medium run the medium ai's code 
				else if (aiDifficulty == 2)botChoice = mediumAi(board); 
				//If the difficultyl is set to hard run the hard ai's code 
				else botChoice = hardAi(board); 
				//Inform of the player of the bot's choice 
				std::cout << "\nThe bot picks hole " << botChoice-6 << ".\n";
				dropIn(botChoice);
			}
			//draw the board now updated with the player or bot's choices 
			drawBoard(false);

			//If someone got a point tell the player 
			if (gotPoint) {
				//If it was the player tell them they got a point 
				if (turn) cout << "You got a point! \n";
				//If it was the ai, inform the player 
				else cout << "The ai got a point. \n";
				//Reset the tracker for getting points 
				gotPoint = false; 
			}

			//If it was the bots turn tell the player what the bot picked
			if (!turn) cout << "The bit picked hole " << botChoice - 6 << "\n"; 

			//If a pit was captured tell the player
			if (captured) {
				//If it was the player tell them 
				if (turn) {
					cout << "Congrats you stole pit " << pitCaptured - 6 << " and got " << gemsStolen << " points for it! \n"; 
				}
				//If it was the ai, inform the player
				else {
					cout << "The ai stole pit " << pitCaptured + 1 << " and got " << gemsStolen << " points for it. \n"; 
				}
				//Reset the tracker for capturing pits 
				captured = false; 
			}

			//Check if the game has ended 
			if (isDone()) {
				//If it has stop the current game 
				inRound = false;
				//clear the board 
				cleanBoard();

				//draw the end game state in white 
				drawBoard(true);

				//Check if the player won 
				if (isWin() == 1) {
					//If yes, print out a big "you win" title card 
					gameWin();
				}
				else if ((isWin() == 0)) {
					//If it's a draw say so 
					std::cout << "\nThe Game Ends In A Draw.";
				}
				else {
					//If the ai won, print a big "you lose" title card 
					gameLose();
				}
			}

			//If an extra turn was awarded 
			if (extraTurn) {
				//if it was the player say they got an extra turn 
				if (turn) cout << "Congrats! You got a free turn! \n"; 
				//If it was the ai, inform the player 
				else cout << "The ai got a free turn. \n"; 
				//Reset the extraTurn tracker 
				extraTurn = false;
			}
			//Otherwise their is no extra turn 
			else {
				//So the turn shifts to the next person 
				turn = !turn;
			}

			//If the game hasn't e let the player read what's happening before progressing to the next turn 
			if(!isDone()) {
				cout << "When you are ready, just enter any character and you will be brought to the next turn.\n"; 
				//Wait for the player to be ready to start the next turn
				nextTurn(); 
			}
			//restart turn loop
		}
		//When the game has ended ask the player if they would like to continue playing
		std::cout << "\nWould you like to continue? (y/n): \n";
		//Take their input 
		gameContinue(); 
		//If they want to end it, stop looping through the game and go back to the main menu 
		if (cont.at(0) == 'n' || cont.at(0) == 'N') {
			inGame = false;
			currentScreen = 0; 
		}
	}
}
