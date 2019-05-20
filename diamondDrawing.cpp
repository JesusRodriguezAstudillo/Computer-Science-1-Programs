/* 
=================================================================================
Name		:Diamond Drawing
Author		:Jesus Rodriguez
Version		:
Copyright	:
Description	:This program was created to read an odd integer between 1 and 19
		 inclusively. A boolean function is used to determine if the
		 number entered is odd. If the input is odd, another function
		 displays the sum of all integers between 1 and the user input.
		 Finally, the user is asked to enter a character. Along with the
		 intger, the two variables serve as parameters for a void function
		 that displays a diamond.
=================================================================================
*/

#include <iostream>
using namespace std;

// Function defintion to check the validity of user input
// It uses an integer as the parameter and returns a boolean
bool valid_int(int value_entered);

// Function definition that will display the sum of integers
// It uses an integer as the parameter and returns an integer
int sum_of_integers(int sum_total);

/* Function definition to display diamond shape
it uses an integer and a characteras the parameters and
returns nothing since it is a void function */
void diamond_shape(int row_total, char diamond_character);

int main ()
{
	// Integer variable handle user input
	int odd_value;

	// Char variable that will make the body of the diamond
	char diamond;

	cout << "+-----------------------------------------------+ \n";
	cout << "|	Computer Science and Engineering	| \n";
	cout << "|	CSCE 1030 - Computer Science I		| \n";
	cout << "| 	Jesus Rodriguez		 jr0463		| \n";
	cout << "|	jr0463@unt.edu				| \n";
	cout << "+-----------------------------------------------+ \n";
	cout << endl;

	// Prompt for integer and loop until user enters a proper value
	do
	{
		cout << "Enter an odd integer between 1 and 19 inclusively: ";
		cin  >> odd_value;
		// Call function to check for validity
		if (valid_int(odd_value))
		{
			// Call function to display the sum of all integers between 1 and the input
			cout << "The sum of integers from 1 to " << odd_value << " is " << sum_of_integers(odd_value) << endl;
		}
		else
		{
			cout << "Your entry is not valid - ";
		}
	// Call function to use as a sentinel
	}while (!valid_int(odd_value));

	// Prompt for the character
	cout << "Please enter a printable character to draw a diamond: ";
	cin  >> diamond; 

	// Call void function to output diamond
	diamond_shape(odd_value, diamond);

	return 0;
}

/* 
=================================================================================
Function	: validity
Parameters	: an integer that represents the integer input by the user
Return		: a boolean that returns true when input is valid otherwise it
		  returns false
Description	: This function uses a mathematical property to check if the value
		  entered by the user is odd. The boolean returns true if the 
		  remainder of the integer entered is 1 when divided by 2. 
==================================================================================
*/
bool valid_int(int value_entered)
{
	/* Start of if statement
	   if checks that user input is with in parameters */
	if ((value_entered < 20) && (value_entered > 0))
	{
		// function returns true if user input is odd
		return ((value_entered % 2 == 1));
	}
	/* else statement returns false if input is even or less than 1 and 
	   greater than 19 */
	else
	{
		return false;
	}
}

/* 
=================================================================================
Function	: Integer Sum
Parameters	: an integer that represents the limit of the sum
Return		: an integer that represent the sum of integers
Description	: This function uses a for loop to add all of the integers 
		  between 1 and the odd integer that the user entered.
==================================================================================
*/
int sum_of_integers(int sum_total)
{
	// declared and initialized an integer value to return sum 
	int total = 0;

	for (int integer_sum = 1; integer_sum <= sum_total; integer_sum++)
		total += integer_sum; 
	
	return (total);
}

/* 
=================================================================================
Function	: Diamond
Parameters	: an integer that represents the number of rows and a character
		  that will form the body of the diamond
Return		: a void function that only displays the diamond shape
Description	: This function uses various nested for loops to displays spaces
 		  and characters that form a diamond. The function has two
		  for-loops that form the top and bottom of a diamond.
==================================================================================
*/
void diamond_shape(int row_total, char diamond_character)
{
	int rows, columns, spaces;

	/* To make the diamond shape, the function was divided into two triangles.
	   This for loop makes the top half of the diamond so it halfs user input by two
	   and adds one for the row where characters equals input.
	*/
	for (rows = 1; rows <= (row_total / 2) + 1; rows++)
	{
		for (spaces = ((row_total / 2) + 1) - rows; spaces > 0; spaces--)
		{
			cout << " ";
		}
		for (columns = 1; columns <= (rows * 2) - 1; columns++)
		{
			cout << diamond_character;
		}
		cout << endl;
	}

	// This for loop makes the bottom of the diamond. Like the top, it halfs the user
	// input but it decreases the number of rows.
	for(rows = (row_total / 2); rows > 0; rows--)
	{
		for(spaces = 1; spaces <= (((row_total / 2) + 1) - rows); spaces++)
		{
			cout << " ";
		}
		for(columns = 1; columns <= (rows * 2) - 1; columns++)
		{	
			cout << diamond_character;
		}
		cout << endl;
	}
	return;
}
