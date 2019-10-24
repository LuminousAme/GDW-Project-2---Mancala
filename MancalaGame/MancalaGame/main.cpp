#include <iostream>
#include <cmath>
#include <ctime>
#include "aiCode.h"
#include "gameBoard.h"

using namespace std;

//Global Variables
bool inGame = true;
int startPieceCount = 4;
int board[14], sboard[14];
bool turn = true, extraTurn = false, inRound = true;

void populate(int piece) {
	//Fill the board array
	for (int i = 0; i < 14; i++) {
		board[i] = piece;
		//Exclude the mancalas
		if (i == 6 || i == 13) {
			board[i] = 0;
		}
	}
}

int getChoice() {
	bool validIn = false;
	int playerPick = 0;
	//Prompt the user
	std::cout << "\nSelect your hole (1-6): \n";
	std::cin >> playerPick;
	playerPick--;
	//Check if the input is valid
	while (!validIn) {
		if (std::cin.fail() || playerPick < 0 || playerPick > 5 || board[playerPick] == 0) {
			std::cout << "Please enter a valid choice: \n";
			std::cin.clear();
			std::cin.ignore();
			std::cin >> playerPick;
			playerPick--;
		}
		else {
			validIn = true;
		}
	}
	return playerPick;
}

bool isCapture(int choice) {
	if (turn) {
		//see if hole is empty and on player side
		if (board[choice] == 0 && choice >= 0 && choice < 6) {
			return true;
		}
	}
	else {
		//see if hole is empty and on ai side
		if (board[choice] == 0 && choice >= 7 && choice < 13) {
			return true;
		}
	}
	return false;
}
void capture(int choice) {
	//find the opposite hole
	int clearedHole = 12 - choice;
	if (turn) {
		board[6] += board[clearedHole] + 1;
		board[clearedHole] = 0;
		board[choice] = -1;
	}
	else {
		board[13] += board[clearedHole] + 1;
		board[clearedHole] = 0;
		board[choice] = -1;
	}
}
bool inBank(int choice) {
	if (turn) {
		if (choice == 6) {
			return true;
		}
	}
	else {
		if (choice == 13) {
			return true;
		}
	}
	return false;
}
void drawBoard() {
	displayBoard(board); 
}
bool isDone() {
	bool doneCheck = true;
	if (turn) {
		for (int i = 0; i < 6; i++) {
			if (board[i] != 0) {
				doneCheck = false;
			}
		}
	}
	else {
		for (int j = 12; j > 6; j--) {
			if (board[j] != 0) {
				doneCheck = false;
			}
		}
	}
	return doneCheck;
}
void dropIn(int choice) {
	int pieceCount = board[choice];
	board[choice] = 0;
	choice++;
	for (int i = 0; i < pieceCount; i++) {
		if (turn && choice == 13) {
			i--;
		}
		else if (!turn && choice == 6) {
			i--;
		}
		else {
			if (i == pieceCount - 1) {
				if (isCapture(choice)) {
					capture(choice);
				}
				if (inBank(choice)) {
					extraTurn = true;
				}
			}
			board[choice]++;
		}
		choice++;
		if (choice >= 14) {
			choice = 0;
		}
	}
}
void cleanBoard() {
	for (int i = 0; i < 6; i++) {
		board[6] += board[i];
		board[i] = 0;
	}
	for (int j = 12; j > 6; j--) {
		board[13] += board[j];
		board[j] = 0;
	}
}
int isWin() {
	if (board[6] > board[13]) {
		return 1;
	}
	else if (board[6] == board[13]){
		return 0;
	}
	else {
		return -1;
	}
}
int main() {
	srand(time(0));
	string cont = "nope";
	while (inGame) {
		//initialize board and variables
		int playerChoice = 0, botChoice = 7;
		populate(startPieceCount);
		memcpy(sboard, board, sizeof(sboard));
		inRound = true;
		while (inRound) {
			drawBoard();
			memcpy(sboard, board, sizeof(sboard));
			if (turn) {
				playerChoice = getChoice();
				dropIn(playerChoice);
			}
			else {
				botChoice = mediumAi(board); 
				std::cout << "\nThe bot picks hole " << botChoice-6 << ".\n";
				dropIn(botChoice);
			}

			if (extraTurn) {
				extraTurn = false;
			}
			else {
				turn = !turn;
			}
			if (isDone()) {
				inRound = false;
				cleanBoard();
				drawBoard();
				if (isWin() == 1) {
					std::cout << "\nYOU WIN!!!!";
				}
				else if ((isWin() == 0)) {
					std::cout << "\nThe Game Ends In A Draw.";
				}
				else {
					std::cout << "\nYou Have Lost The Game.";
				}
			}
		}
		std::cout << "\nWould you like to continue? (y/n): \n";
		std::cin >> cont;
		if (cont.at(0) == 'n' || cont.at(0) == 'N') {
			inGame = false;
		}
	}
	return 0;
}