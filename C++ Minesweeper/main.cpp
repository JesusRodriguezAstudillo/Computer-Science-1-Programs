/*
============================================================================
 Name        : 	Minesweeper
 Author      : 	Jesus Rodriguez
============================================================================
*/
#include "pgrm.h"

int main()
{
	srand(time(0)); // seed the random function

	BOARD **board = new BOARD*[SIZE]; // declare the rows of the dynamic board array

        // create the columns of the dynamic board array
	for(int i = 0; i < SIZE; i++)
	{
		board[i] = new BOARD[SIZE];
	}

	string coor = "00"; // a coordinate in the board
	player p_input; // the struct for player input
	p_input.moves = 0; // initialize the value of the moves
	p_input.score = 0; // initialize the value fo the score
	bool valid = false; // a boolean to check the validity of the input string

	// call display functions
	Header();
	Description();

	cout << "Initializing board...\n";
	Initialize(board); // intialize the board
	Update(p_input, board); // update the board

	do // while the the number of moves is less then the max and the score is less then the max
	{
		do // while the input is not valid
		{
			// prompt for coordinate
			cout << "Enter location for move #" << p_input.moves+1 << " (e.g. B7): ";
			cin  >> coor;
		
			// if the player chose the reshuffle command 
			if(coor == "R0") valid = true; // the command is valid
			// else if the column index is invalid or if there is input larger than a string with 2 characters 
			else if(coor[0] < 'A' || coor[0] > 'I' || coor[2] != 0) 
			{
				valid = false;
				cout << "Invalid location selected: " << coor << ". Try again..." << endl;
			}
			// else if the coordinate has an invalid column
			else if(coor[1] == '0')
			{
				valid = false;
				cout << "Invalid column location selected: " << coor[1] << ". Try again...\n";
			}
			// else the command is valid
			else valid = true;
		}while(!valid);	
	
		p_input.row_pos = coor[0]; // place row value from string
		p_input.col_pos = coor[1] - '0' - 1; // place column value from string
		p_input.moves++; // increase the move counter
	
		// if the player chose to reshuffle
		if(coor == "R0")
		{
			cout << "Board Reshuffled...\n";
			Initialize(board); // call the initiaize function to reshuffle
		}
		// else the player chose a valid coordination
		else
		{
			// prompt for direction
			cout << "Enter direction (V = Vertical, H = Horizontal): ";
			cin  >> p_input.dir;

			// while the direction is not v, V, h, or H
			while(!(p_input.dir == 'v' || p_input.dir == 'V' || p_input.dir == 'h' || p_input.dir == 'H'))
			{
				cout << "Direction not valid\n";

				// reprompt for direction
				cout << "Enter direction (V = Vertical, H = Horizontal): ";
				cin  >> p_input.dir;
			}
		
			Check_Coordinate(board, p_input); // check the values of the coordinate
		}

		Update(p_input, board); // update the board
	}while(p_input.moves < MAX_MOVES && p_input.score < 25);

	Update(p_input, board); // update the board
	if(p_input.score >= 25) cout << "Congratulations on your score of " << p_input.score << " in " << p_input.moves << " moves!\n";
	else cout << "Sorry you failed to score 25 points in 10 moves!\n";

	// delete the columns of the dynamic array
	for(int i = 0; i < SIZE; i++)
	{
		delete []board[i];
	}
	// delete the rows of the dynamic array
	delete []board;

	return 0;
}
