#include "pgrm.h"

/*
============================================================================
Function    : Header
Parameters  : nothing
Return      : nothing
Description : Displays the header
============================================================================
 */
void Header()
{
cout << " +----------------------------------------------+ \n";
cout << " |	 Computer Science and Engineering	|\n";
cout << " |	 CSCE 1030 - Computer Science I		|\n";
cout << " | |\n";
cout << " +----------------------------------------------+\n";
	return;
}
/*
============================================================================
Function    : Description
Parameters  : nothing
Return      : nothing
Description : Displays the introduction message
============================================================================
 */
void Description()
{
cout << "------------------------------------------------------------\n";
cout << "          W e l c o m e   t o   1 0 3 0   C r u s h \n";
cout << " This program will randomly initialize your game board using\n";
cout << " a set of 6 characters (!, \", #, $, %, &) that a player will \n";
cout << " then attempt to match a combination of 3 or more characters\n";
cout << " to gain points in a finite set of moves or time duration.\n";
cout << "------------------------------------------------------------  \n";
	return;
}
/*
============================================================================
Function    : Initialize
Parameters  : an enum array representing the game's board and an int
	      representing the size of the board
Return      : nothing
Description : the function assigns random values between 33 and 38 to the
	      9 x 9 board
============================================================================
 */
void Initialize(BOARD **board)
{
	// initialize the board with random enum values
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			board[i][j] = static_cast<BOARD>((rand() % 6) + 33); // cast the value as an enum type
		}
	}

	return;
}
/*
============================================================================
Function    : Update
Parameters  : an enum array that represents the game's board and an int
	      representing the size of the board
Return      : nothing
Description : the function loops through the enum array and displays the
	      values to the screen
============================================================================
 */
void Update(player input, BOARD **board)
{
	// print the upper part of the board
	cout << "\n    1 2 3 4 5 6 7 8 9\n";
	cout << "  +-------------------+\n";

	// loop through the board and output all the values
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			// print the left part of the board
			if(j == 0)
			{
				cout << static_cast<char>('A' + i) << " | ";
			}
			cout << static_cast<char>(board[i][j]) << ' '; //cast the enum type as a character
		}
		cout << "| "<< endl; // print the right part of the board
	}
	// print the lower part of the board
	cout << "  +-------------------+\n";
	cout << "  Moves:   " << input.moves << " Score:   " << input.score << '\n';

	return;
}
/*
============================================================================
Function    : 	Check_Coordinate
Parameters  : 	a board pointer to a pointer representing a dynamic array of
	      	BOARD values and a player struct representing the players input
Return      :	nothing
Description : 	This function is used to check the array for identical values using
		the values of input.col_pos and input.row_pos as an index
		location in the dynamic array. The function checks the left
		and right if the player chose to check horizontally and above
		and below if the player chose to check vertically. If the score
		is greater than 2 the position are given new values and the player's
		score increases else the function simply returns.
============================================================================
 */
void Check_Coordinate(BOARD **board, player &input)
{
	int score = 0;
	BOARD B_Val = board[input.row_pos - 'A'][input.col_pos];

	// if the adjacent columns need to be checked
	if(input.dir == 'h' || input.dir == 'H')
	{
		int i; // a temporary integer value

		// check the characters to the left
		for(i = input.col_pos; i >= 0; i--)	
		{
			// if the position to the left is the same character
			if(board[input.row_pos - 'A'][i] == B_Val) score++; // increase the score
			else i = - 1; // else stop the loop
		} 

		// check the characters to the right
		for(i = input.col_pos + 1; i < SIZE; i++)	
		{
			// if the position to the right is the same character
			if(board[input.row_pos - 'A'][i] == B_Val) score++; // increase the score
			else i = SIZE; // else stop the loop
		}
	}
	else // else the adjacent rows need to be checked
	{
		int i; // a temporary integer value

		// check the characters above
		for(i = input.row_pos - 'A'; i >= 0; i--)
		{
			// if the position to the left is the same character
			if(board[i][input.col_pos] == B_Val) score++; // increase the score
			else i = -1; // else stop the loop
		} 

		// check the characters below
		for(i = input.row_pos - 'A' + 1; i < SIZE; i++)
		{
			// if the position to the right is the same character
			if(board[i][input.col_pos] == B_Val) score++; // increase the score
			else i = SIZE; // else stop the loop
		} 
	}

	if(score > 2) // if the score is at least 3 
	{
		int i; // an int for the index
		input.score += score; // increase the player's score

		cout << "Nice match! You got +" << score << " points!\n";
	
		// if the horizontal values need to be changed
		if(input.dir == 'h' || input.dir == 'H')
		{
			// change the characters to the left
			for(i = input.col_pos; i >= 0; i--)	
			{
				// if the position to the left is the same character
				if(board[input.row_pos - 'A'][i] == B_Val)
				{
					board[input.row_pos - 'A'][i] = static_cast<BOARD>((rand() % TOTAL_CHARS) + 33); // change the character 
				}
				else i = - 1; // else stop the loop
			} 

			// change the characters to the right
			for(i = input.col_pos + 1; i < SIZE; i++)	
			{
				// if the position to the right is the same character
				if(board[input.row_pos - 'A'][i] == B_Val)
				{
					board[input.row_pos - 'A'][i] = static_cast<BOARD>((rand() % TOTAL_CHARS) + 33); // change the character 
				}
				else i = SIZE; // else stop the loop
			}
		}
		// else the row values need to be changed
		else
		{
			// change the characters above
			for(i = input.row_pos - 'A'; i >= 0; i--)
			{
				// if the position to the left is the same character
				if(board[i][input.col_pos] == B_Val)
				{
					board[i][input.col_pos] = static_cast<BOARD>((rand() % TOTAL_CHARS) + 33); // change the character 
				} 
				else i = -1; // else stop the loop
			}

			// change the characters below
			for(i = input.row_pos - 'A' + 1; i < SIZE; i++)
			{
				// if the position to the right is the same character
				if(board[i][input.col_pos] == B_Val)
				{
					board[i][input.col_pos] = static_cast<BOARD>((rand() % TOTAL_CHARS) + 33); // change the character 
				}
				else i = SIZE; // else stop the loop
			}
		}
		return;
	}
	else // the score was too low
	{
		cout << "Sorry, no match! No points awarded...\n";
		return;
	}
}
