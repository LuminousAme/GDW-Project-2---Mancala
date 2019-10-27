/*
Gameboard art by Shezwin Carim 
Gameboard code by Shezwin Carim and Ame Gilham
*/

//Include header file 
#include "gameBoard.h"

//Function to dispaly the game board
void displayBoard(int board[]) {
	//each cout displays a different line of the board
		//the breaks with "<<board[number]<<" allow the number of gems in each pit and manacala to be displayed  
	cout << " _______________________________________________________________________________________________________________\n"
	<< " /  ____________      ________     ________    ________    ________    ________    ________      ___Player___  /\n"
	<< " / |            |    [        ]   [        ]  [        ]  [        ]  [        ]  [        ]    |            | /\n"
	<< " / |            |    " << displayPit(board[12]) << "   " << displayPit(board[11]) << "  " << displayPit(board[10]) << "  " << displayPit(board[9]) << "  " << displayPit(board[8]) << "  " << displayPit(board[7]) << "    |            | /\n"
	<< " / |            |    [________]   [________]  [________]  [________]  [________]  [________]    |            | /\n"
	<< " / |            |                                                                               |            | /\n"
	<< " / |            |     Ai pit 6     Ai pit 5    Ai pit 4    Ai pit 3    Ai pit 2    Ai pit 1     |            | /\n"
	<< " / " << displayMancala(board[13]) << "                                                                               " << displayMancala(board[6]) << " /\n"
	<< " / |            |                                                                               |            | /\n"
	<< " / |            |      pit #1       pit #2      pit #3      pit #4      pit #5      pit #6      |            | /\n"
	<< " / |            |     ________     ________    ________    ________    ________    ________     |            | /\n"
	<< " / |            |    [        ]   [        ]  [        ]  [        ]  [        ]  [        ]    |            | /\n"
	<< " / |            |    " << displayPit(board[0]) << "   " << displayPit(board[1]) << "  " << displayPit(board[2]) << "  " << displayPit(board[3]) << "  " << displayPit(board[4]) << "  " << displayPit(board[5]) << "    |            | /\n"
	<< " / |__Computer__|    [________]   [________]  [________]  [________]  [________]  [________]    |____________| /\n"
	<< " / ____________________________________________________________________________________________________________/\n";
} //end of display board

//Function to display the middle of a pit
string displayPit(int& val) {
	//display for if there are less than 9 gems in a pit 
	if (val <= 9) {
		return "[   " + to_string(val) + "    ]";
	}
	//display for if there are 10 or more gems in a pit 
	else {
		return "[   " + to_string(val) + "   ]";
	}
} //end of displayPit

// Function to display the middle of a manacala
string displayMancala(int& val) {
	//display for if there are less than 9 gems in the mancala 
	if (val <= 9) {
		return	"|     " + to_string(val) + "      |";
	}
	//display for if there are 10 or more gems in the mancala 
	else {
		return  "|     " + to_string(val) + "     |";
	}

}