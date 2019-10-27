#pragma once
#include <iostream>
#include <cmath>
#include <ctime>
#include <windows.h>
#include <MmSystem.h>
#include "MainMenu.h"
#include "aiCode.h"
#include "gameBoard.h"

//Function to fill the board 
void populate(int piece); 

//Function to get the player input
int getChoice(); 

//Function to check if a pits gems have been captured 
bool isCapture(int choice); 

//Function to capture all the gems in an opposite side pit
void capture(int choice); 

//Function to check if the gem is being placed in a mancala
bool inBank(int choice); 

//Function to draw the gameBoard
void drawBoard(bool end);

// Function to check to see if the game is done 
bool isDone(); 

// Function to drop gems into their new pits
void dropIn(int choice);

// Function to clear the board at the end of the game
void cleanBoard(); 

// Function to check if the player won
int isWin(); 

//Function to display a you win title card
void gameWin();

//Function to display a you lose title card 
void gameLose(); 

// Function to let user read while waiting for their next turn 
void nextTurn(); 

// Function to take input for when the game ends 
void gameContinue(); 

//Function to execute the gameplay code
void mancalaGame(); 
