#pragma once

#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <MmSystem.h>


//variable for the ai difficulty, 1 is easy, 2 is medium, and 3 hard 
extern int aiDifficulty;
//variable for the current screen, 0 is mainMenu, 1 is instructions, 2 is settings, and 3 is the main game
extern int currentScreen;

/*
#ifndef MainMenu.h
#define MainMenu.h


#endif // !MainMenu.h
*/


// Some global variables need in main.cpp 

//Declare all of the functions 

//Decalre the function for the instructions menu 
void displayInstructions();

//Declare the function for the settings menu 
void displaySettings(); 

//Declare the function for the main menu 
void displayMainMenu(); 

//Declare the function to draw screen borders 
void displayBorder(int);