/*
Gameboard art by Shezwin Carim
Gameboard code by Shezwin Carim and Ame Gilham
*/

#pragma once

//Import all needed librarbies
#include <iostream>
#include <string> 

//Define namespace
using namespace std;

//Function to display the board
void displayBoard(int board[]);

//Function to display a pit / hole 
string displayPit(int& val);

//Function to display a mancala / store 
string displayMancala(int& val);