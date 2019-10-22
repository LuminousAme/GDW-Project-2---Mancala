#include "gameBoard.h"

//Function to dispaly the game board
void displayBoard(int board[]) {
	//each cout displays a different line of the board
		//the breaks with "<<board[number]<<" allow the number of gems in each pit and manacala to be displayed  
	cout << " _______________________________________________________________________________________________________________\n";
	cout << " /  ____________      ________     ________    ________    ________    ________    ________      ____home____  /\n";
	cout << " / |            |    [        ]   [        ]  [        ]  [        ]  [        ]  [        ]    |            | /\n";
	cout << " / |            |    [   "<<board[12]<<"    ]   [   "<<board[11]<<"    ]  [   "<<board[10]<<"    ]  [   "<< board[9]<<"    ]  [   "<<board[8]<<"    ]  [   "<<board[7]<<"    ]    |            | /\n";
	cout << " / |            |    [________]   [________]  [________]  [________]  [________]  [________]    |            | /\n";
	cout << " / |            |                                                                               |            | /\n";
	cout << " / |            |        6            5           4           3           2           1         |            | /\n";
	cout << " / |     "<<board[13]<<"      |                                                                               |     "<<board[6]<<"      | /\n";
	cout << " / |            |                                                                               |            | /\n";
	cout << " / |            |        1            2           3           4           5           6         |            | /\n";
	cout << " / |            |     ________     ________    ________    ________    ________    ________     |            | /\n";
	cout << " / |            |    [        ]   [        ]  [        ]  [        ]  [        ]  [        ]    |            | /\n";
	cout << " / |            |    [   "<<board[0]<<"    ]   [   "<<board[1]<<"    ]  [   "<<board[2]<<"    ]  [   "<<board[3]<<"    ]  [   "<<board[4]<<"    ]  [   "<<board[5]<<"    ]    |            | /\n";
	cout << " / |____away____|    [________]   [________]  [________]  [________]  [________]  [________]    |____________| /\n";
	cout << " / ____________________________________________________________________________________________________________/\n";
} //end of display board