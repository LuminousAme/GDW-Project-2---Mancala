
#include <aiCode.h> 

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
