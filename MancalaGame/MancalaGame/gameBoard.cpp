#include "gameBoard.h"

//Function to dispaly the game board
void displayBoard(int board[]) {
	//each cout displays a different line of the board
		//the breaks with "<<board[number]<<" allow the number of gems in each pit and manacala to be displayed  
	cout << " _______________________________________________________________________________________________________________\n";
	cout << " /  ____________      ________     ________    ________    ________    ________    ________      ___Player___  /\n";
	cout << " / |            |    [        ]   [        ]  [        ]  [        ]  [        ]  [        ]    |            | /\n";
	cout << " / |            |    [   "<<board[12]<<"    ]   [   "<<board[11]<<"    ]  [   "<<board[10]<<"    ]  [   "<< board[9]<<"    ]  [   "<<board[8]<<"    ]  [   "<<board[7]<<"    ]    |            | /\n";
	cout << " / |            |    [________]   [________]  [________]  [________]  [________]  [________]    |            | /\n";
	cout << " / |            |                                                                               |            | /\n";
	cout << " / |            |     Ai pit 6     Ai pit 5    Ai pit 4    Ai pit 3    Ai pit 2    Ai pit 1     |            | /\n";
	cout << " / |     "<<board[13]<<"      |                                                                               |     "<<board[6]<<"      | /\n";
	cout << " / |            |                                                                               |            | /\n";
	cout << " / |            |      pit #1       pit #2      pit #3      pit #4      pit #5      pit #6      |            | /\n";
	cout << " / |            |     ________     ________    ________    ________    ________    ________     |            | /\n";
	cout << " / |            |    [        ]   [        ]  [        ]  [        ]  [        ]  [        ]    |            | /\n";
	cout << " / |            |    [   "<<board[0]<<"    ]   [   "<<board[1]<<"    ]  [   "<<board[2]<<"    ]  [   "<<board[3]<<"    ]  [   "<<board[4]<<"    ]  [   "<<board[5]<<"    ]    |            | /\n";
	cout << " / |__Computer__|    [________]   [________]  [________]  [________]  [________]  [________]    |____________| /\n";
	cout << " / ____________________________________________________________________________________________________________/\n";
} //end of display board