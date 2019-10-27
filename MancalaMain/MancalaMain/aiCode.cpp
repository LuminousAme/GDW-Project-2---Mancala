#include "aiCode.h" 

// Function for the easy difficulty AI.
int easyAi(int board[])
{
	//declare ai variables
	int options[6]; //Stores all of the possible options for which pit it will pick 
	int numOfOptions = 0; //Index for the above, and the number of pits it is considering 

	//Cycle through each pit on it's side to see if they could get a point by selecting it 
	for (int i = 0; i < 6; i++) {
		// Check if the current pit can get a point 
		if ((13 - (i + 7)) <= board[i + 7]) {
			// If it can add it to the list of pits it is considering
			options[numOfOptions] = i + 7;
			numOfOptions++;
		}
	}

	// If it has more than 1 option, pick which of those pits it uses at random 
	if (numOfOptions > 1) {
		return options[int(rand() % numOfOptions)];
	}
	// If it has only one option, pick that pick 
	else if (numOfOptions == 1) {
		return options[0];
	}
	// Otherwise if it has no options, pick a random pit that has gems in it 
	else {
		//Check each bit 
		for (int i = 0; i < 6; i++) {
			//If it has gems
			if (board[i + 7] > 0) {
				//Add it to the list of available options
				options[numOfOptions] = i + 7;
				numOfOptions++;
			}
		}
		//Pick one of the pits from the available options at random (if any exist)
		if (numOfOptions > 0) {
			return options[int(rand() % numOfOptions)];
		}
		else {
			return -1;
		}
	}
} //End of easyAi 

// Function for the medium difficulty AI.
int mediumAi(int board[])
{
	//declare ai variables
	int options[6]; //Stores all of the possible options for which pit it will pick 
	int numOfOptions = 0; //Index for the above, and the number of pits it is considering 

	//Cycle through each pit on it's side to see if they could get a free turn by selecting it 
	for (int i = 0; i < 6; i++) {
		// Check if the current pit can get a free turn
		if ((13 - (i + 7)) == board[i + 7]) {
			// If it can add it to the list of pits it is considering
			options[numOfOptions] = i + 7;
			numOfOptions++;
		}
	}

	// If it has more than 1 option, pick which of those pits it uses at random 
	if (numOfOptions > 1) {
		return options[int(rand() % numOfOptions)];
	}
	// If it has only one option, pick that pick 
	else if (numOfOptions == 1) {
		return options[0];
	}
	// Otherwise if it has no options, go to the easy Ai logic
	else {
		return easyAi(board);
	}
} //end of mediumAi 

// Function for the hard difficulty AI. 
int hardAi(int board[]) {

	//declare ai variables 
	int zeroPits[6]; // Stores indices of the AI's pits that have no gems in them
	int numOfZeroPits = 0; // Index for the above, Stores the number of AI pits that have no gems in them
	int options[6]; // Stores the indices of all the pits the AI may choose 
	int numOfOptions = 0; // Index of the above, stores the number of pits the ai is considering 
	int opTarget[6]; // Indicies map to options[], the index of the pit the last gem will land in 
	int choice; // Stores the index of the pit it will choose (if it doesn't skip to the medium ai) 

	//Cycle through each each pit on it's side to see if any have zero gems 
	for(int i = 0; i < 6; i++) {
		if (board[i + 7] == 0 && board[5 - i] > 0) {
			//If the pit has no gems, add it to the list and increase the list's size 
			zeroPits[numOfZeroPits] = i + 7; 
			numOfZeroPits++; 
		}
	}
	//If there are pits with no gems, see if it can use them 
	if (numOfZeroPits > 0) {
		//Cycle through each pit with no gems 
		for (int i = 0; i < numOfZeroPits; i++) {
			//cycle through all the pits before the empty pit to see if any can land in the last spot
			for (int j = 0; j < zeroPits[i] - 7; j++) {
				//if it can 
				if ((zeroPits[i] - (j + 7)) == board[j + 7]) {
					//then add that pit to it's list of options 
					options[numOfOptions] = j + 7; 
					//record the pit it is trying to land in 
					opTarget[numOfOptions] = zeroPits[i] - 7; 
					//update the number of options 
					numOfOptions++; 
				}
			}
			//cycle through all the pits after the empty pit to see if any can land in the last spot 
			for (int j = 12; j > zeroPits[i]; j--) {
				if ((13 - j + zeroPits[i] == board[j])) { //equation seems wrong, looks like it might be off by 2 
					//then add that pit to it's list of options 
					options[numOfOptions] = j; 
					//record the pit it is trying to land in
					opTarget[numOfOptions] = zeroPits[i] - 7; 
					//update the number of options 
					numOfOptions++;
				}
			}
		}
		// If it has options that work determine which one is best 
		if (numOfOptions > 0) {

			// default to the first options 
			choice = options[0]; 
			// looping through every other option 
			for (int i = 1; i < numOfOptions; i++) {
				// If the next option will get the ai more points 
				if (board[opTarget[i] - 7] > board[opTarget[i - 1] - 7]) {
					// Make that it's main choice 
					choice = options[i]; 
				}
			}
			//Return it's choice of pit 
			return choice; 
		}
		// If not just go to the medium AI's logic 
		else {
			return mediumAi(board); 
		}
	}
	//If there are none just go to the medium AI's logic 
	else {
		return mediumAi(board);
	}
} //end of hardAi 