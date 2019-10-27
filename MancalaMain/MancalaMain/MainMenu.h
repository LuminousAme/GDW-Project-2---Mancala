/*
Menus code by Johnathan Naire
With editting by Ame Gilham
*/

#pragma once

//Import all needed librarbies 
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <MmSystem.h>

//Define console for text colour change
extern HANDLE Console;

//variable for the ai difficulty, 1 is easy, 2 is medium, and 3 hard 
extern int aiDifficulty;
//variable for the current screen, 0 is mainMenu, 1 is instructions, 2 is settings, and 3 is the main game (it will be equal to 4 when the user is leaving the game)
extern int currentScreen;

//Declare all of the functions 

//Decalre the function for the instructions menu 
void displayInstructions();

//Declare the function for the settings menu 
void displaySettings(); 

// Function to display the credits 
void displayCredits(); 

//Declare the function for the main menu 
void displayMainMenu(); 

//Declare the function to draw screen borders 
void displayBorder(int);